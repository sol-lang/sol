#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "ast.h"

#define TMP_PATH_SZ 256

char *sol_AbsInitPaths[] = {
	"/etc/sol/init.sol",
	"/opt/sol/init.sol",
};

char *sol_HomeInitPaths[] = {
	"/.config/sol/init.sol",
};

char sol_TempPath[TMP_PATH_SZ];

#define LENGTH(array) (sizeof(array) / sizeof(array[0]))

int sol_state_init(sol_state_t *state) {
	sol_object_t *globals, *mod, *meths;
	sol_object_t *btype, *bsize, *bobj;
	unsigned long i;
	FILE *fp;
	stmt_node *stmt;
	char *suffix;

	sol_mm_initialize(state);

	state->None = NULL;
	state->OutOfMemory = NULL;
	state->scopes = NULL;
	state->error = NULL;
	state->traceback = NULL;
	state->ret = NULL;
	state->sflag = SF_NORMAL;
	state->lastvalue = NULL;
	state->loopvalue = NULL;

#ifdef DEBUG_GC
	// This is necessary for DEBUG_GC's early allocation; it gets overwritten,
	// unfortunately, during sol_ops_init below, so it's duplicated.
	state->SingletOps.tname = "singlet";
#endif

	// If any of the following fail, some very weird things are happening.
	if(!(state->None = sol_new_singlet(state, "None"))) {
		goto cleanup;
	}
	if(!(state->OutOfMemory = sol_new_singlet(state, "OutOfMemory"))) {
		goto cleanup;
	}

	// We can now use the normal error reporting mechanism, now
	// that errors are distinguishable. Set that up now.

	//Initialize all of the builtin operations
	//(these ones are technically already pointed to by None/OOM)
	sol_ops_init(&(state->NullOps));

	state->SingletOps = state->NullOps;
	state->IntOps = state->NullOps;
	state->FloatOps = state->NullOps;
	state->StringOps = state->NullOps;
	state->ListOps = state->NullOps;
	state->MapOps = state->NullOps;
	state->MCellOps = state->NullOps;
	state->FuncOps = state->NullOps;
	state->MacroOps = state->NullOps;
	state->CFuncOps = state->NullOps;
	state->ASTNodeOps = state->NullOps;
	state->BufferOps = state->NullOps;
	state->DyLibOps = state->NullOps;
	state->DySymOps = state->NullOps;
	state->StreamOps = state->NullOps;

	state->SingletOps.tname = "singlet";
	state->SingletOps.tostring = sol_f_singlet_tostring;
	state->SingletOps.tobuffer = sol_f_singlet_tobuffer;
	state->SingletOps.free = sol_f_singlet_free;

	state->IntOps.tname = "int";
	state->IntOps.add = sol_f_int_add;
	state->IntOps.sub = sol_f_int_sub;
	state->IntOps.mul = sol_f_int_mul;
	state->IntOps.div = sol_f_int_div;
	state->IntOps.mod = sol_f_int_mod;
	state->IntOps.pow = sol_f_int_pow;
	state->IntOps.band = sol_f_int_band;
	state->IntOps.bor = sol_f_int_bor;
	state->IntOps.bxor = sol_f_int_bxor;
	state->IntOps.blsh = sol_f_int_blsh;
	state->IntOps.brsh = sol_f_int_brsh;
	state->IntOps.bnot = sol_f_int_bnot;
	state->IntOps.cmp = sol_f_int_cmp;
	state->IntOps.toint = sol_f_int_toint;
	state->IntOps.tofloat = sol_f_int_tofloat;
	state->IntOps.tostring = sol_f_int_tostring;

	state->FloatOps.tname = "float";
	state->FloatOps.add = sol_f_float_add;
	state->FloatOps.sub = sol_f_float_sub;
	state->FloatOps.mul = sol_f_float_mul;
	state->FloatOps.div = sol_f_float_div;
	state->FloatOps.cmp = sol_f_float_cmp;
	state->FloatOps.toint = sol_f_float_toint;
	state->FloatOps.tofloat = sol_f_float_tofloat;
	state->FloatOps.tostring = sol_f_float_tostring;

	state->StringOps.tname = "string";
	state->StringOps.add = sol_f_str_add;
	state->StringOps.mul = sol_f_str_mul;
	state->StringOps.cmp = sol_f_str_cmp;
	state->StringOps.index = sol_f_str_index;
	state->StringOps.len = sol_f_str_len;
	state->StringOps.iter = sol_f_str_iter;
	state->StringOps.toint = sol_f_str_toint;
	state->StringOps.tofloat = sol_f_str_tofloat;
	state->StringOps.tostring = sol_f_str_tostring;
	state->StringOps.tobuffer = sol_f_str_tobuffer;
	state->StringOps.repr = sol_f_str_repr;
	state->StringOps.free = sol_f_str_free;

	state->ListOps.tname = "list";
	state->ListOps.add = sol_f_list_add;
	state->ListOps.mul = sol_f_list_mul;
	state->ListOps.cmp = sol_f_list_cmp;
	state->ListOps.call = sol_f_not_impl;
	state->ListOps.index = sol_f_list_index;
	state->ListOps.setindex = sol_f_list_setindex;
	state->ListOps.len = sol_f_list_len;
	state->ListOps.iter = sol_f_list_iter;
	state->ListOps.tostring = sol_f_list_tostring;
	state->ListOps.free = sol_f_list_free;

	state->MapOps.tname = "map";
	state->MapOps.add = sol_f_map_add;
	state->MapOps.call = sol_f_map_call;
	state->MapOps.index = sol_f_map_index;
	state->MapOps.setindex = sol_f_map_setindex;
	state->MapOps.len = sol_f_map_len;
	state->MapOps.iter = sol_f_map_iter;
	state->MapOps.tostring = sol_f_map_tostring;
	state->MapOps.repr = sol_f_map_repr;
	state->MapOps.free = sol_f_map_free;

	state->MCellOps.tname = "mcell";
	state->MCellOps.tostring = sol_f_mcell_tostring;
	state->MCellOps.free = sol_f_mcell_free;

	state->FuncOps.tname = "function";
	state->FuncOps.call = sol_f_func_call;
	state->FuncOps.index = sol_f_func_index;
	state->FuncOps.setindex = sol_f_func_setindex;
	state->FuncOps.tostring = sol_f_func_tostring;
	state->FuncOps.free = sol_f_func_free;

	state->MacroOps = state->FuncOps;  // XXX Hack
	state->MacroOps.tname = "macro";
	state->MacroOps.tflags = SOL_TF_NO_EVAL_CALL_ARGS;

	state->CFuncOps.tname = "cfunction";
	state->CFuncOps.call = sol_f_cfunc_call;
	state->CFuncOps.tostring = sol_f_cfunc_tostring;
	state->CFuncOps.free = sol_f_cfunc_free;

	state->CMacroOps = state->CFuncOps;
	state->CMacroOps.tname = "cmacro";
	state->CMacroOps.tflags = SOL_TF_NO_EVAL_CALL_ARGS;

	state->ASTNodeOps.tname = "astnode";
	state->ASTNodeOps.call = sol_f_astnode_call;
	state->ASTNodeOps.index = sol_f_astnode_index;
	state->ASTNodeOps.setindex = sol_f_astnode_setindex;
	state->ASTNodeOps.tostring = sol_f_astnode_tostring;
	state->ASTNodeOps.free = sol_f_astnode_free;

	state->BufferOps.tname = "buffer";
	state->BufferOps.add = sol_f_buffer_add;
	state->BufferOps.mul = sol_f_buffer_mul;
	state->BufferOps.cmp = sol_f_buffer_cmp;
	state->BufferOps.len = sol_f_buffer_len;
	state->BufferOps.iter = sol_f_buffer_iter;
	state->BufferOps.index = sol_f_buffer_index;
	state->BufferOps.tostring = sol_f_buffer_tostring;
	state->BufferOps.repr = sol_f_buffer_repr;
	state->BufferOps.toint = sol_f_buffer_toint;
	state->BufferOps.tofloat = sol_f_buffer_tofloat;
	state->BufferOps.tobuffer = sol_f_buffer_tobuffer;
	state->BufferOps.free = sol_f_buffer_free;

	state->DyLibOps.tname = "dylib";
	state->DyLibOps.index = sol_f_dylib_index;
	state->DyLibOps.free = sol_f_dylib_free;
	state->DyLibOps.tostring = sol_f_dylib_tostring;

	state->DySymOps.tname = "dysym";
	state->DySymOps.call = sol_f_dysym_call;
	state->DySymOps.index = sol_f_dysym_index;
	state->DySymOps.setindex = sol_f_dysym_setindex;
	state->DySymOps.tostring = sol_f_dysym_tostring;

	state->StreamOps.tname = "stream";
	state->StreamOps.blsh = sol_f_stream_blsh;
	state->StreamOps.brsh = sol_f_stream_brsh;
	state->StreamOps.index = sol_f_stream_index;
	state->StreamOps.free = sol_f_stream_free;
	state->StreamOps.tostring = sol_f_stream_tostring;

#ifdef DEBUG_GC
	state->obfuncs.copy = (dsl_copier) _sol_gc_dsl_copier;
	state->obfuncs.destr = (dsl_destructor) _sol_gc_dsl_destructor;
#else
	state->obfuncs.copy = (dsl_copier) sol_obj_acquire;
	state->obfuncs.destr = (dsl_destructor) sol_obj_free;
#endif

#ifdef SOL_ICACHE
	state->icache_bypass = 1;
	for(i = 0; i <= (SOL_ICACHE_MAX - SOL_ICACHE_MIN); i++) {
		state->icache[i] = sol_new_int(state, ((long) i) + SOL_ICACHE_MIN);
	}
	state->icache_bypass = 0;
#endif

	state->calling_type = "(none)";
	state->calling_meth = "(none)";

	state->lastvalue = sol_incref(state->None);
	state->loopvalue = sol_incref(state->None);

	state->error = state->None;
	state->scopes = sol_new_list(state);
	if(sol_has_error(state)) {
		goto cleanup;
	}
	globals = sol_new_map(state);
	state->modules = sol_new_map(state);
	state->methods = sol_new_map(state);
	if(sol_has_error(state)) {
		goto cleanup;
	}
	sol_list_insert(state, state->scopes, 0, globals);
	sol_obj_free(globals);
	if(sol_has_error(state)) {
		goto cleanup;
	}

	state->_stdin = sol_new_stream(state, stdin, MODE_READ);
	state->_stdout = sol_new_stream(state, stdout, MODE_WRITE);
	state->_stderr = sol_new_stream(state, stderr, MODE_WRITE);

	// NB: None is actually a keyword in the language--it doesn't need to be a
	// global (see parser.y)
	// OutOfMemory (and other important singlets) are set, not borrowed,
	// because the state still holds a reference to them
	sol_map_set_name(state, globals, "OutOfMemory", state->OutOfMemory);
	sol_map_borrow_name(state, globals, "toint", sol_new_cfunc(state, sol_f_toint, "toint"));
	sol_map_borrow_name(state, globals, "tofloat", sol_new_cfunc(state, sol_f_tofloat, "tofloat"));
	sol_map_borrow_name(state, globals, "tostring", sol_new_cfunc(state, sol_f_tostring, "tostring"));
	sol_map_borrow_name(state, globals, "tobuffer", sol_new_cfunc(state, sol_f_tobuffer, "tobuffer"));
	sol_map_borrow_name(state, globals, "try", sol_new_cfunc(state, sol_f_try, "try"));
	sol_map_borrow_name(state, globals, "apply", sol_new_cfunc(state, sol_f_apply, "apply"));
	sol_map_borrow_name(state, globals, "error", sol_new_cfunc(state, sol_f_error, "error"));
	sol_map_borrow_name(state, globals, "type", sol_new_cfunc(state, sol_f_type, "type"));
	sol_map_borrow_name(state, globals, "prepr", sol_new_cfunc(state, sol_f_prepr, "prepr"));
	sol_map_borrow_name(state, globals, "print", sol_new_cfunc(state, sol_f_print, "print"));
	sol_map_borrow_name(state, globals, "rawget", sol_new_cfunc(state, sol_f_rawget, "rawget"));
	sol_map_borrow_name(state, globals, "rawset", sol_new_cfunc(state, sol_f_rawset, "rawset"));
	sol_map_borrow_name(state, globals, "range", sol_new_cfunc(state, sol_f_range, "range"));
	//sol_map_borrow_name(state, globals, "exec", sol_new_cfunc(state, sol_f_exec, "exec"));
	//sol_map_borrow_name(state, globals, "eval", sol_new_cfunc(state, sol_f_eval, "eval"));
	sol_map_borrow_name(state, globals, "execfile", sol_new_cfunc(state, sol_f_execfile, "execfile"));
	sol_map_borrow_name(state, globals, "parse", sol_new_cfunc(state, sol_f_parse, "parse"));
	sol_map_borrow_name(state, globals, "ord", sol_new_cfunc(state, sol_f_ord, "ord"));
	sol_map_borrow_name(state, globals, "chr", sol_new_cfunc(state, sol_f_chr, "chr"));

	mod = sol_new_map(state);
	sol_map_borrow_name(state, mod, "getref", sol_new_cfunc(state, sol_f_debug_getref, "debug.getref"));
	sol_map_borrow_name(state, mod, "setref", sol_new_cfunc(state, sol_f_debug_setref, "debug.setref"));
	sol_map_borrow_name(state, mod, "closure", sol_new_cfunc(state, sol_f_debug_closure, "debug.closure"));
	sol_map_borrow_name(state, mod, "globals", sol_new_cfunc(state, sol_f_debug_globals, "debug.globals"));
	sol_map_borrow_name(state, mod, "locals", sol_new_cfunc(state, sol_f_debug_locals, "debug.locals"));
	sol_map_borrow_name(state, mod, "scopes", sol_new_cfunc(state, sol_f_debug_scopes, "debug.scopes"));
	sol_map_borrow_name(state, mod, "version", sol_new_buffer(state, SOL_VERSION, strlen(SOL_VERSION), OWN_NONE, NULL, NULL));
	sol_map_borrow_name(state, mod, "hexversion", sol_new_int(state, SOL_HEXVER));
#ifdef SOL_ICACHE
	sol_map_borrow_name(state, mod, "icache_min", sol_new_int(state, SOL_ICACHE_MIN));
	sol_map_borrow_name(state, mod, "icache_max", sol_new_int(state, SOL_ICACHE_MAX));
#endif
	sol_map_borrow_name(state, mod, "modules", state->modules);
	sol_map_borrow_name(state, mod, "methods", state->methods);
	sol_map_borrow_name(state, mod, "getops", sol_new_cfunc(state, sol_f_debug_getops, "debug.getops"));
	sol_register_module_name(state, "debug", mod);
	sol_obj_free(mod);

	mod = sol_new_map(state);
	sol_map_borrow_name(state, mod, "str", sol_new_cfunc(state, sol_f_iter_str, "iter.str"));
	sol_map_borrow_name(state, mod, "buffer", sol_new_cfunc(state, sol_f_iter_buffer, "iter.buffer"));
	sol_map_borrow_name(state, mod, "list", sol_new_cfunc(state, sol_f_iter_list, "iter.list"));
	sol_map_borrow_name(state, mod, "map", sol_new_cfunc(state, sol_f_iter_map, "iter.map"));
	sol_register_module_name(state, "iter", mod);
	sol_obj_free(mod);

#ifndef NO_READLINE
	mod = sol_new_map(state);
	sol_map_borrow_name(state, mod, "readline", sol_new_cfunc(state, sol_f_readline_readline, "readline.readline"));
	sol_map_borrow_name(state, mod, "add_history", sol_new_cfunc(state, sol_f_readline_add_history, "readline.add_history"));
	sol_register_module_name(state, "readline", mod);
	sol_obj_free(mod);
#endif

	mod = sol_new_map(state);
	sol_map_borrow_name(state, mod, "ST_EXPR", sol_new_int(state, ST_EXPR));
	sol_map_borrow_name(state, mod, "ST_LIST", sol_new_int(state, ST_LIST));
	sol_map_borrow_name(state, mod, "ST_RET", sol_new_int(state, ST_RET));
	sol_map_borrow_name(state, mod, "ST_CONT", sol_new_int(state, ST_CONT));
	sol_map_borrow_name(state, mod, "ST_BREAK", sol_new_int(state, ST_BREAK));
	sol_map_borrow_name(state, mod, "EX_LIT", sol_new_int(state, EX_LIT));
	sol_map_borrow_name(state, mod, "EX_LISTGEN", sol_new_int(state, EX_LISTGEN));
	sol_map_borrow_name(state, mod, "EX_MAPGEN", sol_new_int(state, EX_MAPGEN));
	sol_map_borrow_name(state, mod, "EX_BINOP", sol_new_int(state, EX_BINOP));
	sol_map_borrow_name(state, mod, "EX_UNOP", sol_new_int(state, EX_UNOP));
	sol_map_borrow_name(state, mod, "EX_INDEX", sol_new_int(state, EX_INDEX));
	sol_map_borrow_name(state, mod, "EX_SETINDEX", sol_new_int(state, EX_SETINDEX));
	sol_map_borrow_name(state, mod, "EX_ASSIGN", sol_new_int(state, EX_ASSIGN));
	sol_map_borrow_name(state, mod, "EX_REF", sol_new_int(state, EX_REF));
	sol_map_borrow_name(state, mod, "EX_CALL", sol_new_int(state, EX_CALL));
	sol_map_borrow_name(state, mod, "EX_FUNCDECL", sol_new_int(state, EX_FUNCDECL));
	sol_map_borrow_name(state, mod, "EX_IFELSE", sol_new_int(state, EX_IFELSE));
	sol_map_borrow_name(state, mod, "EX_LOOP", sol_new_int(state, EX_LOOP));
	sol_map_borrow_name(state, mod, "EX_ITER", sol_new_int(state, EX_ITER));
	sol_map_borrow_name(state, mod, "OP_ADD", sol_new_int(state, OP_ADD));
	sol_map_borrow_name(state, mod, "OP_SUB", sol_new_int(state, OP_SUB));
	sol_map_borrow_name(state, mod, "OP_MUL", sol_new_int(state, OP_MUL));
	sol_map_borrow_name(state, mod, "OP_DIV", sol_new_int(state, OP_DIV));
	sol_map_borrow_name(state, mod, "OP_MOD", sol_new_int(state, OP_MOD));
	sol_map_borrow_name(state, mod, "OP_POW", sol_new_int(state, OP_POW));
	sol_map_borrow_name(state, mod, "OP_BAND", sol_new_int(state, OP_BAND));
	sol_map_borrow_name(state, mod, "OP_BOR", sol_new_int(state, OP_BOR));
	sol_map_borrow_name(state, mod, "OP_BXOR", sol_new_int(state, OP_BXOR));
	sol_map_borrow_name(state, mod, "OP_LAND", sol_new_int(state, OP_LAND));
	sol_map_borrow_name(state, mod, "OP_LOR", sol_new_int(state, OP_LOR));
	sol_map_borrow_name(state, mod, "OP_EQUAL", sol_new_int(state, OP_EQUAL));
	sol_map_borrow_name(state, mod, "OP_NEQUAL", sol_new_int(state, OP_NEQUAL));
	sol_map_borrow_name(state, mod, "OP_LESS", sol_new_int(state, OP_LESS));
	sol_map_borrow_name(state, mod, "OP_GREATER", sol_new_int(state, OP_GREATER));
	sol_map_borrow_name(state, mod, "OP_LESSEQ", sol_new_int(state, OP_LESSEQ));
	sol_map_borrow_name(state, mod, "OP_GREATEREQ", sol_new_int(state, OP_GREATEREQ));
	sol_map_borrow_name(state, mod, "OP_LSHIFT", sol_new_int(state, OP_LSHIFT));
	sol_map_borrow_name(state, mod, "OP_RSHIFT", sol_new_int(state, OP_RSHIFT));
	sol_map_borrow_name(state, mod, "OP_NEG", sol_new_int(state, OP_NEG));
	sol_map_borrow_name(state, mod, "OP_BNOT", sol_new_int(state, OP_BNOT));
	sol_map_borrow_name(state, mod, "OP_LNOT", sol_new_int(state, OP_LNOT));
	sol_map_borrow_name(state, mod, "OP_LEN", sol_new_int(state, OP_LEN));
	sol_map_borrow_name(state, mod, "LIT_INT", sol_new_int(state, LIT_INT));
	sol_map_borrow_name(state, mod, "LIT_FLOAT", sol_new_int(state, LIT_FLOAT));
	sol_map_borrow_name(state, mod, "LIT_STRING", sol_new_int(state, LIT_STRING));
	sol_map_borrow_name(state, mod, "LIT_NONE", sol_new_int(state, LIT_NONE));
	sol_map_borrow_name(state, mod, "KIND_STMT", sol_new_int(state, -1));
	sol_map_borrow_name(state, mod, "KIND_EXPR", sol_new_int(state, -2));
	sol_map_invert(state, mod);
	sol_map_borrow_name(state, mod, "print", sol_new_cfunc(state, sol_f_ast_print, "ast.print"));
	sol_register_module_name(state, "ast", mod);

	btype = sol_new_map(state);
	sol_map_borrow_name(state, btype, "none", sol_new_int(state, BUF_NONE));
	sol_map_borrow_name(state, btype, "uint8", sol_new_int(state, BUF_UINT8));
	sol_map_borrow_name(state, btype, "uint16", sol_new_int(state, BUF_UINT16));
	sol_map_borrow_name(state, btype, "uint32", sol_new_int(state, BUF_UINT32));
	sol_map_borrow_name(state, btype, "uint64", sol_new_int(state, BUF_UINT64));
	sol_map_borrow_name(state, btype, "int8", sol_new_int(state, BUF_INT8));
	sol_map_borrow_name(state, btype, "int16", sol_new_int(state, BUF_INT16));
	sol_map_borrow_name(state, btype, "int32", sol_new_int(state, BUF_INT32));
	sol_map_borrow_name(state, btype, "int64", sol_new_int(state, BUF_INT64));
	sol_map_borrow_name(state, btype, "char", sol_new_int(state, BUF_CHAR));
	sol_map_borrow_name(state, btype, "byte", sol_new_int(state, BUF_BYTE));
	sol_map_borrow_name(state, btype, "int", sol_new_int(state, BUF_INT));
	sol_map_borrow_name(state, btype, "uint", sol_new_int(state, BUF_UINT));
	sol_map_borrow_name(state, btype, "long", sol_new_int(state, BUF_LONG));
	sol_map_borrow_name(state, btype, "ulong", sol_new_int(state, BUF_ULONG));
	sol_map_borrow_name(state, btype, "float", sol_new_int(state, BUF_FLOAT));
	sol_map_borrow_name(state, btype, "double", sol_new_int(state, BUF_DOUBLE));
	sol_map_borrow_name(state, btype, "cstr", sol_new_int(state, BUF_CSTR));
	sol_map_borrow_name(state, btype, "ptr", sol_new_int(state, BUF_PTR));
	sol_map_invert(state, btype);

	bsize = sol_new_map(state);
	sol_map_borrow_name(state, bsize, "uint8", sol_new_int(state, sizeof(uint8_t)));
	sol_map_borrow_name(state, bsize, "uint16", sol_new_int(state, sizeof(uint16_t)));
	sol_map_borrow_name(state, bsize, "uint32", sol_new_int(state, sizeof(uint32_t)));
	sol_map_borrow_name(state, bsize, "uint64", sol_new_int(state, sizeof(uint64_t)));
	sol_map_borrow_name(state, bsize, "int8", sol_new_int(state, sizeof(int8_t)));
	sol_map_borrow_name(state, bsize, "int16", sol_new_int(state, sizeof(int16_t)));
	sol_map_borrow_name(state, bsize, "int32", sol_new_int(state, sizeof(int32_t)));
	sol_map_borrow_name(state, bsize, "int64", sol_new_int(state, sizeof(int64_t)));
	sol_map_borrow_name(state, bsize, "char", sol_new_int(state, sizeof(char)));
	sol_map_borrow_name(state, bsize, "byte", sol_new_int(state, sizeof(unsigned char)));
	sol_map_borrow_name(state, bsize, "int", sol_new_int(state, sizeof(int)));
	sol_map_borrow_name(state, bsize, "uint", sol_new_int(state, sizeof(unsigned int)));
	sol_map_borrow_name(state, bsize, "long", sol_new_int(state, sizeof(long)));
	sol_map_borrow_name(state, bsize, "ulong", sol_new_int(state, sizeof(unsigned long)));
	sol_map_borrow_name(state, bsize, "float", sol_new_int(state, sizeof(float)));
	sol_map_borrow_name(state, bsize, "double", sol_new_int(state, sizeof(double)));
	sol_map_borrow_name(state, bsize, "cstr", sol_new_int(state, sizeof(char *)));
	sol_map_borrow_name(state, bsize, "ptr", sol_new_int(state, sizeof(void *)));

	bobj = sol_new_map(state);
	sol_map_borrow_name(state, bobj, "SOL_SINGLET", sol_new_int(state, SOL_SINGLET));
	sol_map_borrow_name(state, bobj, "SOL_INTEGER", sol_new_int(state, SOL_INTEGER));
	sol_map_borrow_name(state, bobj, "SOL_FLOAT", sol_new_int(state, SOL_FLOAT));
	sol_map_borrow_name(state, bobj, "SOL_STRING", sol_new_int(state, SOL_STRING));
	sol_map_borrow_name(state, bobj, "SOL_LIST", sol_new_int(state, SOL_LIST));
	sol_map_borrow_name(state, bobj, "SOL_MAP", sol_new_int(state, SOL_MAP));
	sol_map_borrow_name(state, bobj, "SOL_MCELL", sol_new_int(state, SOL_MCELL));
	sol_map_borrow_name(state, bobj, "SOL_FUNCTION", sol_new_int(state, SOL_FUNCTION));
	sol_map_borrow_name(state, bobj, "SOL_CFUNCTION", sol_new_int(state, SOL_CFUNCTION));
	sol_map_borrow_name(state, bobj, "SOL_STMT", sol_new_int(state, SOL_STMT));
	sol_map_borrow_name(state, bobj, "SOL_EXPR", sol_new_int(state, SOL_EXPR));
	sol_map_borrow_name(state, bobj, "SOL_BUFFER", sol_new_int(state, SOL_BUFFER));
	sol_map_borrow_name(state, bobj, "SOL_DYLIB", sol_new_int(state, SOL_DYLIB));
	sol_map_borrow_name(state, bobj, "SOL_DYSYM", sol_new_int(state, SOL_DYSYM));
	sol_map_borrow_name(state, bobj, "SOL_STREAM", sol_new_int(state, SOL_STREAM));
	sol_map_borrow_name(state, bobj, "SOL_CDATA", sol_new_int(state, SOL_CDATA));
	sol_map_invert(state, bobj);

	mod = sol_new_map(state);
	sol_map_borrow_name(state, mod, "new", sol_new_cfunc(state, sol_f_buffer_new, "buffer.new"));
	sol_map_borrow_name(state, mod, "fromstring", sol_new_cfunc(state, sol_f_buffer_fromstring, "buffer.fromstring"));
	sol_map_borrow_name(state, mod, "fromobject", sol_new_cfunc(state, sol_f_buffer_fromobject, "buffer.fromobject"));
	sol_map_borrow_name(state, mod, "fromaddress", sol_new_cfunc(state, sol_f_buffer_fromaddress, "buffer.fromaddress"));
	sol_map_set_name(state, mod, "type", btype);
	sol_map_set_name(state, mod, "sizeof", bsize);
	sol_map_set_name(state, mod, "objtype", bobj);
	sol_register_module_name(state, "buffer", mod);
	sol_obj_free(mod);
	sol_obj_free(bobj);
	sol_obj_free(bsize);
	sol_obj_free(btype);

	mod = sol_new_map(state);
	sol_map_borrow_name(state, mod, "MODE_READ", sol_new_int(state, MODE_READ));
	sol_map_borrow_name(state, mod, "MODE_WRITE", sol_new_int(state, MODE_WRITE));
	sol_map_borrow_name(state, mod, "MODE_APPEND", sol_new_int(state, MODE_APPEND));
	sol_map_borrow_name(state, mod, "MODE_TRUNCATE", sol_new_int(state, MODE_TRUNCATE));
	sol_map_borrow_name(state, mod, "MODE_BINARY", sol_new_int(state, MODE_BINARY));
	sol_map_borrow_name(state, mod, "SEEK_SET", sol_new_int(state, SEEK_SET));
	sol_map_borrow_name(state, mod, "SEEK_CUR", sol_new_int(state, SEEK_CUR));
	sol_map_borrow_name(state, mod, "SEEK_END", sol_new_int(state, SEEK_END));
	sol_map_borrow_name(state, mod, "ALL", sol_new_buffer(state, "ALL", 3, OWN_NONE, NULL, NULL));
	sol_map_borrow_name(state, mod, "LINE", sol_new_buffer(state, "LINE", 4, OWN_NONE, NULL, NULL));
	sol_map_borrow_name(state, mod, "TIOCGWINSZ", sol_new_int(state, TIOCGWINSZ));
	sol_map_borrow_name(state, mod, "TIOCSWINSZ", sol_new_int(state, TIOCSWINSZ));
	sol_map_borrow_name(state, mod, "open", sol_new_cfunc(state, sol_f_stream_open, "io.open"));
	sol_map_borrow_name(state, mod, "__setindex", sol_new_cfunc(state, sol_f_io_setindex, "io.__setindex"));
	sol_map_borrow_name(state, mod, "__index", sol_new_cfunc(state, sol_f_io_index, "io.__index"));
	sol_register_module_name(state, "io", mod);
	sol_obj_free(mod);

	meths = sol_new_map(state);
	sol_map_borrow_name(state, meths, "get", sol_new_cfunc(state, sol_f_buffer_get, "buffer.get"));
	sol_map_borrow_name(state, meths, "set", sol_new_cfunc(state, sol_f_buffer_set, "buffer.set"));
	sol_map_borrow_name(state, meths, "address", sol_new_cfunc(state, sol_f_buffer_address, "buffer.address"));
	sol_map_borrow_name(state, meths, "size", sol_new_cfunc(state, sol_f_buffer_size, "buffer.size"));
	sol_map_borrow_name(state, meths, "sub", sol_new_cfunc(state, sol_f_buffer_sub, "buffer.sub"));
	sol_map_borrow_name(state, meths, "split", sol_new_cfunc(state, sol_f_buffer_split, "buffer.split"));
	sol_map_borrow_name(state, meths, "find", sol_new_cfunc(state, sol_f_buffer_find, "buffer.find"));
	sol_register_methods_name(state, "buffer", meths);
	sol_obj_free(meths);

	meths = sol_new_map(state);
	sol_map_borrow_name(state, meths, "copy", sol_new_cfunc(state, sol_f_list_copy, "list.copy"));
	sol_map_borrow_name(state, meths, "insert", sol_new_cfunc(state, sol_f_list_insert, "list.insert"));
	sol_map_borrow_name(state, meths, "remove", sol_new_cfunc(state, sol_f_list_remove, "list.remove"));
	sol_map_borrow_name(state, meths, "truncate", sol_new_cfunc(state, sol_f_list_truncate, "list.truncate"));
	sol_map_borrow_name(state, meths, "map", sol_new_cfunc(state, sol_f_list_map, "list.map"));
	sol_map_borrow_name(state, meths, "filter", sol_new_cfunc(state, sol_f_list_filter, "list.filter"));
	sol_map_borrow_name(state, meths, "reduce", sol_new_cfunc(state, sol_f_list_reduce, "list.reduce"));
	sol_register_methods_name(state, "list", meths);
	sol_obj_free(meths);

	meths = sol_new_map(state);
	sol_map_borrow_name(state, meths, "read", sol_new_cfunc(state, sol_f_stream_read_buffer, "stream.read_buffer"));
	sol_map_borrow_name(state, meths, "read_buffer", sol_new_cfunc(state, sol_f_stream_read_buffer, "stream.read_buffer"));
	sol_map_borrow_name(state, meths, "write", sol_new_cfunc(state, sol_f_stream_write, "stream.write"));
	sol_map_borrow_name(state, meths, "seek", sol_new_cfunc(state, sol_f_stream_seek, "stream.seek"));
	sol_map_borrow_name(state, meths, "tell", sol_new_cfunc(state, sol_f_stream_tell, "stream.tell"));
	sol_map_borrow_name(state, meths, "flush", sol_new_cfunc(state, sol_f_stream_flush, "stream.flush"));
	sol_map_borrow_name(state, meths, "eof", sol_new_cfunc(state, sol_f_stream_eof, "stream.eof"));
	sol_map_borrow_name(state, meths, "ioctl", sol_new_cfunc(state, sol_f_stream_ioctl, "stream.ioctl"));
	sol_register_methods_name(state, "stream", meths);
	sol_obj_free(meths);

	meths = sol_new_map(state);
	sol_map_borrow_name(state, meths, "sub", sol_new_cfunc(state, sol_f_str_sub, "str.sub"));
	sol_map_borrow_name(state, meths, "split", sol_new_cfunc(state, sol_f_str_split, "str.split"));
	sol_map_borrow_name(state, meths, "find", sol_new_cfunc(state, sol_f_str_find, "str.find"));
	sol_register_methods_name(state, "string", meths);
	sol_obj_free(meths);

	state->fnstack = sol_new_list(state);

	if(sol_has_error(state)) {
		goto cleanup;
	}

	// Perform initialization based on the user profile, if so requested.
	
	if(!(state->features & SOL_FT_NO_USR_INIT)) {
		for(i = 0; i < LENGTH(sol_AbsInitPaths); i++) {
			fp = fopen(sol_AbsInitPaths[i], "r");
			if(state->features & SOL_FT_DEBUG) {
				printf("state init: loading abs %s: ", sol_AbsInitPaths[i]);
			}
			if(fp) {
				if(state->features & SOL_FT_DEBUG) {
					printf("found");
				}
				stmt = sol_compile_file(fp);
				sol_exec(state, stmt);
				st_free(stmt);
				fclose(fp);
			} else {
				if(state->features & SOL_FT_DEBUG) {
					printf("not found");
				}
			}
			if(state->features & SOL_FT_DEBUG) {
				printf("\n");
			}
		}

		suffix = getenv("HOME");
		if(state->features & SOL_FT_DEBUG) {
			printf("state init: loading relative to %s\n", suffix);
		}
		if(suffix) {
			strncpy(sol_TempPath, suffix, TMP_PATH_SZ);
			suffix = sol_TempPath + strlen(sol_TempPath);
			for(i = 0; i < LENGTH(sol_HomeInitPaths); i++) {
				strncpy(suffix, sol_HomeInitPaths[i], TMP_PATH_SZ - (suffix - sol_TempPath));
				if(state->features & SOL_FT_DEBUG) {
					printf("state init: loading rel %s: ", sol_TempPath);
				}
				fp = fopen(sol_TempPath, "r");
				if(fp) {
					if(state->features & SOL_FT_DEBUG) {
						printf("found");
					}
					stmt = sol_compile_file(fp);
					sol_exec(state, stmt);
					st_free(stmt);
					fclose(fp);
				} else {
					if(state->features & SOL_FT_DEBUG) {
						printf("not found");
					}
				}
				if(state->features & SOL_FT_DEBUG) {
					printf("\n");
				}
			}
		}
		
		if(sol_has_error(state)) {
			goto cleanup;
		}
	}

	// We're all set!
	return 1;

cleanup:
	sol_obj_free(state->None);
	sol_obj_free(state->OutOfMemory);
	return 0;
}

void sol_state_cleanup(sol_state_t *state) {
	long i;
	sol_obj_free(state->scopes);
	sol_obj_free(state->error);
	sol_obj_free(state->None);
	sol_obj_free(state->OutOfMemory);
	sol_obj_free(state->_stdin);
	sol_obj_free(state->_stdout);
	sol_obj_free(state->_stderr);
	if(state->ret) {
		sol_obj_free(state->ret);
	}
#ifdef SOL_ICACHE
	for(i = 0; i <= (SOL_ICACHE_MAX - SOL_ICACHE_MIN); i++) {
		sol_obj_free(state->icache[i]);
	}
#endif
	sol_obj_free(state->modules);
	sol_obj_free(state->methods);
	sol_mm_finalize(state);
}

sol_object_t *sol_state_resolve(sol_state_t *state, sol_object_t *key) {
	sol_object_t *temp, *args;
	dsl_seq_iter *iter = dsl_new_seq_iter(state->scopes->seq);
	args = sol_new_list(state);
	sol_list_insert(state, args, 0, state->None);
	sol_list_insert(state, args, 1, key);
	while(!dsl_seq_iter_is_invalid(iter)) {
		sol_list_set_index(state, args, 0, dsl_seq_iter_at(iter));
		temp = CALL_METHOD(state, ((sol_object_t *) dsl_seq_iter_at(iter)), index, args);
		if(!sol_is_none(state, temp)) {
			dsl_free_seq_iter(iter);
			sol_obj_free(args);
			return temp;
		}
		sol_obj_free(temp);
		dsl_seq_iter_next(iter);
	}
	dsl_free_seq_iter(iter);
	sol_obj_free(args);

	temp = sol_get_module(state, key);
	if(!sol_is_none(state, temp)) {
		return temp;
	}
	sol_obj_free(temp);

	return sol_incref(state->None);
}

sol_object_t *sol_state_resolve_name(sol_state_t *state, const char *name) {
	sol_object_t *key = sol_new_buffer(state, (char *) name, strlen(name), OWN_NONE, NULL, NULL), *temp;

	if(sol_has_error(state)) {
		return sol_incref(state->None);
	}

	temp = sol_state_resolve(state, key);
	sol_obj_free(key);
	return temp;
}

void sol_state_assign(sol_state_t *state, sol_object_t *key, sol_object_t *val) {
	sol_object_t *cur = state->scopes, *next, *active = NULL, *args;

	if(!cur) {
		sol_set_error_string(state, "Global state does not exist");
		return;
	}

	active = sol_list_get_index(state, state->scopes, sol_list_len(state, state->scopes) - 1);

	if(!active || sol_is_none(state, cur)) {
		sol_set_error_string(state, "No scopes exist");
		return;
	}

	args = sol_new_list(state);
	sol_list_insert(state, args, 0, active);
	sol_list_insert(state, args, 1, key);
	sol_list_insert(state, args, 2, val);
	sol_obj_free(CALL_METHOD(state, active, setindex, args));
	sol_obj_free(args);
}

void sol_state_assign_name(sol_state_t *state, const char *name, sol_object_t *val) {
	sol_object_t *key = sol_new_buffer(state, (char *) name, strlen(name), OWN_NONE, NULL, NULL);

	if(sol_has_error(state)) {
		return;
	}

	sol_state_assign(state, key, val);
	sol_obj_free(key);
}

void sol_state_assign_l(sol_state_t *state, sol_object_t *key, sol_object_t *val) {
	sol_object_t *cur = state->scopes, *args;

	cur = sol_list_get_index(state, state->scopes, 0);

	if(!cur || sol_is_none(state, cur)) {
		sol_set_error_string(state, "Local state does not exist");
		return;
	}

	args = sol_new_list(state);
	sol_list_insert(state, args, 0, cur);
	sol_list_insert(state, args, 1, key);
	sol_list_insert(state, args, 2, val);
	sol_obj_free(CALL_METHOD(state, cur, setindex, args));
	sol_obj_free(args);
}

void sol_state_assign_l_name(sol_state_t *state, const char *name, sol_object_t *val) {
	sol_object_t *key = sol_new_buffer(state, (char *) name, strlen(name), OWN_NONE, NULL, NULL);

	if(sol_has_error(state)) {
		return;
	}

	sol_state_assign_l(state, key, val);
	sol_obj_free(key);
}

void sol_state_push_scope(sol_state_t *state, sol_object_t *scope) {
	sol_list_push(state, state->scopes, scope);
}

sol_object_t *sol_state_pop_scope(sol_state_t *state) {
	return sol_list_pop(state, state->scopes);
}

sol_object_t *sol_get_error(sol_state_t *state) {
	return sol_incref(state->error);
}

sol_object_t *sol_set_error(sol_state_t *state, sol_object_t *err) {
	state->error = sol_incref(err);
	sol_init_traceback(state);
	return sol_incref(state->None);
}

sol_object_t *sol_set_error_string(sol_state_t *state, const char *serr) {
	sol_object_t *err = sol_new_buffer(state, strdup(serr), strlen(serr), OWN_FREE, NULL, NULL), *res;

	if(sol_has_error(state)) {
		sol_obj_free(err);
		return sol_incref(state->None);
	}

	res = sol_set_error(state, err);
	sol_obj_free(err);

	return res;
}

void sol_clear_error(sol_state_t *state) {
	// This silliness ensures we don't accidentally free None.
	sol_object_t *olderr = state->error;
	state->error = sol_incref(state->None);
	sol_obj_free(olderr);
}

void sol_init_traceback(sol_state_t *state) {
	if(state->traceback) {
		sol_obj_free(state->traceback);
	}
	state->traceback = sol_new_list(state);
}

void sol_add_traceback(sol_state_t *state, sol_object_t *node) {
	sol_object_t *pair = sol_new_list(state), *scope = sol_list_get_index(state, state->scopes, 0);
	sol_list_insert(state, pair, 0, node);
	sol_list_insert(state, pair, 1, scope);
	sol_obj_free(scope);
	if(sol_list_len(state, state->fnstack) > 0) {
		scope = sol_list_get_index(state, state->fnstack, 0);
		sol_list_insert(state, pair, 2, scope);
		sol_obj_free(scope);
	} else {
		sol_list_insert(state, pair, 2, state->None);
	}
	sol_list_insert(state, state->traceback, 0, pair);
	sol_obj_free(pair);
}

sol_object_t *sol_traceback(sol_state_t *state) {
	if(state->traceback) {
		return sol_incref(state->traceback);
	}
	return sol_incref(state->None);
}

void sol_register_module(sol_state_t *state, sol_object_t *key, sol_object_t *val) {
	sol_map_set(state, state->modules, key, val);
}

void sol_register_module_name(sol_state_t *state, char *name, sol_object_t *val) {
	sol_map_set_name(state, state->modules, name, val);
}

sol_object_t *sol_get_module(sol_state_t *state, sol_object_t *key) {
	return sol_map_get(state, state->modules, key);
}

sol_object_t *sol_get_module_name(sol_state_t *state, char *name) {
	return sol_map_get_name(state, state->modules, name);
}

void sol_register_methods(sol_state_t *state, sol_object_t *key, sol_object_t *val) {
	sol_map_set(state, state->methods, key, val);
}

void sol_register_methods_name(sol_state_t *state, char *name, sol_object_t *val) {
	sol_map_set_name(state, state->methods, name, val);
}

sol_object_t *sol_get_methods(sol_state_t *state, sol_object_t *key) {
	return sol_map_get(state, state->methods, key);
}

sol_object_t *sol_get_methods_name(sol_state_t *state, char *name) {
	return sol_map_get_name(state, state->methods, name);
}

sol_object_t *sol_f_io_index(sol_state_t *state, sol_object_t *args) {
	sol_object_t *self = sol_list_get_index(state, args, 0), *name = sol_list_get_index(state, args, 1), *namestr = sol_cast_string(state, name), *res;
	if(sol_string_eq(state, namestr, "stdin")) {
		sol_obj_free(name);
		sol_obj_free(namestr);
		return sol_incref(state->_stdin);
	}
	if(sol_string_eq(state, namestr, "stdout")) {
		sol_obj_free(name);
		sol_obj_free(namestr);
		return sol_incref(state->_stdout);
	}
	if(sol_string_eq(state, namestr, "stderr")) {
		sol_obj_free(name);
		sol_obj_free(namestr);
		return sol_incref(state->_stderr);
	}
	sol_obj_free(namestr);
	res = sol_map_get(state, self, name);
	sol_obj_free(self);
	sol_obj_free(name);
	return res;
}

sol_object_t *sol_f_io_setindex(sol_state_t *state, sol_object_t *args) {
	sol_object_t *name = sol_list_get_index(state, args, 1), *value = sol_list_get_index(state, args, 2);
	sol_object_t *namestr = sol_cast_string(state, name), *io;
	if(sol_string_eq(state, namestr, "stdin")) {
		sol_obj_free(state->_stdin);
		state->_stdin = sol_incref(value);
		goto done;
	}
	if(sol_string_eq(state, namestr, "stdout")) {
		sol_obj_free(state->_stdout);
		state->_stdout = sol_incref(value);
		goto done;
	}
	if(sol_string_eq(state, namestr, "stderr")) {
		sol_obj_free(state->_stderr);
		state->_stderr = sol_incref(value);
		goto done;
	}
	io = sol_list_get_index(state, args, 0);
	sol_map_set(state, io, name, value);
	sol_obj_free(io);
done:
	sol_obj_free(namestr);
	sol_obj_free(value);
	sol_obj_free(name);
	return sol_incref(state->None);
}

sol_object_t *sol_get_stdin(sol_state_t *state) {
	return sol_incref(state->_stdin);
}

sol_object_t *sol_get_stdout(sol_state_t *state) {
	return sol_incref(state->_stdout);
}

sol_object_t *sol_get_stderr(sol_state_t *state) {
	return sol_incref(state->_stderr);
}

void sol_ops_init(sol_ops_t *ops) {
	ops->tname = "unknown";
	ops->tflags = 0;
	ops->add = sol_f_not_impl;
	ops->sub = sol_f_not_impl;
	ops->mul = sol_f_not_impl;
	ops->div = sol_f_not_impl;
	ops->mod = sol_f_not_impl;
	ops->pow = sol_f_not_impl;
	ops->tbang = sol_f_tbang;
	ops->band = sol_f_not_impl;
	ops->bor = sol_f_not_impl;
	ops->bxor = sol_f_not_impl;
	ops->blsh = sol_f_not_impl;
	ops->brsh = sol_f_not_impl;
	ops->bnot = sol_f_not_impl;
	ops->cmp = sol_f_default_cmp;
	ops->call = sol_f_not_impl;
	ops->index = sol_f_not_impl;
	ops->setindex = sol_f_not_impl;
	ops->len = sol_f_not_impl;
	ops->iter = sol_f_not_impl;
	ops->toint = sol_f_not_impl;
	ops->tofloat = sol_f_not_impl;
	ops->tostring = sol_f_default_tostring;
	ops->tobuffer = sol_f_default_tobuffer;
	ops->repr = sol_f_default_repr;
	ops->init = sol_f_no_op;
	ops->free = sol_f_no_op;
}
