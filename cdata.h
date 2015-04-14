#ifndef CDATA_H
#define CDATA_H

#include "sol.h"

typedef enum {
	SOL_MT_INT,
	SOL_MT_INT8,
	SOL_MT_INT16,
	SOL_MT_INT32,
	SOL_MT_INT64,
	SOL_MT_UINT,
	SOL_MT_UINT8,
	SOL_MT_UINT16,
	SOL_MT_UINT32,
//    SOL_MT_UINT64, TODO: Not yet supported
	SOL_MT_FLOAT,
	SOL_MT_DOUBLE,
	SOL_MT_CHAR,
	SOL_MT_CSTR,
	SOL_MT_CFUNC,
	SOL_MT_PTR // Don't use this in add_member--use add_pointer
} sol_memtype_t;

typedef enum {
	SOL_CS_MEMBER,
	SOL_CS_CFUNC
} sol_spec_t;

typedef struct {
	sol_spec_t type;
	union {
		struct {
			sol_memtype_t memtype;
			int offset;
			sol_object_t *specs;
		};
		sol_cfunc_t cfunc;
	};
} sol_memspec_t;

typedef struct {
	void *data;
	sol_object_t *specs;
} sol_cstruct_t;

sol_object_t *sol_new_cstruct_specs(sol_state_t *);
void sol_cstruct_add_member(sol_state_t *, sol_object_t *, sol_object_t *, sol_memtype_t, int);
void sol_cstruct_add_member_name(sol_state_t *, sol_object_t *, char *, sol_memtype_t, int);
void sol_cstruct_add_pointer(sol_state_t *, sol_object_t *, sol_object_t *, sol_object_t *, int);
void sol_cstruct_add_pointer_name(sol_state_t *, sol_object_t *, char *, sol_object_t *, int);
void sol_cstruct_add_func(sol_state_t *, sol_object_t *, sol_object_t *, sol_cfunc_t);
void sol_cstruct_add_func_name(sol_state_t *, sol_object_t *, char *, sol_cfunc_t);

sol_object_t *sol_new_cstruct(sol_state_t *, void *, sol_object_t *);

extern sol_ops_t sol_cstruct_spec_ops;
extern sol_ops_t sol_cstruct_ops;

sol_object_t *sol_f_cstruct_index(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_cstruct_setindex(sol_state_t *, sol_object_t *);

#endif
