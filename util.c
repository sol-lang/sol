#include "sol.h"

#include <stdarg.h>

sol_object_t *sol_util_call(sol_state_t *state, sol_object_t *func, int *error, int elems, ...) {
	va_list va;
	sol_object_t *args = sol_new_list(state), *res = NULL;
	int i;

	if(sol_has_error(state)) {
		return sol_incref(state->None);
	}
	if(error) {
		*error = 0;
	}

	sol_list_insert(state, args, 0, func);

	va_start(va, elems);
	for(i=0; i<elems; i++) {
		sol_list_insert(state, args, i+1, va_arg(va, sol_object_t *));
	}
	va_end(va);

	if(!func->ops->call) {
		return sol_incref(state->None);
	}
	res = func->ops->call(state, args);
	if(!res) {
		res = sol_incref(state->None);
	}
	if(sol_has_error(state)) {
		sol_object_t *err = sol_get_error(state);
		sol_clear_error(state);
		sol_obj_free(res);
		if(error) {
			*error = 1;
		}
		res = err;
	}

	return res;
}
