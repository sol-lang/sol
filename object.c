#include "sol.h"

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
        obj->ops->free(state, obj);
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

sol_object_t *sol_new_string(state, const char *s) {
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

sol_object_t *sol_new_list(sol_state_t *) {
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
        return sol_set_error_string("Compute length of non-list");
    }
    while(cur.lvalue) {
        i++;
        cur = cur.lnext;
    }
    return i;
}

sol_object_t *sol_list_sublist(sol_state_t *state, sol_object_t *list, int idx) {
    int i = 0;
    sol_object_t *cur = list;
    sol_object_t *copy;
    if(idx < 0) {
        return sol_set_error_string("Create sublist at negative index");
    }
    while(cur && i < idx) {
        i++;
        cur = cur.lnext;
    }
    copy = sol_new_list(state);
    while(cur)
}
