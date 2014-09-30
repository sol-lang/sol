#include <string.h>
#include <stdlib.h>
#include "sol.h"

// This is supposedly a C99 trick.

static char *_itoa(int i) {
	int n = sprintf(NULL, "%d", i) + 1;
	char *s = malloc(n)
	snprintf(s, n, "%d", i);
	return s;
}

static char *_ftoa(double f) {
	int n = sprintf(NULL, "%f", f) + 1;
	char *s = malloc(n)
	snprintf(s, n, "%f", f);
	return s;
}

sol_object_t *sol_f_not_impl(sol_state_t *state, sol_object_t *args) {
	return sol_set_error_string(state, "Undefined method");
}

sol_object_t *sol_f_no_op(sol_state_t *state, sol_object *args) {
	return sol_incref(state->None);
}

sol_object_t *sol_f_toint(sol_state_t *state, sol_object_t *args) {
	sol_object_t *obj = sol_list_get_index(state, args, 0);
	sol_object_t *res = obj->ops->toint(state, args);
	sol_obj_free(obj);
	return res;
}

sol_object_t *sol_f_tofloat(sol_state_t *state, sol_object_t *args) {
	sol_object_t *obj = sol_list_get_index(state, args, 0);
	sol_object_t *res = obj->ops->tofloat(state, args);
	sol_obj_free(obj);
	return res;
}

sol_object_t *sol_f_tostring(sol_state_t *state, sol_object_t *args) {
	sol_object_t *obj = sol_list_get_index(state, args, 0);
	sol_object_t *res = obj->ops->tostring(state, args);
	sol_obj_free(obj);
	return res;
}

sol_object_t *sol_f_try(sol_state_t *state, sol_object_t *args) {
	sol_object_t *func = sol_list_get_index(state, args, 0), fargs = sol_list_sublist(state, args, 1);
	sol_object_t *ls = sol_new_list(state), *one = sol_new_int(state, 1);
	sol_object_t *res = func->ops->call(state, fargs);
	sol_obj_free(func);
	sol_obj_free(fargs);
	if(sol_has_error(state)) {
		sol_object_t *err = sol_get_error(state);
		sol_object_t *zero = sol_new_int(state, 0);
		sol_object_free(res);
		sol_object_free(one);
		sol_clear_error(state);
		sol_list_insert(state, ls, 0, err);
		sol_obj_free(err);
		sol_list_insert(state, ls, 0, zero);
		sol_obj_free(zero);
		return ls;
	}
	sol_list_insert(state, ls, 0, res);
	sol_obj_free(res);
	sol_list_insert(state, ls, 0, one);
	sol_obj_free(one);
	return ls;
}

sol_object_t *sol_f_int_add(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_int(state, sol_list_get_index(state, args, 1));
	sol_object_t *res = sol_new_int(state, a->ival + b->ival);
	sol_obj_free(a);
	sol_obj_free(b);
	if(sol_has_error(state)) {sol_obj_free(res); return sol_incref(state->None);}
	return res;
}

sol_object_t *sol_f_int_sub(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_int(state, sol_list_get_index(state, args, 1));
	sol_object_t *res = sol_new_int(state, a->ival - b->ival);
	sol_obj_free(a);
	sol_obj_free(b);
	if(sol_has_error(state)) {sol_obj_free(res); return sol_incref(state->None);}
	return res;
}

sol_object_t *sol_f_int_mul(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_int(state, sol_list_get_index(state, args, 1));
	sol_object_t *res = sol_new_int(state, a->ival * b->ival);
	sol_obj_free(a);
	sol_obj_free(b);
	if(sol_has_error(state)) {sol_obj_free(res); return sol_incref(state->None);}
	return res;
}

sol_object_t *sol_f_int_div(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_int(state, sol_list_get_index(state, args, 1));
	sol_object_t *res = sol_new_int(state, a->ival / b->ival);
	sol_obj_free(a);
	sol_obj_free(b);
	if(sol_has_error(state)) {sol_obj_free(res); return sol_incref(state->None);}
	return res;
}

sol_object_t *sol_f_int_band(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_int(state, sol_list_get_index(state, args, 1));
	sol_object_t *res = sol_new_int(state, a->ival & b->ival);
	sol_obj_free(a);
	sol_obj_free(b);
	if(sol_has_error(state)) {sol_obj_free(res); return sol_incref(state->None);}
	return res;
}

sol_object_t *sol_f_int_bor(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_int(state, sol_list_get_index(state, args, 1)));
	sol_object_t *res = sol_new_int(state, a->ival | b->ival);
	sol_obj_free(a);
	sol_obj_free(b);
	if(sol_has_error(state)) {sol_obj_free(res); return sol_incref(state->None);}
	return res;
}

sol_object_t *sol_f_int_bxor(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_int(state, sol_list_get_index(state, args, 1));
	sol_object_t *res = sol_new_int(state, a->ival ^ b->ival);
	sol_obj_free(a);
	sol_obj_free(b);
	if(sol_has_error(state)) {sol_obj_free(res); return sol_incref(state->None);}
	return res;
}

sol_object_t *sol_f_int_bnot(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0);
	sol_object_t *res = sol_new_int(state, ~a->ival);
	sol_obj_free(a);
	return res;
}

sol_object_t *sol_f_int_toint(sol_state_t *state, sol_object_t *args) {
	return sol_list_get_index(state, args, 0);
}

sol_object_t *sol_f_int_tofloat(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0);
	sol_object_t *res = sol_new_float(state, (double) a->ival);
	sol_obj_free(a);
	return res;
}

sol_object_t *sol_f_int_tostring(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0);
	char *s = _itoa(a->ival);
	sol_object_t *res = sol_new_string(state, s);
	sol_obj_free(a);
	free(s);
	return res;
}

sol_object_t *sol_f_float_add(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_float(state, sol_list_get_index(state, args, 1));
	sol_object_t *res = sol_new_float(state, a->fval + b->fval);
	sol_obj_free(a);
	sol_obj_free(b);
	if(sol_has_error(state)) {sol_obj_free(res); return sol_incref(state->None);}
	return res;
}

sol_object_t *sol_f_float_sub(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_float(state, sol_list_get_index(state, args, 1));
	sol_object_t *res = sol_new_float(state, a->fval - b->fval);
	sol_obj_free(a);
	sol_obj_free(b);
	if(sol_has_error(state)) {sol_obj_free(res); return sol_incref(state->None);}
	return res;
}

sol_object_t *sol_f_float_mul(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_float(state, sol_list_get_index(state, args, 1)));
	sol_object_t *res = sol_new_float(state, a->fval * b->fval);
	sol_obj_free(a);
	sol_obj_free(b);
	if(sol_has_error(state)) {sol_obj_free(res); return sol_incref(state->None);}
	return res;
}

sol_object_t *sol_f_float_div(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_float(state, sol_list_get_index(state, args, 1));
	sol_object_t *res = sol_new_float(state, a->fval / b->fval);
	sol_obj_free(a);
	sol_obj_free(b);
	if(sol_has_error(state)) {sol_obj_free(res); return sol_incref(state->None);}
	return res;
}

sol_object_t *sol_f_float_toint(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0);
	sol_object_t *res = sol_new_int(state, (int) a->fval);
	sol_obj_free(a);
	return res;
}

sol_object_t *sol_f_float_tofloat(sol_state_t *state, sol_object_t *args) {
	return sol_list_get_index(state, args, 0)
}

sol_object_t *sol_f_float_tostring(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0);
	char *s = _ftoa(a->fval);
	sol_object_t *res = sol_new_string(state, s);
	sol_obj_free(a);
	free(s);
	return res;
}

sol_object_t *sol_f_str_add(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_string(state, sol_list_get_index(state, args, 1)));
	int n = strlen(a->str) + strlen(b->str) + 1;
	char *s = malloc(n);
	sol_object_t *res = sol_new_string(state, strncat(strncpy(s, n, a->str), n, b->str));
	sol_obj_free(a);
	sol_obj_free(b);
	free(s);
	if(sol_has_error(state)) {sol_obj_free(res); return sol_incref(state->None);}
	return res;
}

sol_object_t *sol_f_str_mul(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_int(state, sol_list_get_index(state, args, 1));
	int n = strlen(a->str) * b->ival + 1;
	char *s = malloc(n);
	int i;
	s[0]='\0';
	for(i = 0; i < b->ival; i++) strncat(s, n, a->str);
	sol_object_t *res = sol_new_string(state, s);
	sol_obj_free(a);
	sol_obj_free(b);
	free(s);
	if(sol_has_error(state)) {sol_obj_free(res); return sol_incref(state->None);}
	return res;
}

sol_object_t *sol_f_str_len(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0);
	sol_object_t *ret = sol_new_int(state, strlen(a->str));
	sol_obj_free(a);
	return res;
}

sol_object_t *sol_f_str_toint(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0);
	sol_object_t *ret = sol_new_int(state, atoi(a->str));
	sol_obj_free(a);
	return res;
}

sol_object_t *sol_f_str_tofloat(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0);
	sol_object_t *ret = sol_new_float(state, atof(a->str));
	sol_obj_free(a);
	return res;
}

sol_object_t *sol_f_str_tostring(sol_state_t *state, sol_object_t *args) {
	return sol_list_get_index(state, args, 0)
}

sol_object_t *sol_f_list_add(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_list_get_index(state, args, 1), *ls;
	if(!sol_is_list(b)) {
		sol_obj_free(a);
		sol_obj_free(b);
		return sol_set_error_string(state, "Adding list to non-list");
	}
	ls = sol_list_copy(state, a);
	sol_list_append(state, ls, b);
	sol_obj_free(a);
	sol_obj_free(b);
	return ls;
}

sol_object_t *sol_f_list_mul(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_int(state, sol_list_get_index(state, args, 1)), *ls;
	int i;
	if(sol_has_error(state)) {
		sol_obj_free(a);
		sol_obj_free(b);
		return sol_incref(state->None);
	}
	ls = sol_new_list(state);
	for(i = 0; i < b->ival; i++) {
		sol_list_append(state, ls, a);
		if(sol_has_error(state)) {
			sol_obj_free(a);
			sol_obj_free(b);
			return sol_incref(state->None);
		}
	}
	return ls;
}

sol_object_t *sol_f_list_index(sol_state_t *state, sol_object_t *args) {
	sol_object_t *ls = sol_list_get_index(state, args, 0), *b = sol_cast_int(state, sol_list_get_index(state, args, 1));
	sol_object_t *res = sol_list_get_index(state, ls, b->ival);
	sol_obj_free(ls);
	sol_obj_free(b);
	return res;
}

sol_object_t *sol_f_list_setindex(sol_state_t *state, sol_object_t *args) {
	sol_object_t *ls = sol_list_get_index(state, args, 0), *b = sol_cast_int(state, sol_list_get_index(state, args ,1));
	sol_objcet_t *val = sol_list_get_index(state, args, 2);
	sol_list_set_index(state, ls, b->ival, val);
	sol_obj_free(ls);
	sol_obj_free(b);
	sol_obj_free(val);
	return sol_incref(state->None);
}

sol_object_t *sol_f_list_len(sol_state_t *state, sol_object_t *args) {
	sol_object_t *ls = sol_list_get_index(state, args, 0);
	sol_object_t *res = sol_new_int(state, sol_list_len(state, ls));
	sol_obj_free(ls);
	return res;
}

sol_object_t *sol_f_list_tostring(sol_state_t *state, sol_object_t *args) {
	return sol_new_string(state, "<List>");
}

sol_object_t *sol_f_map_add(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_list_get_index(state, args, 1), *map;
	if(!sol_is_map(b)) {
		sol_obj_free(a);
		sol_obj_free(b);
		return sol_set_error_string(state, "Adding map to non-map");
	}
	map = sol_map_copy(state, a);
	sol_map_merge(state, map, b);
	sol_obj_free(a);
	sol_obj_free(b);
	return map;
}

sol_object_t *sol_f_map_index(sol_state_t *state, sol_object_t *args) {
	sol_object_t *map = sol_list_get_index(state, args, 0), *b = sol_list_get_index(state, args, 1);
	sel_object_t *res = sol_map_get(state, map, b);
	sol_obj_free(map);
	sol_obj_free(b);
	return res;
}

sol_object_t *sol_f_map_setindex(sol_state_t *state, sol_object_t *args) {
	sol_object_t *map = sol_list_get_index(state, args, 0), *b = sol_list_get_index(state, args, 1);
	sol_object_t *val = sol_list_get_index(state, args, 2);
	sol_map_set(state, map, b, val);
	sol_obj_free(map);
	sol_obj_free(b);
	sol_obj_free(val);
	return sol_incref(state->None);
}

sol_object_t *sol_f_map_len(sol_state_t *state, sol_object_t *args) {
	sol_object_t *map = sol_list_get_index(sate, args, 0);
	sol_object_t *res = sol_new_int(state, sol_map_len(state, map));
	sol_obj_free(map);
	return res;
}

sol_object_t *sol_f_map_tostring(sol_state_t *state, sol_object_t *args) {
	return sol_new_string(state, "<Map>");
}

sol_object_t *sol_f_func_tostring(sol_state_t *state, sol_object_t *args) {
	return sol_new_string(state, "<Function>");
}

sol_object_t *sol_f_cfunc_call(sol_state_t *state, sol_object_t *args) {
	sol_object_t *func = sol_list_get_index(state, args, 0), *fargs = sol_list_sublist(state, args, 1);
	sol_object_t *res = func->cfunc(state, fargs);
	sol_obj_free(func);
	sol_obj_free(fargs);
	return res;
}

sol_object_t *sol_f_cfunc_tostring(sol_state_t *state, sol_object_t *args) {
	return sol_new_string(state, "<CFunction>");
}
