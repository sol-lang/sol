#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sol.h"

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

void _sol_gc_obj_free(sol_object_t *obj) {
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
	fprintf(gclog, "%s\t%s\tALLOC\n", prtime(), func);
	return _sol_gc_alloc_object(state);
}

sol_object_t *_int_sol_incref(const char *func, sol_object_t *obj) {
	int oldref = obj->refcnt++;
	fprintf(gclog, "%s\t%s\tINCREF\t%s\t%p\t%d\t->\t%d\n", prtime(), func, obj->ops->tname, obj, oldref, obj->refcnt);
	return obj;
}

void _int_sol_obj_free(const char *func, sol_object_t *obj) {
	fprintf(gclog, "%s\t%s\tDECREF\t%s\t%p\t%d\t->\t%d\n", prtime(), func, obj->ops->tname, obj, obj->refcnt, obj->refcnt - 1);
	_sol_gc_obj_free(obj);
}


void sol_obj_release(sol_object_t *obj) {
	fprintf(gclog, "%s\t\tFREE\t%s\t%p\n", prtime(), obj->ops->tname, obj);
    if(obj->ops->free) obj->ops->free(NULL, obj);
    free(obj);
}

sol_object_t *_sol_gc_dsl_copier(sol_object_t *obj) {
	fprintf(gclog, "%s\t<dsl>\tINCREF\t%s\t%p\t%d\t->\t%d\n", prtime(), obj->ops->tname, obj, obj->refcnt, ++obj->refcnt);
	return obj;
}

void _sol_gc_dsl_destructor(sol_object_t *obj) {
	fprintf(gclog, "%s\t<dsl>\tDECREF\t%s\t%p\t%d\t->\t%d\n", prtime(), obj->ops->tname, obj, obj->refcnt, obj->refcnt - 1);
	_sol_gc_obj_free(obj);
}

#else

sol_object_t *sol_alloc_object(sol_state_t *state) {
	return _sol_gc_alloc_object(state);
}

void sol_obj_free(sol_object_t *obj) {
	_sol_gc_obj_free(obj);
}

void sol_obj_release(sol_object_t *obj) {
	if(obj->ops->free) {
		obj->ops->free(NULL, obj);
	}
	free(obj);
}

void sol_mm_initialize(sol_state_t *state) {}
void sol_mm_finalize(sol_state_t *state) {}

#endif