#include "ast.h"
#include "parser.tab.h"

#include <stdarg.h>
#include <stdio.h>

void prlev(sol_state_t *state, int lev, const char *fmt, ...) {
	va_list vl;
	int i;

	for(i = 0; i < lev; i++) {
		sol_putchar(state, '|');
		sol_putchar(state, ' ');
	}
	va_start(vl, fmt);
	sol_vprintf(state, fmt, vl);
	va_end(vl);
	sol_putchar(state, '\n');
}

void prex( sol_state_t *, expr_node *, int);

void prst(sol_state_t *state, stmt_node *node, int lev) {
	if(!node) {
		prlev(state, lev, "<NULL>");
		return;
	}
	switch(node->type) {
		case ST_EXPR:
			prlev(state, lev, "Stmt<Expr>:");
			prex(state, node->expr, lev + 1);
			break;

		case ST_LIST:
			prlev(state, lev, "Stmt<List>:");
			stmtlist_node *cur = node->stmtlist;
			while(cur && cur->stmt) {
				prst(state, cur->stmt, lev + 1);
				cur = cur->next;
			}
			break;

		case ST_RET:
			prlev(state, lev, "Stmt<Ret>:");
			prex(state, node->ret->ret, lev + 1);
			break;

		case ST_CONT:
			prlev(state, lev, "Stmt<Continue>:");
			prex(state, node->cont->val, lev + 1);
			break;

		case ST_BREAK:
			prlev(state, lev, "Stmt<Break>:");
			prex(state, node->brk->val, lev + 1);
			break;
	}
}

void prex(sol_state_t *state, expr_node *node, int lev) {
	assoclist_node *cura;
	exprlist_node *cure;
	identlist_node *curi;
	if(!node) {
		prlev(state, lev, "<NULL>");
		return;
	}
	switch(node->type) {
		case EX_LIT:
			prlev(state, lev, "Literal:");
			lev++;
			switch(node->lit->type) {
				case LIT_INT:
					prlev(state, lev, "Int: %ld", node->lit->ival);
					break;

				case LIT_FLOAT:
					prlev(state, lev, "Float: %f", node->lit->fval);
					break;

				case LIT_STRING:
					prlev(state, lev, "String: %s", node->lit->str);
					break;

				case LIT_BUFFER:
					prlev(state, lev, "Buffer of %lu bytes:", LENGTH_OF(node->lit->buf));
					prlev(state, lev + 1, "%s", BYTES_OF(node->lit->buf));

				case LIT_NONE:
					prlev(state, lev, "None");
					break;
			}
			break;

		case EX_LISTGEN:
			prlev(state, lev, "ListGen:");
			cure = node->listgen->list;
			while(cure && cure->expr) {
				prex(state, cure->expr, lev + 1);
				cure = cure->next;
			}
			break;

		case EX_MAPGEN:
			prlev(state, lev, "MapGen:");
			lev++;
			cura = node->mapgen->map;
			while(cura && cura->item) {
				prlev(state, lev, "<Key>:");
				prex(state, cura->item->key, lev + 1);
				prlev(state, lev, "<Value>:");
				prex(state, cura->item->value, lev + 1);
				cura = cura->next;
			}
			break;

		case EX_BINOP:
			prlev(state, lev, "BinOp:");
			lev++;
			switch(node->binop->type) {
				case OP_ADD:
					prlev(state, lev, "Op: +");
					break;

				case OP_SUB:
					prlev(state, lev, "Op: -");
					break;

				case OP_MUL:
					prlev(state, lev, "Op: *");
					break;

				case OP_DIV:
					prlev(state, lev, "Op: /");
					break;

				case OP_MOD:
					prlev(state, lev, "Op: %");
					break;

				case OP_POW:
					prlev(state, lev, "Op: **");
					break;

				case OP_TBANG:
					prlev(state, lev, "Op: !!!");
					break;

				case OP_BAND:
					prlev(state, lev, "Op: &");
					break;

				case OP_BOR:
					prlev(state, lev, "Op: |");
					break;

				case OP_BXOR:
					prlev(state, lev, "Op: ^");
					break;

				case OP_LAND:
					prlev(state, lev, "Op: &&");
					break;

				case OP_LOR:
					prlev(state, lev, "Op: ||");
					break;

				case OP_EQUAL:
					prlev(state, lev, "Op: ==");
					break;

				case OP_NEQUAL:
					prlev(state, lev, "Op: !=");
					break;

				case OP_LESS:
					prlev(state, lev, "Op: <");
					break;

				case OP_GREATER:
					prlev(state, lev, "Op: >");
					break;

				case OP_LESSEQ:
					prlev(state, lev, "Op: <=");
					break;

				case OP_GREATEREQ:
					prlev(state, lev, "Op: >=");
					break;

				case OP_LSHIFT:
					prlev(state, lev, "Op: <<");
					break;

				case OP_RSHIFT:
					prlev(state, lev, "Op: >>");
					break;
			}
			prlev(state, lev, "Left:");
			prex(state, node->binop->left, lev + 1);
			prlev(state, lev, "Right:");
			prex(state, node->binop->right, lev + 1);
			break;

		case EX_UNOP:
			prlev(state, lev, "UnOp:");
			lev++;
			switch(node->unop->type) {
				case OP_NEG:
					prlev(state, lev, "Op: -");
					break;

				case OP_BNOT:
					prlev(state, lev, "Op: ~");
					break;

				case OP_LNOT:
					prlev(state, lev, "Op: !");
					break;

				case OP_LEN:
					prlev(state, lev, "Op: #");
					break;
			}
			prlev(state, lev, "Expr:");
			prex(state, node->unop->expr, lev + 1);
			break;

		case EX_INDEX:
			prlev(state, lev, "Index:");
			lev++;
			prlev(state, lev, "Expr:");
			prex(state, node->index->expr, lev + 1);
			prlev(state, lev, "Index:");
			prex(state, node->index->index, lev + 1);
			break;

		case EX_SETINDEX:
			prlev(state, lev, "SetIndex:");
			lev++;
			prlev(state, lev, "Expr:");
			prex(state, node->setindex->expr, lev + 1);
			prlev(state, lev, "Index:");
			prex(state, node->setindex->index, lev + 1);
			prlev(state, lev, "Value:");
			prex(state, node->setindex->value, lev + 1);
			break;

		case EX_ASSIGN:
			prlev(state, lev, "Assign:");
			lev++;
			prlev(state, lev, "Ident: %s", node->assign->ident);
			prlev(state, lev, "Value:");
			prex(state, node->assign->value, lev + 1);
			break;

		case EX_REF:
			prlev(state, lev, "Ref: %s", node->ref->ident);
			break;

		case EX_CALL:
			prlev(state, lev, "Call:");
			lev++;
			prlev(state, lev, "Expr:");
			prex(state, node->call->expr, lev + 1);
			prlev(state, lev, "Method: %s", node->call->method);
			prlev(state, lev, "Args:");
			cure = node->call->args;
			while(cure && cure->expr) {
				prex(state, cure->expr, lev + 1);
				cure = cure->next;
			}
			break;

		case EX_FUNCDECL:
			prlev(state, lev, "FuncDecl:");
			lev++;
			prlev(state, lev, "Name: %s", node->funcdecl->name);
			prlev(state, lev, "Params:");
			if(!node->funcdecl->params) {
				prlev(state, lev + 1, "<NULL>");
			} else {
				prlev(state, lev + 1, "Args:");
				curi = node->funcdecl->params->args;
				while(curi && curi->ident) {
					prlev(state, lev + 2, curi->ident);
					curi = curi->next;
				}
				prlev(state, lev + 1, "ClKeys:");
				curi = node->funcdecl->params->clkeys;
				while(curi && curi->ident) {
					prlev(state, lev + 2, curi->ident);
					curi = curi->next;
				}
				prlev(state, lev + 1, "ClValues:");
				cure = node->funcdecl->params->clvalues;
				while(cure && cure->expr) {
					prex(state, cure->expr, lev + 2);
					cure = cure->next;
				}
				prlev(state, lev + 1, "Rest: %s", node->funcdecl->params->rest);
			}
			prlev(state, lev, "Body:");
			prst(state, node->funcdecl->body, lev + 1);
			break;

		case EX_IFELSE:
			prlev(state, lev, "Expr<IfElse>:");
			lev++;
			prlev(state, lev, "Cond:");
			prex(state, node->ifelse->cond, lev + 1);
			prlev(state, lev, "IfTrue:");
			prst(state, node->ifelse->iftrue, lev + 1);
			prlev(state, lev, "IfFalse:");
			prst(state, node->ifelse->iffalse, lev + 1);
			break;

		case EX_LOOP:
			prlev(state, lev, "Expr<Loop>:");
			lev++;
			prlev(state, lev, "Cond:");
			prex(state, node->loop->cond, lev + 1);
			prlev(state, lev, "Loop:");
			prst(state, node->loop->loop, lev + 1);
			break;

		case EX_ITER:
			prlev(state, lev, "Expr<Iter>:");
			lev++;
			prlev(state, lev, "Var: %s", node->iter->var);
			prlev(state, lev, "Iter:");
			prex(state, node->iter->iter, lev + 1);
			prlev(state, lev, "Loop:");
			prst(state, node->iter->loop, lev + 1);
			break;
	}
}

void st_print(sol_state_t *state, stmt_node *stmt) {
	prst(state, stmt, 0);
}

void ex_print(sol_state_t *state, expr_node *expr) {
	prex(state, expr, 0);
}

/*int main(int argc, char **argv) {
	stmt_node *program = NULL;

	if(argc>1) yydebug = 1;

	if(yyparse(&program)) {
		printf("Syntax error (somewhere)\n");
		printf("Partial tree:\n");
		prst(state, program, 0);
		return 1;
	}

	prst(state, program, 0);
	return 0;
}*/

