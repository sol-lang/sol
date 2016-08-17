#include "cdata.h"

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define AS(arg, tp) ((tp *) (arg))
#define AT(loc, tp, off) (*((tp *) ((char *) loc) + off))
#define NEW(tp) malloc(sizeof(tp))
#define ENSURE() if(!sol_cstruct_is_init) sol_cstruct_init()

int sol_cstruct_is_init = 0;
sol_ops_t sol_cstruct_spec_ops;
sol_ops_t sol_cstruct_ops;

void sol_cstruct_init(void) {
	sol_ops_init(&sol_cstruct_spec_ops);
	sol_ops_init(&sol_cstruct_ops);

	sol_cstruct_ops.index = sol_f_cstruct_index;
	sol_cstruct_ops.setindex = sol_f_cstruct_setindex;
	sol_cstruct_is_init = 1;
}

sol_object_t *sol_new_cstruct_specs(sol_state_t *state) {
	return sol_new_map(state);
}

sol_object_t *sol_new_cstruct_spec(sol_state_t *state, sol_spec_t type) {
	ENSURE();
	sol_object_t *res = sol_new_cdata(state, NEW(sol_memspec_t), &sol_cstruct_spec_ops);
	AS(res->cdata, sol_memspec_t)->type = type;
	return res;
}

void sol_cstruct_add_member(sol_state_t *state, sol_object_t *specs, sol_object_t *key, sol_memtype_t memtype, int offset) {
	sol_object_t *spec = sol_new_cstruct_spec(state, SOL_CS_MEMBER);
	AS(spec->cdata, sol_memspec_t)->memtype = memtype;
	AS(spec->cdata, sol_memspec_t)->offset = offset;
	sol_map_set(state, specs, key, spec);
	sol_obj_free(spec);
}

void sol_cstruct_add_member_name(sol_state_t *state, sol_object_t *specs, char *name, sol_memtype_t memtype, int offset) {
	sol_object_t *spec = sol_new_cstruct_spec(state, SOL_CS_MEMBER);
	AS(spec->cdata, sol_memspec_t)->memtype = memtype;
	AS(spec->cdata, sol_memspec_t)->offset = offset;
	sol_map_set_name(state, specs, name, spec);
	sol_obj_free(spec);
}

void sol_cstruct_add_pointer(sol_state_t *state, sol_object_t *pspecs, sol_object_t *key, sol_object_t *specs, int offset) {
	sol_object_t *spec = sol_new_cstruct_spec(state, SOL_CS_MEMBER);
	AS(spec->cdata, sol_memspec_t)->memtype = SOL_MT_PTR;
	AS(spec->cdata, sol_memspec_t)->offset = offset;
	AS(spec->cdata, sol_memspec_t)->specs = pspecs;
	sol_map_set(state, specs, key, spec);
	sol_obj_free(spec);
}

void sol_cstruct_add_pointer_name(sol_state_t *state, sol_object_t *pspecs, char *name, sol_object_t *specs, int offset) {
	sol_object_t *spec = sol_new_cstruct_spec(state, SOL_CS_MEMBER);
	AS(spec->cdata, sol_memspec_t)->memtype = SOL_MT_PTR;
	AS(spec->cdata, sol_memspec_t)->offset = offset;
	AS(spec->cdata, sol_memspec_t)->specs = pspecs;
	sol_map_set_name(state, specs, name, spec);
	sol_obj_free(spec);
}

void sol_cstruct_add_func(sol_state_t *state, sol_object_t *specs, sol_object_t *key, sol_cfunc_t cfunc) {
	sol_object_t *spec = sol_new_cstruct_spec(state, SOL_CS_CFUNC);
	AS(spec->cdata, sol_memspec_t)->cfunc = cfunc;
	sol_map_set(state, specs, key, spec);
	sol_obj_free(spec);
}

void sol_cstruct_add_func_name(sol_state_t *state, sol_object_t *specs, char *name, sol_cfunc_t cfunc) {
	sol_object_t *spec = sol_new_cstruct_spec(state, SOL_CS_CFUNC);
	AS(spec->cdata, sol_memspec_t)->cfunc = cfunc;
	sol_map_set_name(state, specs, name, spec);
	sol_obj_free(spec);
}

sol_object_t *sol_new_cstruct(sol_state_t *state, void *data, sol_object_t *specs) {
	sol_object_t *res = sol_new_cdata(state, NEW(sol_cstruct_t), &sol_cstruct_ops);
	AS(res->cdata, sol_cstruct_t)->data = data;
	AS(res->cdata, sol_cstruct_t)->specs = sol_incref(specs);
	return res;
}

sol_object_t *sol_f_cstruct_index(sol_state_t *state, sol_object_t *args) {
	sol_object_t *cstructobj = sol_list_get_index(state, args, 0), *idx = sol_list_get_index(state, args, 1);
	sol_cstruct_t *cstruct = cstructobj->cdata;
	sol_object_t *specobj = sol_map_get(state, cstruct->specs, idx), *res = NULL;
	sol_memspec_t *spec;
	char cbuf[2] = {0, 0};
	if(sol_is_none(state, specobj)) {
		sol_obj_free(specobj);
		sol_obj_free(idx);
		sol_obj_free(cstructobj);
		return sol_set_error_string(state, "No such CStruct index");
	}
	spec = specobj->cdata;
	switch(spec->type) {
		case SOL_CS_MEMBER:
			switch(spec->memtype) {
				case SOL_MT_INT:
					res = sol_new_int(state, AT(cstruct->data, int, spec->offset));
					break;

				case SOL_MT_INT8:
					res = sol_new_int(state, AT(cstruct->data, int8_t, spec->offset));
					break;

				case SOL_MT_INT16:
					res = sol_new_int(state, AT(cstruct->data, int16_t, spec->offset));
					break;

				case SOL_MT_INT32:
					res = sol_new_int(state, AT(cstruct->data, int32_t, spec->offset));
					break;

				case SOL_MT_INT64:
					res = sol_new_int(state, AT(cstruct->data, int64_t, spec->offset));
					break;

				case SOL_MT_UINT:
					res = sol_new_int(state, AT(cstruct->data, unsigned int, spec->offset));
					break;

				case SOL_MT_UINT8:
					res = sol_new_int(state, AT(cstruct->data, uint8_t, spec->offset));
					break;

				case SOL_MT_UINT16:
					res = sol_new_int(state, AT(cstruct->data, uint16_t, spec->offset));
					break;

				case SOL_MT_UINT32:
					res = sol_new_int(state, AT(cstruct->data, uint32_t, spec->offset));
					break;

				/*case SOL_MT_UINT64:
				    res = sol_new_int(state, AT(cstruct->data, uint64_t, spec->offset));
				    break;*/

				case SOL_MT_FLOAT:
					res = sol_new_float(state, AT(cstruct->data, float, spec->offset));
					break;

				case SOL_MT_DOUBLE:
					res = sol_new_float(state, AT(cstruct->data, double, spec->offset));
					break;

				case SOL_MT_CHAR:
					cbuf[0] = AT(cstruct->data, char, spec->offset);
					res = sol_new_string(state, cbuf);
					break;

				case SOL_MT_CSTR:
					res = sol_new_string(state, AT(cstruct->data, char *, spec->offset));
					break;

				case SOL_MT_CFUNC:
					res = sol_new_cfunc(state, AT(cstruct->data, sol_cfunc_t, spec->offset), NULL);
					break;

				case SOL_MT_PTR:
					res = sol_new_cstruct(state, AT(cstruct->data, void *, spec->offset), spec->specs);
					break;
			}
			break;

		case SOL_CS_CFUNC:
			res = sol_new_cfunc(state, spec->cfunc, NULL);
			break;
	}
	if(!res) {
		res = sol_incref(state->None);
	}
	return res;
}

sol_object_t *sol_f_cstruct_setindex(sol_state_t *state, sol_object_t *args) {
	sol_object_t *cstructobj = sol_list_get_index(state, args, 0), *idx = sol_list_get_index(state, args, 1), *val = sol_list_get_index(state, args, 2);
	sol_cstruct_t *cstruct = cstructobj->cdata;
	sol_object_t *specobj = sol_map_get(state, cstruct->specs, idx);
	sol_memspec_t *spec;
	char cbuf[2] = {0, 0};
	if(sol_is_none(state, specobj)) {
		sol_obj_free(specobj);
		sol_obj_free(idx);
		sol_obj_free(cstructobj);
		return sol_set_error_string(state, "No such CStruct index");
	}
	spec = specobj->cdata;
	switch(spec->type) {
		case SOL_CS_MEMBER:
			switch(spec->memtype) {
				case SOL_MT_INT:
					AT(cstruct->data, int, spec->offset) = sol_cast_int(state, val)->ival;
					break;

				case SOL_MT_INT8:
					AT(cstruct->data, int8_t, spec->offset) = sol_cast_int(state, val)->ival;
					break;

				case SOL_MT_INT16:
					AT(cstruct->data, int16_t, spec->offset) = sol_cast_int(state, val)->ival;
					break;

				case SOL_MT_INT32:
					AT(cstruct->data, int32_t, spec->offset) = sol_cast_int(state, val)->ival;
					break;

				case SOL_MT_INT64:
					AT(cstruct->data, int64_t, spec->offset) = sol_cast_int(state, val)->ival;
					break;

				case SOL_MT_UINT:
					AT(cstruct->data, unsigned int, spec->offset) = sol_cast_int(state, val)->ival;
					break;

				case SOL_MT_UINT8:
					AT(cstruct->data, uint8_t, spec->offset) = sol_cast_int(state, val)->ival;
					break;

				case SOL_MT_UINT16:
					AT(cstruct->data, uint16_t, spec->offset) = sol_cast_int(state, val)->ival;
					break;

				case SOL_MT_UINT32:
					AT(cstruct->data, uint32_t, spec->offset) = sol_cast_int(state, val)->ival;
					break;

				/*case SOL_MT_UINT64:
				    AT(cstruct->data, uint64_t, spec->offset) = sol_cast_int(state, val)->ival;
				    break;*/

				case SOL_MT_FLOAT:
					AT(cstruct->data, float, spec->offset) = sol_cast_float(state, val)->fval;
					break;

				case SOL_MT_DOUBLE:
					AT(cstruct->data, double, spec->offset) = sol_cast_float(state, val)->fval;
					break;

				case SOL_MT_CHAR:
					AT(cstruct->data, char, spec->offset) = sol_cast_string(state, val)->str[0];
					break;

				case SOL_MT_CSTR:
					AT(cstruct->data, char *, spec->offset) = strdup(sol_cast_string(state, val)->str);
					break;

				case SOL_MT_CFUNC:
					return sol_set_error_string(state, "Can't assign CFunc members");
					break;

				case SOL_MT_PTR:
					if(!sol_is_cdata(val) || spec->specs != AS(val->cdata, sol_cstruct_t)->specs) {
						return sol_set_error_string(state, "Invalid type for PTR assignment");
					}
					AT(cstruct->data, void *, spec->offset) = AS(val->cdata, sol_cstruct_t)->data;
			}
			break;

		case SOL_CS_CFUNC:
			return sol_set_error_string(state, "Can't assign CFunc members");
			break;
	}
	return sol_incref(state->None);
}
