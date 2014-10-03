#include <stdlib.h>
#include <string.h>
#include "ast.h"

expr_node *sol_comp_as_expr(stmt_node *stmt) {
    if(stmt->type == ST_EXPR) return stmt->expr;
    return NULL;
}

void sol_comp_free(stmt_node *stmt) {
    st_free(stmt);
}

void ex_free(expr_node *);

void st_free(stmt_node *stmt) {
    stmtlist_node *curs, *prevs;
    if(!stmt) return;
    switch(stmt->type) {
        case ST_EXPR:
            ex_free(stmt->expr);
            break;

        case ST_IFELSE:
            ex_free(stmt->ifelse->cond);
            st_free(stmt->ifelse->iftrue);
            st_free(stmt->ifelse->iffalse);
            free(stmt->ifelse);
            break;

        case ST_LOOP:
            ex_free(stmt->loop->cond);
            st_free(stmt->loop->loop);
            free(stmt->loop);
            break;

        case ST_ITER:
            free(stmt->iter->var);
            ex_free(stmt->iter->iter);
            st_free(stmt->iter->loop);
            free(stmt->iter);
            break;

        case ST_LIST:
            curs = stmt->stmtlist;
            while(curs) {
                if(curs->stmt) st_free(curs->stmt);
                prevs = curs;
                curs = curs->next;
                free(prevs);
            }
            break;

        case ST_RET:
            ex_free(stmt->ret->ret);
            free(stmt->ret);
            break;
    }
    free(stmt);
}

void ex_free(expr_node *expr) {
    exprlist_node *cure, *preve;
    assoclist_node *cura, *preva;
    identlist_node *curi, *previ;
    if(!expr) return;
    switch(expr->type) {
        case EX_LIT:
            if(expr->lit->type == LIT_STRING) free(expr->lit->str);
            free(expr->lit);
            break;

        case EX_LISTGEN:
            cure = expr->listgen->list;
            while(cure) {
                if(cure->expr) ex_free(cure->expr);
                preve = cure;
                cure = cure->next;
                free(preve);
            }
            free(expr->listgen);
            break;

        case EX_MAPGEN:
            cura = expr->mapgen->map;
            while(cura) {
                if(cura->item) {
                    ex_free(cura->item->key);
                    ex_free(cura->item->value);
                    free(cura->item);
                }
                preva = cura;
                cura = cura->next;
                free(preva);
            }
            free(expr->mapgen);
            break;

        case EX_BINOP:
            ex_free(expr->binop->left);
            ex_free(expr->binop->right);
            free(expr->binop);
            break;

        case EX_UNOP:
            ex_free(expr->unop->expr);
            free(expr->unop);
            break;

        case EX_INDEX:
            ex_free(expr->index->expr);
            ex_free(expr->index->index);
            free(expr->index);
            break;

        case EX_SETINDEX:
            ex_free(expr->setindex->expr);
            ex_free(expr->setindex->index);
            ex_free(expr->setindex->value);
            free(expr->setindex);
            break;

        case EX_ASSIGN:
            free(expr->assign->ident);
            ex_free(expr->assign->value);
            free(expr->assign);
            break;

        case EX_REF:
            free(expr->ref->ident);
            free(expr->ref);
            break;

        case EX_CALL:
            ex_free(expr->call->expr);
            cure = expr->call->args;
            while(cure) {
                if(cure->expr) ex_free(cure->expr);
                preve = cure;
                cure = cure->next;
                free(preve);
            }
            free(expr->call);
            break;

        case EX_FUNCDECL:
            free(expr->funcdecl->name);
            st_free(expr->funcdecl->body);
            curi = expr->funcdecl->args;
            while(curi) {
                if(curi->ident) free(curi->ident);
                previ = curi;
                curi = curi->next;
                free(previ);
            }
            free(expr->funcdecl);
            break;
    }
    free(expr);
}

sol_object_t *sol_eval(sol_state_t *state, expr_node *expr) {
    sol_object_t *res, *args, *left, *right, *lint, *rint, *value, *scope, *key, *list;
    exprlist_node *cure;
    assoclist_node *cura;
    identlist_node *curi;
    if(!expr) return sol_set_error_string(state, "Evaluate NULL expression");
    switch(expr->type) {
        case EX_LIT:
            switch(expr->lit->type) {
                case LIT_INT:
                    return sol_new_int(state, expr->lit->ival);
                    break;

                case LIT_FLOAT:
                    return sol_new_float(state, expr->lit->fval);
                    break;

                case LIT_STRING:
                    return sol_new_string(state, expr->lit->str);
                    break;
					
				case LIT_NONE:
					return sol_incref(state->None);
					break;
            }
            break;

        case EX_LISTGEN:
            res = sol_new_list(state);
            cure = expr->listgen->list;
            while(cure) {
                if(cure->expr) sol_list_insert(state, &res, sol_list_len(state, res), sol_eval(state, cure->expr));
                cure = cure->next;
            }
            return res;
            break;

        case EX_MAPGEN:
            res = sol_new_map(state);
            cura = expr->mapgen->map;
            while(cura) {
                if(cura->item) sol_map_set(state, res, sol_eval(state, cura->item->key), sol_eval(state, cura->item->value));
                cura = cura->next;
            }
            return res;
            break;

        case EX_BINOP:
            list = sol_new_list(state);
            left = sol_eval(state, expr->binop->left);
            right = sol_eval(state, expr->binop->right);
            sol_list_insert(state, &list, 0, left);
            sol_list_insert(state, &list, 1, right);
            switch(expr->binop->type) {
                case OP_ADD:
                    res = left->ops->add(state, list);
                    break;

                case OP_SUB:
                    res = left->ops->sub(state, list);
                    break;

                case OP_MUL:
                    res = left->ops->mul(state, list);
                    break;

                case OP_DIV:
                    res = left->ops->div(state, list);
                    break;

                case OP_POW:
                    res = left->ops->pow(state, list);
                    break;

                case OP_BAND:
                    res = left->ops->band(state, list);
                    break;

                case OP_BOR:
                    res = left->ops->bor(state, list);
                    break;

                case OP_BXOR:
                    res = left->ops->bxor(state, list);
                    break;

                case OP_LAND:
                    lint = sol_cast_int(state, left);
                    rint = sol_cast_int(state, right);
                    res = sol_new_int(state, BOOL_TO_INT(lint && rint));
                    sol_obj_free(lint);
                    sol_obj_free(rint);
                    break;

                case OP_LOR:
                    lint = sol_cast_int(state, left);
                    rint = sol_cast_int(state, right);
                    res = sol_new_int(state, BOOL_TO_INT(lint || rint));
                    sol_obj_free(lint);
                    sol_obj_free(rint);
                    break;

                case OP_EQUAL:
                    res = sol_new_int(state, BOOL_TO_INT(sol_cast_int(state, left->ops->cmp(state, list))->ival==0));
                    break;

                case OP_LESS:
                    res = sol_new_int(state, BOOL_TO_INT(sol_cast_int(state, left->ops->cmp(state, list))->ival<0));
                    break;

                case OP_GREATER:
                    res = sol_new_int(state, BOOL_TO_INT(sol_cast_int(state, left->ops->cmp(state, list))->ival>0));
                    break;

                case OP_LESSEQ:
                    res = sol_new_int(state, BOOL_TO_INT(sol_cast_int(state, left->ops->cmp(state, list))->ival<=0));
                    break;

                case OP_GREATEREQ:
                    res = sol_new_int(state, BOOL_TO_INT(sol_cast_int(state, left->ops->cmp(state, list))->ival>=0));
                    break;
            }
            sol_obj_free(left);
            sol_obj_free(right);
            sol_obj_free(list);
            return res;
            break;

        case EX_UNOP:
            left = sol_eval(state, expr->unop->expr);
            list = sol_new_list(state);
            sol_list_insert(state, &list, 0, left);
            switch(expr->unop->type) {
                case OP_NEG:
                    right = sol_new_int(state, -1);
                    sol_list_insert(state, &list, 1, right);
                    res = left->ops->mul(state, list);
                    sol_obj_free(right);
                    break;

                case OP_BNOT:
                    res = left->ops->bnot(state, list);
                    break;

                case OP_LNOT:
                    lint = sol_cast_int(state, left);
                    res = sol_new_int(state, BOOL_TO_INT(!lint->ival));
                    sol_obj_free(lint);
                    break;
					
				case OP_LEN:
					res = left->ops->len(state, list);
					break;
            }
            sol_obj_free(left);
            sol_obj_free(list);
            return res;
            break;

        case EX_INDEX:
            left = sol_eval(state, expr->index->expr);
            right = sol_eval(state, expr->index->index);
            list = sol_new_list(state);
            sol_list_insert(state, &list, 0, left);
            sol_list_insert(state, &list, 1, right);
            res = left->ops->index(state, list);
            sol_obj_free(left);
            sol_obj_free(right);
            sol_obj_free(list);
            return res;
            break;

        case EX_SETINDEX:
            left = sol_eval(state, expr->setindex->expr);
            right = sol_eval(state, expr->setindex->index);
            value = sol_eval(state, expr->setindex->value);
            list = sol_new_list(state);
            sol_list_insert(state, &list, 0, left);
            sol_list_insert(state, &list, 1, right);
            sol_list_insert(state, &list, 2, value);
            res = left->ops->setindex(state, list);
            sol_obj_free(left);
            sol_obj_free(right);
            sol_obj_free(value);
            sol_obj_free(list);
            return res;
            break;

        case EX_ASSIGN:
            value = sol_eval(state, expr->assign->value);
            sol_state_assign_l_name(state, expr->assign->ident, value);
            return value;
            break;

        case EX_REF:
            return sol_state_resolve_name(state, expr->ref->ident);
            break;

        case EX_CALL:
            value = sol_eval(state, expr->call->expr);
            list = sol_new_list(state);
            sol_list_insert(state, &list, 0, value);
            cure = expr->call->args;
            while(cure) {
                if(cure->expr) sol_list_insert(state, &list, sol_list_len(state, list), sol_eval(state, cure->expr));
                cure = cure->next;
            }
            res = value->ops->call(state, list);
            sol_obj_free(value);
            sol_obj_free(list);
            return res;
            break;

        case EX_FUNCDECL:
            res = sol_new_func(state, expr->funcdecl->args, expr->funcdecl->body, expr->funcdecl->name);
            if(expr->funcdecl->name) {
                sol_state_assign_l_name(state, expr->funcdecl->name, res);
            }
            return res;
            break;
    }
}

void sol_exec(sol_state_t *state, stmt_node *stmt) {
    sol_object_t *value, *vint;
    stmtlist_node *curs;
    if(!stmt) {
        sol_obj_free(sol_set_error_string(state, "Execute NULL statement"));
        return;
    }
    switch(stmt->type) {
        case ST_EXPR:
            sol_obj_free(sol_eval(state, stmt->expr));
            break;

        case ST_IFELSE:
            value = sol_eval(state, stmt->ifelse->cond);
            vint = sol_cast_int(state, value);
            if(vint->ival) {
                if(stmt->ifelse->iftrue) sol_exec(state, stmt->ifelse->iftrue);
            } else {
                if(stmt->ifelse->iffalse) sol_exec(state, stmt->ifelse->iffalse);
            }
            if(vint != value) sol_obj_free(value);
            sol_obj_free(vint);
            break;

        case ST_LOOP:
            value = sol_eval(state, stmt->loop->cond);
            vint = sol_cast_int(state, value);
            while(vint->ival) {
                sol_obj_free(value);
                sol_obj_free(vint);
                sol_exec(state, stmt->loop->loop);
                if(state->ret || state->sflag == SF_BREAKING || sol_has_error(state)) break;
                value = sol_eval(state, stmt->loop->cond);
                vint = sol_cast_int(state, value);
            }
            state->sflag = SF_NORMAL;
            break;

        case ST_ITER:
            value = sol_eval(state, stmt->iter->iter);
            while(value != state->StopIteration) {
                sol_state_assign_l_name(state, stmt->iter->var, value);
                sol_obj_free(value);
                sol_exec(state, stmt->loop->loop);
                if(state->ret || state->sflag == SF_BREAKING || sol_has_error(state)) break;
                value = sol_eval(state, stmt->iter->iter);
            }
            state->sflag = SF_NORMAL;
            break;

        case ST_LIST:
            curs = stmt->stmtlist;
            while(curs && state->sflag == SF_NORMAL && !sol_has_error(state) && !state->ret) {
                if(curs->stmt) sol_exec(state, curs->stmt);
                curs = curs->next;
            }
            break;

        case ST_RET:
            if(stmt->ret->ret) {
                state->ret = sol_eval(state, stmt->ret->ret);
            } else {
                state->ret = sol_incref(state->None);
            }
            break;

        case ST_CONT:
            state->sflag = SF_CONTINUING;
            break;

        case ST_BREAK:
            state->sflag = SF_BREAKING;
            break;
    }
}

sol_object_t *sol_f_func_call(sol_state_t *state, sol_object_t *args) {
    sol_object_t *res, *scope, *value, *curo = args, *key;
    identlist_node *curi;
    value = curo->lvalue;
	if(!value->func) return sol_incref(state->None);
    curo = curo->lnext;
    scope = sol_map_copy(state, value->closure);
    curi = AS(value->args, identlist_node);
    while(curi) {
        if(curi->ident) {
            key = sol_new_string(state, curi->ident);
            if(!(curo && curo->lvalue)) {
                sol_map_set(state, scope, key, sol_incref(state->None));
            } else {
                sol_map_set(state, scope, key, curo->lvalue);
                curo = curo->lnext;
            }
            sol_obj_free(key);
            curi = curi->next;
        }
    }
    if(value->fname) {
		key = sol_new_string(state, value->fname);
		sol_map_set(state, scope, key, value);
		sol_obj_free(key);
	}
    sol_state_push_scope(state, scope);
    sol_exec(state, AS(value->func, stmt_node));
    sol_state_pop_scope(state);
    sol_map_merge_existing(state, value->closure, scope);
    if(state->ret) {
        res = state->ret;
        state->ret = NULL;
    } else {
        res = sol_incref(state->None);
    }
    sol_obj_free(scope);
    return res;
}

sol_object_t *sol_new_func(sol_state_t *state, identlist_node *identlist, stmt_node *body, char *name) {
    sol_object_t *obj = sol_alloc_object(state);
    if(sol_has_error(state)) return sol_incref(state->None);
    obj->func = body;
    obj->args = identlist;
	obj->fname = (name?strdup(name):NULL);
    obj->closure = sol_new_map(state);
    obj->type = SOL_FUNCTION;
    obj->ops = &(state->FuncOps);
    return obj;
}
