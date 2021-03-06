#ifndef AST_H
#define AST_H

#include "sol.h"

#define FUNC_IS_MACRO 1

#include <stdio.h>

/** Locator structure.
 *
 * Contains the location of a symbol; available on all `stmt_node`s and `expr_node`s as `loc`.
 */
typedef struct {
	size_t line;
	size_t col;
} loc_t;

struct tag_expr_node;
typedef struct tag_expr_node expr_node;

struct tag_stmt_node;
typedef struct tag_stmt_node stmt_node;

/** Literal type
 *
 * Defines the types of literals that may appear in a source program.
 */
typedef enum {LIT_INT=1024, LIT_FLOAT, LIT_STRING, LIT_BUFFER, LIT_NONE} lit_t;
/** Literal node
 *
 * Represents a literal in a source program.
 */
typedef struct {
	lit_t type; ///< The type of literal.
	union {
		long ival; ///< Integer value for `LIT_INT`.
		double fval; ///< Floating-point value for `LIT_FLOAT`.
		char *str; ///< String value for `LIT_STRING`.
		unsigned long *buf; ///< Buffer value for `LIT_BUFFER`; points to. (char *)(buf + 1) points to the first byte in the buffer. There are *buf bytes starting there. See also LENGTH_OF and BYTES_OF.
	};
} lit_node;

/** Returns the length (as an unsigned long) of the buffer in bytes, not including the length itself. */
#define LENGTH_OF(buf) (*((unsigned long *) (buf)))
/** Returns a (char *) pointing to the first byte in the buffer. */
#define BYTES_OF(buf) ((char *) (((unsigned long *) (buf)) + 1))

/** Binary operation type
 *
 * Defines the types of binary operators that may occur in a source program.
 */
typedef enum {OP_ADD=512, OP_SUB, OP_MUL, OP_DIV, OP_MOD, OP_POW, OP_BAND, OP_BOR, OP_BXOR, OP_LAND, OP_LOR, OP_EQUAL, OP_NEQUAL, OP_LESS, OP_GREATER, OP_LESSEQ, OP_GREATEREQ, OP_LSHIFT, OP_RSHIFT, OP_TBANG} binop_t;
/** Binary operation node
 *
 * Represents a binary operator in a source program.
 */
typedef struct {
	binop_t type; ///< The type of binary operation
	expr_node *left; ///< The left hand side.
	expr_node *right; ///< The right hand side.
} binop_node;

/** Unary operation type
 *
 * Defines the types of unary operators that may occur in a source program.
 */
typedef enum {OP_NEG=768, OP_BNOT, OP_LNOT, OP_LEN} unop_t;
/** Unary opreation node
 *
 * Represents a unary operator in a source program.
 */
typedef struct {
	unop_t type; ///< The type of unary operation.
	expr_node *expr; ///< The value to which it is applied.
} unop_node;

/** Index node
 *
 * Represents an index operation in a source program.
 */
typedef struct {
	expr_node *expr; ///< Expression to index.
	expr_node *index; ///< Expression to index by.
} index_node;

/** Setindex node
 *
 * Represents a setindex operation in a source program.
 */
typedef struct {
	expr_node *expr; ///< Expression to set the index of.
	expr_node *index; ///< Expression to index by.
	expr_node *value; ///< Value to set said index to.
} setindex_node;

typedef struct {
	char *ident;
	expr_node *value;
} assign_node;

typedef struct {
	char *ident;
} ref_node;

typedef struct tag_exprlist_node {
	expr_node *expr;
	struct tag_exprlist_node *next;
} exprlist_node;

typedef struct {
	expr_node *key;
	expr_node *value;
} associtem_node;

typedef struct tag_assoclist_node {
	associtem_node *item;
	struct tag_assoclist_node *next;
} assoclist_node;

typedef struct {
	exprlist_node *list;
} listgen_node;

typedef struct {
	assoclist_node *map;
} mapgen_node;

typedef struct {
	expr_node *expr;
	exprlist_node *args;
	char *method;
} call_node;

typedef struct tag_identlist_node {
	char *ident;
	struct tag_identlist_node *next;
} identlist_node;

typedef struct {
	identlist_node *args;
	exprlist_node *annos;
	identlist_node *clkeys;
	exprlist_node *clvalues;
	char *rest;
} paramlist_node;

typedef struct {
	char *name;
	paramlist_node *params;
	expr_node *anno;
	stmt_node *body;
	unsigned short flags;  // FUNC_IS_MACRO
} funcdecl_node;

typedef struct {
	expr_node *cond;
	stmt_node *iftrue;
	stmt_node *iffalse;
} ifelse_node;

typedef struct {
	expr_node *cond;
	stmt_node *loop;
} loop_node;

typedef struct {
	char *var;
	expr_node *iter;
	stmt_node *loop;
} iter_node;

typedef enum {EX_LIT=256, EX_LISTGEN, EX_MAPGEN, EX_BINOP, EX_UNOP, EX_INDEX, EX_SETINDEX, EX_ASSIGN, EX_REF, EX_CALL, EX_FUNCDECL, EX_IFELSE, EX_LOOP, EX_ITER} expr_t;
typedef struct tag_expr_node {
	expr_t type;
	loc_t loc;
	union {
		lit_node *lit;
		listgen_node *listgen;
		mapgen_node *mapgen;
		binop_node *binop;
		unop_node *unop;
		index_node *index;
		setindex_node *setindex;
		assign_node *assign;
		ref_node *ref;
		call_node *call;
		funcdecl_node *funcdecl;
		ifelse_node *ifelse;
		loop_node *loop;
		iter_node *iter;
	};
} expr_node;

typedef struct {
	expr_node *ret;
} ret_node;

typedef struct {
	expr_node *val;
} cont_node;

typedef struct {
	expr_node *val;
} break_node;

typedef struct tag_stmtlist_node {
	stmt_node *stmt;
	struct tag_stmtlist_node *next;
} stmtlist_node;

typedef enum {ST_EXPR, ST_LIST, ST_RET, ST_CONT, ST_BREAK} stmt_t;
typedef struct tag_stmt_node {
	stmt_t type;
	loc_t loc;
	union {
		expr_node *expr;
		stmtlist_node *stmtlist;
		ret_node *ret;
		cont_node *cont;
		break_node *brk;
	};
} stmt_node;

typedef enum {
	BC_NULL,
	BC_ST_EXPR,
	BC_ST_LIST,
	BC_ST_RET,
	BC_ST_CONT,
	BC_ST_BREAK,
	BC_EX_LIT,
	BC_EX_LISTGEN,
	BC_EX_MAPGEN,
	BC_EX_BINOP,
	BC_EX_UNOP,
	BC_EX_INDEX,
	BC_EX_SETINDEX,
	BC_EX_ASSIGN,
	BC_EX_REF,
	BC_EX_CALL,
	BC_EX_FUNCDECL,
	BC_EX_IFELSE,
	BC_EX_LOOP,
	BC_EX_ITER,
	BC_LIT_INT,
	BC_LIT_FLOAT,
	BC_LIT_STRING,
	BC_LIT_BUFFER,
	BC_LIT_NONE,
	BC_INT,
	BC_FLOAT,
	BC_STRING,
	BC_BUFFER,
	BC_LIST_ST,
	BC_LIST_EX,
	BC_LIST_AS,
	BC_LIST_ID,
	BC_LIST_PM,
	BC_ENDLIST,
} bytecode;

#define AS_ST(arg) ((stmt_node *) (arg))
#define AS_EX(arg) ((expr_node *) (arg))
#define AS(arg, tp) ((tp *) (arg))
#define NEW_ST() malloc(sizeof(stmt_node))
#define NEW_EX() malloc(sizeof(expr_node))
#define SET_LOC(node, l) do { (node)->loc.line = (l).first_line; (node)->loc.col = (l).first_column; } while(0)
#define NEW(arg) malloc(sizeof(arg))
#define MAKE_REF_BINOP(nd, tp, name, val) nd = NEW_EX(); \
	nd->type = EX_BINOP; \
	nd->binop = NEW(binop_node); \
	nd->binop->type = tp; \
	nd->binop->left = NEW_EX(); \
	nd->binop->left->type = EX_REF; \
	nd->binop->left->ref = NEW(ref_node); \
	nd->binop->left->ref->ident = strdup(name); \
	nd->binop->right = val
#define MAKE_IDX_BINOP(nd, tp, obj, idx, val) nd = NEW_EX(); \
	nd->type = EX_BINOP; \
	nd->binop = NEW(binop_node); \
	nd->binop->type = tp; \
	nd->binop->left = NEW_EX(); \
	nd->binop->left->type = EX_INDEX; \
	nd->binop->left->index = NEW(index_node); \
	nd->binop->left->index->expr = ex_copy(obj); \
	nd->binop->left->index->index = ex_copy(idx); \
	nd->binop->right = val
#define BOOL_TO_INT(cond) ((cond)?1:0)
#define CALL_METHOD(state, obj, meth, args) ({\
		sol_object_t *res;\
		state->calling_type = obj->ops->tname;\
		state->calling_meth = #meth;\
		res = obj->ops->meth(state, args);\
		state->calling_type = "(none)";\
		state->calling_meth = "(none)";\
		res;\
})

sol_object_t *sol_new_func(sol_state_t *, identlist_node *, stmt_node *, char *, paramlist_node *, expr_node *, unsigned short);
sol_object_t *sol_new_stmtnode(sol_state_t *, stmt_node *);
sol_object_t *sol_new_exprnode(sol_state_t *, expr_node *);

// runtime.c

stmt_node *sol_compile(const char *);
stmt_node *sol_compile_buffer(const char *, size_t);
stmt_node *sol_compile_file(FILE *);
void sol_write_html(FILE *);
expr_node *sol_comp_as_expr(stmt_node *);
void sol_compile_free(stmt_node *);

stmt_node *st_copy(stmt_node *);
expr_node *ex_copy(expr_node *);
stmtlist_node *stl_copy(stmtlist_node *);
exprlist_node *exl_copy(exprlist_node *);
assoclist_node *asl_copy(assoclist_node *);
identlist_node *idl_copy(identlist_node *);
paramlist_node *pl_copy(paramlist_node *);

void st_free(stmt_node *);
void ex_free(expr_node *);
void stl_free(stmtlist_node *);
void exl_free(exprlist_node *);
void asl_free(assoclist_node *);
void idl_free(identlist_node *);
void pl_free(paramlist_node *);

void st_print(sol_state_t *, stmt_node *);
void ex_print(sol_state_t *, expr_node *);
void ob_print(sol_object_t *);

sol_object_t *sol_eval(sol_state_t *, expr_node *);
void sol_exec(sol_state_t *, stmt_node *);

// ser.c

void sol_ser_stmt(FILE *, stmt_node *);
void sol_ser_expr(FILE *, expr_node *);
void sol_ser_stl(FILE *, stmtlist_node *);
void sol_ser_exl(FILE *, exprlist_node *);
void sol_ser_asl(FILE *, assoclist_node *);
void sol_ser_idl(FILE *, identlist_node *);
void sol_ser_pl(FILE *, paramlist_node *);
void sol_ser_lit(FILE *, lit_node *);
void sol_ser_int(FILE *, long);
void sol_ser_float(FILE *, double);
void sol_ser_str(FILE *, const char *);
void sol_ser_buf(FILE *, unsigned long *);

void *sol_deser(FILE *);
void *sol_deser_checked(FILE *, bytecode);
void *sol_deser_stmt(FILE *);
void *sol_deser_expr(FILE *);
void *sol_deser_lit(FILE *);

#endif
