#include "sol.h"

int sol_state_init(sol_state_t *state) {
	sol_object_t *globals, *debug, *iter;

	state->None = NULL;
	state->OutOfMemory = NULL;
	state->scopes = NULL;
	state->error = NULL;
	state->ret = NULL;
	state->sflag = SF_NORMAL;

	// If any of the following fail, some very weird things are happening.
	if(!(state->None = sol_new_singlet(state))) goto cleanup;
	if(!(state->OutOfMemory = sol_new_singlet(state))) goto cleanup;
	if(!(state->StopIteration = sol_new_singlet(state))) goto cleanup;

	// We can now use the normal error reporting mechanism, now
	// that errors are distinguishable. Set that up now.

	//Initialize all of the builtin operations
	//(these ones are technically already pointed to by None/OOM)
	state->NullOps.add = sol_f_not_impl;
	state->NullOps.sub = sol_f_not_impl;
	state->NullOps.mul = sol_f_not_impl;
	state->NullOps.div = sol_f_not_impl;
	state->NullOps.band = sol_f_not_impl;
	state->NullOps.bor = sol_f_not_impl;
	state->NullOps.bxor = sol_f_not_impl;
	state->NullOps.blsh = sol_f_not_impl;
	state->NullOps.brsh = sol_f_not_impl;
	state->NullOps.bnot = sol_f_not_impl;
	state->NullOps.cmp = sol_f_default_cmp;
	state->NullOps.call = sol_f_not_impl;
	state->NullOps.index = sol_f_not_impl;
	state->NullOps.setindex = sol_f_not_impl;
	state->NullOps.len = sol_f_not_impl;
	state->NullOps.iter = sol_f_not_impl;
	state->NullOps.toint = sol_f_not_impl;
	state->NullOps.tofloat = sol_f_not_impl;
	state->NullOps.tostring = sol_f_not_impl;
	state->NullOps.init = sol_f_no_op;
	state->NullOps.free = sol_f_no_op;
	
	state->IntOps = state->NullOps;
	state->FloatOps = state->NullOps;
	state->StringOps = state->NullOps;
	state->ListOps = state->NullOps;
	state->LCellOps = state->NullOps;
	state->MapOps = state->NullOps;
	state->MCellOps = state->NullOps;
	state->FuncOps = state->NullOps;
	state->CFuncOps = state->NullOps;

	state->IntOps.add = sol_f_int_add;
	state->IntOps.sub = sol_f_int_sub;
	state->IntOps.mul = sol_f_int_mul;
	state->IntOps.div = sol_f_int_div;
	state->IntOps.band = sol_f_int_band;
	state->IntOps.bor = sol_f_int_bor;
	state->IntOps.bxor = sol_f_int_bxor;
	state->IntOps.blsh = sol_f_int_blsh;
	state->IntOps.brsh = sol_f_int_brsh;
	state->IntOps.bnot = sol_f_int_bnot;
	state->IntOps.cmp = sol_f_int_cmp;
	state->IntOps.toint = sol_f_int_toint;
	state->IntOps.tofloat = sol_f_int_tofloat;
	state->IntOps.tostring = sol_f_int_tostring;

	state->FloatOps.add = sol_f_float_add;
	state->FloatOps.sub = sol_f_float_sub;
	state->FloatOps.mul = sol_f_float_mul;
	state->FloatOps.div = sol_f_float_div;
	state->FloatOps.cmp = sol_f_float_cmp;
	state->FloatOps.toint = sol_f_float_toint;
	state->FloatOps.tofloat = sol_f_float_tofloat;
	state->FloatOps.tostring = sol_f_float_tostring;

	state->StringOps.add = sol_f_str_add;
	state->StringOps.mul = sol_f_str_mul;
	state->StringOps.cmp = sol_f_str_cmp;
	state->StringOps.len = sol_f_str_len;
	state->StringOps.iter = sol_f_str_iter;
	state->StringOps.toint = sol_f_str_toint;
	state->StringOps.tofloat = sol_f_str_tofloat;
	state->StringOps.tostring = sol_f_str_tostring;
	state->StringOps.free = sol_f_str_free;

	state->ListOps.add = sol_f_list_add;
	state->ListOps.mul = sol_f_list_mul;
	state->ListOps.call = sol_f_not_impl;
	state->ListOps.index = sol_f_list_index;
	state->ListOps.setindex = sol_f_list_setindex;
	state->ListOps.len = sol_f_list_len;
	state->ListOps.iter = sol_f_list_iter;
	state->ListOps.tostring = sol_f_list_tostring;
	state->ListOps.free = sol_f_list_free;
	
	state->LCellOps = state->ListOps;
	state->LCellOps.free = sol_f_lcell_free;

	state->MapOps.add = sol_f_map_add;
	state->MapOps.call = sol_f_map_call;
	state->MapOps.index = sol_f_map_index;
	state->MapOps.setindex = sol_f_map_setindex;
	state->MapOps.len = sol_f_map_len;
	state->MapOps.iter = sol_f_map_iter;
	state->MapOps.tostring = sol_f_map_tostring;
	state->MapOps.free = sol_f_map_free;
	
	state->MCellOps = state->MapOps;
	state->MCellOps.free = sol_f_mcell_free;

	state->FuncOps.call = sol_f_func_call;
	state->FuncOps.index = sol_f_func_index;
	state->FuncOps.setindex = sol_f_func_setindex;
	state->FuncOps.tostring = sol_f_func_tostring;

	state->CFuncOps.call = sol_f_cfunc_call;
	state->CFuncOps.tostring = sol_f_cfunc_tostring;

	state->error = state->None;
	state->scopes = sol_new_list(state);
	if(sol_has_error(state)) goto cleanup;
	globals = sol_new_map(state);
	debug = sol_new_map(state);
	iter = sol_new_map(state);
	if(sol_has_error(state)) goto cleanup;
	sol_list_insert(state, state->scopes, 0, globals);
	if(sol_has_error(state)) goto cleanup;
	// I'm going to buffer all of these together because I can.
	sol_map_set_name(state, globals, "OutOfMemory", state->OutOfMemory);
	sol_map_set_name(state, globals, "StopIteration", state->StopIteration);
	sol_map_set_name(state, globals, "toint", sol_new_cfunc(state, sol_f_toint));
	sol_map_set_name(state, globals, "tofloat", sol_new_cfunc(state, sol_f_tofloat));
	sol_map_set_name(state, globals, "tostring", sol_new_cfunc(state, sol_f_tostring));
	sol_map_set_name(state, globals, "try", sol_new_cfunc(state, sol_f_try));
	sol_map_set_name(state, globals, "type", sol_new_cfunc(state, sol_f_type));
	sol_map_set_name(state, globals, "prepr", sol_new_cfunc(state, sol_f_prepr));
	sol_map_set_name(state, globals, "print", sol_new_cfunc(state, sol_f_print));
	sol_map_set_name(state, globals, "rawget", sol_new_cfunc(state, sol_f_rawget));
	sol_map_set_name(state, globals, "rawset", sol_new_cfunc(state, sol_f_rawset));
	sol_map_set_name(state, globals, "range", sol_new_cfunc(state, sol_f_range));
	
	sol_map_set_name(state, debug, "getref", sol_new_cfunc(state, sol_f_debug_getref));
	sol_map_set_name(state, debug, "setref", sol_new_cfunc(state, sol_f_debug_setref));
	sol_map_set_name(state, debug, "closure", sol_new_cfunc(state, sol_f_debug_closure));
	sol_map_set_name(state, debug, "globals", sol_new_cfunc(state, sol_f_debug_globals));
	sol_map_set_name(state, debug, "locals", sol_new_cfunc(state, sol_f_debug_locals));
	sol_map_set_name(state, globals, "debug", debug);
	sol_obj_free(debug);
	
	sol_map_set_name(state, iter, "str", sol_new_cfunc(state, sol_f_iter_str));
	sol_map_set_name(state, iter, "list", sol_new_cfunc(state, sol_f_iter_list));
	sol_map_set_name(state, iter, "map", sol_new_cfunc(state, sol_f_iter_map));
	sol_map_set_name(state, globals, "iter", iter);
	sol_obj_free(iter);
	if(sol_has_error(state)) goto cleanup;

	// We're all set!
	return 1;

	cleanup:
	sol_obj_free(state->None);
	sol_obj_free(state->OutOfMemory);
	sol_obj_free(state->StopIteration);
	return 0;
}

sol_object_t *sol_state_resolve(sol_state_t *state, sol_object_t *key) {
	sol_object_t *cur = state->scopes, *temp;
	while(cur) {
        if(cur->lvalue) {
			temp = sol_map_get(state, cur->lvalue, key);
			if(!sol_is_none(state, temp)) return sol_incref(temp);
		}
		cur = cur->lnext;
	}

	return sol_incref(state->None);
}

sol_object_t *sol_state_resolve_name(sol_state_t *state, const char *name) {
	sol_object_t *key = sol_new_string(state, name), *temp;

	if(sol_has_error(state)) return sol_incref(state->None);

	temp = sol_state_resolve(state, key);
	sol_obj_free(key);
	return temp;
}

void sol_state_assign(sol_state_t *state, sol_object_t *key, sol_object_t *val) {
	sol_object_t *cur = state->scopes, *next, *active = NULL;

	if(!cur) {
		sol_set_error_string(state, "Global state does not exist");
		return;
	}

	next = cur->lnext;
	while(next) {
		cur = next;
		if(cur->lvalue) active = cur;
		next = cur->lnext;
	}
	
	if(!active) {
		sol_set_error_string(state, "No scopes exist");
		return;
	}

	sol_map_set(state, active->lvalue, key, val);
}

void sol_state_assign_name(sol_state_t *state, const char *name, sol_object_t *val) {
	sol_object_t *key = sol_new_string(state, name);

	if(sol_has_error(state)) return;

	sol_state_assign(state, key, val);
	sol_obj_free(key);
}

void sol_state_assign_l(sol_state_t *state, sol_object_t *key, sol_object_t *val) {
	sol_object_t *cur = state->scopes;
	
	while(cur && !cur->lvalue) cur = cur->lnext;

	if(!cur) {
		sol_set_error_string(state, "Local state does not exist");
		return;
	}

	sol_map_set(state, cur->lvalue, key, val);
}

void sol_state_assign_l_name(sol_state_t *state, const char *name, sol_object_t *val) {
	sol_object_t *key = sol_new_string(state, name);

	if(sol_has_error(state)) return;

	sol_state_assign_l(state, key, val);
	sol_obj_free(key);
}

void sol_state_push_scope(sol_state_t *state, sol_object_t *scope) {
    sol_list_push(state, state->scopes, scope);
}

sol_object_t *sol_state_pop_scope(sol_state_t *state) {
    return sol_list_pop(state, state->scopes);
}

sol_object_t *sol_get_error(sol_state_t *state) {
	return sol_incref(state->error);
}

sol_object_t *sol_set_error(sol_state_t *state, sol_object_t *err) {
	state->error = sol_incref(err);
	return sol_incref(state->None);
}

sol_object_t *sol_set_error_string(sol_state_t *state, const char *serr) {
	sol_object_t *err = sol_new_string(state, serr), *res;

	if(sol_has_error(state)) return sol_incref(state->None);

	res = sol_set_error(state, err);
	sol_obj_free(err);

	return res;
}

void sol_clear_error(sol_state_t *state) {
	// This silliness ensures we don't accidentally free None.
	sol_object_t *olderr = state->error;
	state->error = sol_incref(state->None);
	sol_obj_free(olderr);
}
