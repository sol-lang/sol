#include "sol.h"

int sol_state_init(sol_state_t *state) {
	sol_object_t *globals;

	state->None = NULL;
	state->OutOfMemory = NULL;
	state->scopes = NULL;
	state->error = NULL;

	// If any of the following fail, some very weird things are happening.
	if(!(state->None = sol_new_singlet(state))) goto cleanup;
	if(!(state->OutOfMemory = sol_new_singlet(state))) goto cleanup;

	// We can now use the normal error reporting mechanism, now
	// that errors are distinguishable. Set that up now.
	state->error = state->None;
	state->scopes = sol_new_list(state);
	if(sol_has_error(state)) goto cleanup;
	globals = sol_new_map();
	if(sol_has_error(state)) goto cleanup;
	sol_list_insert(state, state->scopes, 0, globals);
	if(sol_has_error(state)) goto cleanup;
	// I'm going to buffer all of these together because I can.
	sol_map_set(state, globals, sol_new_string(state, "toint"), sol_new_cfunc(state, sol_f_toint));
	sol_map_set(state, globals, sol_new_string(state, "tofloat"), sol_new_cfunc(state, sol_f_tofloat));
	sol_map_set(state, globals, sol_new_string(state, "tostring"), sol_new_cfunc(state, sol_f_tostring));
	sol_map_set(state, globals, sol_new_string(state, "try"), sol_new_cfunc(state, sol_f_try));
	if(sol_has_error(state)) goto cleanup;

	//Initialize all of the builtin operations
	//(these ones are technically already pointed to by None/OOM)
	state->NullOps.add = sol_f_not_impl;
	state->NullOps.sub = sol_f_not_impl;
	state->NullOps.mul = sol_f_not_impl;
	state->NullOps.div = sol_f_not_impl;
	state->NullOps.band = sol_f_not_impl;
	state->NullOps.bor = sol_f_not_impl;
	state->NullOps.bxor = sol_f_not_impl;
	state->NullOps.bnot = sol_f_not_impl;
	state->NullOps.call = sol_f_not_impl;
	state->NullOps.index = sol_f_not_impl;
	state->NullOps.setindex = sol_f_not_impl;
	state->NullOps.len = sol_f_not_impl;
	state->NullOps.toint = sol_f_not_impl;
	state->NullOps.tofloat = sol_not_impl
	state->NullOps.tostring = sol_f_not_impl;
	state->NullOps.init = sol_f_no_op;
	state->NullOps.free = sol_f_no_op;

	state->IntOps.add = sol_f_int_add;
	state->IntOps.sub = sol_f_int_sub;
	state->IntOps.mul = sol_f_int_mul;
	state->IntOps.div = sol_f_int_div;
	state->IntOps.band = sol_f_int_band;
	state->IntOps.bor = sol_f_int_bor;
	state->IntOps.bxor = sol_f_int_bxor;
	state->IntOps.bnot = sol_f_int_bnot;
	state->IntOps.call = sol_f_not_impl;
	state->IntOps.index = sol_f_not_impl;
	state->IntOps.setindex = sol_f_not_impl;
	state->IntOps.len = sol_f_not_impl;
	state->IntOps.toint = sol_f_int_toint;
	state->IntOps.tofloat = sol_f_int_tofloat;
	state->IntOps.tostring = sol_f_int_tostring;
	state->IntOps.init = sol_f_no_op;
	state->IntOps.free = sol_f_no_op;

	state->FloatOps.add = sol_f_float_add;
	state->FloatOps.sub = sol_f_float_sub;
	state->FloatOps.mul = sol_f_float_mul;
	state->FloatOps.div = sol_f_float_div;
	state->FloatOps.band = sol_f_not_impl;
	state->FloatOps.bor = sol_f_not_impl;
	state->FloatOps.bxor = sol_f_not_impl;
	state->FloatOps.bnot = sol_f_not_impl;
	state->FloatOps.call = sol_f_not_impl;
	state->FloatOps.index = sol_f_not_impl;
	state->FloatOps.setindex = sol_f_not_impl;
	state->FloatOps.len = sol_f_not_impl;
	state->FloatOps.toint = sol_f_float_toint;
	state->FloatOps.tofloat = sol_f_float_tofloat;
	state->FloatOps.tostring = sol_f_float_tostring;
	state->FloatOps.init = sol_f_no_op;
	state->FloatOps.free = sol_f_no_op;

	state->StringOps.add = sol_f_str_add;
	state->StringOps.sub = sol_f_not_impl;
	state->StringOps.mul = sol_f_str_mul;
	state->StringOps.div = sol_f_not_impl;
	state->StringOps.band = sol_f_not_impl
	state->StringOps.bor = sol_f_not_impl;
	state->StringOps.bxor = sol_f_not_impl;
	state->StringOps.bnot = sol_f_not_impl;
	state->StringOps.call = sol_f_not_impl;
	state->StringOps.index = sol_f_not_impl;
	state->StringOps.setindex = sol_f_not_impl;
	state->StringOps.len = sol_f_str_len;
	state->StringOps.toint = sol_f_str_toint;
	state->StringOps.tofloat = sol_f_str_tofloat;
	state->StringOps.tostring = sol_f_str_tostring;
	state->StringOps.init = sol_f_no_op;
	state->StringOps.free = sol_f_str_free;

	state->ListOps.add = sol_f_list_add;
	state->ListOps.sub = sol_f_not_impl;
	state->ListOps.mul = sol_f_list_mul;
	state->ListOps.div = sol_f_not_impl;
	state->ListOps.band = sol_f_not_impl;
	state->ListOps.bor = sol_f_not_impl;
	state->ListOps.bxor = sol_f_not_impl;
	state->ListOps.bnot = sol_f_not_impl;
	state->ListOps.call = sol_f_not_impl;
	state->ListOps.index = sol_f_list_index;
	state->ListOps.setindex = sol_f_list_setindex;
	state->ListOps.len = sol_f_list_len;
	state->ListOps.toint = sol_f_not_impl;
	state->ListOps.tofloat = sol_f_not_impl;
	state->ListOps.tostring = sol_f_list_tostring;
	state->ListOps.init = sol_f_no_op;
	state->ListOps.free = sol_f_list_free;

	state->MapOps.add = sol_f_map_add;
	state->MapOps.sub = sol_f_not_impl;
	state->MapOps.mul = sol_f_not_impl;
	state->MapOps.div = sol_f_not_impl;
	state->MapOps.band = sol_f_not_impl;
	state->MapOps.bor = sol_f_not_impl;
	state->MapOps.bxor = sol_f_not_impl;
	state->MapOps.bnot = sol_f_not_impl;
	state->MapOps.call = sol_f_not_impl;
	state->MapOps.index = sol_f_map_index;
	state->MapOps.setindex = sol_f_map_setindex;
	state->MapOps.len = sol_f_map_len;
	state->MapOps.toint = sol_f_not_impl;
	state->MapOps.tofloat = sol_f_not_impl;
	state->MapOps.tostring = sol_f_map_tostring;
	state->MapOps.init = sol_f_no_op;
	state->MapOps.free = sol_f_map_free;

	state->CFuncOps.add = sol_f_not_impl;
	state->CFuncOps.sub = sol_f_not_impl;
	state->CFuncOps.mul = sol_f_not_impl;
	state->CFuncOps.div = sol_f_not_impl;
	state->CFuncOps.band = sol_f_not_impl;
	state->CFuncOps.bor = sol_f_not_impl;
	state->CFuncOps.bxor = sol_f_not_impl;
	state->CFuncOps.bnot = sol_f_not_impl;
	state->CFuncOps.call = sol_f_cfunc_call;
	state->CFuncOps.index = sol_f_not_impl;
	state->CFuncOps.setindex = sol_f_not_impl;
	state->CFuncOps.len = sol_f_not_impl;
	state->CFuncOps.toint = sol_f_not_impl;
	state->CFuncOps.tofloat = sol_f_not_impl;
	state->CFuncOps.tostring = sol_f_cfunc_tostring;
	state->CFuncOps.init = sol_f_no_op;
	state->CFuncOps.free = sol_f_no_op;

	// We're all set!
	return 1;

	_cleanup:
	sol_obj_free(state->None);
	sol_obj_free(state->OutOfMemory);
	return 0;
}

sol_object_t *sol_state_resolve(sol_state_t *state, sol_object_t *key) {
	sol_object_t *cur = state->scopes, *temp;
	while(cur.lvalue) {
		temp = sol_map_get(state, cur.lvalue, key);
		if(!sol_is_none(temp)) return sol_incref(temp);
		cur = cur.lnext;
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
	sol_object_t *cur = state->scopes, *next;

	if(!cur) {
		sol_set_error_string(state, "Global state does not exist");
		return;
	}

	next = cur.lnext;
	while(next) {
		cur = next;
		next = cur.lnext;
	}

	sol_map_set(state, cur.lvalue, key, val);
}

void sol_state_assign_name(sol_state_t *state, const char *name, sol_object_t *val) {
	sol_object_t *key = sol_new_string(name);

	if(sol_has_error(state)) return;

	sol_state_assign(state, key, val);
	sol_obj_free(key);
}

void sol_state_assign_l(sol_state_t *state, sol_object_t *key, sol_object_t *val) {
	sol_object_t *cur = state->scopes;

	if(!cur) {
		sol_set_error_string(state, "Local state does not exist");
		return;
	}

	sol_map_set(state, cur.lvalue, key, val);
}

void sol_state_assign_l_name(sol_state_t *state, const char *name, sol_object_t *val) {
	sol_object_t *key = sol_new_string(name);

	if(sol_has_error(state)) return;

	sol_state_assign_l(state, key, val);
	sol_obj_free(key);
}

sol_object_t *sol_get_error(sol_state_t *state) {
	return sol_incref(state->error);
}

sol_object_t *sol_set_error(sol_state_t *state, sol_object_t *err) {
	state->error = sol_incref(err);
	return sol_incref(state->None);
}

sol_object_t *sol_set_error_string(sol_state_t *state, const char *serr) {
	sol_object_t *err = sol_new_string(serr);

	if(sol_has_error(state)) return sol_incref(state->None);

	sol_set_error(state, err);
	sol_obj_free(err);
}

void sol_clear_error(sol_state_t *state) {
	// This silliness ensures we don't accidentally free None.
	sol_object_t *olderr = state->error;
	state->error = sol_incref(state->None);
	sol_obj_free(olderr);
}
