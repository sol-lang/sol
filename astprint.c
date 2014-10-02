#include "ast.h"
#include "parser.tab.h"

#include <stdarg.h>
#include <stdio.h>

void prlev(int lev, const char *fmt, ...) {
	va_list vl;
	int i;

	for(i = 0; i < lev; i++) putchar(' ');
	va_start(vl, fmt);
	vprintf(fmt, vl);
	va_end(vl);
	putchar('\n');
}

void prex(expr_node *, int);

void prst(stmt_node *node, int lev) {
	if(!node) {
		prlev(lev, "<NULL>");
		return;
	}
	switch(node->type) {
		case ST_EXPR:
			prlev(lev, "Stmt<Expr>:");
			prex(node->expr, lev+1);
			break;

		case ST_IFELSE:
			prlev(lev, "Stmt<IfElse>:");
			lev++;
			prlev(lev, "Cond:");
			prex(node->ifelse->cond, lev+1);
			prlev(lev, "IfTrue:");
			prst(node->ifelse->iftrue, lev+1);
			prlev(lev, "IfFalse:");
			prst(node->ifelse->iffalse, lev+1);
			break;

		case ST_LOOP:
			prlev(lev, "Stmt<Loop>:");
			lev++;
			prlev(lev, "Cond:");
			prex(node->loop->cond, lev+1);
			prlev(lev, "Loop:");
			prst(node->loop->loop, lev+1);
			break;

		case ST_ITER:
			prlev(lev, "Stmt<Iter>:");
			lev++;
			prlev(lev, "Var: %s", node->iter->var);
			prlev(lev, "Iter:");
			prex(node->iter->iter, lev+1);
			prlev(lev, "Loop:");
			prst(node->iter->loop, lev+1);
			break;

		case ST_LIST:
			prlev(lev, "Stmt<List>:");
			stmtlist_node *cur = node->stmtlist;
			while(cur && cur->stmt) {
				prst(cur->stmt, lev+1);
				cur = cur->next;
			}
			break;

        case ST_RET:
            prlev(lev, "Stmt<Ret>:");
            prex(node->ret->ret, lev+1);
            break;

        case ST_CONT:
            prlev(lev, "Stmt<Continue>");
            break;

        case ST_BREAK:
            prlev(lev, "Stmt<Break>");
            break;
	}
}

void prex(expr_node *node, int lev) {
	assoclist_node *cura;
	exprlist_node *cure;
	identlist_node *curi;
	if(!node) {
		prlev(lev, "<NULL>");
		return;
	}
	switch(node->type) {
		case EX_LIT:
			prlev(lev, "Literal:");
			lev++;
			switch(node->lit->type) {
				case LIT_INT:
					prlev(lev, "Int: %ld", node->lit->ival);
					break;

				case LIT_FLOAT:
					prlev(lev, "Float: %f", node->lit->fval);
					break;

				case LIT_STRING:
					prlev(lev, "String: %s", node->lit->str);
					break;
			}
			break;

		case EX_LISTGEN:
			prlev(lev, "ListGen:");
			cure = node->listgen->list;
			while(cure && cure->expr) {
				prex(cure->expr, lev+1);
				cure = cure->next;
			}
			break;

		case EX_MAPGEN:
			prlev(lev, "MapGen:");
			lev++;
			cura = node->mapgen->map;
			while(cura && cura->item) {
				prlev(lev, "<Key>:");
				prex(cura->item->key, lev+1);
				prlev(lev, "<Value>:");
				prex(cura->item->value, lev+1);
				cura = cura->next;
			}
			break;

		case EX_BINOP:
			prlev(lev, "BinOp:");
			lev++;
			switch(node->binop->type) {
				case OP_ADD:
					prlev(lev, "Op: +");
					break;

				case OP_SUB:
					prlev(lev, "Op: -");
					break;

				case OP_MUL:
					prlev(lev, "Op: *");
					break;

				case OP_DIV:
					prlev(lev, "Op: /");
					break;

				case OP_POW:
					prlev(lev, "Op: **");
					break;

				case OP_BAND:
					prlev(lev, "Op: &");
					break;

				case OP_BOR:
					prlev(lev, "Op: |");
					break;

				case OP_BXOR:
					prlev(lev, "Op: ^");
					break;

				case OP_LAND:
					prlev(lev, "Op: &&");
					break;

				case OP_LOR:
					prlev(lev, "Op: ||");
					break;

				case OP_EQUAL:
					prlev(lev, "Op: ==");
					break;

				case OP_LESS:
					prlev(lev, "Op: <");
					break;

				case OP_GREATER:
					prlev(lev, "Op: >");
					break;

				case OP_LESSEQ:
					prlev(lev, "Op: <=");
					break;

				case OP_GREATEREQ:
					prlev(lev, "Op: >=");
					break;
			}
			prlev(lev, "Left:");
			prex(node->binop->left, lev+1);
			prlev(lev, "Right:");
			prex(node->binop->right, lev+1);
			break;

		case EX_UNOP:
			prlev(lev, "UnOp:");
			lev++;
			switch(node->unop->type) {
				case OP_NEG:
					prlev(lev, "Op: -");
					break;

				case OP_BNOT:
					prlev(lev, "Op: ~");
					break;

				case OP_LNOT:
					prlev(lev, "Op: !");
					break;
			}
			prlev(lev, "Expr:");
			prex(node->unop->expr, lev+1);
			break;

		case EX_INDEX:
			prlev(lev, "Index:");
			lev++;
			prlev(lev, "Expr:");
			prex(node->index->expr, lev+1);
			prlev(lev, "Index:");
			prex(node->index->index, lev+1);
			break;

		case EX_SETINDEX:
			prlev(lev, "SetIndex:");
			lev++;
			prlev(lev, "Expr:");
			prex(node->setindex->expr, lev+1);
			prlev(lev, "Index:");
			prex(node->setindex->index, lev+1);
			prlev(lev, "Value:");
			prex(node->setindex->value, lev+1);
			break;

		case EX_ASSIGN:
			prlev(lev, "Assign:");
			lev++;
			prlev(lev, "Ident: %s", node->assign->ident);
			prlev(lev, "Value:");
			prex(node->assign->value, lev+1);
			break;

		case EX_REF:
			prlev(lev, "Ref: %s", node->ref->ident);
			break;

		case EX_CALL:
			prlev(lev, "Call:");
			lev++;
			prlev(lev, "Expr:");
			prex(node->call->expr, lev+1);
			prlev(lev, "Args:");
			cure = node->call->args;
			while(cure && cure->expr) {
				prex(cure->expr, lev+1);
				cure = cure->next;
			}
			break;

		case EX_FUNCDECL:
			prlev(lev, "FuncDecl:");
			lev++;
			prlev(lev, "Name: %s", node->funcdecl->name);
			prlev(lev, "Args:");
			curi = node->funcdecl->args;
			while(curi && curi->ident) {
				prlev(lev+1, curi->ident);
				curi = curi->next;
			}
			prlev(lev, "Body:");
			prst(node->funcdecl->body, lev+1);
			break;
	}
}

void st_print(stmt_node *stmt) {
    prst(stmt, 0);
}

void ex_print(expr_node *expr) {
    prex(expr, 0);
}

/*int main(int argc, char **argv) {
	stmt_node *program = NULL;

	if(argc>1) yydebug = 1;

	if(yyparse(&program)) {
		printf("Syntax error (somewhere)\n");
		printf("Partial tree:\n");
		prst(program, 0);
		return 1;
	}

	prst(program, 0);
	return 0;
}*/

