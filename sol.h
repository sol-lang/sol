#ifndef SOL_H
#define SOL_H

#ifndef NULL
#define NULL ((void *) 0)
#endif

// Forward declarations:
struct sol_tag_object_t;
typedef struct sol_tag_object_t sol_object_t;

struct sol_tag_state_t;
typedef struct sol_tag_state_t sol_state_t;

typedef sol_object_t *(*sol_cfunc_t)(sol_state_t *, sol_object_t *);

typedef struct {
	sol_cfunc_t add;
	sol_cfunc_t sub;
	sol_cfunc_t mul;
	sol_cfunc_t div;
	sol_cfunc_t band;
	sol_cfunc_t bor;
	sol_cfunc_t bxor;
	sol_cfunc_t bnot;
	sol_cfunc_t call;
	sol_cfunc_t index;
	sol_cfunc_t setindex;
	sol_cfunc_t len;
	sol_cfunc_t toint;
	sol_cfunc_t tofloat;
	sol_cfunc_t tostring;
	sol_cfunc_t init;
	sol_cfunc_t free;
} sol_ops_t;

typedef enum {
	SOL_SINGLET,
	SOL_INTEGER,
	SOL_FLOAT,
	SOL_STRING,
	SOL_LIST,
	SOL_MAP,
	SOL_FUNCTION,
	SOL_CFUNCTION,
	SOL_CDATA,
	SOL_FRAME
} sol_objtype_t;

typedef enum {
	FR_CALL,
	FR_STMT
} sol_frametype_t;

typedef struct sol_tag_object_t {
	sol_objtype_t type;
	int refcnt;
	sol_ops_t *ops;
	union {
		int ival;
		double fval;
		const char *str;
		struct {
			struct sol_tag_object_t *lvalue;
			struct sol_tag_object_t *lnext;
		};
		struct {
			struct sol_tag_object_t *mkey;
			struct sol_tag_object_t *mval;
			struct sol_tag_object_t *mnext;
		};
		struct {
			void *func; // Actually a node *
			sol_object_t *closure;
		};
		sol_cfunc_t cfunc;
		void *cdata;
		struct {
			sol_frametype_t frtype;
			void *frame; // Actually a node *
		};
	};
} sol_object_t;

typedef struct sol_tag_state_t {
	sol_object_t *scopes; // A list of scope maps, innermost out, ending at the global scope
	sol_object_t *values; // Expression value stack (as a list)
	sol_object_t *returns; // Return frame stack (as a list)
	sol_object_t *error; // Some arbitrary error descriptor, sol_None if no error
	sol_object_t *None;
	sol_object_t *OutOfMemory;
	sol_ops_t NullOps;
	sol_ops_t IntOps;
	sol_ops_t FloatOps;
	sol_ops_t StringOps;
	sol_ops_t ListOps;
	sol_ops_t MapOps;
	sol_ops_t FuncOps;
	sol_ops_t CFuncOps;
} sol_state_t;

// state.c

int sol_state_init(sol_state_t *);
void sol_state_cleanup(sol_state_t *);

sol_object_t *sol_state_resolve(sol_state_t *, sol_object_t *);
sol_object_t *sol_state_resolve_name(sol_state_t *, const char *);
void sol_state_assign(sol_state_t *, sol_object_t *, sol_object_t *);
void sol_state_assign_name(sol_state_t *, const char *, sol_object_t *);
void sol_state_assign_l(sol_state_t *, sol_object_t *, sol_object_t *);
void sol_state_assign_l_name(sol_state_t *, const char *, sol_object_t *);

sol_object_t *sol_get_error(sol_state_t *);
sol_object_t *sol_set_error(sol_state_t *, sol_object_t *);
sol_object_t *sol_set_error_string(sol_state_t *, const char *);
void sol_clear_error(sol_state_t *);

// builtins.c

extern sol_cfunc_t sol_f_not_impl;
extern sol_cfunc_t sol_f_no_op;

extern sol_cfunc_t sol_f_toint;
extern sol_cfunc_t sol_f_tofloat;
extern sol_cfunc_t sol_f_tostring;
extern sol_cfunc_t sol_f_try;

extern sol_cfunc_t sol_f_int_add;
extern sol_cfunc_t sol_f_int_sub;
extern sol_cfunc_t sol_f_int_mul;
extern sol_cfunc_t sol_f_int_div;
extern sol_cfunc_t sol_f_int_band;
extern sol_cfunc_t sol_f_int_bor;
extern sol_cfunc_t sol_f_int_bxor;
extern sol_cfunc_t sol_f_int_bnot;
extern sol_cfunc_t sol_f_int_toint;
extern sol_cfunc_t sol_f_int_tofloat;
extern sol_cfunc_t sol_f_int_tostring;

extern sol_cfunc_t sol_f_float_add;
extern sol_cfunc_t sol_f_float_sub;
extern sol_cfunc_t sol_f_float_mul;
extern sol_cfunc_t sol_f_float_div;
extern sol_cfunc_t sol_f_float_toint;
extern sol_cfunc_t sol_f_float_tofloat;
extern sol_cfunc_t sol_f_float_tostring;

extern sol_cfunc_t sol_f_str_add;
extern sol_cfunc_t sol_f_str_mul;
extern sol_cfunc_t sol_f_str_len;
extern sol_cfunc_t sol_f_str_toint;
extern sol_cfunc_t sol_f_str_tofloat;
extern sol_cfunc_t sol_f_str_tostring;

extern sol_cfunc_t sol_f_list_add;
extern sol_cfunc_t sol_f_list_mul;
extern sol_cfunc_t sol_f_list_index;
extern sol_cfunc_t sol_f_list_setindex;
extern sol_cfunc_t sol_f_list_len;
extern sol_cfunc_t sol_f_list_tostring;

extern sol_cfunc_t sol_f_map_add;
extern sol_cfunc_t sol_f_map_index;
extern sol_cfunc_t sol_f_map_setindex;
extern sol_cfunc_t sol_f_map_len;
extern sol_cfunc_t sol_f_map_tostring;

extern sol_cfunc_t sol_f_func_call; // Defined in ast.c
extern sol_cfunc_t sol_f_func_tostring;

extern sol_cfunc_t sol_f_cfunc_call;
extern sol_cfunc_t sol_f_cfunc_tostring;

// object.c

#define sol_incref(obj) (++((obj)->refcnt), obj)
#define sol_decref(obj) (--((obj)->refcnt))

void sol_obj_free(sol_object_t *);
void sol_obj_release(sol_object_t *);

#define sol_is_singlet(obj) ((obj)->type == SOL_SINGLET)
#define sol_is_none(state, obj) ((obj) == state->sol_None)
#define sol_is_oom(state, obj) ((obj) == state->sol_OutOfMemory)
#define sol_is_int(obj) ((obj)-> type == SOL_INTEGER)
#define sol_is_float(obj) ((obj)->type == SOL_FLOAT)
#define sol_is_string(obj) ((obj)->type == SOL_STRING)
#define sol_is_list(obj) ((obj)->type == SOL_LIST)
#define sol_is_map(obj) ((obj)->type == SOL_MAP)
#define sol_is_func(obj) ((obj)->type == SOL_FUNCTION)
#define sol_is_cfunc(obj) ((obj)->type == SOL_CFUNCTION)
#define sol_is_cdata(obj) ((obj)->type == SOL_CDATA)

#define sol_has_error(state) (!sol_is_none((state), (state)->error))

sol_object_t *sol_new_singlet(sol_state_t *);
sol_object_t *sol_new_int(sol_state_t *, int);
sol_object_t *sol_new_float(sol_state_t *, double);
sol_object_t *sol_new_string(sol_state_t *, const char *);

sol_object_t *sol_new_list(sol_state_t *);
int sol_list_len(sol_state_t *, sol_object_t *);
sol_object_t *sol_list_sublist(sol_state_t *, sol_object_t *, int);
sol_object_t *sol_list_get_index(sol_state_t *, sol_object_t *, int);
void sol_list_set_index(sol_state_t *, sol_object_t *, int, sol_object_t *);
void sol_list_insert(sol_state_t *, sol_object_t **, int, sol_object_t *);
sol_object_t *sol_list_remove(sol_state_t *, sol_object_t **, int);
sol_object_t *sol_list_copy(sol_state_t *, sol_object_t *);
void sol_list_append(sol_state_t *, sol_object_t *, sol_object_t *);
#define sol_list_push(st, ls, obj) sol_list_insert(st, &(ls), 0, obj);
#define sol_list_pop(st, ls) sol_list_remove(st, &(ls), 0);

sol_object_t *sol_new_map(sol_state_t *);
int sol_map_len(sol_state_t *, sol_object_t *);
sol_object_t *sol_map_submap(sol_state_t *, sol_object_t *, sol_object_t *);
sol_object_t *sol_map_get(sol_state_t *, sol_object_t *, sol_object_t *);
void sol_map_set(sol_state_t *, sol_object_t *, sol_object_t *, sol_object_t *);
sol_object_t *sol_map_copy(sol_state_t *, sol_object_t *);
void sol_map_merge(sol_state_t *, sol_object_t *, sol_object_t *);

// Defined in ast.h
// sol_object_t *sol_new_func(sol_state_t *, identlist_node *, stmt_node *);

sol_object_t *sol_new_cfunc(sol_state_t *, sol_cfunc_t);
sol_object_t *sol_new_cdata(sol_state_t *, void *, sol_ops_t *);

sol_object_t *sol_cast_int(sol_state_t *, sol_object_t *);
sol_object_t *sol_cast_float(sol_state_t *, sol_object_t *);
sol_object_t *sol_cast_string(sol_state_t *, sol_object_t *);

extern sol_cfunc_t sol_f_str_free;
extern sol_cfunc_t sol_f_list_free;
extern sol_cfunc_t sol_f_map_free;

#endif
