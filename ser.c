#include <string.h>
#include <stdlib.h>

#include "ast.h"

extern int yydebug;

char *sol_BytecodeNames[] = {
	"BC_NULL",
	"BC_ST_EXPR",
	"BC_ST_LIST",
	"BC_ST_RET",
	"BC_ST_CONT",
	"BC_ST_BREAK",
	"BC_EX_LIT",
	"BC_EX_LISTGEN",
	"BC_EX_MAPGEN",
	"BC_EX_BINOP",
	"BC_EX_UNOP",
	"BC_EX_INDEX",
	"BC_EX_SETINDEX",
	"BC_EX_ASSIGN",
	"BC_EX_REF",
	"BC_EX_CALL",
	"BC_EX_FUNCDECL",
	"BC_EX_IFELSE",
	"BC_EX_LOOP",
	"BC_EX_ITER",
	"BC_LIT_INT",
	"BC_LIT_FLOAT",
	"BC_LIT_STRING",
	"BC_LIT_NONE",
	"BC_INT",
	"BC_FLOAT",
	"BC_STRING",
	"BC_LIST_ST",
	"BC_LIST_EX",
	"BC_LIST_AS",
	"BC_LIST_ID",
	"BC_LIST_PM",
	"BC_ENDLIST",
};

void sol_ser_stmt(FILE *io, stmt_node *st) {
	if(!st) {
		fputc(BC_NULL, io);
		return;
	}
	switch(st->type) {
		case ST_EXPR:
			fputc(BC_ST_EXPR, io);
			sol_ser_expr(io, st->expr);
			break;

		case ST_LIST:
			fputc(BC_ST_LIST, io);
			sol_ser_stl(io, st->stmtlist);
			break;

		case ST_RET:
			fputc(BC_ST_RET, io);
			sol_ser_expr(io, st->ret->ret);
			break;

		case ST_CONT:
			fputc(BC_ST_CONT, io);
			sol_ser_expr(io, st->cont->val);
			break;

		case ST_BREAK:
			fputc(BC_ST_BREAK, io);
			sol_ser_expr(io, st->brk->val);
			break;

		default:
			printf("WARNING: Unknown statement type to serialize: %d\n", st->type);
			break;
	}
}

void sol_ser_stl(FILE *io, stmtlist_node *stl) {
	fputc(BC_LIST_ST, io);
	while(stl) {
		sol_ser_stmt(io, stl->stmt);
		stl = stl->next;
	}
	fputc(BC_ENDLIST, io);
}

void sol_ser_expr(FILE *io, expr_node *ex) {
	if(!ex) {
		fputc(BC_NULL, io);
		return;
	}
	switch(ex->type) {
		case EX_LIT:
			fputc(BC_EX_LIT, io);
			sol_ser_lit(io, ex->lit);
			break;

		case EX_LISTGEN:
			fputc(BC_EX_LISTGEN, io);
			sol_ser_exl(io, ex->listgen->list);
			break;

		case EX_MAPGEN:
			fputc(BC_EX_MAPGEN, io);
			sol_ser_asl(io, ex->mapgen->map);
			break;

		case EX_BINOP:
			fputc(BC_EX_BINOP, io);
			fputc(ex->binop->type - OP_ADD, io);
			sol_ser_expr(io, ex->binop->left);
			sol_ser_expr(io, ex->binop->right);
			break;

		case EX_UNOP:
			fputc(BC_EX_UNOP, io);
			fputc(ex->unop->type - OP_NEG, io);
			sol_ser_expr(io, ex->unop->expr);
			break;

		case EX_INDEX:
			fputc(BC_EX_INDEX, io);
			sol_ser_expr(io, ex->index->expr);
			sol_ser_expr(io, ex->index->index);
			break;

		case EX_SETINDEX:
			fputc(BC_EX_SETINDEX, io);
			sol_ser_expr(io, ex->setindex->expr);
			sol_ser_expr(io, ex->setindex->index);
			sol_ser_expr(io, ex->setindex->value);
			break;

		case EX_ASSIGN:
			fputc(BC_EX_ASSIGN, io);
			sol_ser_str(io, ex->assign->ident);
			sol_ser_expr(io, ex->assign->value);
			break;

		case EX_REF:
			fputc(BC_EX_REF, io);
			sol_ser_str(io, ex->ref->ident);
			break;

		case EX_CALL:
			fputc(BC_EX_CALL, io);
			sol_ser_expr(io, ex->call->expr);
			sol_ser_exl(io, ex->call->args);
			sol_ser_str(io, ex->call->method);
			break;

		case EX_FUNCDECL:
			fputc(BC_EX_FUNCDECL, io);
			sol_ser_str(io, ex->funcdecl->name);
			sol_ser_pl(io, ex->funcdecl->params);
			sol_ser_expr(io, ex->funcdecl->anno);
			sol_ser_stmt(io, ex->funcdecl->body);
			break;

		case EX_IFELSE:
			fputc(BC_EX_IFELSE, io);
			sol_ser_expr(io, ex->ifelse->cond);
			sol_ser_stmt(io, ex->ifelse->iftrue);
			sol_ser_stmt(io, ex->ifelse->iffalse);
			break;

		case EX_LOOP:
			fputc(BC_EX_LOOP, io);
			sol_ser_expr(io, ex->loop->cond);
			sol_ser_stmt(io, ex->loop->loop);
			break;

		case EX_ITER:
			fputc(BC_EX_ITER, io);
			sol_ser_str(io, ex->iter->var);
			sol_ser_expr(io, ex->iter->iter);
			sol_ser_stmt(io, ex->iter->loop);
			break;

		default:
			printf("WARNING: Unknown expression type to serialize: %d\n", ex->type);
			break;
	}
}

void sol_ser_exl(FILE *io, exprlist_node *exn) {
	fputc(BC_LIST_EX, io);
	while(exn) {
		sol_ser_expr(io, exn->expr);
		exn = exn->next;
	}
	fputc(BC_ENDLIST, io);
}

void sol_ser_asl(FILE *io, assoclist_node *asl) {
	fputc(BC_LIST_AS, io);
	while(asl) {
		if(asl->item) {
			sol_ser_expr(io, asl->item->key);
			sol_ser_expr(io, asl->item->value);
		}
		asl = asl->next;
	}
	fputc(BC_ENDLIST, io);
}

void sol_ser_idl(FILE *io, identlist_node *idl) {
	fputc(BC_LIST_ID, io);
	while(idl) {
		sol_ser_str(io, idl->ident);
		idl = idl->next;
	}
	fputc(BC_ENDLIST, io);
}

void sol_ser_pl(FILE *io, paramlist_node *pl) {
	if(!pl) {
		fputc(BC_NULL, io);
		return;
	}
	fputc(BC_LIST_PM, io);
	sol_ser_idl(io, pl->args);
	sol_ser_exl(io, pl->annos);
	sol_ser_idl(io, pl->clkeys);
	sol_ser_exl(io, pl->clvalues);
	sol_ser_str(io, pl->rest);
	fputc(BC_ENDLIST, io);
}

void sol_ser_lit(FILE *io, lit_node *lit) {
	if(!lit) {
		fputc(BC_NULL, io);
		return;
	}
	switch(lit->type) {
		case LIT_INT:
			fputc(BC_LIT_INT, io);
			sol_ser_int(io, lit->ival);
			break;

		case LIT_FLOAT:
			fputc(BC_LIT_FLOAT, io);
			sol_ser_float(io, lit->fval);
			break;

		case LIT_STRING:
			fputc(BC_LIT_STRING, io);
			sol_ser_str(io, lit->str);
			break;

		case LIT_NONE:
			fputc(BC_LIT_NONE, io);
			break;

		default:
			printf("WARNING: Unknown literal type to serialize: %d\n", lit->type);
			break;
	}
}

void sol_ser_str(FILE *io, const char *s) {
	size_t len;
	if(!s) {
		fputc(BC_NULL, io);
		return;
	}
	fputc(BC_STRING, io);
	len = strlen(s);
	fwrite(&len, sizeof(size_t), 1, io);
	fwrite(s, sizeof(char), len, io);
}

void sol_ser_int(FILE *io, long i) {
	fputc(BC_INT, io);
	fwrite(&i, sizeof(long), 1, io);
}

void sol_ser_float(FILE *io, double f) {
	fputc(BC_FLOAT, io);
	fwrite(&f, sizeof(double), 1, io);
}

void *sol_deser_checked(FILE *io, bytecode b) {
	int c = fgetc(io);
	if(c != b && c != BC_NULL) {
		printf("WARNING: Deserialization failed; expected %d, got %d\n", b, c);
	}
	ungetc(c, io);
	return sol_deser(io);
}

void *sol_deser_stmt(FILE *io) {
	int c = fgetc(io);
	switch(c) {
		default:
			printf("WARNING: Deserialization failed; expected stmt type, got %d\n", c);
			break;

		case BC_NULL:
		case BC_ST_EXPR:
		case BC_ST_LIST:
		case BC_ST_RET:
		case BC_ST_CONT:
		case BC_ST_BREAK:
			;
	}
	ungetc(c, io);
	return sol_deser(io);
}

void *sol_deser_expr(FILE *io) {
	int c = fgetc(io);
	switch(c) {
		default:
			printf("WARNING: Deserialization failed; expected expr type, got %d\n", c);
			break;

		case BC_NULL:
		case BC_EX_LIT:
		case BC_EX_LISTGEN:
		case BC_EX_MAPGEN:
		case BC_EX_BINOP:
		case BC_EX_UNOP:
		case BC_EX_INDEX:
		case BC_EX_SETINDEX:
		case BC_EX_ASSIGN:
		case BC_EX_REF:
		case BC_EX_CALL:
		case BC_EX_FUNCDECL:
		case BC_EX_IFELSE:
		case BC_EX_LOOP:
		case BC_EX_ITER:
			;
	}
	ungetc(c, io);
	return sol_deser(io);
}

void *sol_deser_lit(FILE *io) {
	int c = fgetc(io);
	switch(c) {
		default:
			printf("WARNING: Deserialization failed; expected lit type, got %d\n", c);
			break;

		case BC_NULL:
		case BC_LIT_INT:
		case BC_LIT_FLOAT:
		case BC_LIT_STRING:
		case BC_LIT_NONE:
			;
	}
	ungetc(c, io);
	return sol_deser(io);
}

void *sol_deser(FILE *io) {
	bytecode b = fgetc(io);
	void *obj = NULL, *node = NULL;

	if(yydebug) {
		fprintf(stderr, "Encountered BC %s", sol_BytecodeNames[b]);
	}

	switch(b) {
		case BC_NULL:
			return NULL;
			break;

		case BC_ST_EXPR:
			obj = NEW(stmt_node);
			AS_ST(obj)->type = ST_EXPR;
			AS_ST(obj)->expr = sol_deser_expr(io);
			return obj;
			break;

		case BC_ST_LIST:
			obj = NEW(stmt_node);
			AS_ST(obj)->type = ST_LIST;
			AS_ST(obj)->stmtlist = sol_deser_checked(io, BC_LIST_ST);
			return obj;

		case BC_ST_RET:
			obj = NEW(stmt_node);
			AS_ST(obj)->type = ST_RET;
			AS_ST(obj)->ret = NEW(ret_node);
			AS_ST(obj)->ret->ret = sol_deser_expr(io);
			return obj;

		case BC_ST_CONT:
			obj = NEW(stmt_node);
			AS_ST(obj)->type = ST_CONT;
			AS_ST(obj)->cont = NEW(cont_node);
			AS_ST(obj)->cont->val = sol_deser_expr(io);
			return obj;

		case BC_ST_BREAK:
			obj = NEW(stmt_node);
			AS_ST(obj)->type = ST_BREAK;
			AS_ST(obj)->brk = NEW(break_node);
			AS_ST(obj)->brk->val = sol_deser_expr(io);
			return obj;

		case BC_EX_LIT:
			obj = NEW(expr_node);
			AS_EX(obj)->type = EX_LIT;
			AS_EX(obj)->lit = sol_deser_lit(io);
			return obj;

		case BC_EX_LISTGEN:
			obj = NEW(expr_node);
			AS_EX(obj)->type = EX_LISTGEN;
			AS_EX(obj)->listgen = NEW(listgen_node);
			AS_EX(obj)->listgen->list = sol_deser_checked(io, BC_LIST_EX);
			return obj;

		case BC_EX_MAPGEN:
			obj = NEW(expr_node);
			AS_EX(obj)->type = EX_MAPGEN;
			AS_EX(obj)->mapgen = NEW(mapgen_node);
			AS_EX(obj)->mapgen->map = sol_deser_checked(io, BC_LIST_AS);
			return obj;

		case BC_EX_BINOP:
			obj = NEW(expr_node);
			AS_EX(obj)->type = EX_BINOP;
			AS_EX(obj)->binop = NEW(binop_node);
			AS_EX(obj)->binop->type = OP_ADD + fgetc(io);
			AS_EX(obj)->binop->left = sol_deser_expr(io);
			AS_EX(obj)->binop->right = sol_deser_expr(io);
			return obj;

		case BC_EX_UNOP:
			obj = NEW(expr_node);
			AS_EX(obj)->type = EX_UNOP;
			AS_EX(obj)->unop = NEW(unop_node);
			AS_EX(obj)->unop->type = OP_NEG + fgetc(io);
			AS_EX(obj)->unop->expr = sol_deser_expr(io);
			return obj;

		case BC_EX_INDEX:
			obj = NEW(expr_node);
			AS_EX(obj)->type = EX_INDEX;
			AS_EX(obj)->index = NEW(index_node);
			AS_EX(obj)->index->expr = sol_deser_expr(io);
			AS_EX(obj)->index->index = sol_deser_expr(io);
			return obj;

		case BC_EX_SETINDEX:
			obj = NEW(expr_node);
			AS_EX(obj)->type = EX_SETINDEX;
			AS_EX(obj)->setindex = NEW(setindex_node);
			AS_EX(obj)->setindex->expr = sol_deser_expr(io);
			AS_EX(obj)->setindex->index = sol_deser_expr(io);
			AS_EX(obj)->setindex->value = sol_deser_expr(io);
			return obj;

		case BC_EX_ASSIGN:
			obj = NEW(expr_node);
			AS_EX(obj)->type = EX_ASSIGN;
			AS_EX(obj)->assign = NEW(assign_node);
			AS_EX(obj)->assign->ident = sol_deser_checked(io, BC_STRING);
			AS_EX(obj)->assign->value = sol_deser_expr(io);
			return obj;

		case BC_EX_REF:
			obj = NEW(expr_node);
			AS_EX(obj)->type = EX_REF;
			AS_EX(obj)->ref = NEW(ref_node);
			AS_EX(obj)->ref->ident = sol_deser_checked(io, BC_STRING);
			return obj;

		case BC_EX_CALL:
			obj = NEW(expr_node);
			AS_EX(obj)->type = EX_CALL;
			AS_EX(obj)->call = NEW(call_node);
			AS_EX(obj)->call->expr = sol_deser_expr(io);
			AS_EX(obj)->call->args = sol_deser_checked(io, BC_LIST_EX);
			AS_EX(obj)->call->method = sol_deser_checked(io, BC_STRING);
			return obj;

		case BC_EX_FUNCDECL:
			obj = NEW(expr_node);
			AS_EX(obj)->type = EX_FUNCDECL;
			AS_EX(obj)->funcdecl = NEW(funcdecl_node);
			AS_EX(obj)->funcdecl->name = sol_deser_checked(io, BC_STRING);
			AS_EX(obj)->funcdecl->params = sol_deser_checked(io, BC_LIST_PM);
			AS_EX(obj)->funcdecl->anno = sol_deser_expr(io);
			AS_EX(obj)->funcdecl->body = sol_deser_stmt(io);
			return obj;

		case BC_EX_IFELSE:
			obj = NEW(expr_node);
			AS_EX(obj)->type = EX_IFELSE;
			AS_EX(obj)->ifelse = NEW(ifelse_node);
			AS_EX(obj)->ifelse->cond = sol_deser_expr(io);
			AS_EX(obj)->ifelse->iftrue = sol_deser_stmt(io);
			AS_EX(obj)->ifelse->iffalse = sol_deser_stmt(io);
			return obj;

		case BC_EX_LOOP:
			obj = NEW(expr_node);
			AS_EX(obj)->type = EX_LOOP;
			AS_EX(obj)->loop = NEW(loop_node);
			AS_EX(obj)->loop->cond = sol_deser_expr(io);
			AS_EX(obj)->loop->loop = sol_deser_stmt(io);
			return obj;

		case BC_EX_ITER:
			obj = NEW(expr_node);
			AS_EX(obj)->type = EX_ITER;
			AS_EX(obj)->iter = NEW(iter_node);
			AS_EX(obj)->iter->var = sol_deser_checked(io, BC_STRING);
			AS_EX(obj)->iter->iter = sol_deser_expr(io);
			AS_EX(obj)->iter->loop = sol_deser_stmt(io);
			return obj;

		case BC_LIT_INT:
			obj = NEW(lit_node);
			AS(obj, lit_node)->type = LIT_INT;
			node = sol_deser_checked(io, BC_INT);
			AS(obj, lit_node)->ival = *AS(node, long);
			free(node);
			return obj;

		case BC_LIT_FLOAT:
			obj = NEW(lit_node);
			AS(obj, lit_node)->type = LIT_FLOAT;
			node = sol_deser_checked(io, BC_FLOAT);
			AS(obj, lit_node)->fval = *AS(node, double);
			free(node);
			return obj;

		case BC_LIT_STRING:
			obj = NEW(lit_node);
			AS(obj, lit_node)->type = LIT_STRING;
			AS(obj, lit_node)->str = sol_deser_checked(io, BC_STRING);
			return obj;

		case BC_LIT_NONE:
			obj = NEW(lit_node);
			AS(obj, lit_node)->type = LIT_NONE;
			return obj;

		case BC_INT:
			obj = NEW(long);
			fread(obj, sizeof(long), 1, io);
			return obj;

		case BC_FLOAT:
			obj = NEW(double);
			fread(obj, sizeof(double), 1, io);
			return obj;

		case BC_STRING:
			node = NEW(size_t);
			fread(node, sizeof(size_t), 1, io);
			obj = malloc(*AS(node, size_t) + 1);
			fread(obj, sizeof(char), *AS(node, size_t), io);
			AS(obj, char)[*AS(node, size_t)] = 0;
			free(node);
			return obj;

		case BC_LIST_ST:
			while((b = fgetc(io)) != BC_ENDLIST) {
				ungetc(b, io);
				if(!node) {
					node = NEW(stmtlist_node);
					obj = node;
				} else {
					AS(node, stmtlist_node)->next = NEW(stmtlist_node);
					node = AS(node, stmtlist_node)->next;
				}
				AS(node, stmtlist_node)->stmt = sol_deser_stmt(io);
				AS(node, stmtlist_node)->next = NULL;
			}
			return obj;

		case BC_LIST_EX:
			while((b = fgetc(io)) != BC_ENDLIST) {
				ungetc(b, io);
				if(!node) {
					node = NEW(exprlist_node);
					obj = node;
				} else {
					AS(node, exprlist_node)->next = NEW(exprlist_node);
					node = AS(node, exprlist_node)->next;
				}
				AS(node, exprlist_node)->expr = sol_deser_expr(io);
				AS(node, exprlist_node)->next = NULL;
			}
			return obj;

		case BC_LIST_AS:
			while((b = fgetc(io)) != BC_ENDLIST) {
				ungetc(b, io);
				if(!node) {
					node = NEW(assoclist_node);
					obj = node;
				} else {
					AS(node, assoclist_node)->next = NEW(assoclist_node);
					node = AS(node, assoclist_node)->next;
				}
				AS(node, assoclist_node)->item = NEW(associtem_node);
				AS(node, assoclist_node)->item->key = sol_deser_expr(io);
				AS(node, assoclist_node)->item->value = sol_deser_expr(io);
				AS(node, assoclist_node)->next = NULL;
			}
			return obj;

		case BC_LIST_ID:
			while((b = fgetc(io)) != BC_ENDLIST) {
				ungetc(b, io);
				if(!node) {
					node = NEW(identlist_node);
					obj = node;
				} else {
					AS(node, identlist_node)->next = NEW(identlist_node);
					node = AS(node, identlist_node)->next;
				}
				AS(node, identlist_node)->ident = sol_deser_checked(io, BC_STRING);
				AS(node, identlist_node)->next = NULL;
			}
			return obj;

		case BC_LIST_PM:
			obj = NEW(paramlist_node);
			AS(obj, paramlist_node)->args = sol_deser_checked(io, BC_LIST_ID);
			AS(obj, paramlist_node)->annos = sol_deser_checked(io, BC_LIST_EX);
			AS(obj, paramlist_node)->clkeys = sol_deser_checked(io, BC_LIST_ID);
			AS(obj, paramlist_node)->clvalues = sol_deser_checked(io, BC_LIST_EX);
			AS(obj, paramlist_node)->rest = sol_deser_checked(io, BC_STRING);
			if(fgetc(io) != BC_ENDLIST) {
				printf("WARNING: Missed ENDLIST for paramlist_node\n");
			}
			return obj;

		default:
			printf("WARNING: Illegal bytecode %d\n", b);
			break;
	}
	return NULL;
}
