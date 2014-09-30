#ifndef AST_H
#define AST_H

#include "sol.h"

struct tag_expr_node;
typedef struct tag_expr_node expr_node;

struct tag_stmt_node;
typedef struct tag_stmt_node stmt_node;

typedef enum {LIT_INT, LIT_FLOAT, LIT_STRING} lit_t;
typedef struct {
	lit_t type;
	union {
		int ival;
		double fval;
		char *str;
	};
} lit_node;

typedef enum {OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_POW, OP_BAND, OP_BOR, OP_BXOR, OP_LAND, OP_LOR, OP_EQUAL, OP_LESS, OP_GREATER, OP_LESSEQ, OP_GREATEREQ} binop_t;
typedef struct {
	binop_t type;
	expr_node *left;
	expr_node *right;
} binop_node;

typedef enum {OP_NEG, OP_BNOT, OP_LNOT} unop_t;
typedef struct {
	unop_t type;
	expr_node *expr;
} unop_node;

typedef struct {
	expr_node *expr;
	expr_node *index;
} index_node;

typedef struct {
	expr_node *expr;
	expr_node *index;
	expr_node *value;
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
} call_node;

typedef struct tag_identlist_node {
	char *ident;
	struct tag_identlist_node *next;
} identlist_node;

typedef struct {
	char *name;
	identlist_node *args;
	stmt_node *body;
} funcdecl_node;

typedef enum {EX_LIT, EX_LISTGEN, EX_MAPGEN, EX_BINOP, EX_UNOP, EX_INDEX, EX_SETINDEX, EX_ASSIGN, EX_REF, EX_CALL, EX_FUNCDECL} expr_t;
typedef struct tag_expr_node {
	expr_t type;
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
	};
} expr_node;

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

typedef struct tag_stmtlist_node {
	stmt_node *stmt;
	struct tag_stmtlist_node *next;
} stmtlist_node;

typedef enum {ST_EXPR, ST_IFELSE, ST_LOOP, ST_ITER, ST_LIST} stmt_t;
typedef struct tag_stmt_node {
	stmt_t type;
	union {
		expr_node *expr;
		ifelse_node *ifelse;
		loop_node *loop;
		iter_node *iter;
		stmtlist_node *stmtlist;
	};
} stmt_node;

#define AS_ST(arg) ((stmt_node *) (arg))
#define AS_EX(arg) ((expr_node *) (arg))
#define AS(arg, tp) ((tp *) (arg))
#define NEW_ST() malloc(sizeof(stmt_node))
#define NEW_EX() malloc(sizeof(expr_node))
#define NEW(arg) malloc(sizeof(arg))
#define MAKE_REF_BINOP(nd, tp, name, val) nd = NEW_EX(); \
	nd->type = EX_BINOP; \
	nd->binop = NEW(binop_node); \
	nd->binop->type = tp; \
	nd->binop->left = NEW_EX(); \
	nd->binop->left->type = EX_REF; \
	nd->binop->left->ref = NEW(ref_node); \
	nd->binop->left->ref->ident = name; \
	nd->binop->right = val
#define MAKE_IDX_BINOP(nd, tp, obj, idx, val) nd = NEW_EX(); \
	nd->type = EX_BINOP; \
	nd->binop = NEW(binop_node); \
	nd->binop->type = tp; \
	nd->binop->left = NEW_EX(); \
	nd->binop->left->type = EX_INDEX; \
	nd->binop->left->index = NEW(index_node); \
	nd->binop->left->index->expr = obj; \
	nd->binop->left->index->index = idx; \
	nd->binop->right = val

sol_object_t *sol_new_func(sol_state_t *, identlist_node *, stmt_node *);

#endif