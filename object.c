#include "ast.h"  // For CALL_METHOD

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <dlfcn.h>
#include <stdarg.h>

sol_object_t *sol_cast_int(sol_state_t *state, sol_object_t *obj) {
	sol_object_t *res, *ls;
	if(sol_is_int(obj)) {
		return sol_incref(obj);
	}
	ls = sol_new_list(state);
	sol_list_insert(state, ls, 0, obj);
	res = CALL_METHOD(state, obj, toint, ls);
	sol_obj_free(ls);
	return res;
}

sol_object_t *sol_cast_float(sol_state_t *state, sol_object_t *obj) {
	sol_object_t *res, *ls;
	if(sol_is_float(obj)) {
		return sol_incref(obj);
	}
	ls = sol_new_list(state);
	sol_list_insert(state, ls, 0, obj);
	res = CALL_METHOD(state, obj, tofloat, ls);
	sol_obj_free(ls);
	return res;
}

sol_object_t *sol_cast_buffer(sol_state_t *state, sol_object_t *obj) {
	sol_object_t *res, *ls;
	if(sol_is_buffer(obj)) {
		return sol_incref(obj);
	}
	ls = sol_new_list(state);
	sol_list_insert(state, ls, 0, obj);
	res = CALL_METHOD(state, obj, tobuffer, ls);
	sol_obj_free(ls);
	return res;
}

sol_object_t *sol_cast_string(sol_state_t *state, sol_object_t *obj) {
	sol_object_t *res, *ls;
	if(sol_is_string(obj)) {
		return sol_incref(obj);
	}
	ls = sol_new_list(state);
	sol_list_insert(state, ls, 0, obj);
	res = CALL_METHOD(state, obj, tostring, ls);
	sol_obj_free(ls);
	return res;
}

sol_object_t *sol_cast_repr(sol_state_t *state, sol_object_t *obj) {
	sol_object_t *res, *ls = sol_new_list(state);
	sol_list_insert(state, ls, 0, obj);
	res = CALL_METHOD(state, obj, repr, ls);
	sol_obj_free(ls);
	return res;
}

// This will not fail here; error checking is done in sol_state_init().

sol_object_t *sol_new_singlet(sol_state_t *state, const char *name) {
	sol_object_t *res = malloc(sizeof(sol_object_t));
	if(res) {
		res->type = SOL_SINGLET;
		res->refcnt = 0;
		res->ops = &(state->SingletOps);
		res->str = strdup(name);
	}
	return sol_incref(res); // XXX Segfault
}

sol_object_t *sol_f_singlet_free(sol_state_t *state, sol_object_t *singlet) {
	free(singlet->str);
}

// And, now, for the rest of the checked stuff...

void sol_init_object(sol_state_t *state, sol_object_t *obj) {
	if(obj->ops->init) {
		obj->ops->init(state, obj);
	}
}

sol_object_t *sol_new_int(sol_state_t *state, long i) {
	sol_object_t *res;
#ifdef SOL_ICACHE
	if(!state->icache_bypass && i >= SOL_ICACHE_MIN && i <= SOL_ICACHE_MAX) {
		res = sol_incref(state->icache[i - SOL_ICACHE_MIN]);
		if(res->ival != i) {
			printf("WARNING: Integer at %ld mutated to %ld! Resetting...\n", i, res->ival);
			res->ival = i;
		}
		return res;
	}
#endif
	res = sol_alloc_object(state);
	res->type = SOL_INTEGER;
	res->ival = i;
	res->ops = &(state->IntOps);
	sol_init_object(state, res);
	return res;
}

sol_object_t *sol_new_float(sol_state_t *state, double f) {
	sol_object_t *res = sol_alloc_object(state);
	res->type = SOL_FLOAT;
	res->fval = f;
	res->ops = &(state->FloatOps);
	sol_init_object(state, res);
	return res;
}

sol_object_t *sol_new_string(sol_state_t *state, const char *s) {
	sol_object_t *res = sol_alloc_object(state);
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

sol_object_t *sol_string_concat(sol_state_t *state, sol_object_t *a, sol_object_t *b) {
	sol_object_t *res, *sa = sol_cast_string(state, a), *sb = sol_cast_string(state, b);
	int n = strlen(sa->str) + strlen(sb->str) + 1;
	char *s = malloc(n);
	res = sol_new_string(state, strncat(strncpy(s, a->str, n), b->str, n));
	sol_obj_free(sa);
	sol_obj_free(sb);
	free(s);
	return res;
}

sol_object_t *sol_string_concat_cstr(sol_state_t *state, sol_object_t *a, char *s) {
	sol_object_t *b = sol_new_string(state, s);
	sol_object_t *res = sol_string_concat(state, a, b);
	sol_obj_free(b);
	return res;
}

sol_object_t *sol_f_str_free(sol_state_t *state, sol_object_t *obj) {
	free(obj->str);
	return obj;
}

sol_object_t *sol_new_list(sol_state_t *state) {
	sol_object_t *res = sol_alloc_object(state);
	res->type = SOL_LIST;
	res->seq = dsl_seq_new_array(NULL, &(state->obfuncs));
	res->ops = &(state->ListOps);
	sol_init_object(state, res);
	return res;
}

sol_object_t *sol_list_from_seq(sol_state_t *state, dsl_seq *seq) {
	sol_object_t *res = sol_alloc_object(state);
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
	for(i = 0; i < idx; i++) {
		dsl_seq_delete(subl, 0);
	}
	return sol_list_from_seq(state, subl);
}

sol_object_t *sol_list_get_index(sol_state_t *state, sol_object_t *list, int idx) {
	if(idx < 0 || idx >= dsl_seq_len(list->seq)) {
		return sol_incref(state->None);
	}
	return sol_incref(AS_OBJ(dsl_seq_get(list->seq, idx)));
}

void sol_list_set_index(sol_state_t *state, sol_object_t *list, int idx, sol_object_t *obj) {
	if(idx < 0 || idx >= dsl_seq_len(list->seq)) {
		return;
	}
	dsl_seq_set(list->seq, idx, obj);
}

void sol_list_insert(sol_state_t *state, sol_object_t *list, int idx, sol_object_t *obj) {
	if(idx < 0 || idx > dsl_seq_len(list->seq)) {
		return;
	}
	dsl_seq_insert(list->seq, idx, obj);
}

sol_object_t *sol_list_remove(sol_state_t *state, sol_object_t *list, int idx) {
	if(idx < 0 || idx >= dsl_seq_len(list->seq)) {
		return sol_incref(state->None);
	}
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
	if(pos >= len) {
		for(i = 0; i < sz - pos; i++) {
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
	map->type = SOL_MAP;
	map->ops = &(state->MapOps);
	map->seq = dsl_seq_new_array(NULL, &(state->obfuncs));
	sol_init_object(state, map);
	return map;
}

sol_object_t *sol_map_from_seq(sol_state_t *state, dsl_seq *seq) {
	sol_object_t *map = sol_alloc_object(state);
	if(sol_has_error(state)) {
		return sol_incref(state->None);
	}
	map->type = SOL_MAP;
	map->ops = &(state->MapOps);
	map->seq = seq;
	return map;
}

int sol_map_len(sol_state_t *state, sol_object_t *map) {
	return dsl_seq_len(map->seq);
}

sol_object_t *sol_map_mcell_index(sol_state_t *state, sol_object_t *map, int index) {
	sol_object_t *res = dsl_seq_get(map->seq, index);
	if(res) {
		return sol_incref(res);
	}
	return sol_incref(state->None);
}

sol_object_t *sol_map_mcell(sol_state_t *state, sol_object_t *map, sol_object_t *key) {
	sol_object_t *list, *cmp, *icmp, *res = NULL;
	dsl_seq_iter *iter;
	if(!sol_is_map(map)) {
		printf("WARNING: Attempt to index non-map as map\n");
		return sol_incref(state->None);
	}
	list = sol_new_list(state);
	iter = dsl_new_seq_iter(map->seq);
	if(sol_has_error(state)) {
		dsl_free_seq_iter(iter);
		sol_obj_free(list);
		return sol_incref(state->None);
	}
	sol_list_insert(state, list, 0, state->None);
	sol_list_insert(state, list, 1, key);
	while(!res && !dsl_seq_iter_is_invalid(iter)) {
		sol_list_set_index(state, list, 0, AS_OBJ(dsl_seq_iter_at(iter))->key);
		cmp = CALL_METHOD(state, AS_OBJ(dsl_seq_iter_at(iter))->key, cmp, list);
		if(sol_has_error(state)) {
			sol_obj_free(cmp);
			sol_clear_error(state);
			continue;
		}
		icmp = sol_cast_int(state, cmp);
		sol_obj_free(cmp);
		if(icmp->ival == 0) {
			res = AS_OBJ(dsl_seq_iter_at(iter));
		}
		sol_obj_free(icmp);
		dsl_seq_iter_next(iter);
	} 
	dsl_free_seq_iter(iter);
	sol_obj_free(list);
	if(res) {
		return sol_incref(res);
	}
	return sol_incref(state->None);
}

int sol_map_has(sol_state_t *state, sol_object_t *map, sol_object_t *key) {
	sol_object_t *mcell = sol_map_mcell(state, map, key);
	int res = !sol_is_none(state, mcell);
	sol_decref(mcell);
	return res;
}

sol_object_t *sol_map_get(sol_state_t *state, sol_object_t *map, sol_object_t *key) {
	sol_object_t *mcell = sol_map_mcell(state, map, key), *ret;
	if(sol_is_none(state, mcell)) {
		ret = mcell;
	} else {
		ret = mcell->val;
	}
	sol_obj_free(mcell);
	return sol_incref(ret);
}

sol_object_t *sol_map_get_name(sol_state_t *state, sol_object_t *map, char *name) {
	sol_object_t *key = sol_new_buffer(state, name, strlen(name), OWN_NONE, NULL, NULL);
	sol_object_t *res = sol_map_get(state, map, key);
	sol_obj_free(key);
	return res;
}

void sol_map_set(sol_state_t *state, sol_object_t *map, sol_object_t *key, sol_object_t *val) {
	sol_object_t *mcell = sol_map_mcell(state, map, key), *newcell, *temp;
	if(sol_is_none(state, val)) {
		if(!sol_is_none(state, mcell)) {
			// XXX hacky
			dsl_seq_iter *iter = dsl_new_seq_iter(map->seq);
			while(!dsl_seq_iter_is_invalid(iter)) {
				if(mcell == dsl_seq_iter_at(iter)) {
					dsl_seq_iter_delete_at(iter);
					break;
				}
				dsl_seq_iter_next(iter);
			}
		}
		return;
	} 
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
	sol_obj_free(mcell);
}

void sol_map_set_name(sol_state_t *state, sol_object_t *map, char *name, sol_object_t *val) {
	sol_object_t *key = sol_new_buffer(state, name, strlen(name), OWN_NONE, NULL, NULL);
	sol_map_set(state, map, key, val);
	sol_obj_free(key);
}

void sol_map_set_existing(sol_state_t *state, sol_object_t *map, sol_object_t *key, sol_object_t *val) {
	sol_object_t *mcell = sol_map_mcell(state, map, key), *temp;
	if(!sol_is_none(state, mcell)) {
		temp = mcell->val;
		mcell->val = sol_incref(val);
		sol_obj_free(temp);
	}
	sol_obj_free(mcell);
}

sol_object_t *sol_map_copy(sol_state_t *state, sol_object_t *map) {
	return sol_map_from_seq(state, dsl_seq_copy(map->seq));
}

void sol_map_merge(sol_state_t *state, sol_object_t *dest, sol_object_t *src) {
	dsl_seq_iter *iter = dsl_new_seq_iter(src->seq);
	while(!dsl_seq_iter_is_invalid(iter)) {
		sol_map_set(state, dest, AS_OBJ(dsl_seq_iter_at(iter))->key, AS_OBJ(dsl_seq_iter_at(iter))->val);
		dsl_seq_iter_next(iter);
	}
	dsl_free_seq_iter(iter);
}

void sol_map_merge_existing(sol_state_t *state, sol_object_t *dest, sol_object_t *src) {
	dsl_seq_iter *iter = dsl_new_seq_iter(src->seq);
	while(!dsl_seq_iter_is_invalid(iter)) {
		sol_map_set_existing(state, dest, AS_OBJ(dsl_seq_iter_at(iter))->key, AS_OBJ(dsl_seq_iter_at(iter))->val);
		dsl_seq_iter_next(iter);
	}
	dsl_free_seq_iter(iter);
}

void sol_map_invert(sol_state_t *state, sol_object_t *map) {
	dsl_seq *pairs = dsl_seq_copy(map->seq);
	dsl_seq_iter *iter = dsl_new_seq_iter(pairs);
	sol_object_t *mcell;
	while(!dsl_seq_iter_is_invalid(iter)) {
		mcell = dsl_seq_iter_at(iter);
		sol_map_set(state, map, mcell->val, mcell->key);
		dsl_seq_iter_next(iter);
	}
	dsl_free_seq_iter(iter);
	dsl_free_seq(pairs);
}

sol_object_t *sol_f_map_free(sol_state_t *state, sol_object_t *map) {
	dsl_free_seq(map->seq);
	return map;
}

sol_object_t *sol_f_mcell_free(sol_state_t *state, sol_object_t *mcell) {
	if(mcell->key) {
		sol_obj_free(mcell->key);
	} else {
		printf("WARNING: Freed mcell with NULL key\n");
	}
	if(mcell->val) {
		sol_obj_free(mcell->val);
	} else {
		printf("WARNING: Freed mcell with NULL value\n");
	}
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

sol_object_t *sol_new_cfunc(sol_state_t *state, sol_cfunc_t cfunc, char *name) {
	sol_object_t *res = sol_alloc_object(state);
	res->type = SOL_CFUNCTION;
	res->ops = &(state->CFuncOps);
	res->cfunc = cfunc;
	res->cfname = name ? strdup(name) : NULL;
	sol_init_object(state, res);
	return res;
}

sol_object_t *sol_new_cmacro(sol_state_t *state, sol_cfunc_t cfunc, char *name) {
	sol_object_t *res = sol_alloc_object(state);
	res->type = SOL_CMACRO;
	res->ops = &(state->CMacroOps);
	res->cfunc = cfunc;
	res->cfname = name ? strdup(name) : NULL;
	sol_init_object(state, res);
	return res;
}

sol_object_t *sol_f_cfunc_free(sol_state_t *state, sol_object_t *cfunc) {
	free(cfunc->cfname);
	return cfunc;
}

sol_object_t *sol_new_cdata(sol_state_t *state, void *cdata, sol_ops_t *ops) {
	sol_object_t *res = sol_alloc_object(state);
	res->type = SOL_CDATA;
	res->ops = ops;
	res->cdata = cdata;
	sol_init_object(state, res);
	return res;
}

sol_object_t *sol_f_astnode_free(sol_state_t *state, sol_object_t *node) {
	switch(node->type) {
		case SOL_STMT:
			st_free((stmt_node *) node->node);
			break;

		case SOL_EXPR:
			ex_free((expr_node *) node->node);
			break;
	}
	return node;
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
	sol_init_object(state, res);
	return res;
}

int sol_buffer_cmp(sol_state_t *state, sol_object_t *buf, const char *s) {
	size_t len = strlen(s);
	if(buf->sz != -1 && buf->sz < len) len = buf->sz;
	return memcmp(buf->buffer, s, len);
}

sol_object_t *sol_buffer_concat(sol_state_t *state, sol_object_t *a, sol_object_t *b) {
	sol_object_t *ba = sol_cast_buffer(state, a), *bb = sol_cast_buffer(state, b);
	char *buf;
	size_t total;
	if(ba->sz < 0 || bb->sz < 0) {
		sol_obj_free(ba);
		sol_obj_free(bb);
		return sol_set_error_string(state, "Concatenate unsized buffer");
	}
	total = ba->sz + bb->sz;
	buf = malloc(sizeof(char) * total);
	if(!buf) {
		sol_obj_free(ba);
		sol_obj_free(bb);
		return sol_incref(state->OutOfMemory);
	}
	memcpy(buf, ba->buffer, ba->sz);
	memcpy(buf + ba->sz, bb->buffer, bb->sz);
	sol_obj_free(ba);
	sol_obj_free(bb);
	return sol_new_buffer(state, buf, total, OWN_FREE, NULL, NULL);
}

sol_object_t *sol_buffer_concat_cstr(sol_state_t *state, sol_object_t *a, char *b) {
	sol_object_t *buf = sol_new_buffer(state, b, strlen(b), OWN_NONE, NULL, NULL);
	sol_object_t *res = sol_buffer_concat(state, a, buf);
	sol_obj_free(buf);
	return res;
}

char *sol_buffer_strdup(sol_object_t *a) {
	char *b;
	if(a->sz < 0) return NULL;
	b = malloc(a->sz + 1);
	if(!b) return NULL;
	strncpy(b, a->buffer, a->sz);
	b[a->sz] = '\0';
	return b;
}

sol_object_t *sol_f_buffer_free(sol_state_t *state, sol_object_t *buf) {
	switch(buf->own) {
		case OWN_FREE:
			free(buf->buffer);
			break;

		case OWN_CALLF:
			if(buf->freef) buf->freef(buf->buffer, buf->sz);
			break;
	}
	return buf;
}

sol_object_t *sol_new_dylib(sol_state_t *state, void *handle) {
	sol_object_t *res = sol_alloc_object(state);
	res->type = SOL_DYLIB;
	res->ops = &(state->DyLibOps);
	res->dlhandle = handle;
	sol_init_object(state, res);
	return res;
}

sol_object_t *sol_f_dylib_free(sol_state_t *state, sol_object_t *dylib) {
	dlclose(dylib->dlhandle);
	return dylib;
}

sol_object_t *sol_new_dysym(sol_state_t *state, void *sym, dsl_seq *argtp, sol_buftype_t rettp) {
	sol_object_t *res = sol_alloc_object(state);
	res->type = SOL_DYSYM;
	res->ops = &(state->DySymOps);
	res->dlsym = sym;
	if(argtp) {
		res->argtp = dsl_seq_copy(argtp);
	} else {
		res->argtp = dsl_seq_new_array(NULL, &(state->obfuncs));
	}
	res->rettp = rettp;
	sol_init_object(state, res);
	return res;
}

sol_object_t *sol_new_stream(sol_state_t *state, FILE *stream, sol_modes_t modes) {
	sol_object_t *res = sol_alloc_object(state);
	res->type = SOL_STREAM;
	res->ops = &(state->StreamOps);
	res->stream = stream;
	res->modes = modes;
	sol_init_object(state, res);
	return res;
}

size_t sol_stream_printf(sol_state_t *state, sol_object_t *stream, const char *fmt, ...) {
	va_list va;
	size_t res;
	if(!(stream->modes & MODE_WRITE)) {
		if(state) {
			sol_obj_free(sol_set_error_string(state, "Write to non-writable stream"));
		}
		return 0;
	}
	va_start(va, fmt);
	//res = vfprintf(stream->stream, fmt, va);
	res = vprintf(fmt, va);
	va_end(va);
	return res;
}

size_t sol_stream_vprintf(sol_state_t *state, sol_object_t *stream, const char *fmt, va_list va) {
	if(!(stream->modes & MODE_WRITE)) {
		if(state) {
			sol_obj_free(sol_set_error_string(state, "Write to non-writable stream"));
		}
		return 0;
	}
	//return vfprintf(stream->stream, fmt, va);
	return vprintf(fmt, va);
}

size_t sol_stream_scanf(sol_state_t *state, sol_object_t *stream, const char *fmt, ...) {
	va_list va;
	size_t res;
	if(!(stream->modes & MODE_READ)) {
		if(state) {
			sol_obj_free(sol_set_error_string(state, "Read from non-readable stream"));
		}
		return 0;
	}
	va_start(va, fmt);
	res = vfscanf(stream->stream, fmt, va);
	va_end(va);
	return res;
}

size_t sol_stream_fread(sol_state_t *state, sol_object_t *stream, char *buffer, size_t sz, size_t memb) {
	if(!(stream->modes & MODE_READ)) {
		if(state) {
			sol_obj_free(sol_set_error_string(state, "Read from non-readable stream"));
		}
		return 0;
	}
	return fread(buffer, sz, memb, stream->stream);
}

size_t sol_stream_fwrite(sol_state_t *state, sol_object_t *stream, char *buffer, size_t sz, size_t memb) {
	if(!(stream->modes & MODE_WRITE)) {
		if(state) {
			sol_obj_free(sol_set_error_string(state, "Write to non-writable stream"));
		}
		return 0;
	}
	return fwrite(buffer, sz, memb, stream->stream);
}

char *sol_stream_fgets(sol_state_t *state, sol_object_t *stream, char *buffer, size_t sz) {
	if(!(stream->modes & MODE_READ)) {
		if(state) {
			sol_obj_free(sol_set_error_string(state, "Read from non-readable stream"));
		}
		return NULL;
	}
	return fgets(buffer, sz, stream->stream);
}

int sol_stream_fputc(sol_state_t *state, sol_object_t *stream, int ch) {
	if(!(stream->modes & MODE_WRITE)) {
		if(state) {
			sol_obj_free(sol_set_error_string(state, "Write to non-writable stream"));
		}
		return 0;
	}
	return fputc(ch, stream->stream);
}

int sol_stream_feof(sol_state_t *state, sol_object_t *stream) {
	return feof(stream->stream);
}

int sol_stream_ferror(sol_state_t *state, sol_object_t *stream) {
	return ferror(stream->stream);
}

int sol_stream_fseek(sol_state_t *state, sol_object_t *stream, long offset, int whence) {
	return fseek(stream->stream, offset, whence);
}

long sol_stream_ftell(sol_state_t *state, sol_object_t *stream) {
	return ftell(stream->stream);
}

int sol_stream_fflush(sol_state_t *state, sol_object_t *stream) {
	return fflush(stream->stream);
}

sol_object_t *sol_f_stream_free(sol_state_t *state, sol_object_t *stream) {
	//printf("IO: Closing open file\n");
	fclose(stream->stream);
	return stream;
}
