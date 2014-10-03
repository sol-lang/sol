%{
#include "sol.h"
#include "ast.h"

#include <string.h>

#define YYSTYPE void *

%}

%define lr.type ielr

%token IF THEN ELSE
%token WHILE FOR IN DO
%token FUNC RETURN BREAK CONTINUE
%token END NONE
%token IDENT
%token INT FLOAT STRING
%token PLUS MINUS STAR SLASH DSTAR BAND BOR BXOR BNOT LAND LOR LNOT
%token ASSIGN ASSIGNPLUS ASSIGNMINUS ASSIGNSTAR ASSIGNSLASH ASSIGNDSTAR ASSIGNBAND ASSIGNBOR ASSIGNBXOR
%token EQUAL LESS GREATER LESSEQ GREATEREQ
%token LBRACE RBRACE LPAREN RPAREN LBRACKET RBRACKET DOT COLON SEMICOLON COMMA POUND

%parse-param {stmt_node **program}

%debug

%%

program:
  stmt { *program = AS_ST($1); }
;

stmt:
  expr { $$ = NEW_ST(); AS_ST($$)->type = ST_EXPR; AS_ST($$)->expr = $1; }
| IF expr THEN stmt END { $$ = NEW_ST(); AS_ST($$)->type = ST_IFELSE; AS_ST($$)->ifelse = NEW(ifelse_node); AS_ST($$)->ifelse->cond = $2; AS_ST($$)->ifelse->iftrue = $4; AS_ST($$)->ifelse->iffalse = NULL; }
| IF expr THEN stmt ELSE stmt END { $$ = NEW_ST(); AS_ST($$)->type = ST_IFELSE; AS_ST($$)->ifelse = NEW(ifelse_node); AS_ST($$)->ifelse->cond = $2; AS_ST($$)->ifelse->iftrue = $4; AS_ST($$)->ifelse->iffalse = $6; }
| WHILE expr DO stmt END { $$ = NEW_ST(); AS_ST($$)->type = ST_LOOP; AS_ST($$)->loop = NEW(loop_node); AS_ST($$)->loop->cond = $2; AS_ST($$)->loop->loop = $4; }
| FOR IDENT IN expr DO stmt END { $$ = NEW_ST(); AS_ST($$)->type = ST_ITER; AS_ST($$)->iter = NEW(iter_node); AS_ST($$)->iter->var = strdup($2); AS_ST($$)->iter->iter = $4; AS_ST($$)->iter->loop = $6; }
| RETURN expr { $$ = NEW_ST(); AS_ST($$)->type = ST_RET; AS_ST($$)->ret = NEW(ret_node); AS_ST($$)->ret->ret = $2; }
| RETURN { $$ = NEW_ST(); AS_ST($$)->type = ST_RET; AS_ST($$)->ret = NEW(ret_node); AS_ST($$)->ret->ret = NULL; }
| BREAK { $$ = NEW_ST(); AS_ST($$)->type = ST_BREAK; }
| CONTINUE { $$ = NEW_ST(); AS_ST($$)->type = ST_CONT; }
| stmt SEMICOLON { $$ = $1; }
| stmt_list { $$ = $1; }
;

stmt_list:
  stmt_list stmt {
	stmtlist_node *cur = AS_ST($1)->stmtlist;
	while(cur->next) cur = cur->next;
	cur->next = NEW(stmtlist_node);
	cur = cur->next;
	cur->stmt = $2;
	cur->next = NULL;
	$$ = $1;
  }
| stmt stmt {
	$$ = NEW_ST();
	AS_ST($$)->type = ST_LIST;
	AS_ST($$)->stmtlist = NEW(stmtlist_node);
	AS_ST($$)->stmtlist->stmt = $1;
	AS_ST($$)->stmtlist->next = NEW(stmtlist_node);
	AS_ST($$)->stmtlist->next->stmt = $2;
	AS_ST($$)->stmtlist->next->next = NULL;
  }
;

expr:
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
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = AS_EX($1)->index->expr;
    AS_EX($$)->setindex->index = AS_EX($1)->index->index;
    AS_EX($$)->setindex->value = $3;
    //ex_free(AS_EX($1));
}
| ex_index_expr ASSIGNPLUS expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = AS_EX($1)->index->expr;
    AS_EX($$)->setindex->index = AS_EX($1)->index->index;
    MAKE_IDX_BINOP(AS_EX($$)->setindex->value, OP_ADD, AS_EX($1)->index->expr, AS_EX($1)->index->index, $3);
    //ex_free(AS_EX($1));
}
| ex_index_expr ASSIGNMINUS expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = AS_EX($1)->index->expr;
    AS_EX($$)->setindex->index = AS_EX($1)->index->index;
    MAKE_IDX_BINOP(AS_EX($$)->setindex->value, OP_SUB, AS_EX($1)->index->expr, AS_EX($1)->index->index, $3);
    //ex_free(AS_EX($1));
}
| ex_index_expr ASSIGNSTAR expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = AS_EX($1)->index->expr;
    AS_EX($$)->setindex->index = AS_EX($1)->index->index;
    MAKE_IDX_BINOP(AS_EX($$)->setindex->value, OP_MUL, AS_EX($1)->index->expr, AS_EX($1)->index->index, $3);
    //ex_free(AS_EX($1));
}
| ex_index_expr ASSIGNSLASH expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = AS_EX($1)->index->expr;
    AS_EX($$)->setindex->index = AS_EX($1)->index->index;
    MAKE_IDX_BINOP(AS_EX($$)->setindex->value, OP_DIV, AS_EX($1)->index->expr, AS_EX($1)->index->index, $3);
    //ex_free(AS_EX($1));
}
| ex_index_expr ASSIGNDSTAR expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = AS_EX($1)->index->expr;
    AS_EX($$)->setindex->index = AS_EX($1)->index->index;
    MAKE_IDX_BINOP(AS_EX($$)->setindex->value, OP_POW, AS_EX($1)->index->expr, AS_EX($1)->index->index, $3);
    //ex_free(AS_EX($1));
}
| ex_index_expr ASSIGNBAND expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = AS_EX($1)->index->expr;
    AS_EX($$)->setindex->index = AS_EX($1)->index->index;
    MAKE_IDX_BINOP(AS_EX($$)->setindex->value, OP_BAND, AS_EX($1)->index->expr, AS_EX($1)->index->index, $3);
    //ex_free(AS_EX($1));
}
| ex_index_expr ASSIGNBOR expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = AS_EX($1)->index->expr;
    AS_EX($$)->setindex->index = AS_EX($1)->index->index;
    MAKE_IDX_BINOP(AS_EX($$)->setindex->value, OP_BOR, AS_EX($1)->index->expr, AS_EX($1)->index->index, $3);
    //ex_free(AS_EX($1));
}
| ex_index_expr ASSIGNBXOR expr {
    if(AS_EX($1)->type != EX_INDEX) {
        yyerror("Assigning to non-indexing expression");
        YYABORT;
    }
    $$ = NEW_EX();
    AS_EX($$)->type = EX_SETINDEX;
    AS_EX($$)->setindex = NEW(setindex_node);
    AS_EX($$)->setindex->expr = AS_EX($1)->index->expr;
    AS_EX($$)->setindex->index = AS_EX($1)->index->index;
    MAKE_IDX_BINOP(AS_EX($$)->setindex->value, OP_BXOR, AS_EX($1)->index->expr, AS_EX($1)->index->index, $3);
    //ex_free(AS_EX($1));
}
| logic_expr { $$ = $1; }
;

logic_expr:
  logic_expr LAND logic_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_LAND; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| logic_expr LOR logic_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_LOR; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| ulogic_expr { $$ = $1; }
;

ulogic_expr:
  LNOT ulogic_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_UNOP; AS_EX($$)->unop = NEW(unop_node); AS_EX($$)->unop->type = OP_LNOT; AS_EX($$)->unop->expr = $2; }
| rel_expr { $$ = $1; }
;

rel_expr:
  rel_expr EQUAL rel_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_EQUAL; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| rel_expr LESS rel_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_LESS; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| rel_expr GREATER rel_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_GREATER; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| rel_expr LESSEQ rel_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_LESSEQ; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| rel_expr GREATEREQ rel_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_GREATEREQ; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| term_expr { $$ = $1; }
;

term_expr:
  term_expr PLUS term_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_ADD; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| term_expr MINUS term_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_SUB; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| factor_expr { $$ = $1; }
;

factor_expr:
  factor_expr STAR factor_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_MUL; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| factor_expr SLASH factor_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_DIV; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| power_expr { $$ = $1; }
;

power_expr:
  power_expr DSTAR power_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_POW; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| binary_expr { $$ = $1; }
;

binary_expr:
  ubinary_expr BAND ubinary_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_BAND; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| ubinary_expr BOR ubinary_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_BOR; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
| ubinary_expr BXOR ubinary_expr { $$ = NEW_EX(); AS_EX($$)->type = EX_BINOP; AS_EX($$)->binop = NEW(binop_node); AS_EX($$)->binop->type = OP_BXOR; AS_EX($$)->binop->left = $1; AS_EX($$)->binop->right = $3; }
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
  call_expr LPAREN expr_list RPAREN { $$ = NEW_EX(); AS_EX($$)->type = EX_CALL; AS_EX($$)->call = NEW(call_node); AS_EX($$)->call->expr = $1; AS_EX($$)->call->args = $3; }
| funcdecl_expr { $$ = $1; }
;

funcdecl_expr:
  FUNC IDENT LPAREN ident_list RPAREN opt_stmt END {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_FUNCDECL;
	AS_EX($$)->funcdecl = NEW(funcdecl_node);
	AS_EX($$)->funcdecl->name = $2;
	AS_EX($$)->funcdecl->args = $4;
	AS_EX($$)->funcdecl->body = $6;
}
| FUNC LPAREN ident_list RPAREN opt_stmt END {
	$$ = NEW_EX();
	AS_EX($$)->type = EX_FUNCDECL;
	AS_EX($$)->funcdecl = NEW(funcdecl_node);
	AS_EX($$)->funcdecl->name = NULL;
	AS_EX($$)->funcdecl->args = $3;
	AS_EX($$)->funcdecl->body = $5;
}
| index_expr { $$ = $1; }
;

opt_stmt:
  stmt { $$ = $1; }
| /* empty */ { $$ = NULL; }
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
| STRING { $$ = NEW_EX(); AS_EX($$)->type = EX_LIT; AS_EX($$)->lit = NEW(lit_node); AS_EX($$)->lit->type = LIT_STRING; AS_EX($$)->lit->str = $1; }
| NONE { $$ = NEW_EX(); AS_EX($$)->type = EX_LIT; AS_EX($$)->lit = NEW(lit_node); AS_EX($$)->lit->type = LIT_NONE; }
| gen_expr { $$ = $1; }
;

gen_expr:
  LBRACKET expr_list RBRACKET { $$ = NEW_EX(); AS_EX($$)->type = EX_LISTGEN; AS_EX($$)->listgen = NEW(listgen_node); AS_EX($$)->listgen->list = $2; }
| LBRACE assoc_list RBRACE { $$ = NEW_EX(); AS_EX($$)->type = EX_MAPGEN; AS_EX($$)->mapgen = NEW(mapgen_node); AS_EX($$)->mapgen->map = $2; }
| paren_expr { $$ = $1; }
;

paren_expr:
  LPAREN expr RPAREN { $$ = $2; }
;

expr_list:
  /*empty*/ { $$ = NULL; }
| expr {
	$$ = NEW(exprlist_node);
	AS($$, exprlist_node)->expr = $1;
	AS($$, exprlist_node)->next = NULL;
}
| expr_list expr {
	exprlist_node *cur = $1;
	while(cur->next) cur = cur->next;
	cur->next = NEW(exprlist_node);
	cur = cur->next;
	cur->expr = $2;
	cur->next = NULL;
	$$ = $1;
}
| expr_list COMMA expr {
	exprlist_node *cur = $1;
	while(cur->next) cur = cur->next;
	cur->next = NEW(exprlist_node);
	cur = cur->next;
	cur->expr = $3;
	cur->next = NULL;
	$$ = $1;
}
;

ident_list:
  /*empty*/ { $$ = NULL; }
| IDENT {
	$$ = NEW(identlist_node);
	AS($$, identlist_node)->ident = $1;
	AS($$, identlist_node)->next = NULL;
}
| ident_list IDENT {
	identlist_node *cur = $1;
	while(cur->next) cur = cur->next;
	cur->next = NEW(identlist_node);
	cur = cur->next;
	cur->ident = $2;
	cur->next = NULL;
	$$ = $1;
}
| ident_list COMMA IDENT {
	identlist_node *cur = $1;
	while(cur->next) cur = cur->next;
	cur->next = NEW(identlist_node);
	cur = cur->next;
	cur->ident = $3;
	cur->next = NULL;
	$$ = $1;
}
;

assoc_list:
  /*empty*/ { $$ = NULL; }
| assoc_item {
	$$ = NEW(assoclist_node);
	AS($$, assoclist_node)->item = $1;
	AS($$, assoclist_node)->next = NULL;
}
| assoc_list assoc_item {
	assoclist_node *cur = $1;
	while(cur->next) cur = cur->next;
	cur->next = NEW(assoclist_node);
	cur = cur->next;
	cur->item = $2;
	cur->next = NULL;
	$$ = $1;
}
| assoc_list COMMA assoc_item {
	assoclist_node *cur = $1;
	while(cur->next) cur = cur->next;
	cur->next = NEW(assoclist_node);
	cur = cur->next;
	cur->item = $3;
	cur->next = NULL;
	$$ = $1;
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

%%

// TODO
