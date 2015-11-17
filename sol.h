#ifndef SOL_H
#define SOL_H

#ifndef NULL
#define NULL ((void *) 0)
#endif

#include <stdio.h>
#include <stdarg.h>
#include "dsl/dsl.h"

/** The version of the project, as made available through `debug.version`. */
#define VERSION "0.2a0"
/** The hexadecimal version of the project, formatted 0xAAIIRPP where:
 * 
 * - AA is the two-digit major version
 * - II is the two-digit minor version
 * - R is 'A' for alpha, 'B' for beta, 'C' for candidate, and 'F' for final
 * - PP is the two-digit patch
 *
 * This value is guaranteed to always increase by revision.
 */
#define HEXVER 0x0002A00

#ifndef SOL_ICACHE_MIN
/** The smallest integer to cache. */
#define SOL_ICACHE_MIN -128
#endif

#ifndef SOL_ICACHE_MAX
/** The largest integer to cache. */
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

/** CFunction type.
 *
 * This is the essential type for most C interface routines. It receives two
 * parameters:
 *
 * - The state under which the function is invoked, and
 * - A list object containing a set of parameters, which are generally
 *   well-defined per location or operation.
 *
 * The function should return a new reference to an object. If the value is
 * unimportant or otherwise ignored, the canonical return value is
 * `sol_incref`(state->None).
 */

typedef sol_object_t *(*sol_cfunc_t)(sol_state_t *, sol_object_t *);

/** Print function type.
 *
 * \rst
 * .. admonition:: Deprecated
 *
 *     This is not used anywhere and is likely to be removed in the
 *     near future.
 * \endrst
 */

typedef void (*sol_printfunc_t)(sol_object_t *);

/** Type methods structure.
 *
 * Sol bases most of its object behavior on methods defined on so-called "ops
 * structures" of this type pointed to by the objects themselves. In general,
 * these contain the address of one such structure stored directly in the state
 * (each state has its own set of these structures for all the builtin types,
 * initialized in `sol_state_init`), but they can conceivably be allocated and
 * initialized elsewhere, e.g., in extension modules.
 *
 * Nearly all of the fields in this structure are function pointers to
 * `sol_cfunc_t` that are called when an operator is invoked on an object. In
 * the case of binary operators, only the left operand is considered.
 *
 * In member documentation of these functions, the list [in brackets]
 * represents, visually, the list that the function can expect to receive as
 * the second argument (where "rhs" is right-hand-side of a binary operator,
 * and "this" is the object whose ops structure was indexed). Note that the
 * runtime does not use nor take advantage of the returns of all of these
 * methods.
 */

typedef struct {
	/** A C-string naming the type, for use by the built-in `type` function. */
	char *tname;
	/** Called with [this, rhs] to perform binary addition ("+"). */
	sol_cfunc_t add;
	/** Called with [this, rhs] to perform binary subtraction ("-"). */
	sol_cfunc_t sub;
	/** Called with [this, rhs] to perform binary multiplication ("*"). */
	sol_cfunc_t mul;
	/** Called with [this, rhs] to perform binary division ("/"). */
	sol_cfunc_t div;
	/** Called with [this, rhs] to perform binary modulus ("%"). */
	sol_cfunc_t mod;
	/** Called with [this, rhs] to perform binary exponentiation ("**"). */
	sol_cfunc_t pow;
	/** TODO: document me!*/
	sol_cfunc_t tbang;
	/** Called with [this, rhs] to perform binary bitwise AND ("&") */
	sol_cfunc_t band;
	/** Called with [this, rhs] to perform binary bitwise OR ("|") */
	sol_cfunc_t bor;
	/** Called with [this, rhs] to perform binary bitwise XOR ("^") */
	sol_cfunc_t bxor;
	/** Called with [this, rhs] to perform binary bitwise left shift ("<<") */
	sol_cfunc_t blsh;
	/** Called with [this, rhs] to perform binary bitwise right shift (">>") */
	sol_cfunc_t brsh;
	/** Called with [this] to perform bitwise not ("~") */
	sol_cfunc_t bnot;
	/** Called with [this, rhs] to perform comparison; the result should be an integer object of value -1 (this < rhs), 0 (this == rhs), or 1 (this > rhs) */
	sol_cfunc_t cmp;
	/** Called with [this, arg1, arg2, ...] to perform a call (as "this(arg1, arg2, ...)") */
	sol_cfunc_t call;
	/** Called with [this, index] to perform an index like "this[index]" or "this.index" (in the latter, index will be a string object) */
	sol_cfunc_t index;
	/** Called with [this, index, value] to perform a setindex (like "this[index] = value" or "this.index = value" for index being a string object) */
	sol_cfunc_t setindex;
	/** Called with [this] to perform a length predicate (like "#this") */
	sol_cfunc_t len;
	/** Called with [this] to return a function object (or cfunction object) that will iterate over "this" (see the iterator protocol for more details) */
	sol_cfunc_t iter;
	/** Called with [this] to cast "this" to an integer object. This may raise an error, which should be checked. */
	sol_cfunc_t toint;
	/** Called with [this] to cast "this" to a float object. This may raise an error, which should be checked. */
	sol_cfunc_t tofloat;
	/** Called with [this] to cast "this" to a string object. This generally shouldn't raise an error, and usually falls back to a simple representation. */
	sol_cfunc_t tostring;
	/** Called with [this] to provide a representation of "this", in the sense that it is human-readable and informative. This usually falls back to tostring. */
	sol_cfunc_t repr;
	/** Called with this (*not a list*) as a result of calling `sol_init_object`. Since this is usually called from a constructor anyway, it's usually fairly useless. It should return this. */
	sol_cfunc_t init;
	/** Called with this (*not a list*) and *with a NULL state* before an object is freed; it should free any resources this object exclusively holds, and return this. */
	sol_cfunc_t free;
} sol_ops_t;

/** Object types known to Sol.
 *
 * This is rarely checked and generally only used where necessary, as there is
 * no way to extend this list naturally for an extension developer.
 *
 * For each of these types, there is almost certainly a test macro for it.
 */

typedef enum {
	/** The singlet type--the type of None, as well as StopIteration and OutOfMemory. It is also the "default" type. */
	SOL_SINGLET,
	/** The integer type, implemented as a long. */
	SOL_INTEGER,
	/** The floating point type, implemented as a double. */
	SOL_FLOAT,
	/** The string type, implemented as a C string. */
	SOL_STRING,
	/** The list type, implemented as a DSL sequence of object pointers. */
	SOL_LIST,
	/** The map type, implemented as a DSL sequence of MCELL object pointers arranged as an associative array.. */
	SOL_MAP,
	/** The mcell type, a simple key-value pair only to be found in a map. */
	SOL_MCELL,
	/** The function type, the type of all user-defined functions in Sol. */
	SOL_FUNCTION,
	/** The cfunction type, the type of objects wrapping a `sol_cfunc_t`. */
	SOL_CFUNCTION,
	/** The statement type, the type of objects wrapping a `stmt_node`. */
	SOL_STMT,
	/** The expression type, the type of objects wrapping an `expr_node`. */
	SOL_EXPR,
	/** The buffer type, a type designed to access arbitrary memory. */
	SOL_BUFFER,
	/** The dylib type, the type of dynamically-loaded shared libraries. */
	SOL_DYLIB,
	/** The dysym type, the type of symbols resolved in dylib objects. */
	SOL_DYSYM,
	/** The stream type, the type wrapping FILE *. */
	SOL_STREAM,
	/** The cdata type, the type used for extension by various modules. */
	SOL_CDATA
} sol_objtype_t;


/** Buffer types.
 *
 * These types indicate what a buffer or subsection of a buffer may refer to.
 */

typedef enum {
	/** The region is typeless. This is the default, and prohibits access unless it is retyped. */
	BUF_NONE,
	/** The region contains an 8-bit signed integer. */
	BUF_INT8,
	/** The region contains a 16-bit signed integer. */
	BUF_INT16,
	/** The region contains a 32-bit signed integer. */
	BUF_INT32,
	/** The region contains a 64-bit signed integer. */
	BUF_INT64,
	/** The region contains an 8-bit unsigned integer. */
	BUF_UINT8,
	/** The region contains a 16-bit unsigned integer. */
	BUF_UINT16,
	/** The region contains a 32-bit unsigned integer. */
	BUF_UINT32,
	/** The region contains a 64-bit unsigned integer. */
	BUF_UINT64,
	/** The region contains an ASCII character. */
	BUF_CHAR,
	/** The region contains exactly one addressable unit. */
	BUF_BYTE,
	/** The region contains a platform-sized signed integer. */
	BUF_INT,
	/** The region contains a platform-sized unsigned integer. */
	BUF_UINT,
	/** The region contains a platform-sized signed long integer. */
	BUF_LONG,
	/** The region contains a platform-sized unsigned long integer. */
	BUF_ULONG,
	/** The region contains a platform single-precision floating point. */
	BUF_FLOAT,
	/** The region contains a platform double-precision floating point. */
	BUF_DOUBLE,
	/** The region contains a pointer to a NUL-terminated C string. */
	BUF_CSTR,
	/** The region contains a generic pointer (which will instantiate another buffer). */
	BUF_PTR
} sol_buftype_t;

/** Ownership types.
 *
 * These functions determine what happens to the memory region aliased by a
 * buffer when that object is freed or copied.
 */

typedef enum {
	/** Nothing happens; the object is freed or copied normally. */
	OWN_NONE,
	/** The libc `free` function is called on the buffer. Nothing happens when a new buffer is made to alias it. */
	OWN_FREE,
	/** The movefunc and freefunc are respectively consulted. */
	OWN_CALLF
} sol_owntype_t;

/**
 * Transput modes.
 *
 * These constants are defined (by the same name) on the `io` module as valid bits for the second argument to `io.open`.
 */

typedef enum {
	/** Permit reading. If this is not set, any attempt to read will raise an error. */
	MODE_READ = 1,
	/** Permit writing. If this is not set, any attempt to write will raise an error. */
	MODE_WRITE = 2,
	/** When opening for writing, direct all writes to the end of the file. This has no effect on read positions, when opened in both modes. */
	MODE_APPEND = 4,
	/** When opened for writing, truncate the file to zero size. Previous contents are lost. */
	MODE_TRUNCATE = 8,
	/** Prepare the file for reading or writing binary data as opposed to text. */
	MODE_BINARY = 16
} sol_modes_t;

/** Buffer freeing function.
 *
 * This is called with the buffer region and given size when a buffer object is
 * freed (from state.BufferOps.free) when the `sol_owntype_t` is set to
 * `OWN_CALLF`. It should do whatever is needed to release this one alias of
 * memory. Note that care should be taken if multiple buffer objects alias the
 * same region.
 */

typedef void (*sol_freefunc_t)(void *, size_t);

/** Buffer moving function.
 *
 * This is called with the buffer region and given size when a buffer object is
 * somehow copied (usually by dereferencing a `BUF_PTR`). It should return the
 * region that the new buffer object should refer to. The size is assumed to
 * not change.
 */

typedef void *(*sol_movefunc_t)(void *, size_t);

/** Object structure.
 *
 * This structure defines the interface of every Sol object. Just as well (and
 * as an implementation detail), it contains the operative members of every
 * built-in type.
 */

typedef struct sol_tag_object_t {
	/** The type of this object. */
	sol_objtype_t type;
	/** The number of living references to this object, increased by `sol_incref` and decreased by `sol_obj_free`. */
	int refcnt;
	/** The ops structure defining the behavior of this object under certain operations (more or less, its behavioral "type"). */
	sol_ops_t *ops;
	union {
		/** For `SOL_INTEGER`, the value of the integer. */
		long ival;
		/** For `SOL_FLOAT`, the value of the floating point number. */
		double fval;
		/** For `SOL_STRING`, the C string pointer. For `SOL_SINGLET`, the name of this singlet. */
		char *str;
		/** For `SOL_LIST` and `SOL_MAP`, the DSL sequence that contains the items or pairs. */
		dsl_seq *seq;
		struct {
			/** For `SOL_MCELL`, the key of the pair. */
			struct sol_tag_object_t *key;
			/** For `SOL_MCELL`, the value of the pair. */
			struct sol_tag_object_t *val;
		};
		struct {
			/** For `SOL_FUNCTION`, the `stmt_node` pointer representing the function's body. */
			void *func; // Actually a stmt_node *
			/** For `SOL_FUNCTION`, the `identlist_node` pointer representing the list of the functions argument names. */
			void *args; // Actually an identlist_node *
			/** For `SOL_FUNCTION`, a map representing the closure (initial scope, updated on exit) of the function. */
			struct sol_tag_object_t *closure;
			/** For `SOL_FUNCTION`, a map of data defined by the user on this function object. */
			struct sol_tag_object_t *udata;
			/** For `SOL_FUNCTION`, the name of the function if it was not declared anonymously (otherwise NULL). */
			char *fname;
		};
		/** For `SOL_CFUNCTION`, the C function pointer. */
		sol_cfunc_t cfunc;
		/** For `SOL_STMT` and `SOL_EXPR`, the `stmt_node` or `expr_node` pointer, respectively. */
		void *node;
		struct {
			/** For `SOL_BUFFER`, the memory region referred to by this buffer. */
			void *buffer;
			/** For `SOL_BUFFER`, the size of this memory region. Negative values indicate no or unknown size. */
			ssize_t sz;
			/** For `SOL_BUFFER`, the ownership type of this buffer's region. */
			sol_owntype_t own;
			/** For `SOL_BUFFER`, the freeing function if own == `OWN_CALLF` */
			sol_freefunc_t freef;
			/** For `SOL_BUFFER`, the moving function if own == `OWN_CALLF` */
			sol_movefunc_t movef;
		};
		/** For `SOL_DYLIB`, the handle as returned by `dlopen`. */
		void *dlhandle;
		struct {
			/** For `SOL_DYSYM`, the symbol as resolved by `dlsym`. */
			void *dlsym;
			/** For `SOL_DYSYM`, a sequence of the types of the arguments (a set of `sol_buftype_t` cast to void *, the native type of DSL), if the symbol is a function. */
			dsl_seq *argtp;
			/** For `SOL_DYSYM`, the return type of the symbol if it is a function; otherwise, the type of the symbol if it is a variable. */
			sol_buftype_t rettp;
		};
		struct {
			/** For `SOL_STREAM`, the actual file object. */
			FILE *stream;
			/** For `SOL_STREAM`, the modes for which this stream is open. */
			sol_modes_t modes;
		};
		/** For `SOL_CDATA`, an arbitrary, user-defined pointer. */
		void *cdata;
	};
} sol_object_t;

/** State flags.
 *
 * These flags get set during execution and indicate an altered state of
 * interpretation (other than the altered state of interpretation that comes
 * about due to an error propagation).
 */

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
sol_object_t *sol_f_tbang(sol_state_t *, sol_object_t *);
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
