#include "sol.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

sol_object_t *sol_cast_int(sol_state_t *state, sol_object_t *obj) {
	sol_object_t *res, *ls;
	if(sol_is_int(obj)) return sol_incref(obj);
	ls = sol_new_list(state);
	sol_list_insert(state, ls, 0, obj);
	res = obj->ops->toint(state, ls);
	sol_obj_free(ls);
	sol_obj_free(obj);
	return res;
}

sol_object_t *sol_cast_float(sol_state_t *state, sol_object_t *obj) {
	sol_object_t *res, *ls;
	if(sol_is_float(obj)) return sol_incref(obj);
	ls = sol_new_list(state);
	sol_list_insert(state, ls, 0, obj);
	res = obj->ops->tofloat(state, ls);
	sol_obj_free(ls);
	sol_obj_free(obj);
	return res;
}

sol_object_t *sol_cast_string(sol_state_t *state, sol_object_t *obj) {
	sol_object_t *res, *ls;
	if(sol_is_string(obj)) return sol_incref(obj);
	ls = sol_new_list(state);
	sol_list_insert(state, ls, 0, obj);
	res = obj->ops->tostring(state, ls);
	sol_obj_free(ls);
	sol_obj_free(obj);
	return res;
}

// This will not fail here; error checking is done in sol_state_init().

sol_object_t *sol_new_singlet(sol_state_t *state, const char *name) {
	sol_object_t *res = malloc(sizeof(sol_object_t));
	if(res) {
		res->type = SOL_SINGLET;
		res->refcnt = 0;
		res->ops = &(state->NullOps);
		res->str = strdup(name);
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
	if(obj->ops->init) obj->ops->init(state, obj);
}

sol_object_t *sol_obj_acquire(sol_object_t *obj) {
	return sol_incref(obj);
}

void sol_obj_free(sol_object_t *obj) {
	if(!obj) {
		printf("WARNING: Attempt to free NULL\n");
		return;
	}
	if(sol_decref(obj) <= 0) {
		if(obj->refcnt < 0) {
			printf("WARNING: Encountered refcnt < 0!\nObject %p type %d ref %d\n", obj, obj->type, obj->refcnt);
		} else {
			sol_obj_release(obj);
		}
	}
}

void sol_obj_release(sol_object_t *obj) {
    if(obj->ops->free) obj->ops->free(NULL, obj);
    free(obj);
}

sol_object_t *sol_new_int(sol_state_t *state, long i) {
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

int sol_string_cmp(sol_state_t *state, sol_object_t *str, const char *s) {
	return strcmp(str->str, s);
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
	res->seq = dsl_seq_new_array(NULL, &(state->obfuncs));
	res->ops = &(state->ListOps);
	sol_init_object(state, res);
	return res;
}

sol_object_t *sol_list_from_seq(sol_state_t *state, dsl_seq *seq) {
	sol_object_t *res = sol_alloc_object(state);
	if(sol_has_error(state)) {
		sol_obj_free(res);
		return sol_incref(state->None);
	}
	res->type = SOL_LIST;
	res->seq = seq;
	res->ops = &(state->ListOps);
	sol_init_object(state, res);
	return res;
}

int sol_list_len(sol_state_t *state, sol_object_t *list) {
	return dsl_seq_len(list->seq);
}

sol_object_t *sol_list_sublist(sol_state_t *state, sol_object_t *list, int idx) {
	int i = 0;
	dsl_seq *subl;
	if(idx < 0) {
		return sol_set_error_string(state, "Create sublist at negative index");
	}
	subl = dsl_seq_copy(list->seq);
	for(i=0; i<idx; i++) {
		dsl_seq_delete(subl, 0);
	}
	return sol_list_from_seq(state, subl);
}

sol_object_t *sol_list_get_index(sol_state_t *state, sol_object_t *list, int idx) {
	if(idx<0 || idx>=dsl_seq_len(list->seq)) return sol_incref(state->None);
	return sol_incref(AS_OBJ(dsl_seq_get(list->seq, idx)));
}

void sol_list_set_index(sol_state_t *state, sol_object_t *list, int idx, sol_object_t *obj) {
	if(idx<0 || idx>=dsl_seq_len(list->seq)) return;
	dsl_seq_set(list->seq, idx, obj);
}

void sol_list_insert(sol_state_t *state, sol_object_t *list, int idx, sol_object_t *obj) {
	if(idx<0 || idx>dsl_seq_len(list->seq)) return;
	dsl_seq_insert(list->seq, idx, obj);
}

sol_object_t *sol_list_remove(sol_state_t *state, sol_object_t *list, int idx) {
	if(idx<0 || idx>=dsl_seq_len(list->seq)) return sol_incref(state->None);
	return dsl_seq_remove(list->seq, idx);
}

sol_object_t *sol_list_copy(sol_state_t *state, sol_object_t *list) {
	return sol_list_from_seq(state, dsl_seq_copy(list->seq));
}

sol_object_t *sol_list_truncate(sol_state_t *state, sol_object_t *list, int len) {
	dsl_seq *newseq = dsl_seq_copy(list->seq);
	dsl_seq_iter *iter = dsl_new_seq_iter(newseq);
	int pos = dsl_seq_iter_seek(iter, len);
	int sz = dsl_seq_len(newseq);
	int i;
	if(pos>=len) {
		for(i=0; i<sz-pos; i++) {
			dsl_seq_iter_delete_at(iter);
		}
	}
	dsl_free_seq_iter(iter);
	return sol_list_from_seq(state, newseq);
}

void sol_list_append(sol_state_t *state, sol_object_t *dest, sol_object_t *src) {
    dsl_seq *oldseq = dest->seq;
	dest->seq = dsl_seq_append(dest->seq, src->seq);
	dsl_free_seq(oldseq);
}

sol_object_t *sol_f_list_free(sol_state_t *state, sol_object_t *list) {
    dsl_free_seq(list->seq);
	return list;
}

/*int sol_test_cycle(sol_state_t *state, sol_object_t *seq) {
	sol_object_t *seen[1024]={};
	sol_object_t *cur = seq, **item;
	while(cur) {
		item = seen;
		while(*item) {
			if(*item == cur) return 1;
			item++;
		}
		*item = cur;
		if(sol_is_list(seq)) {
			cur = cur->lnext;
		} else {
			cur = cur->mnext;
		}
	}
	return 0;
}

int sol_validate_list(sol_state_t *state, sol_object_t *list) {
	sol_object_t *cur = list;
	int i = 0;
	char msg[128];
	while(cur) {
		if(!sol_is_list(cur)) {
			snprintf(msg, 128, "Node at index %d not a list node", i);
			sol_obj_free(sol_set_error_string(state, msg));
			return 1;
		}
		/*if(cur->lnext && !cur->lvalue) {
			snprintf(msg, 128, "Node at index %d has a next node but NULL value", i);
			sol_obj_free(sol_set_error_string(state, msg));
			return 1;
		}*//*
		cur = cur->lnext;
		i++;
	}
	if(sol_test_cycle(state, list)) {
		snprintf(msg, 128, "Cycle detected");
		sol_obj_free(sol_set_error_string(state, msg));
		return 1;
	}
	return 0;
}*/

sol_object_t *sol_new_map(sol_state_t *state) {
    sol_object_t *map = sol_alloc_object(state);
    if(sol_has_error(state)) return sol_incref(state->None);
    map->type = SOL_MAP;
    map->ops = &(state->MapOps);
    map->seq = dsl_seq_new_array(NULL, &(state->obfuncs));
    return map;
}

sol_object_t *sol_map_from_seq(sol_state_t *state, dsl_seq *seq) {
    sol_object_t *map = sol_alloc_object(state);
    if(sol_has_error(state)) return sol_incref(state->None);
    map->type = SOL_MAP;
    map->ops = &(state->MapOps);
    map->seq = seq;
    return map;
}

int sol_map_len(sol_state_t *state, sol_object_t *map) {
    return dsl_seq_len(map->seq);
}

sol_object_t *sol_map_mcell(sol_state_t *state, sol_object_t *map, sol_object_t *key) {
    sol_object_t *list = sol_new_list(state), *cmp, *icmp, *res = NULL;
	dsl_seq_iter *iter = dsl_new_seq_iter(map->seq);
	if(sol_has_error(state)) {
		dsl_free_seq_iter(iter);
		sol_obj_free(list);
		return sol_incref(state->None);
	}
    sol_list_insert(state, list, 0, key);
	sol_list_insert(state, list, 1, state->None);
    if(!dsl_seq_iter_is_invalid(iter)) do {
		sol_list_set_index(state, list, 1, AS_OBJ(dsl_seq_iter_at(iter))->key);
		cmp = key->ops->cmp(state, list);
		icmp = sol_cast_int(state, cmp);
		sol_obj_free(cmp);
		if(icmp->ival == 0) {
			res = AS_OBJ(dsl_seq_iter_at(iter));
		}
		sol_obj_free(icmp);
	} while(dsl_seq_iter_next(iter));
	dsl_free_seq_iter(iter);
	sol_obj_free(list);
	if(res) {
		return res;
	}
    return sol_incref(state->None);
}

int sol_map_has(sol_state_t *state, sol_object_t *map, sol_object_t *key) {
	sol_object_t *mcell = sol_map_mcell(state, map, key);
	int res = sol_is_none(state, mcell);
	sol_obj_free(mcell);
	return res;
}

sol_object_t *sol_map_get(sol_state_t *state, sol_object_t *map, sol_object_t *key) {
    sol_object_t *mcell = sol_map_mcell(state, map, key);
    if(sol_is_none(state, mcell)) {
		return mcell;
	}
	return sol_incref(mcell->val);
}

sol_object_t *sol_map_get_name(sol_state_t *state, sol_object_t *map, char *name) {
	sol_object_t *key = sol_new_string(state, name);
	sol_object_t *res = sol_map_get(state, map, key);
	sol_obj_free(key);
	return res;
}

void sol_map_set(sol_state_t *state, sol_object_t *map, sol_object_t *key, sol_object_t *val) {
    sol_object_t *mcell =sol_map_mcell(state, map, key), *newcell, *temp;
	if(sol_is_none(state, mcell)) {
		newcell = sol_alloc_object(state);
		newcell->type = SOL_MCELL;
		newcell->ops = &(state->MCellOps);
		newcell->key = sol_incref(key);
		newcell->val = sol_incref(val);
		dsl_seq_insert(map->seq, 0, newcell);
		sol_obj_free(newcell);
	} else {
		temp = mcell->val;
		mcell->val = sol_incref(val);
		sol_obj_free(temp);
	}
}

void sol_map_set_name(sol_state_t *state, sol_object_t *map, char *name, sol_object_t *val) {
	sol_object_t *key = sol_new_string(state, name);
	sol_map_set(state, map, key, val);
	sol_obj_free(key);
}

void sol_map_set_existing(sol_state_t *state, sol_object_t *map, sol_object_t *key, sol_object_t *val) {
    sol_object_t *mcell =sol_map_mcell(state, map, key), *temp;
	if(!sol_is_none(state, mcell)) {
		temp = mcell->val;
		mcell->val = sol_incref(val);
		sol_obj_free(temp);
	}
}

sol_object_t *sol_map_copy(sol_state_t *state, sol_object_t *map) {
    return sol_map_from_seq(state, dsl_seq_copy(map->seq));
}

void sol_map_merge(sol_state_t *state, sol_object_t *dest, sol_object_t *src) {
    dsl_seq_iter *iter = dsl_new_seq_iter(src->seq);
	if(!dsl_seq_iter_is_invalid(iter)) do {
		sol_map_set(state, dest, AS_OBJ(dsl_seq_iter_at(iter))->key, AS_OBJ(dsl_seq_iter_at(iter))->val);
	} while(dsl_seq_iter_next(iter));
	dsl_free_seq_iter(iter);
}

void sol_map_merge_existing(sol_state_t *state, sol_object_t *dest, sol_object_t *src) {
    dsl_seq_iter *iter = dsl_new_seq_iter(src->seq);
	if(!dsl_seq_iter_is_invalid(iter)) do {
		sol_map_set_existing(state, dest, AS_OBJ(dsl_seq_iter_at(iter))->key, AS_OBJ(dsl_seq_iter_at(iter))->val);
	} while(dsl_seq_iter_next(iter));
	dsl_free_seq_iter(iter);
}

sol_object_t *sol_f_map_free(sol_state_t *state, sol_object_t *map) {
    dsl_free_seq(map->seq);
    return map;
}

sol_object_t *sol_f_mcell_free(sol_state_t *state, sol_object_t *mcell) {
	if(mcell->key) sol_obj_free(mcell->key);
	if(mcell->val) sol_obj_free(mcell->val);
	return mcell;
}

/*int sol_validate_map(sol_state_t *state, sol_object_t *map) {
	sol_object_t *cur = map;
	int i = 0;
	char msg[128];
	while(cur) {
		if(!sol_is_map(cur)) {
			snprintf(msg, 128, "Node at index %d not a map node", i);
			sol_obj_free(sol_set_error_string(state, msg));
			return 1;
		}
		if(cur->mnext && (!cur->mkey || !cur->mval)) {
			snprintf(msg, 128, "Node at index %d has a next node but NULL key or value", i);
			sol_obj_free(sol_set_error_string(state, msg));
			return 1;
		}
		cur = cur->mnext;
		i++;
	}
	return 0;
}*/

sol_object_t *sol_new_cfunc(sol_state_t *state, sol_cfunc_t cfunc) {
    sol_object_t *res = sol_alloc_object(state);
    res->type = SOL_CFUNCTION;
    res->ops = &(state->CFuncOps);
    res->cfunc = cfunc;
    return res;
}

sol_object_t *sol_new_cdata(sol_state_t *state, void *cdata, sol_ops_t *ops) {
    sol_object_t *res = sol_alloc_object(state);
    res->type = SOL_CDATA;
    res->ops = ops;
    res->cdata = cdata;
    return res;
}

sol_object_t *sol_new_buffer(sol_state_t *state, void *buffer, ssize_t sz, sol_owntype_t own, sol_freefunc_t freef, sol_movefunc_t movef) {
	sol_object_t *res = sol_alloc_object(state);
	res->type = SOL_BUFFER;
	res->ops = &(state->BufferOps);
	res->buffer = buffer;
	res->sz = sz;
	res->own = own;
	res->freef = freef;
	res->movef = movef;
	return res;
}

sol_object_t *sol_f_buffer_free(sol_state_t *state, sol_object_t *buf) {
	switch(buf->own) {
		case OWN_FREE:
			free(buf->buffer);
			break;
			
		case OWN_CALLF:
			buf->freef(buf->buffer, buf->sz);
			break;
	}
	return buf;
}
