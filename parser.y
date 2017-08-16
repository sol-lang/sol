%{
#include "sol.h"
#include "ast.h"

#include <string.h>

#define YYSTYPE void *
#define YYLTYPE loc_t

/* Hacks */
#define first_line line
#define last_line line
#define first_column col
#define last_column col

int yylex(YYSTYPE *, loc_t *);
void yyerror(loc_t *, stmt_node **, char *);

%}

%define lr.type ielr
%define api.pure full

%token IF THEN ELSEIF ELSE
%token WHILE FOR IN DO
%token FUNC MACRO LAMBDA RETURN BREAK CONTINUE
%token END NONE
%token IDENT
%token INT FLOAT STRING
%token PLUS MINUS STAR SLASH PERCENT DSTAR BAND BOR BXOR BNOT LAND LOR LNOT
%token ASSIGN ASSIGNPLUS ASSIGNMINUS ASSIGNSTAR ASSIGNSLASH ASSIGNDSTAR ASSIGNBAND ASSIGNBOR ASSIGNBXOR
%token EQUAL NEQUAL LESS GREATER LESSEQ GREATEREQ RSHIFT LSHIFT
%token LBRACE RBRACE BLPAREN LPAREN RPAREN LBRACKET RBRACKET DOT COLON SEMICOLON COMMA POUND
%token TBANG

%parse-param {stmt_node **program}

%debug
%locations
%initial-action {
	@$.first_line = 1; @$.first_column = 0;
	@$.last_line = 1; @$.last_column = 1;
}

%%

program:
  stmt_list { *program = AS_ST($1); }
;

stmt_list:
  stmt_list stmt {
	stmtlist_node *cur = AS_ST($1)->stmtlist;
	while(cur->next) cur = cur->next;
	if(cur->stmt) {
        cur->next = NEW(stmtlist_node);
        cur = cur->next;
	}
    cur->stmt = $2;
    cur->next = NULL;
    $$ = $1;
  }
| /* empty */ {
    $$ = NEW_ST();
    AS_ST($$)->type = ST_LIST;
    AS_ST($$)->stmtlist = NEW(stmtlist_node);
    AS_ST($$)->stmtlist->stmt = NULL;
    AS_ST($$)->stmtlist->next = NULL;
}
;

stmt:
  expr { $$ = NEW_ST(); SET_LOC(AS_ST($$), @$); AS_ST($$)->type = ST_EXPR; AS_ST($$)->expr = $1; }
| RETURN expr { $$ = NEW_ST(); SET_LOC(AS_ST($$), @$); AS_ST($$)->type = ST_RET; AS_ST($$)->ret = NEW(ret_node); AS_ST($$)->ret->ret = $2; }
| RETURN { $$ = NEW_ST(); SET_LOC(AS_ST($$), @$); AS_ST($$)->type = ST_RET; AS_ST($$)->ret = NEW(ret_node); AS_ST($$)->ret->ret = NULL; }
| BREAK { $$ = NEW_ST(); SET_LOC(AS_ST($$), @$); AS_ST($$)->type = ST_BREAK; AS_ST($$)->brk = NEW(break_node); AS_ST($$)->brk->val = NULL;}
| BREAK expr { $$ = NEW_ST(); SET_LOC(AS_ST($$), @$); AS_ST($$)->type = ST_BREAK; AS_ST($$)->brk = NEW(break_node); AS_ST($$)->brk->val = $2; }
| CONTINUE { $$ = NEW_ST(); SET_LOC(AS_ST($$), @$); AS_ST($$)->type = ST_CONT; AS_ST($$)->cont = NEW(cont_node); AS_ST($$)->cont->val = NULL; }
| CONTINUE expr { $$ = NEW_ST(); SET_LOC(AS_ST($$), @$); AS_ST($$)->type = ST_CONT; AS_ST($$)->cont = NEW(cont_node); AS_ST($$)->cont->val = $2; }
| stmt SEMICOLON { $$ = $1; }
;

expr:
  control_expr { $$ = $1; }
;

control_expr:
  IF expr THEN stmt_list if_termin {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_IFELSE;
	AS_EX($$)->ifelse = NEW(ifelse_node);
	AS_EX($$)->ifelse->cond = $2;
	AS_EX($$)->ifelse->iftrue = $4;
	AS_EX($$)->ifelse->iffalse = $5;
}
| WHILE expr DO stmt_list END {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_LOOP;
	AS_EX($$)->loop = NEW(loop_node);
	AS_EX($$)->loop->cond = $2;
	AS_EX($$)->loop->loop = $4;
}
| FOR IDENT IN expr DO stmt_list END {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_ITER;
	AS_EX($$)->iter = NEW(iter_node);
	AS_EX($$)->iter->var = $2;
	AS_EX($$)->iter->iter = $4;
	AS_EX($$)->iter->loop = $6;
}
| assign_expr { $$ = $1; }
;

if_termin:
	ELSEIF expr THEN stmt_list if_termin {
		$$ = NEW_ST();
		AS_ST($$)->type = ST_EXPR;
		AS_ST($$)->expr = NEW_EX();
		AS_ST($$)->expr->type = EX_IFELSE;
		AS_ST($$)->expr->ifelse = NEW(ifelse_node);
		AS_ST($$)->expr->ifelse->cond = $2;
		AS_ST($$)->expr->ifelse->iftrue = $4;
		AS_ST($$)->expr->ifelse->iffalse = $5;
	}
|	ELSE stmt_list END {
		$$ = $2;
	}
|	END { $$ = NULL; }
;

assign_expr:
  IDENT ASSIGN expr { $$ = NEW_EX(); AS_EX($$)->type = EX_ASSIGN; AS_EX($$)->assign = NEW(assign_node); AS_EX($$)->assign->ident = $1; AS_EX($$)->assign->value = $3; }
| IDENT ASSIGNPLUS expr {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_ASSIGN;
	AS_EX($$)->assign = NEW(assign_node);
	AS_EX($$)->assign->ident = $1;
	MAKE_REF_BINOP(AS_EX($$)->assign->value, OP_ADD, $1, $3);
  }
| IDENT ASSIGNMINUS expr {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_ASSIGN;
	AS_EX($$)->assign = NEW(assign_node);
	AS_EX($$)->assign->ident = $1;
	MAKE_REF_BINOP(AS_EX($$)->assign->value, OP_SUB, $1, $3);
  }
| IDENT ASSIGNSTAR expr {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_ASSIGN;
	AS_EX($$)->assign = NEW(assign_node);
	AS_EX($$)->assign->ident = $1;
	MAKE_REF_BINOP(AS_EX($$)->assign->value, OP_MUL, $1, $3);
  }
| IDENT ASSIGNSLASH expr {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_ASSIGN;
	AS_EX($$)->assign = NEW(assign_node);
	AS_EX($$)->assign->ident = $1;
    MAKE_REF_BINOP(AS_EX($$)->assign->value, OP_DIV, $1, $3);
  }
| IDENT ASSIGNDSTAR expr {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_ASSIGN;
	AS_EX($$)->assign = NEW(assign_node);
	AS_EX($$)->assign->ident = $1;
	MAKE_REF_BINOP(AS_EX($$)->assign->value, OP_POW, $1, $3);
  }
| IDENT ASSIGNBAND expr {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_ASSIGN;
	AS_EX($$)->assign = NEW(assign_node);
	AS_EX($$)->assign->ident = $1;
	MAKE_REF_BINOP(AS_EX($$)->assign->value, OP_BAND, $1, $3);
  }
| IDENT ASSIGNBOR expr {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_ASSIGN;
	AS_EX($$)->assign = NEW(assign_node);
	AS_EX($$)->assign->ident = $1;
	MAKE_REF_BINOP(AS_EX($$)->assign->value, OP_BOR, $1, $3);
  }
| IDENT ASSIGNBXOR expr {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_ASSIGN;
	AS_EX($$)->assign = NEW(assign_node);
	AS_EX($$)->assign->ident = $1;
	MAKE_REF_BINOP(AS_EX($$)->assign->value, OP_BXOR, $1, $3);
  }
| ex_index_expr ASSIGN expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror(&@$, NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = ex_copy(AS_EX($1)->index->expr);
    AS_EX($$)->setindex->index = ex_copy(AS_EX($1)->index->index);
    AS_EX($$)->setindex->value = $3;
    ex_free(AS_EX($1));
}
| ex_index_expr ASSIGNPLUS expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror(&@$, NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = ex_copy(AS_EX($1)->index->expr);
    AS_EX($$)->setindex->index = ex_copy(AS_EX($1)->index->index);
    MAKE_IDX_BINOP(AS_EX($$)->setindex->value, OP_ADD, AS_EX($1)->index->expr, AS_EX($1)->index->index, $3);
    ex_free(AS_EX($1));
}
| ex_index_expr ASSIGNMINUS expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror(&@$, NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = ex_copy(AS_EX($1)->index->expr);
    AS_EX($$)->setindex->index = ex_copy(AS_EX($1)->index->index);
    MAKE_IDX_BINOP(AS_EX($$)->setindex->value, OP_SUB, AS_EX($1)->index->expr, AS_EX($1)->index->index, $3);
    ex_free(AS_EX($1));
}
| ex_index_expr ASSIGNSTAR expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror(&@$, NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = ex_copy(AS_EX($1)->index->expr);
    AS_EX($$)->setindex->index = ex_copy(AS_EX($1)->index->index);
    MAKE_IDX_BINOP(AS_EX($$)->setindex->value, OP_MUL, AS_EX($1)->index->expr, AS_EX($1)->index->index, $3);
    ex_free(AS_EX($1));
}
| ex_index_expr ASSIGNSLASH expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror(&@$, NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = ex_copy(AS_EX($1)->index->expr);
    AS_EX($$)->setindex->index = ex_copy(AS_EX($1)->index->index);
    MAKE_IDX_BINOP(AS_EX($$)->setindex->value, OP_DIV, AS_EX($1)->index->expr, AS_EX($1)->index->index, $3);
    ex_free(AS_EX($1));
}
| ex_index_expr ASSIGNDSTAR expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror(&@$, NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = ex_copy(AS_EX($1)->index->expr);
    AS_EX($$)->setindex->index = ex_copy(AS_EX($1)->index->index);
    MAKE_IDX_BINOP(AS_EX($$)->setindex->value, OP_POW, AS_EX($1)->index->expr, AS_EX($1)->index->index, $3);
    ex_free(AS_EX($1));
}
| ex_index_expr ASSIGNBAND expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror(&@$, NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = ex_copy(AS_EX($1)->index->expr);
    AS_EX($$)->setindex->index = ex_copy(AS_EX($1)->index->index);
    MAKE_IDX_BINOP(AS_EX($$)->setindex->value, OP_BAND, AS_EX($1)->index->expr, AS_EX($1)->index->index, $3);
    ex_free(AS_EX($1));
}
| ex_index_expr ASSIGNBOR expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror(&@$, NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = ex_copy(AS_EX($1)->index->expr);
    AS_EX($$)->setindex->index = ex_copy(AS_EX($1)->index->index);
    MAKE_IDX_BINOP(AS_EX($$)->setindex->value, OP_BOR, AS_EX($1)->index->expr, AS_EX($1)->index->index, $3);
    ex_free(AS_EX($1));
}
| ex_index_expr ASSIGNBXOR expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror(&@$, NULL, "Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = ex_copy(AS_EX($1)->index->expr);
    AS_EX($$)->setindex->index = ex_copy(AS_EX($1)->index->index);
    MAKE_IDX_BINOP(AS_EX($$)->setindex->value, OP_BXOR, AS_EX($1)->index->expr, AS_EX($1)->index->index, $3);
    ex_free(AS_EX($1));
}
| logic_expr { $$ = $1; }
;

logic_expr:
  logic_expr LAND ulogic_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_LAND; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| logic_expr LOR ulogic_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_LOR; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| ulogic_expr { $$ = $1; }
;

ulogic_expr:
  LNOT ulogic_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_UNOP; AS_EX($$)->unop = NEW(unop_node); AS_EX($$)->unop->type = OP_LNOT; AS_EX($$)->unop->expr = $2; }
| rel_expr { $$ = $1; }
;

rel_expr:
  term_expr EQUAL rel_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_EQUAL; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| term_expr NEQUAL rel_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_NEQUAL; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| term_expr LESS rel_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_LESS; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| term_expr GREATER rel_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_GREATER; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| term_expr LESSEQ rel_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_LESSEQ; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| term_expr GREATEREQ rel_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_GREATEREQ; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| term_expr { $$ = $1; }
;

term_expr:
  term_expr PLUS factor_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_ADD; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| term_expr MINUS factor_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_SUB; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| factor_expr { $$ = $1; }
;

factor_expr:
  factor_expr STAR power_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_MUL; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| factor_expr SLASH power_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_DIV; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| factor_expr PERCENT power_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_MOD; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| power_expr { $$ = $1; }
;

power_expr:
  tbang_expr DSTAR power_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_POW; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| tbang_expr { $$ = $1; }
;

tbang_expr:
  binary_expr TBANG tbang_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_TBANG; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| binary_expr { $$ = $1; }
;


binary_expr:
  binary_expr BAND binary_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_BAND; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| binary_expr BOR binary_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_BOR; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| binary_expr BXOR binary_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_BXOR; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| binary_expr LSHIFT binary_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_LSHIFT; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| binary_expr RSHIFT binary_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_RSHIFT; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| ubinary_expr { $$ = $1; }
;

ubinary_expr:
  BNOT ubinary_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_UNOP; AS_EX($$)->unop = NEW(unop_node); AS_EX($$)->unop->type = OP_BNOT; AS_EX($$)->unop->expr = $2; }
| ulen_expr { $$ = $1; }
;

ulen_expr:
  POUND ulen_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_UNOP; AS_EX($$)->unop = NEW(unop_node); AS_EX($$)->unop->type = OP_LEN; AS_EX($$)->unop->expr = $2; }
| call_expr { $$ = $1; }
;

call_expr:
  call_expr LPAREN expr_list RPAREN { $$ = NEW_EX(); AS_EX($$)->type = EX_CALL; AS_EX($$)->call = NEW(call_node); AS_EX($$)->call->expr = $1; AS_EX($$)->call->args = $3; AS_EX($$)->call->method = NULL; }
| call_expr COLON IDENT LPAREN expr_list RPAREN {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_CALL;
	AS_EX($$)->call = NEW(call_node);
	AS_EX($$)->call->expr = $1;
	AS_EX($$)->call->args = $5;
	AS_EX($$)->call->method = $3;
}
| funcdecl_expr { $$ = $1; }
;

funcdecl_expr:
  FUNC IDENT any_lparen param_list RPAREN maybe_anno stmt_list END {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_FUNCDECL;
	AS_EX($$)->funcdecl = NEW(funcdecl_node);
	AS_EX($$)->funcdecl->name = $2;
	AS_EX($$)->funcdecl->params = $4;
	AS_EX($$)->funcdecl->anno = $6;
	AS_EX($$)->funcdecl->body = $7;
	AS_EX($$)->funcdecl->flags = 0;
}
| FUNC any_lparen param_list RPAREN maybe_anno stmt_list END {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_FUNCDECL;
	AS_EX($$)->funcdecl = NEW(funcdecl_node);
	AS_EX($$)->funcdecl->name = NULL;
	AS_EX($$)->funcdecl->params = $3;
	AS_EX($$)->funcdecl->anno = $5;
	AS_EX($$)->funcdecl->body = $6;
	AS_EX($$)->funcdecl->flags = 0;
}
| MACRO IDENT any_lparen param_list RPAREN maybe_anno stmt_list END {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_FUNCDECL;
	AS_EX($$)->funcdecl = NEW(funcdecl_node);
	AS_EX($$)->funcdecl->name = $2;
	AS_EX($$)->funcdecl->params = $4;
	AS_EX($$)->funcdecl->anno = $6;
	AS_EX($$)->funcdecl->body = $7;
	AS_EX($$)->funcdecl->flags = FUNC_IS_MACRO;
}
| MACRO any_lparen param_list RPAREN maybe_anno stmt_list END {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_FUNCDECL;
	AS_EX($$)->funcdecl = NEW(funcdecl_node);
	AS_EX($$)->funcdecl->name = NULL;
	AS_EX($$)->funcdecl->params = $3;
	AS_EX($$)->funcdecl->anno = $5;
	AS_EX($$)->funcdecl->body = $6;
	AS_EX($$)->funcdecl->flags = FUNC_IS_MACRO;
}
| LAMBDA any_lparen param_list RPAREN maybe_anno expr END {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_FUNCDECL;
	AS_EX($$)->funcdecl = NEW(funcdecl_node);
	AS_EX($$)->funcdecl->name = NULL;
	AS_EX($$)->funcdecl->params = $3;
	AS_EX($$)->funcdecl->anno = $5;
	AS_EX($$)->funcdecl->body = NEW_ST();
	AS_EX($$)->funcdecl->body->type = ST_RET;
	AS_EX($$)->funcdecl->body->ret = NEW(ret_node);
	AS_EX($$)->funcdecl->body->ret->ret = $6;
	AS_EX($$)->funcdecl->flags = 0;
}
| MACRO LAMBDA any_lparen param_list RPAREN maybe_anno expr END {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_FUNCDECL;
	AS_EX($$)->funcdecl = NEW(funcdecl_node);
	AS_EX($$)->funcdecl->name = NULL;
	AS_EX($$)->funcdecl->params = $4;
	AS_EX($$)->funcdecl->anno = $6;
	AS_EX($$)->funcdecl->body = NEW_ST();
	AS_EX($$)->funcdecl->body->type = ST_RET;
	AS_EX($$)->funcdecl->body->ret = NEW(ret_node);
	AS_EX($$)->funcdecl->body->ret->ret = $7;
	AS_EX($$)->funcdecl->flags = FUNC_IS_MACRO;
}
| index_expr { $$ = $1; }
;

index_expr:
  expr LBRACKET expr RBRACKET { $$ = NEW_EX(); AS_EX($$)->type = EX_INDEX; AS_EX($$)->index = NEW(index_node); AS_EX($$)->index->expr = $1; AS_EX($$)->index->index = $3; }
| expr DOT IDENT {
    $$ = NEW_EX();
    AS_EX($$)->type = EX_INDEX;
    AS_EX($$)->index = NEW(index_node);
    AS_EX($$)->index->expr = $1;
    AS_EX($$)->index->index = NEW_EX();
    AS_EX($$)->index->index->type = EX_LIT;
    AS_EX($$)->index->index->lit = NEW(lit_node);
    AS_EX($$)->index->index->lit->type = LIT_STRING;
    AS_EX($$)->index->index->lit->str = $3;
}
| ref_expr { $$ = $1; }
;

ex_index_expr:
  expr LBRACKET expr RBRACKET { $$ = NEW_EX(); AS_EX($$)->type = EX_INDEX; AS_EX($$)->index = NEW(index_node); AS_EX($$)->index->expr = $1; AS_EX($$)->index->index = $3; }
| expr DOT IDENT {
    $$ = NEW_EX();
    AS_EX($$)->type = EX_INDEX;
    AS_EX($$)->index = NEW(index_node);
    AS_EX($$)->index->expr = $1;
    AS_EX($$)->index->index = NEW_EX();
    AS_EX($$)->index->index->type = EX_LIT;
    AS_EX($$)->index->index->lit = NEW(lit_node);
    AS_EX($$)->index->index->lit->type = LIT_STRING;
    AS_EX($$)->index->index->lit->str = $3;
}
;

ref_expr:
  IDENT { $$ = NEW_EX(); AS_EX($$)->type = EX_REF; AS_EX($$)->ref = NEW(ref_node); AS_EX($$)->ref->ident = $1; }
| lit_expr { $$ = $1; }
;

lit_expr:
  INT { $$ = NEW_EX(); AS_EX($$)->type = EX_LIT; AS_EX($$)->lit = NEW(lit_node); AS_EX($$)->lit->type = LIT_INT; AS_EX($$)->lit->ival = *AS($1, long); free($1); }
| MINUS INT { $$ = NEW_EX(); AS_EX($$)->type = EX_LIT; AS_EX($$)->lit = NEW(lit_node); AS_EX($$)->lit->type = LIT_INT; AS_EX($$)->lit->ival = -(*AS($2, long)); free($2); }
| FLOAT { $$ = NEW_EX(); AS_EX($$)->type = EX_LIT; AS_EX($$)->lit = NEW(lit_node); AS_EX($$)->lit->type = LIT_FLOAT; AS_EX($$)->lit->fval = *AS($1, double); free($1); }
| STRING { $$ = NEW_EX(); AS_EX($$)->type = EX_LIT; AS_EX($$)->lit = NEW(lit_node); AS_EX($$)->lit->type = LIT_BUFFER; AS_EX($$)->lit->buf = $1; }
| NONE { $$ = NEW_EX(); AS_EX($$)->type = EX_LIT; AS_EX($$)->lit = NEW(lit_node); AS_EX($$)->lit->type = LIT_NONE; }
| gen_expr { $$ = $1; }
;

gen_expr:
  LBRACKET expr_list RBRACKET { $$ = NEW_EX(); AS_EX($$)->type = EX_LISTGEN; AS_EX($$)->listgen = NEW(listgen_node); AS_EX($$)->listgen->list = $2; }
| LBRACE assoc_list RBRACE { $$ = NEW_EX(); AS_EX($$)->type = EX_MAPGEN; AS_EX($$)->mapgen = NEW(mapgen_node); AS_EX($$)->mapgen->map = $2; }
| paren_expr { $$ = $1; }
;

paren_expr:
  any_lparen expr RPAREN { $$ = $2; }
;

expr_list:
  /*empty*/ { $$ = NULL; }
| expr {
	$$ = NEW(exprlist_node);
	AS($$, exprlist_node)->expr = $1;
	AS($$, exprlist_node)->next = NULL;
}
| expr_list COMMA { $$ = $1; }
| expr_list expr {
	exprlist_node *cur = $1;
	if(!cur) {
		cur = NEW(exprlist_node);
		cur->expr = $2;
		cur->next = NULL;
		$$ = cur;
	} else {
		while(cur->next) cur = cur->next;
		cur->next = NEW(exprlist_node);
		cur = cur->next;
		cur->expr = $2;
		cur->next = NULL;
		$$ = $1;
	}
}
;

ident_list:
  /*empty*/ { $$ = NULL; }
| IDENT {
	$$ = NEW(identlist_node);
	AS($$, identlist_node)->ident = $1;
	AS($$, identlist_node)->next = NULL;
}
| ident_list COMMA { $$ = $1; }
| ident_list IDENT {
	identlist_node *cur = $1;
	if(!cur) {
		cur = NEW(identlist_node);
		cur->ident = $2;
		cur->next = NULL;
		$$ = cur;
	} else {
		while(cur->next) cur = cur->next;
		cur->next = NEW(identlist_node);
		cur = cur->next;
		cur->ident = $2;
		cur->next = NULL;
		$$ = $1;
	}
}
;

param_list:
  /*empty*/ { $$ = NULL; }
| param_list IDENT ASSIGN expr {
	paramlist_node *pl = $1;
	identlist_node *curk;
	exprlist_node *curv;
	if(!pl) {
		pl = NEW(paramlist_node);
		pl->args = NULL;
		pl->annos = NULL;
		pl->clkeys = NULL;
		pl->clvalues = NULL;
		pl->rest = NULL;
	}
	if(!pl->clkeys) {
		pl->clkeys = NEW(identlist_node);
		curk = pl->clkeys;
		pl->clvalues = NEW(exprlist_node);
		curv = pl->clvalues;
	} else {
		curk = pl->clkeys;
		curv = pl->clvalues;
		while(curk->next) {
			curk = curk->next;
			curv = curv->next;
		}
		curk->next = NEW(identlist_node);
		curk = curk->next;
		curv->next = NEW(exprlist_node);
		curv = curv->next;
	}
	curk->ident = $2;
	curk->next = NULL;
	curv->expr = $4;
	curv->next = NULL;
	$$ = pl;
}
| param_list STAR IDENT {
	paramlist_node *pl = $1;
	if(!pl) {
		pl = NEW(paramlist_node);
		pl->args = NULL;
		pl->annos = NULL;
		pl->clkeys = NULL;
		pl->clvalues = NULL;
		pl->rest = NULL;
	}
	pl-> rest = $3;
	$$ = pl;
}
| param_list IDENT maybe_anno {
	paramlist_node *pl = $1;
	identlist_node *cura;
	exprlist_node *curn;
	if(!pl) {
		pl = NEW(paramlist_node);
		pl->args = NULL;
		pl->annos = NULL;
		pl->clkeys = NULL;
		pl->clvalues = NULL;
		pl->rest = NULL;
	}
	if(!pl->args) {
		pl->args = NEW(identlist_node);
		cura = pl->args;
		pl->annos = NEW(exprlist_node);
		curn = pl->annos;
	} else {
		cura = pl->args;
		curn = pl->annos;
		while(cura->next) {
			cura = cura->next;
			curn = curn->next;
		}
		cura->next = NEW(identlist_node);
		cura = cura->next;
		curn->next = NEW(exprlist_node);
		curn = curn->next;
	}
	cura->ident = $2;
	cura->next = NULL;
	curn->expr = $3;
	curn->next = NULL;
	$$ = pl;
}
| param_list COMMA { $$ = $1; }
;

assoc_list:
  /*empty*/ { $$ = NULL; }
| assoc_item {
	$$ = NEW(assoclist_node);
	AS($$, assoclist_node)->item = $1;
	AS($$, assoclist_node)->next = NULL;
}
| assoc_list COMMA { $$ = $1; }
| assoc_list assoc_item {
	assoclist_node *cur = $1;
	if(!cur) {
		cur = NEW(assoclist_node);
		cur->item = $2;
		cur->next = NULL;
		$$ = cur;
	} else {
		while(cur->next) cur = cur->next;
		cur->next = NEW(assoclist_node);
		cur = cur->next;
		cur->item = $2;
		cur->next = NULL;
		$$ = $1;
	}
}
;

assoc_item:
  LBRACKET expr RBRACKET ASSIGN expr {
	$$ = NEW(associtem_node);
	AS($$, associtem_node)->key = $2;
	AS($$, associtem_node)->value = $5;
}
| IDENT ASSIGN expr {
	$$ = NEW(associtem_node);
	AS($$, associtem_node)->key = NEW_EX();
	AS($$, associtem_node)->key->type = EX_LIT;
	AS($$, associtem_node)->key->lit = NEW(lit_node);
	AS($$, associtem_node)->key->lit->type = LIT_STRING;
	AS($$, associtem_node)->key->lit->str = $1;
	AS($$, associtem_node)->value = $3;
}
;

any_lparen:
  LPAREN
| BLPAREN
;

maybe_anno:
  COLON expr { $$ = $2; }
| /* empty */ { $$ = NULL; }
;

%%

// TODO
