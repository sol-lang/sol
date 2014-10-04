#include "sol.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

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
	if(obj->ops->init) obj->ops->init(state, obj);
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
		sol_obj_free(sol_set_error_string(state, "Compute length of non-list"));
		return -1;
	}
	while(cur) {
		if(cur->lvalue) i++;
		cur = cur->lnext;
	}
	return i;
}

sol_object_t *sol_list_sublist(sol_state_t *state, sol_object_t *list, int idx) {
	int i = 0;
	sol_object_t *cur = list;
	sol_object_t *copy, *res;
	if(idx < 0) {
		return sol_set_error_string(state, "Create sublist at negative index");
	}
	while(cur && i < idx) {
		if(cur->lvalue) i++;
		cur = cur->lnext;
	}
	copy = sol_new_list(state);
	res = copy;
	while(cur) {
		if(cur->lvalue) {
			copy->lvalue = sol_incref(cur->lvalue);
			if(cur->lnext) {
				copy->lnext = sol_alloc_object(state);
				copy = copy->lnext;
				copy->type = SOL_LCELL;
				copy->ops = &(state->LCellOps);
				copy->lnext = NULL;
				copy->lvalue = NULL;
			}
		}
		cur = cur->lnext;
	}
	return res;
}

sol_object_t *sol_list_get_index(sol_state_t *state, sol_object_t *list, int idx) {
	sol_object_t *cur = list;
	int i = 0;
	if(!sol_is_list(list)) {
		return sol_set_error_string(state, "Get index of non-list");
	}
	if(idx < 0) {
		return sol_set_error_string(state, "Get negative index");
	}
	while(cur && i < idx) {
		if(cur->lvalue) i++;
		cur = cur->lnext;
	}
	while(cur && !cur->lvalue) cur = cur->lnext;
	if(cur) {
		return sol_incref(cur->lvalue);
	} else {
		return sol_set_error_string(state, "Get out-of-bounds index");
	}
}

void sol_list_set_index(sol_state_t *state, sol_object_t *list, int idx, sol_object_t *obj) {
	sol_object_t *cur = list, *temp;
	int i = 0;
	if(!sol_is_list(list)) {
		sol_obj_free(sol_set_error_string(state, "Set index of non-list"));
		return;
	}
	if(idx < 0) {
		sol_obj_free(sol_set_error_string(state, "Set negative index"));
		return;
	}
	while(cur && i < idx) {
		if(cur->lvalue) i++;
		cur = cur->lnext;
	}
	if(cur) {
		temp = cur->lvalue;
		cur->lvalue = sol_incref(obj);
		sol_obj_free(temp);
	} else {
		sol_obj_free(sol_set_error_string(state, "Set out-of-bounds index"));
		return;
	}
}

void sol_list_insert(sol_state_t *state, sol_object_t *list, int idx, sol_object_t *obj) {
	sol_object_t *next = list, *prev = NULL, *temp = sol_alloc_object(state);
	int i = 0;
	if(sol_has_error(state)) return;
	if(!sol_is_list(list)) {
		sol_obj_free(sol_set_error_string(state, "Insert into non-list"));
		return;
	}
	if(idx < 0) {
		sol_obj_free(sol_set_error_string(state, "Insert at negative index"));
		return;
	}
	temp->type = SOL_LCELL;
	temp->ops = &(state->LCellOps);
	temp->lvalue = sol_incref(obj);
	while(next && i < idx) {
		if(next->lvalue) i++;
		prev = next;
		next = next->lnext;
	}
	if(next) {
		if(prev) {
			prev->lnext = temp;
			temp->lnext = next;
		} else {
			assert(next == list);
			temp->lnext = sol_alloc_object(state);
			temp->lnext->type = SOL_LCELL;
			temp->lnext->ops = &(state->LCellOps);
			temp->lnext->lvalue = list->lvalue;
			temp->lnext->lnext = list->lnext;
			list->lnext = temp;
			list->lvalue = NULL;
		}
	} else {
        if(prev) {
            prev->lnext = temp;
            temp->lnext = NULL;
        } else {
            sol_obj_free(temp->lvalue);
            sol_obj_free(temp);
            sol_obj_free(sol_set_error_string(state, "Out-of-bounds insert"));
            return;
        }
	}
	assert(!sol_validate_list(state, list));
}

sol_object_t *sol_list_remove(sol_state_t *state, sol_object_t *list, int idx) {
	sol_object_t *next = list, *prev = NULL, *res, *temp;
	int i = 0;
	if(sol_has_error(state)) return sol_incref(state->None);
	if(idx < 0) {
		return sol_set_error_string(state, "Remove from negative index");
	}
	while(next && i < idx) {
		if(next->lvalue) i++;
		prev = next;
		next = next->lnext;
	}
	if(next) {
		if(prev) {
            res = next->lvalue;
			prev->lnext = next->lnext;
			sol_obj_free(next);
		} else {
            res = list->lvalue;
			list->lvalue = NULL;
		}
		assert(!sol_validate_list(state, list));
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
			newls->type = SOL_LCELL;
			newls->ops = &(state->LCellOps);
		}
		cur = cur->lnext;
	}
	return res;
}

void sol_list_append(sol_state_t *state, sol_object_t *dest, sol_object_t *src) {
    sol_object_t *curd = dest, *curs = src;
    while(curd->lnext) curd = curd->lnext;
    while(curs) {
		if(curs->lvalue) {
			curd->lvalue = sol_incref(curs->lvalue);
			curd->lnext = sol_alloc_object(state);
			if(sol_has_error(state)) return;
			curd = curd->lnext;
			curd->type = SOL_LCELL;
			curd->ops = &(state->LCellOps);
			curd->lnext = NULL;
			curd->lvalue = NULL;
		}
        curs = curs->lnext;
    }
}

sol_object_t *sol_f_list_free(sol_state_t *state, sol_object_t *list) {
    sol_object_t *cur = list, *prev;
    while(cur) {
        prev = cur;
        cur = cur->lnext;
        if(prev!=list) sol_obj_free(prev);
    }
    return list;
}

sol_object_t *sol_f_lcell_free(sol_state_t *state, sol_object_t *lcell) {
	if(lcell->lvalue) sol_obj_free(lcell->lvalue);
	return lcell;
}

int sol_test_cycle(sol_state_t *state, sol_object_t *seq) {
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
		}*/
		cur = cur->lnext;
		i++;
	}
	if(sol_test_cycle(state, list)) {
		snprintf(msg, 128, "Cycle detected");
		sol_obj_free(sol_set_error_string(state, msg));
		return 1;
	}
	return 0;
}

sol_object_t *sol_new_map(sol_state_t *state) {
    sol_object_t *map = sol_alloc_object(state);
    if(sol_has_error(state)) return sol_incref(state->None);
    map->type = SOL_MAP;
    map->ops = &(state->MapOps);
    map->mkey = NULL;
    map->mval = NULL;
    map->mnext = NULL;
}

int sol_map_len(sol_state_t *state, sol_object_t *map) {
    int i = 0;
    sol_object_t *cur = map;
    while(cur) {
        if(cur->mkey) i++;
        cur = cur->mnext;
    }
    return i;
}

sol_object_t *sol_map_submap(sol_state_t *state, sol_object_t *map, sol_object_t *key) {
    sol_object_t *list = sol_new_list(state), *res = NULL, *cur = map, *cmp;
    sol_list_insert(state, list, 0, key);
    while(cur) {
        if(cur->mkey) {
            sol_list_insert(state, list, 1, cur->mkey);
            cmp = sol_cast_int(state, key->ops->cmp(state, list));
            sol_list_remove(state, list, 1);
            if(cmp->ival == 0) {
                res = cur;
                break;
            }
        }
        cur = cur->mnext;
    }
    if(res) {
        return sol_incref(res);
    } else {
        return sol_incref(state->None);
    }
}

sol_object_t *sol_map_get(sol_state_t *state, sol_object_t *map, sol_object_t *key) {
    sol_object_t *submap = sol_map_submap(state, map, key);
    sol_object_t *res;
    if(sol_is_map(submap)) {
        res = sol_incref(submap->mval);
        return res;
    } else {
        return sol_incref(state->None);
    }
}

sol_object_t *sol_map_get_name(sol_state_t *state, sol_object_t *map, char *name) {
	sol_object_t *key = sol_new_string(state, name);
	sol_object_t *res = sol_map_get(state, map, key);
	sol_obj_free(key);
	return res;
}

void sol_map_set(sol_state_t *state, sol_object_t *map, sol_object_t *key, sol_object_t *val) {
    sol_object_t *cur = map, *prev = NULL, *list = sol_new_list(state), *cmp;
    sol_list_insert(state, list, 0, key);
    while(cur) {
        if(cur->mkey) {
            sol_list_insert(state, list, 1, cur->mkey);
            cmp = sol_cast_int(state, key->ops->cmp(state, list));
            sol_list_remove(state, list, 1);
            if(cmp->ival == 0) {
                if(sol_is_none(state, val)) {
                    if(prev) {
                        prev->mnext = cur->mnext;
                        sol_obj_free(cur);
                    } else {
                        sol_obj_free(cur->mkey);
						sol_obj_free(cur->mval);
                        cur->mkey = NULL;
                        cur->mval = NULL;
                    }
                } else {
					cur->mval = sol_incref(val);
				}
                return;
            }
        }
        prev = cur;
        cur = cur->mnext;
    }
    if(sol_is_none(state, val)) return;
    prev->mnext = sol_alloc_object(state);
    if(sol_has_error(state)) return;
    cur = prev->mnext;
    cur->type = SOL_MCELL;
    cur->ops = &(state->MCellOps);
    cur->mkey = sol_incref(key);
    cur->mval = sol_incref(val);
    cur->mnext = NULL;
}

void sol_map_set_name(sol_state_t *state, sol_object_t *map, char *name, sol_object_t *val) {
	sol_object_t *key = sol_new_string(state, name);
	sol_map_set(state, map, key, val);
	sol_obj_free(key);
}

void sol_map_set_existing(sol_state_t *state, sol_object_t *map, sol_object_t *key, sol_object_t *val) {
    sol_object_t *cur = map, *prev = NULL, *list = sol_new_list(state), *cmp;
    sol_list_insert(state, list, 0, key);
    while(cur) {
        if(cur->mkey) {
            sol_list_insert(state, list, 1, cur->mkey);
            cmp = sol_cast_int(state, key->ops->cmp(state, list));
            sol_obj_free(sol_list_remove(state, list, 1));
            if(cmp->ival == 0) {
                if(sol_is_none(state, val)) {
                    if(prev) {
                        prev->mnext = cur->mnext;
                        sol_obj_free(cur);
                    } else {
                        sol_obj_free(cur->mkey);
						sol_obj_free(cur->mval);
                        cur->mkey = NULL;
                        cur->mval = NULL;
                    }
                } else {
					cur->mval = sol_incref(val);
				}
                return;
            }
        }
        prev = cur;
        cur = cur->mnext;
    }
}

sol_object_t *sol_map_copy(sol_state_t *state, sol_object_t *map) {
    sol_object_t *newmap = sol_new_map(state), *newcur = newmap, *cur = map;
    while(cur) {
        if(cur->mkey) {
            newcur->mkey = sol_incref(cur->mkey);
            newcur->mval = sol_incref(cur->mval);
            newcur->mnext = sol_alloc_object(state);
            newcur = newcur->mnext;
            newcur->type = SOL_MCELL;
            newcur->ops = &(state->MCellOps);
            newcur->mkey = NULL;
            newcur->mval = NULL;
            newcur->mnext = NULL;
        }
        cur = cur->mnext;
    }
    return newmap;
}

void sol_map_merge(sol_state_t *state, sol_object_t *dest, sol_object_t *src) {
    sol_object_t *cur = src;
    while(cur) {
        if(cur->mkey) {
            sol_map_set(state, dest, cur->mkey, cur->mval);
        }
        cur = cur->mnext;
    }
}

void sol_map_merge_existing(sol_state_t *state, sol_object_t *dest, sol_object_t *src) {
    sol_object_t *cur = src;
    while(cur) {
        if(cur->mkey) {
            sol_map_set_existing(state, dest, cur->mkey, cur->mval);
        }
        cur = cur->mnext;
    }
}

sol_object_t *sol_f_map_free(sol_state_t *state, sol_object_t *map) {
    sol_object_t *cur = map, *prev;
    while(cur) {
        if(cur->mkey) {
            sol_obj_free(cur->mkey);
            sol_obj_free(cur->mval);
        }
        prev = cur;
        cur = cur->mnext;
        if(prev!=map) free(prev);
    }
    return map;
}

sol_object_t *sol_f_mcell_free(sol_state_t *state, sol_object_t *mcell) {
	if(mcell->mkey) sol_obj_free(mcell->mkey);
	if(mcell->mval) sol_obj_free(mcell->mval);
	return mcell;
}

int sol_validate_map(sol_state_t *state, sol_object_t *map) {
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
}

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
