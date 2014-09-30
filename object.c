#include "sol.h"

#include <stdlib.h>
#include <string.h>

sol_object_t *sol_cast_int(sol_state_t *state, sol_object_t *obj) {
	sol_object_t *res, *ls;
	if(sol_is_int(obj)) return obj;
	ls = sol_new_list(state);
	sol_list_insert(state, ls, 0, obj);
	res = obj->ops->toint(state, ls);
	sol_obj_free(ls);
	sol_obj_free(obj);
	return res;
}

sol_object_t *sol_cast_float(sol_state_t *state, sol_object_t *obj) {
	sol_object_t *res, *ls;
	if(sol_is_float(obj)) return obj;
	ls = sol_new_list(state);
	sol_list_insert(state, ls, 0, obj);
	res = obj->ops->tofloat(state, ls);
	sol_obj_free(ls);
	sol_obj_free(obj);
	return res;
}

sol_object_t *sol_cast_string(sol_state_t *state, sol_object_t *obj) {
	sol_object_t *res, *ls;
	if(sol_is_string(obj)) return obj;
	ls = sol_new_list(state);
	sol_list_insert(state, ls, 0, obj);
	res = obj->ops->tostring(state, ls);
	sol_obj_free(ls);
	sol_obj_free(obj);
	return res;
}

// This will not fail here; error checking is done in sol_state_init().

sol_object_t *sol_new_singlet(sol_state_t *state) {
	sol_object_t *res = malloc(sizeof(sol_object_t));
	if(res) {
		res->type = SOL_SINGLET;
		res->refcnt = 0;
		res->ops = &(state->NullOps);
	}
	return sol_incref(res);
}

// And, now, for the rest of the checked stuff...

sol_object_t *sol_alloc_object(sol_state_t *state) {
	sol_object_t *res = malloc(sizeof(sol_object_t));
	if(!res) {
		sol_set_error(state, state->OutOfMemory);
		return sol_incref(state->None);
	}
	res->refcnt = 0;
	res->ops = &(state->NullOps);
	return sol_incref(res);
}

void sol_init_object(sol_state_t *state, sol_object_t *obj) {
	obj->ops->init(state, obj);
}

void sol_obj_free(sol_object_t *obj) {
	if(sol_decref(obj) <= 0) {
		obj->ops->free(NULL, obj);
		free(obj);
	}
}

sol_object_t *sol_new_int(sol_state_t *state, int i) {
	sol_object_t *res = sol_alloc_object(state);
	if(sol_has_error(state)) {
		sol_obj_free(res);
		return sol_incref(state->None);
	}
	res->type = SOL_INTEGER;
	res->ival = i;
	res->ops = &(state->IntOps);
	sol_init_object(state, res);
	return res;
}

sol_object_t *sol_new_float(sol_state_t *state, double f) {
	sol_object_t *res = sol_alloc_object(state);
	if(sol_has_error(state)) {
		sol_obj_free(res);
		return sol_incref(state->None);
	}
	res->type = SOL_FLOAT;
	res->fval = f;
	res->ops = &(state->FloatOps);
	sol_init_object(state, res);
	return res;
}

sol_object_t *sol_new_string(sol_state_t *state, const char *s) {
	sol_object_t *res = sol_alloc_object(state);
	if(sol_has_error(state)) {
		sol_obj_free(res);
		return sol_incref(state->None);
	}
	res->type = SOL_STRING;
	res->str = strdup(s);
	if(!res->str) {
		sol_obj_free(res);
		sol_set_error(state, state->OutOfMemory);
		return sol_incref(state->None);
	}
	res->ops = &(state->StringOps);
	sol_init_object(state, res);
	return res;
}

sol_object_t *sol_f_str_free(sol_state_t *state, sol_object_t *obj) {
	free(obj->str);
	return obj;
}

sol_object_t *sol_new_list(sol_state_t *state) {
	sol_object_t *res = sol_alloc_object(state);
	if(sol_has_error(state)) {
		sol_obj_free(res);
		return sol_incref(state->None);
	}
	res->type = SOL_LIST;
	res->lvalue = NULL;
	res->lnext = NULL;
	res->ops = &(state->ListOps);
	sol_init_object(state, res);
	return res;
}

int sol_list_len(sol_state_t *state, sol_object_t *list) {
	int i = 0;
	sol_object_t *cur = list;
	if(!sol_is_list(list)) {
		return sol_set_error_string(state, "Compute length of non-list");
	}
	while(cur && cur->lvalue) {
		i++;
		cur = cur->lnext;
	}
	return i;
}

sol_object_t *sol_list_sublist(sol_state_t *state, sol_object_t *list, int idx) {
	int i = 0;
	sol_object_t *cur = list;
	sol_object_t *copy;
	if(idx < 0) {
		return sol_set_error_string(state, "Create sublist at negative index");
	}
	while(cur && cur->lvalue && i < idx) {
		i++;
		cur = cur->lnext;
	}
	copy = sol_new_list(state);
	while(cur && cur->lvalue) {
		copy->lvalue = sol_incref(cur->lvalue);
		if(cur->lnext) {
			copy->lnext = sol_alloc_object(state);
			copy = copy->lnext;
			copy->type = SOL_LIST;
			copy->ops = &(state->ListOps);
		}
		cur = cur->lnext;
	}
	return copy;
}

sol_object_t *sol_list_get_index(sol_state_t *state, sol_object_t *list, int idx) {
	sol_object_t *cur = list;
	int i = 0;
	if(idx < 0) {
		return sol_set_error_string(state, "Get negative index");
	}
	while(cur && cur->lvalue && i < idx) {
		i++;
		cur = cur->lnext;
	}
	if(cur) {
		return sol_incref(cur->lvalue);
	} else {
		return sol_set_error_string(state, "Get out-of-bounds index");
	}
}

void sol_list_set_index(sol_state_t *state, sol_object_t *list, int idx, sol_object_t *obj) {
	sol_object_t *cur = list;
	int i = 0;
	if(idx < 0) {
		sol_obj_free(sol_set_error_string(state, "Set negative index"));
		return;
	}
	while(cur && cur->lvalue && i < idx) {
		i++;
		cur = cur->lnext;
	}
	if(cur) {
		sol_obj_free(cur->lvalue);
		cur->lvalue = sol_incref(obj);
	} else {
		sol_obj_free(sol_set_error_string(state, "Set out-of-bounds index"));
		return;
	}
}

void sol_list_insert(sol_state_t *state, sol_object_t **list, int idx, sol_object_t *obj) {
	sol_object_t *next = *list, *prev = NULL, *temp = sol_alloc_object(state);
	int i = 0;
	if(sol_has_error(state)) return;
	if(idx < 0) {
		sol_obj_free(sol_set_error_string(state, "Insert at negative index"));
		return;
	}
	temp->type = SOL_LIST;
	temp->ops = &(state->ListOps);
	temp->lvalue = sol_incref(obj);
	while(next && next->lvalue && i < idx) {
		i++;
		prev = next;
		next = next->lnext;
	}
	if(next) {
		temp->lnext = next;
		if(prev) {
			prev->lnext = temp;
		} else {
			sol_obj_free(*list);
			*list = temp;
		}
	} else {
		sol_obj_free(temp->lvalue);
		sol_obj_free(temp);
		sol_obj_free(sol_set_error_string(state, "Out-of-bounds insert"));
		return;
	}
}

sol_object_t *sol_list_remove(sol_state_t *state, sol_object_t **list, int idx) {
	sol_object_t *next = *list, *prev = NULL, *res, *temp;
	int i = 0;
	if(sol_has_error(state)) return;
	if(idx < 0) {
		return sol_set_error_string(state, "Remove from negative index");
	}
	while(next && next->lvalue && i < idx) {
		i++;
		prev = next;
		next = next->lnext;
	}
	if(next) {
		if(prev) {
			res = (*list)->lvalue;
			temp = *list;
			*list = (*list)->lnext;
			sol_obj_free(temp);
		} else {
			res = next->lvalue;
			prev->lnext = next->lnext;
			sol_obj_free(next);
		}
		return res;
	} else {
		return sol_set_error_string(state, "Out-of-bounds remove");
	}
}

sol_object_t *sol_list_copy(sol_state_t *state, sol_object_t *list) {
	sol_object_t *newls = sol_new_list(state), *cur = list;
	sol_object_t *res = newls;
	while(cur->lvalue) {
		newls->lvalue = sol_incref(cur->lvalue);
		if(cur->lnext) {
			newls->lnext = sol_alloc_object(state);
			if(sol_has_error(state)) return sol_incref(state->None);
			newls = newls->lnext;
			newls->type = SOL_LIST;
			newls->ops = &(state->ListOps);
		}
		cur = cur->lnext;
	}
	return res;
}