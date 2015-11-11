#ifndef SOL_H
#define SOL_H

#ifndef NULL
#define NULL ((void *) 0)
#endif

#include <stdio.h>
#include <stdarg.h>
#include "dsl/dsl.h"

#define VERSION "0.2a0"
#define HEXVER 0x0002A00

#ifndef SOL_ICACHE_MIN
#define SOL_ICACHE_MIN -128
#endif

#ifndef SOL_ICACHE_MAX
#define SOL_ICACHE_MAX 256
#endif

#if !defined(SOL_ICACHE) && (SOL_ICACHE_MIN < SOL_ICACHE_MAX)
#define SOL_ICACHE
#endif

// Forward declarations:
struct sol_tag_object_t;
typedef struct sol_tag_object_t sol_object_t;

struct sol_tag_state_t;
typedef struct sol_tag_state_t sol_state_t;

typedef sol_object_t *(*sol_cfunc_t)(sol_state_t *, sol_object_t *);

typedef void (*sol_printfunc_t)(sol_object_t *);

typedef struct {
	char *tname;
	sol_cfunc_t add;
	sol_cfunc_t sub;
	sol_cfunc_t mul;
	sol_cfunc_t div;
	sol_cfunc_t mod;
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
	sol_cfunc_t repr;
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
	SOL_MCELL,
	SOL_FUNCTION,
	SOL_CFUNCTION,
	SOL_STMT,
	SOL_EXPR,
	SOL_BUFFER,
	SOL_DYLIB,
	SOL_DYSYM,
	SOL_STREAM,
	SOL_CDATA
} sol_objtype_t;

typedef enum {
	BUF_NONE,
	BUF_INT8,
	BUF_INT16,
	BUF_INT32,
	BUF_INT64,
	BUF_UINT8,
	BUF_UINT16,
	BUF_UINT32,
	BUF_UINT64,
	BUF_CHAR,
	BUF_BYTE,
	BUF_INT,
	BUF_UINT,
	BUF_LONG,
	BUF_ULONG,
	BUF_FLOAT,
	BUF_DOUBLE,
	BUF_CSTR,
	BUF_PTR
} sol_buftype_t;

typedef enum {
	OWN_NONE,
	OWN_FREE,
	OWN_CALLF
} sol_owntype_t;

typedef enum {
	MODE_READ = 1,
	MODE_WRITE = 2,
	MODE_APPEND = 4,
	MODE_TRUNCATE = 8,
	MODE_BINARY = 16
} sol_modes_t;

typedef void (*sol_freefunc_t)(void *, size_t);
typedef void *(*sol_movefunc_t)(void *, size_t);

typedef struct sol_tag_object_t {
	sol_objtype_t type;
	int refcnt;
	sol_ops_t *ops;
	union {
		long ival;
		double fval;
		char *str;
		dsl_seq *seq;
		struct {
			struct sol_tag_object_t *key;
			struct sol_tag_object_t *val;
		};
		struct {
			void *func; // Actually a stmt_node *
			void *args; // Actually an identlist_node *
			struct sol_tag_object_t *closure;
			struct sol_tag_object_t *udata;
			char *fname;
		};
		sol_cfunc_t cfunc;
		void *node;
		struct {
			void *buffer;
			ssize_t sz;
			sol_owntype_t own;
			sol_freefunc_t freef;
			sol_movefunc_t movef;
		};
		void *dlhandle;
		struct {
			void *dlsym;
			dsl_seq *argtp;
			sol_buftype_t rettp;
		};
		struct {
			FILE *stream;
			sol_modes_t modes;
		};
		void *cdata;
	};
} sol_object_t;

typedef enum {SF_NORMAL, SF_BREAKING, SF_CONTINUING} sol_state_flag_t;

typedef struct sol_tag_state_t {
	sol_object_t *scopes; // A list of scope maps, innermost out, ending at the global scope
	sol_object_t *ret; // Return value of this function, for early return
	sol_object_t *traceback; // The last stack of statement (nodes) in the last error, or NULL
	sol_state_flag_t sflag; // Used to implement break/continue
	sol_object_t *error; // Some arbitrary error descriptor, None if no error
	sol_object_t *stdout; // Standard output stream object (for print())
	sol_object_t *stdin; // Standard input stream object
	sol_object_t *stderr; // Standard error stream object
	sol_object_t *None;
	sol_object_t *OutOfMemory;
	sol_object_t *StopIteration;
	sol_ops_t NullOps;
	sol_ops_t SingletOps;
	sol_ops_t IntOps;
	sol_ops_t FloatOps;
	sol_ops_t StringOps;
	sol_ops_t ListOps;
	sol_ops_t MapOps;
	sol_ops_t MCellOps;
	sol_ops_t FuncOps;
	sol_ops_t CFuncOps;
	sol_ops_t ASTNodeOps;
	sol_ops_t BufferOps;
	sol_ops_t DyLibOps;
	sol_ops_t DySymOps;
	sol_ops_t StreamOps;
	sol_object_t *modules;
	sol_object_t *methods;
	dsl_object_funcs obfuncs;
	const char *calling_type;
	const char *calling_meth;
#ifdef SOL_ICACHE
	sol_object_t *icache[SOL_ICACHE_MAX - SOL_ICACHE_MIN + 1];
	char icache_bypass;
#endif
	sol_object_t *lastvalue;
	sol_object_t *loopvalue;
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

void sol_init_traceback(sol_state_t *);
void sol_add_traceback(sol_state_t *, sol_object_t *);
sol_object_t *sol_traceback(sol_state_t *);

void sol_register_module(sol_state_t *, sol_object_t *, sol_object_t *);
void sol_register_module_name(sol_state_t *, char *, sol_object_t *);
sol_object_t *sol_get_module(sol_state_t *, sol_object_t *);
sol_object_t *sol_get_module_name(sol_state_t *, char *);
void sol_register_methods(sol_state_t *, sol_object_t *, sol_object_t *);
void sol_register_methods_name(sol_state_t *, char *, sol_object_t *);
sol_object_t *sol_get_methods(sol_state_t *, sol_object_t *);
sol_object_t *sol_get_methods_name(sol_state_t *, char *);

sol_object_t *sol_f_io_index(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_io_setindex(sol_state_t *, sol_object_t *);
sol_object_t *sol_get_stdin(sol_state_t *);
sol_object_t *sol_get_stdout(sol_state_t *);
sol_object_t *sol_get_stderr(sol_state_t *);

void sol_ops_init(sol_ops_t *);

// builtins.c

sol_object_t *sol_f_not_impl(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_no_op(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_default_cmp(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_default_tostring(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_default_repr(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_toint(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_tofloat(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_tostring(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_try(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_error(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_type(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_prepr(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_print(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_rawget(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_rawset(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_range(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_exec(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_eval(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_execfile(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_parse(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_ord(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_chr(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_debug_getref(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_debug_setref(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_debug_closure(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_debug_globals(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_debug_locals(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_debug_scopes(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_iter_str(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_iter_list(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_iter_map(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_readline_readline(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_readline_add_history(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_ast_print(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_singlet_tostring(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_int_add(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_sub(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_mul(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_div(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_int_mod(sol_state_t *, sol_object_t *);
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
sol_object_t *sol_f_str_index(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_str_toint(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_str_tofloat(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_str_tostring(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_str_repr(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_str_sub(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_str_split(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_str_find(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_list_add(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_mul(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_index(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_setindex(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_len(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_iter(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_tostring(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_list_copy(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_insert(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_remove(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_truncate(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_map(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_filter(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_map_add(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_map_index(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_map_setindex(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_map_call(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_map_len(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_map_iter(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_map_tostring(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_map_repr(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_mcell_tostring(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_func_call(sol_state_t *, sol_object_t *); // Defined in ast.c
sol_object_t *sol_f_func_index(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_func_setindex(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_func_tostring(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_cfunc_call(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_cfunc_tostring(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_astnode_call(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_astnode_index(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_astnode_setindex(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_astnode_tostring(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_buffer_index(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_buffer_tostring(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_buffer_get(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_buffer_set(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_buffer_address(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_buffer_size(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_buffer_new(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_buffer_fromstring(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_buffer_fromobject(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_buffer_fromaddress(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_dylib_index(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_dylib_tostring(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_dylib_open(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_dysym_call(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_dysym_index(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_dysym_setindex(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_dysym_tostring(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_dysym_get(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_dysym_set(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_stream_blsh(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_stream_brsh(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_stream_index(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_stream_tostring(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_stream_write(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_stream_read(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_stream_seek(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_stream_tell(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_stream_flush(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_stream_eof(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_stream_open(sol_state_t *, sol_object_t *);

// object.c

#define sol_is_singlet(obj) ((obj)->type == SOL_SINGLET)
#define sol_is_none(state, obj) ((obj) == state->None)
#define sol_is_oom(state, obj) ((obj) == state->OutOfMemory)
#define sol_is_int(obj) ((obj)-> type == SOL_INTEGER)
#define sol_is_float(obj) ((obj)->type == SOL_FLOAT)
#define sol_is_string(obj) ((obj)->type == SOL_STRING)
#define sol_is_list(obj) ((obj)->type == SOL_LIST)
#define sol_is_map(obj) ((obj)->type == SOL_MAP || (obj)->type == SOL_MCELL)
#define sol_is_func(obj) ((obj)->type == SOL_FUNCTION)
#define sol_is_cfunc(obj) ((obj)->type == SOL_CFUNCTION)
#define sol_is_aststmt(obj) ((obj)->type == SOL_STMT)
#define sol_is_astexpr(obj) ((obj)->type == SOL_EXPR)
#define sol_is_astnode(obj) (sol_is_aststmt(obj) || sol_is_astexpr(obj))
#define sol_is_buffer(obj) ((obj)->type == SOL_BUFFER)
#define sol_is_cdata(obj) ((obj)->type == SOL_CDATA)

#define sol_has_error(state) (!sol_is_none((state), (state)->error))

sol_object_t *sol_new_singlet(sol_state_t *, const char *);
sol_object_t *sol_new_int(sol_state_t *, long);
sol_object_t *sol_new_float(sol_state_t *, double);

sol_object_t *sol_new_string(sol_state_t *, const char *);
int sol_string_cmp(sol_state_t *, sol_object_t *, const char *);
#define sol_string_eq(state, string, cstr) (sol_string_cmp((state), (string), (cstr))==0)
sol_object_t *sol_string_concat(sol_state_t *, sol_object_t *, sol_object_t *);
sol_object_t *sol_string_concat_cstr(sol_state_t *, sol_object_t *, char *);

sol_object_t *sol_new_list(sol_state_t *);
sol_object_t *sol_list_from_seq(sol_state_t *, dsl_seq *);
int sol_list_len(sol_state_t *, sol_object_t *);
sol_object_t *sol_list_sublist(sol_state_t *, sol_object_t *, int);
sol_object_t *sol_list_get_index(sol_state_t *, sol_object_t *, int);
void sol_list_set_index(sol_state_t *, sol_object_t *, int, sol_object_t *);
void sol_list_insert(sol_state_t *, sol_object_t *, int, sol_object_t *);
sol_object_t *sol_list_remove(sol_state_t *, sol_object_t *, int);
sol_object_t *sol_list_copy(sol_state_t *, sol_object_t *);
sol_object_t *sol_list_truncate(sol_state_t *, sol_object_t *, int);
void sol_list_append(sol_state_t *, sol_object_t *, sol_object_t *);
#define sol_list_push(st, ls, obj) sol_list_insert(st, ls, 0, obj);
#define sol_list_pop(st, ls) sol_list_remove(st, ls, 0);

sol_object_t *sol_new_map(sol_state_t *);
int sol_map_len(sol_state_t *, sol_object_t *);
sol_object_t *sol_map_mcell(sol_state_t *, sol_object_t *, sol_object_t *);
int sol_map_has(sol_state_t *, sol_object_t *, sol_object_t *);
sol_object_t *sol_map_get(sol_state_t *, sol_object_t *, sol_object_t *);
sol_object_t *sol_map_get_name(sol_state_t *, sol_object_t *, char *);
void sol_map_set(sol_state_t *, sol_object_t *, sol_object_t *, sol_object_t *);
#define sol_map_borrow(state, map, key, object) do {\
	sol_object_t *__obj = (object);\
	sol_map_set((state), (map), (key), __obj);\
	sol_obj_free(__obj);\
} while(0)
void sol_map_set_name(sol_state_t *, sol_object_t *, char *, sol_object_t *);
#define sol_map_borrow_name(state, map, str, object) do {\
	sol_object_t *__obj = (object);\
	sol_map_set_name((state), (map), (str), __obj);\
	sol_obj_free(__obj);\
} while(0)
void sol_map_set_existing(sol_state_t *, sol_object_t *, sol_object_t *, sol_object_t *);
sol_object_t *sol_map_copy(sol_state_t *, sol_object_t *);
void sol_map_merge(sol_state_t *, sol_object_t *, sol_object_t *);
void sol_map_merge_existing(sol_state_t *, sol_object_t *, sol_object_t *);
void sol_map_invert(sol_state_t *, sol_object_t *);

// Defined in ast.h
// sol_object_t *sol_new_func(sol_state_t *, identlist_node *, stmt_node *, char *);
// sol_object_t *sol_new_stmtnode(sol_state_t *, stmt_node *);
// sol_object_t *sol_new_exprnode(sol_state_t *, expr_node *);

sol_object_t *sol_new_cfunc(sol_state_t *, sol_cfunc_t);
sol_object_t *sol_new_cdata(sol_state_t *, void *, sol_ops_t *);

sol_object_t *sol_new_buffer(sol_state_t *, void *, ssize_t, sol_owntype_t, sol_freefunc_t, sol_movefunc_t);

sol_object_t *sol_new_dylib(sol_state_t *, void *);

sol_object_t *sol_new_dysym(sol_state_t *, void *, dsl_seq *, sol_buftype_t);

sol_object_t *sol_new_stream(sol_state_t *, FILE *, sol_modes_t);
size_t sol_stream_printf(sol_state_t *, sol_object_t *, const char *, ...);
size_t sol_stream_vprintf(sol_state_t *, sol_object_t *, const char *, va_list);
size_t sol_stream_scanf(sol_state_t *, sol_object_t *, const char *, ...);
size_t sol_stream_fread(sol_state_t *, sol_object_t *, char *, size_t, size_t);
size_t sol_stream_fwrite(sol_state_t *, sol_object_t *, char *, size_t, size_t);
char *sol_stream_fgets(sol_state_t *, sol_object_t *, char *, size_t);
int sol_stream_fputc(sol_state_t *, sol_object_t *, int);
#define _sol_io_on(state, op, strname, ...) do {\
	sol_object_t *__str = sol_get_##strname(state);\
	sol_stream_##op((state), __str, __VA_ARGS__);\
	sol_obj_free(__str);\
} while(0)
#define sol_printf(state, ...) _sol_io_on(state, printf, stdout, __VA_ARGS__)
#define sol_vprintf(state, ...) _sol_io_on(state, vprintf, stdout, __VA_ARGS__)
#define sol_scanf(state, ...) _sol_io_on(state, scanf, stdin, __VA_ARGS__)
#define sol_fread(state, ...) _sol_io_on(state, fread, stdin, __VA_ARGS__)
#define sol_fwrite(state, ...) _sol_io_on(state, fwrite, stdout, __VA_ARGS__)
#define sol_putchar(state, ...) _sol_io_on(state, fputc, stdout, __VA_ARGS__)
int sol_stream_feof(sol_state_t *, sol_object_t *);
int sol_stream_ferror(sol_state_t *, sol_object_t *);
#define sol_stream_ready(state, stream) (!(sol_stream_feof((state), (stream)) || sol_stream_ferror((state), (stream))))
int sol_stream_fseek(sol_state_t *, sol_object_t *, long, int);
long sol_stream_ftell(sol_state_t *, sol_object_t *);
int sol_stream_fflush(sol_state_t *, sol_object_t *);

sol_object_t *sol_cast_int(sol_state_t *, sol_object_t *);
sol_object_t *sol_cast_float(sol_state_t *, sol_object_t *);
sol_object_t *sol_cast_string(sol_state_t *, sol_object_t *);
sol_object_t *sol_cast_repr(sol_state_t *, sol_object_t *);

sol_object_t *sol_f_singlet_free(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_str_free(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_list_free(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_map_free(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_mcell_free(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_func_free(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_astnode_free(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_buffer_free(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_dylib_free(sol_state_t *, sol_object_t *);
sol_object_t *sol_f_stream_free(sol_state_t *, sol_object_t *);

int sol_validate_list(sol_state_t *, sol_object_t *);
int sol_validate_map(sol_state_t *, sol_object_t *);

// util.c

sol_object_t *sol_util_call(sol_state_t *, sol_object_t *, int *, int, ...);

// gc.c

#ifdef DEBUG_GC

sol_object_t *_int_sol_incref(const char *, sol_object_t *);
void _int_sol_obj_free(const char *, sol_object_t *);
sol_object_t *_sol_gc_dsl_copier(sol_object_t *);
void _sol_gc_dsl_destructor(sol_object_t *);

sol_object_t *_int_sol_alloc_object(const char *, sol_state_t *);

#define sol_incref(obj) (_int_sol_incref(__func__, (obj)))
#define sol_obj_free(obj) (_int_sol_obj_free(__func__, (obj)))

#define sol_alloc_object(state) (_int_sol_alloc_object(__func__, (state)))

#else

#define sol_incref(obj) (++((obj)->refcnt), obj)
void sol_obj_free(sol_object_t *);

sol_object_t *sol_alloc_object(sol_state_t *);

#endif

#define sol_decref(obj) (--((obj)->refcnt))

sol_object_t *sol_obj_acquire(sol_object_t *);
void sol_obj_release(sol_object_t *);

void sol_mm_initialize(sol_state_t *);
void sol_mm_finalize(sol_state_t *);

#define AS_OBJ(x) ((sol_object_t *) (x))

#endif
