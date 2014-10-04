#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "sol.h"

// XXX hardcoded buffer sizes

static char *_itoa(int i) {
	int n = 33;
	char *s = malloc(n);
	snprintf(s, n, "%d", i);
	return s;
}

static char *_ftoa(double f) {
	int n = 65;
	char *s = malloc(n);
	snprintf(s, n, "%f", f);
	return s;
}

sol_object_t *sol_f_not_impl(sol_state_t *state, sol_object_t *args) {
	return sol_set_error_string(state, "Undefined method");
}

sol_object_t *sol_f_default_cmp(sol_state_t *state, sol_object_t *args) {
    sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_list_get_index(state, args, 1);
    sol_object_t *res = sol_new_int(state, a!=b);
    sol_obj_free(a);
    sol_obj_free(b);
    return res;
}

sol_object_t *sol_f_no_op(sol_state_t *state, sol_object_t *args) {
	if(state) return sol_incref(state->None);
	return NULL;
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
	sol_object_t *func = sol_list_get_index(state, args, 0), *fargs = sol_list_sublist(state, args, 1);
	sol_object_t *ls = sol_new_list(state), *one = sol_new_int(state, 1);
	sol_object_t *res = func->ops->call(state, fargs);
	sol_obj_free(func);
	sol_obj_free(fargs);
	if(sol_has_error(state)) {
		sol_object_t *err = sol_get_error(state);
		sol_object_t *zero = sol_new_int(state, 0);
		sol_obj_free(res);
		sol_obj_free(one);
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

static char *sol_TypeNames[] = {"singlet", "integer", "float", "string", "list", "listcell", "map", "mapcell", "function", "cfunction", "cdata"};

sol_object_t *sol_f_type(sol_state_t *state, sol_object_t *args) {
    sol_object_t *obj = sol_list_get_index(state, args, 0);
    sol_object_t *res = sol_new_string(state, sol_TypeNames[obj->type]);
    sol_obj_free(obj);
    return res;
}

sol_object_t *p_seen[1024] = {0};

void ob_print(sol_object_t *obj) {
    sol_object_t *cur;
	int i;
	for(i=0; i<1024; i++) {
		if(!p_seen[i]) {
			p_seen[i] = obj;
			break;
		}
		if(p_seen[i] == obj) {
			printf("... (%p)", obj);
			return;
		}
	}
    switch(obj->type) {
        case SOL_SINGLET:
            printf("<Singlet>");
            break;

        case SOL_INTEGER:
            printf("%ld", obj->ival);
            break;

        case SOL_FLOAT:
            printf("%f", obj->fval);
            break;

        case SOL_STRING:
            printf("\"%s\"", obj->str);
            break;
			
		case SOL_LCELL:
			printf("<<");
			/* fall through */

        case SOL_LIST:
            printf("[");
            cur = obj;
            while(cur) {
                if(cur->lvalue) {
                    ob_print(cur->lvalue);
                }
                if(cur->lnext) {
                    printf(", ");
                }
                cur = cur->lnext;
            }
            printf("]");
            break;
			
		case SOL_MCELL:
			printf("<<");
			/* fall through */

        case SOL_MAP:
            printf("{");
            cur = obj;
            while(cur) {
                if(cur->mkey) {
                    printf("[");
                    ob_print(cur->mkey);
                    printf("] = ");
                    ob_print(cur->mval);
                }
                if(cur->mnext) printf(", ");
                cur = cur->mnext;
            }
            printf("}");
            break;

        case SOL_FUNCTION:
			if(obj->fname) {
				printf("<Function %s>", obj->fname);
			} else {
				printf("<Function>");
			}
            break;

        case SOL_CFUNCTION:
            printf("<CFunction>");
            break;

        case SOL_CDATA:
            printf("<CData>");
            break;
    }
}

sol_object_t *sol_f_prepr(sol_state_t *state, sol_object_t *args) {
	int i, sz = sol_list_len(state, args);
    sol_object_t *obj;
	for(i=0; i<1024; i++) p_seen[i] = NULL;
	for(i=0; i<sz; i++) {
		obj = sol_list_get_index(state, args, i);
		ob_print(obj);
		printf(" ");
		sol_obj_free(obj);
	}
	printf("\n");
    return sol_incref(state->None);
}

sol_object_t *sol_f_print(sol_state_t *state, sol_object_t *args) {
	int i, sz = sol_list_len(state, args);
    sol_object_t *obj;
	for(i=0; i<1024; i++) p_seen[i] = NULL;
	for(i=0; i<sz; i++) {
		obj = sol_list_get_index(state, args, i);
		if(sol_is_string(obj)) {
			printf("%s", obj->str);
		} else {
			ob_print(obj);
		}
		printf(" ");
		sol_obj_free(obj);
	}
	printf("\n");
    return sol_incref(state->None);
}

sol_object_t *sol_f_rawget(sol_state_t *state, sol_object_t *args) {
	sol_object_t *obj = sol_list_get_index(state, args, 0), *key, *res;
	if(!sol_is_map(obj)) return sol_set_error_string(state, "Rawset of non-map");
	key = sol_list_get_index(state, args, 1);
	res = sol_map_get(state, obj, key);
	sol_obj_free(key);
	sol_obj_free(obj);
	return sol_incref(state->None);
}


sol_object_t *sol_f_rawset(sol_state_t *state, sol_object_t *args) {
	sol_object_t *obj = sol_list_get_index(state, args, 0), *key, *val;
	if(!sol_is_map(obj)) return sol_set_error_string(state, "Rawset of non-map");
	key = sol_list_get_index(state, args, 1);
	val = sol_list_get_index(state, args, 2);
	sol_map_set(state, obj, key, val);
	sol_obj_free(val);
	sol_obj_free(key);
	sol_obj_free(obj);
	return sol_incref(state->None);
}

sol_object_t *sol_f_range(sol_state_t *state, sol_object_t *args) {
	sol_object_t *res = sol_new_list(state), *bound = sol_cast_int(state, sol_list_get_index(state, args, 0));
	int i;
	for(i=0; i<bound->ival; i++) {
		sol_list_insert(state, res, sol_list_len(state, res), sol_new_int(state, i));
	}
	sol_obj_free(bound);
	return res;
}

sol_object_t *sol_f_debug_getref(sol_state_t *state, sol_object_t *args) {
	sol_object_t *obj = sol_list_get_index(state, args, 0);
	sol_object_t *res = sol_new_int(state, obj->refcnt - 2); // NB: We grabbed a reference, and there's one in the arglist, so account for them.
	sol_obj_free(obj);
	return res;
}

sol_object_t *sol_f_debug_setref(sol_state_t *state, sol_object_t *args) {
	sol_object_t *obj = sol_list_get_index(state, args, 0), *cnt = sol_list_get_index(state, args, 1);
	obj->refcnt = sol_cast_int(state, cnt)->ival + 2; // NB: As above.
	sol_obj_free(cnt);
	sol_obj_free(obj);
	return sol_incref(state->None);
}

sol_object_t *sol_f_debug_closure(sol_state_t *state, sol_object_t *args) {
	sol_object_t *func = sol_list_get_index(state, args, 0);
	sol_object_t *res = sol_incref(func->closure);
	sol_obj_free(func);
	return res;
}

sol_object_t *sol_f_debug_globals(sol_state_t *state, sol_object_t *args) {
	return sol_list_get_index(state, state->scopes, sol_list_len(state, state->scopes)-1);
}

sol_object_t *sol_f_debug_locals(sol_state_t *state, sol_object_t *args) {
	return sol_list_get_index(state, state->scopes, 0);
}

sol_object_t *sol_f_iter_str(sol_state_t *state, sol_object_t *args) {
	sol_object_t *obj = sol_list_get_index(state, args, 0), *local = sol_list_get_index(state, args, 1);
	sol_object_t *index = sol_map_get_name(state, local, "idx"), *res;
	char temp[2] = {0, 0};
	if(sol_is_none(state, index)) {
		sol_obj_free(index);
		index = sol_new_int(state, 0);
		sol_map_set_name(state, local, "idx", index);
	}
	if(index->ival >= strlen(obj->str)) {
		sol_obj_free(index);
		sol_obj_free(obj);
		sol_obj_free(local);
		return sol_incref(state->StopIteration);
	}
	temp[0] = obj->str[index->ival];
	res = sol_new_string(state, temp);
	index->ival++;
	sol_obj_free(index);
	sol_obj_free(local);
	sol_obj_free(obj);
	return res;
}

sol_object_t *sol_f_iter_list(sol_state_t *state, sol_object_t *args) {
	sol_object_t *obj = sol_list_get_index(state, args, 0), *local = sol_list_get_index(state, args, 1);
	sol_object_t *index = sol_map_get_name(state, local, "idx"), *res;
	if(sol_is_none(state, index)) {
		sol_obj_free(index);
		index = sol_new_int(state, 0);
		sol_map_set_name(state, local, "idx", index);
	}
	if(index->ival >= sol_list_len(state, obj)) {
		sol_obj_free(index);
		sol_obj_free(obj);
		sol_obj_free(local);
		return sol_incref(state->StopIteration);
	}
	res = sol_list_get_index(state, obj, index->ival);
	index->ival++;
	sol_obj_free(index);
	sol_obj_free(local);
	sol_obj_free(obj);
	return res;
}

sol_object_t *sol_f_iter_map(sol_state_t *state, sol_object_t *args) {
	sol_object_t *obj = sol_list_get_index(state, args, 0), *local = sol_list_get_index(state, args, 1);
	sol_object_t *index = sol_map_get_name(state, local, "idx"), *res;
	if(sol_is_none(state, index)) {
		sol_obj_free(index);
		index = obj;
		sol_map_set_name(state, local, "idx", index);
	}
	while(index && !index->mkey) index = index->mnext;
	if(!index || !index->mnext) {
		sol_obj_free(index);
		sol_obj_free(obj);
		sol_obj_free(local);
		return sol_incref(state->StopIteration);
	}
	res = sol_incref(index->mkey);
	index = index->mnext;
	sol_map_set_name(state, local, "idx", index);
	sol_obj_free(index);
	sol_obj_free(local);
	sol_obj_free(obj);
	return res;
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

sol_object_t *sol_f_int_pow(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_int(state, sol_list_get_index(state, args, 1));
	sol_object_t *res = sol_new_int(state, (long) pow((double) a->ival, b->ival));
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
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_int(state, sol_list_get_index(state, args, 1));
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

sol_object_t *sol_f_int_blsh(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_int(state, sol_list_get_index(state, args, 1));
	sol_object_t *res = sol_new_int(state, a->ival << b->ival);
	sol_obj_free(a);
	sol_obj_free(b);
	if(sol_has_error(state)) {sol_obj_free(res); return sol_incref(state->None);}
	return res;
}

sol_object_t *sol_f_int_brsh(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_int(state, sol_list_get_index(state, args, 1));
	sol_object_t *res = sol_new_int(state, a->ival >> b->ival);
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

sol_object_t *sol_f_int_cmp(sol_state_t *state, sol_object_t *args) {
    sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_int(state, sol_list_get_index(state, args, 1));
    sol_object_t *res = sol_new_int(state, a->ival==b->ival? 0 : (a->ival<b->ival? -1 : 1));
    sol_obj_free(a);
    sol_obj_free(b);
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
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_float(state, sol_list_get_index(state, args, 1));
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

sol_object_t *sol_f_float_pow(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_float(state, sol_list_get_index(state, args, 1));
	sol_object_t *res = sol_new_float(state, pow(a->fval, b->fval));
	sol_obj_free(a);
	sol_obj_free(b);
	if(sol_has_error(state)) {sol_obj_free(res); return sol_incref(state->None);}
	return res;
}

sol_object_t *sol_f_float_cmp(sol_state_t *state, sol_object_t *args) {
    sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_float(state, sol_list_get_index(state, args, 1));
    sol_object_t *res = sol_new_int(state, a->fval==b->fval? 0 : (a->fval<b->fval? -1 : 1));
    sol_obj_free(a);
    sol_obj_free(b);
    return res;
}

sol_object_t *sol_f_float_toint(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0);
	sol_object_t *res = sol_new_int(state, (int) a->fval);
	sol_obj_free(a);
	return res;
}

sol_object_t *sol_f_float_tofloat(sol_state_t *state, sol_object_t *args) {
	return sol_list_get_index(state, args, 0);
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
	sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_string(state, sol_list_get_index(state, args, 1));
	int n = strlen(a->str) + strlen(b->str) + 1;
	char *s = malloc(n);
	sol_object_t *res = sol_new_string(state, strncat(strncpy(s, a->str, n), b->str, n));
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
	for(i = 0; i < b->ival; i++) strncat(s, a->str, n);
	sol_object_t *res = sol_new_string(state, s);
	sol_obj_free(a);
	sol_obj_free(b);
	free(s);
	if(sol_has_error(state)) {sol_obj_free(res); return sol_incref(state->None);}
	return res;
}

sol_object_t *sol_f_str_cmp(sol_state_t *state, sol_object_t *args) {
    sol_object_t *a = sol_list_get_index(state, args, 0), *b = sol_cast_string(state, sol_list_get_index(state, args, 1));
    sol_object_t *res = sol_new_int(state, strcmp(a->str, b->str));
    sol_obj_free(a);
    sol_obj_free(b);
    return res;
}

sol_object_t *sol_f_str_len(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0);
	sol_object_t *res = sol_new_int(state, strlen(a->str));
	sol_obj_free(a);
	return res;
}

sol_object_t *sol_f_str_iter(sol_state_t *state, sol_object_t *args) {
	return sol_new_cfunc(state, sol_f_iter_str);
}

sol_object_t *sol_f_str_toint(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0);
	sol_object_t *res = sol_new_int(state, atoi(a->str));
	sol_obj_free(a);
	return res;
}

sol_object_t *sol_f_str_tofloat(sol_state_t *state, sol_object_t *args) {
	sol_object_t *a = sol_list_get_index(state, args, 0);
	sol_object_t *res = sol_new_float(state, atof(a->str));
	sol_obj_free(a);
	return res;
}

sol_object_t *sol_f_str_tostring(sol_state_t *state, sol_object_t *args) {
	return sol_list_get_index(state, args, 0);
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
	sol_object_t *val = sol_list_get_index(state, args, 2);
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

sol_object_t *sol_f_list_iter(sol_state_t *state, sol_object_t *args) {
	return sol_new_cfunc(state, sol_f_iter_list);
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
	sol_object_t *indexf = sol_map_get_name(state, map, "__index");
	sol_object_t *res = NULL, *newls;
	if(!sol_is_none(state, indexf)) {
		if(indexf->ops->call && indexf->ops->call != sol_f_not_impl) {
			newls = sol_new_list(state);
			sol_list_insert(state, newls, 0, indexf);
			sol_list_append(state, newls, args);
			res = indexf->ops->call(state, newls);
			sol_obj_free(newls);
		} else if(indexf->ops->index && indexf->ops->index != sol_f_not_impl) {
			res = indexf->ops->index(state, args);
		}
	}
	if(!res) res = sol_map_get(state, map, b);
	sol_obj_free(indexf);
	sol_obj_free(map);
	sol_obj_free(b);
	return res;
}

sol_object_t *sol_f_map_setindex(sol_state_t *state, sol_object_t *args) {
	sol_object_t *map = sol_list_get_index(state, args, 0), *b = sol_list_get_index(state, args, 1);
	sol_object_t *val = sol_list_get_index(state, args, 2);
	sol_object_t *setindexf = sol_map_get_name(state, map, "__setindex"), *newls;
	if(!sol_is_none(state, setindexf)) {
		if(setindexf->ops->call && setindexf->ops->call != sol_f_not_impl) {
			newls = sol_new_list(state);
			sol_list_insert(state, newls, 0, setindexf);
			sol_list_append(state, newls, args);
			sol_obj_free(setindexf->ops->call(state, newls));
			sol_obj_free(newls);
			return sol_incref(state->None);
		} else if(setindexf->ops->setindex && setindexf->ops->setindex != sol_f_not_impl) {
			setindexf->ops->setindex(state, args);
			return sol_incref(state->None);
		}
	}
	sol_obj_free(setindexf);
	sol_map_set(state, map, b, val);
	sol_obj_free(map);
	sol_obj_free(b);
	sol_obj_free(val);
	return sol_incref(state->None);
}

sol_object_t *sol_f_map_call(sol_state_t *state, sol_object_t *args) {
	sol_object_t *map = sol_list_get_index(state, args, 0), *fargs = sol_list_sublist(state, args, 1);
	sol_object_t *callf = sol_map_get_name(state, map, "__call"), *res = NULL;
	if(!sol_is_none(state, callf)) {
		if(callf->ops->call) {
			sol_list_insert(state, fargs, 0, callf);
			sol_list_insert(state, fargs, 1, map);
			res = callf->ops->call(state, fargs);
		}
	}
	sol_obj_free(map);
	sol_obj_free(fargs);
	sol_obj_free(callf);
	if(res) return res;
	return sol_set_error_string(state, "Call map without call method");
}

sol_object_t *sol_f_map_len(sol_state_t *state, sol_object_t *args) {
	sol_object_t *map = sol_list_get_index(state, args, 0);
	sol_object_t *res = sol_new_int(state, sol_map_len(state, map));
	sol_obj_free(map);
	return res;
}

sol_object_t *sol_f_map_iter(sol_state_t *state, sol_object_t *args) {
	return sol_new_cfunc(state, sol_f_iter_map);
}

sol_object_t *sol_f_map_tostring(sol_state_t *state, sol_object_t *args) {
	return sol_new_string(state, "<Map>");
}

sol_object_t *sol_f_func_index(sol_state_t *state, sol_object_t *args) {
	sol_object_t *func = sol_list_get_index(state, args, 0), *key = sol_list_get_index(state, args, 1), *res;
	res = sol_map_get(state, func->closure, key);
	sol_obj_free(func);
	sol_obj_free(key);
	return res;
}

sol_object_t *sol_f_func_setindex(sol_state_t *state, sol_object_t *args) {
	sol_object_t *func = sol_list_get_index(state, args, 0), *key = sol_list_get_index(state, args, 1), *val = sol_list_get_index(state, args, 2);
	sol_map_set(state, func->closure, key, val);
	sol_obj_free(func);
	sol_obj_free(key);
	sol_obj_free(val);
	return sol_incref(state->None);
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
