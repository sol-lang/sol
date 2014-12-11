#include <stdlib.h>
#include "sol.h"

#ifdef DEBUG_GC

#else

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

#endif