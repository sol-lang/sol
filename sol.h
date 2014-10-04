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
	sol_cfunc_t pow;
	sol_cfunc_t band;
	sol_cfunc_t bor;
	sol_cfunc_t bxor;
	sol_cfunc_t blsh;
	sol_cfunc_t brsh;
	sol_cfunc_t bnot;
	sol_cfunc_t cmp;
	sol_cfunc_t call;
	sol_cfunc_t index;
	sol_cfunc_t setindex;
	sol_cfunc_t len;
	sol_cfunc_t iter;
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
	SOL_LCELL,
	SOL_MAP,
	SOL_MCELL,
	SOL_FUNCTION,
	SOL_CFUNCTION,
	SOL_CDATA
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
		long ival;
		double fval;
		char *str;
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
			void *func; // Actually a stmt_node *
			void *args; // Actually an identlist_node *
			struct sol_tag_object_t *closure;
			char *fname;
		};
		sol_cfunc_t cfunc;
		void *cdata;
	};
} sol_object_t;

typedef enum {SF_NORMAL, SF_BREAKING, SF_CONTINUING} sol_state_flag_t;

typedef struct sol_tag_state_t {
	sol_object_t *scopes; // A list of scope maps, innermost out, ending at the global scope
	sol_object_t *ret; // Return value of this function, for early return
	sol_state_flag_t sflag; // Used to implement break/continue
	sol_object_t *error; // Some arbitrary error descriptor, None if no error
	sol_object_t *None;
	sol_object_t *OutOfMemory;
	sol_object_t *StopIteration;
	sol_ops_t NullOps;
	sol_ops_t IntOps;
	sol_ops_t FloatOps;
	sol_ops_t StringOps;
	sol_ops_t ListOps;
	sol_ops_t LCellOps;
	sol_ops_t MapOps;
	sol_ops_t MCellOps;
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

void sol_state_push_scope(sol_state_t *, sol_object_t *);
sol_object_t *sol_state_pop_scope(sol_state_t *);

sol_object_t *sol_get_error(sol_state_t *);
sol_object_t *sol_set_error(sol_state_t *, sol_object_t *);
sol_object_t *sol_set_error_string(sol_state_t *, const char *);
void sol_clear_error(sol_state_t *);

// builtins.c

sol_object_t *sol_f_not_impl(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_no_op(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_default_cmp(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_toint(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_tofloat(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_tostring(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_try(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_type(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_prepr(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_print(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_rawget(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_rawset(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_range(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_debug_getref(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_debug_setref(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_debug_closure(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_debug_globals(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_debug_locals(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_iter_str(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_iter_list(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_iter_map(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_int_add(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_sub(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_mul(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_div(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_pow(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_band(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_bor(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_bxor(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_blsh(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_brsh(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_bnot(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_cmp(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_toint(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_tofloat(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_tostring(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_float_add(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_float_sub(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_float_mul(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_float_div(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_float_pow(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_float_cmp(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_float_toint(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_float_tofloat(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_float_tostring(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_str_add(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_str_mul(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_str_len(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_str_iter(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_str_cmp(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_str_toint(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_str_tofloat(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_str_tostring(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_list_add(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_mul(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_index(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_setindex(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_len(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_iter(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_tostring(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_map_add(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_map_index(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_map_setindex(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_map_call(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_map_len(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_map_iter(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_map_tostring(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_func_call(sol_state_t *, sol_object_t *); // Defined in ast.c
sol_object_t *sol_f_func_index(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_func_setindex(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_func_tostring(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_cfunc_call(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_cfunc_tostring(sol_state_t *, sol_object_t *);

// object.c

#define sol_incref(obj) (++((obj)->refcnt), obj)
#define sol_decref(obj) (--((obj)->refcnt))

void sol_obj_free(sol_object_t *);
void sol_obj_release(sol_object_t *);

#define sol_is_singlet(obj) ((obj)->type == SOL_SINGLET)
#define sol_is_none(state, obj) ((obj) == state->None)
#define sol_is_oom(state, obj) ((obj) == state->OutOfMemory)
#define sol_is_int(obj) ((obj)-> type == SOL_INTEGER)
#define sol_is_float(obj) ((obj)->type == SOL_FLOAT)
#define sol_is_string(obj) ((obj)->type == SOL_STRING)
#define sol_is_list(obj) ((obj)->type == SOL_LIST || (obj)->type == SOL_LCELL)
#define sol_is_map(obj) ((obj)->type == SOL_MAP || (obj)->type == SOL_MCELL)
#define sol_is_func(obj) ((obj)->type == SOL_FUNCTION)
#define sol_is_cfunc(obj) ((obj)->type == SOL_CFUNCTION)
#define sol_is_cdata(obj) ((obj)->type == SOL_CDATA)

#define sol_has_error(state) (!sol_is_none((state), (state)->error))

sol_object_t *sol_alloc_object(sol_state_t *);

sol_object_t *sol_new_singlet(sol_state_t *);
sol_object_t *sol_new_int(sol_state_t *, long);
sol_object_t *sol_new_float(sol_state_t *, double);
sol_object_t *sol_new_string(sol_state_t *, const char *);

sol_object_t *sol_new_list(sol_state_t *);
int sol_list_len(sol_state_t *, sol_object_t *);
sol_object_t *sol_list_sublist(sol_state_t *, sol_object_t *, int);
sol_object_t *sol_list_get_index(sol_state_t *, sol_object_t *, int);
void sol_list_set_index(sol_state_t *, sol_object_t *, int, sol_object_t *);
void sol_list_insert(sol_state_t *, sol_object_t *, int, sol_object_t *);
sol_object_t *sol_list_remove(sol_state_t *, sol_object_t *, int);
sol_object_t *sol_list_copy(sol_state_t *, sol_object_t *);
void sol_list_append(sol_state_t *, sol_object_t *, sol_object_t *);
#define sol_list_push(st, ls, obj) sol_list_insert(st, ls, 0, obj);
#define sol_list_pop(st, ls) sol_list_remove(st, ls, 0);

sol_object_t *sol_new_map(sol_state_t *);
int sol_map_len(sol_state_t *, sol_object_t *);
sol_object_t *sol_map_submap(sol_state_t *, sol_object_t *, sol_object_t *);
sol_object_t *sol_map_get(sol_state_t *, sol_object_t *, sol_object_t *);
sol_object_t *sol_map_get_name(sol_state_t *, sol_object_t *, char *);
void sol_map_set(sol_state_t *, sol_object_t *, sol_object_t *, sol_object_t *);
void sol_map_set_name(sol_state_t *, sol_object_t *, char *, sol_object_t *);
void sol_map_set_existing(sol_state_t *, sol_object_t *, sol_object_t *, sol_object_t *);
sol_object_t *sol_map_copy(sol_state_t *, sol_object_t *);
void sol_map_merge(sol_state_t *, sol_object_t *, sol_object_t *);
void sol_map_merge_existing(sol_state_t *, sol_object_t *, sol_object_t *);

// Defined in ast.h
// sol_object_t *sol_new_func(sol_state_t *, identlist_node *, stmt_node *, char *);

sol_object_t *sol_new_cfunc(sol_state_t *, sol_cfunc_t);
sol_object_t *sol_new_cdata(sol_state_t *, void *, sol_ops_t *);

sol_object_t *sol_cast_int(sol_state_t *, sol_object_t *);
sol_object_t *sol_cast_float(sol_state_t *, sol_object_t *);
sol_object_t *sol_cast_string(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_str_free(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_free(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_lcell_free(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_map_free(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_mcell_free(sol_state_t *, sol_object_t *);

int sol_validate_list(sol_state_t *, sol_object_t *);
int sol_validate_map(sol_state_t *, sol_object_t *);

#endif
