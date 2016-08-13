#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sol.h"

/** Allocates and returns a new reference to a typeless object.
 *
 * This is an internal function. Users should use `sol_alloc_object` instead.
 */

sol_object_t *_sol_gc_alloc_object(sol_state_t *state) {
	sol_object_t *res = malloc(sizeof(sol_object_t));
	if(!res) {
		sol_set_error(state, state->OutOfMemory);
		return sol_incref(state->None);
	}
	res->refcnt = 0;
	res->ops = &(state->NullOps);
	return sol_incref(res);
}

/** Frees a reference to an object.
 *
 * This is an internal function. Users should use `sol_obj_free` instead.
 */

void _sol_gc_obj_free(sol_object_t *obj) {
	if(!obj) {
		/*printf("WARNING: Attempt to free NULL\n");*/
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

/** Increments the reference count of an object, and return it.
 *
 * This function is exactly an identity function, but it increments the
 * object's reference count.
 *
 * It is intended for use in places where a function is required, such as
 * assigning to a function pointer.
 *
 * Users with the ability to should use `sol_incref` instead.
 */

sol_object_t *sol_obj_acquire(sol_object_t *obj) {
	return sol_incref(obj);
}

#ifdef DEBUG_GC

static FILE *gclog = NULL;
static int gcrefcnt = 0;

static char gctime[64];

/*
char *prtime() {
	time_t t;
	struct tm t2;
	time(&t);
	localtime_r(&t, &t2);
	strftime(gctime, 64, "%Y/%m/%d %T", &t2);
	return gctime;
}
*/

char *prtime() {return "";}

void sol_mm_initialize(sol_state_t *state) {
	if(gclog) {
		fprintf(gclog, " === Reopened at %s ===\n", prtime());
	} else {
		gclog = fopen("gclog.txt", "a");
		fprintf(gclog, "=== Opened at %s ===\n", prtime());
	}
	gcrefcnt++;
}

void sol_mm_finalize(sol_state_t *state) {
	gcrefcnt--;
	fprintf(gclog, "=== Closed at %s ===\n", prtime());
	if(gcrefcnt <= 0) {
		fflush(gclog);
		fclose(gclog);
		gclog = NULL;
	}
}

sol_object_t *_int_sol_alloc_object(const char *func, sol_state_t *state) {
	fprintf(gclog, "%s\tA\n", func);
	return _sol_gc_alloc_object(state);
}

sol_object_t *_int_sol_incref(const char *func, sol_object_t *obj) {
	int oldref = obj->refcnt++;
	fprintf(gclog, "%s\tI\t%s\t%p\t%d\t->\t%d\n", func, obj->ops->tname, obj, oldref, obj->refcnt);
	return obj;
}

void _int_sol_obj_free(const char *func, sol_object_t *obj) {
	fprintf(gclog, "%s\tD\t%s\t%p\t%d\t->\t%d\n", func, obj->ops->tname, obj, obj->refcnt, obj->refcnt - 1);
	_sol_gc_obj_free(obj);
}


void sol_obj_release(sol_object_t *obj) {
	fprintf(gclog, "\tF\t%s\t%p\n", obj->ops->tname, obj);
    if(obj->ops->free) obj->ops->free(NULL, obj);
    free(obj);
}

sol_object_t *_sol_gc_dsl_copier(sol_object_t *obj) {
	fprintf(gclog, "<dsl>\tI\t%s\t%p\t%d\t->\t%d\n", obj->ops->tname, obj, obj->refcnt, ++obj->refcnt);
	return obj;
}

void _sol_gc_dsl_destructor(sol_object_t *obj) {
	fprintf(gclog, "<dsl>\tD\t%s\t%p\t%d\t->\t%d\n", obj->ops->tname, obj, obj->refcnt, obj->refcnt - 1);
	_sol_gc_obj_free(obj);
}

#else

/** Allocates and returns a new reference to a typeless object.
 *
 * This function is intended to be called from object constructors that will
 * ultimately set the type and operations on the object.
 *
 * The returned reference is initially the only reference to this object.
 */

sol_object_t *sol_alloc_object(sol_state_t *state) {
	return _sol_gc_alloc_object(state);
}

/** Frees a reference to an object.
 *
 * If the given reference is the last reference to this object, the memory is
 * freed, after any type-specific destructors are called.
 */

void sol_obj_free(sol_object_t *obj) {
	_sol_gc_obj_free(obj);
}

/** Destroys an object.
 *
 * This function is called on an object whose last reference has been freed; it
 * is responsible for implementing the destructor protocol (and so calling the
 * necessary methods). In general, it should not be used by user code, as it
 * may introduce use-after-free.
 */

void sol_obj_release(sol_object_t *obj) {
	if(obj->ops->free) {
		obj->ops->free(NULL, obj);
	}
	free(obj);
}

/** Initialize the memory manager for a state.
 *
 * You normally do not need to call this; it is also done in `sol_state_init`.
 */

void sol_mm_initialize(sol_state_t *state) {}

/** Finalize the memory manager for a state.
 *
 * You normally do not need to call this; it is also done in
 * `sol_state_cleanup`.
 */

void sol_mm_finalize(sol_state_t *state) {}

#endif
