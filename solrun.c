#include <stdio.h>
#include "ast.h"
#include "parser.tab.h"

#ifndef NO_HELP
extern char _binary_sol_help_txt_start, _binary_sol_help_txt_end;
#endif

int main(int argc, char **argv) {
	stmt_node *program;
	sol_state_t state;
	char *c;
	int printtree = 0, clean = 1, argidx = 2;
	FILE *prgstream = stdin, *compstream = NULL;
	int result = 0, compile = 0, compiled = 0, html = 0;
	unsigned i;

	state.features = 0;

	if(argc > 1) {
		c = argv[1];
		while(*c) {
			switch(*c) {
				case 'd':
					yydebug = 1;
					break;

				case 'D':
					state.features |= SOL_FT_DEBUG;
					break;

				case 't':
					printtree = 1;
					break;

				case 'r':
					if(argc < argidx) {
						printf("r option requires file\n");
						return 2;
					}
					prgstream = fopen(argv[argidx++], "r");
					break;

				case 'i':
					state.features |= SOL_FT_NO_USR_INIT;
					break;

				case 'c':
					compile = 1;
					if(argc < argidx) {
						printf("c option requires file\n");
						return 2;
					}
					compstream = fopen(argv[argidx++], "wb");
					break;

				case 'C':
					compiled = 1;
					break;

				case 'V':
					printf(SOL_BUILD_ID "\n");
				case 'h':
#ifndef NO_HELP
					fwrite(
						&_binary_sol_help_txt_start,
						1,
						&_binary_sol_help_txt_end - &_binary_sol_help_txt_start,
						stdout
					);
#else
					printf("Sorry, no help in this version (-DNO_HELP)!\n");
#endif
					printf("\nThis Sol is configured to use the following initialization files (it is never an\nerror if these files cannot be read, but errors propagate normally):\n");
					for(i = 0; i < sizeof(sol_AbsInitPaths) / sizeof(sol_AbsInitPaths[0]); i++)
						if(sol_AbsInitPaths[i])
							printf("- %s\n", sol_AbsInitPaths[i]);
					for(i = 0; i < sizeof(sol_HomeInitPaths) / sizeof(sol_HomeInitPaths[0]); i++)
						if(sol_HomeInitPaths[i])
							printf("- $HOME%s\n", sol_HomeInitPaths[i]);
					return 0;
					break;

				case 'H':
					html = 1;
					break;
			}
			c++;
		}
	}

	if(!prgstream) {
		printf("No input program (check filenames)\n");
		return 2;
	}

	if(compiled) {
		program = sol_deser_stmt(prgstream);
	} else {
		if(html) {
			sol_write_html(prgstream);
			return;
		}
		program = sol_compile_file(prgstream);
	}
	
	if(!program) {
		printf("NULL program (probably a syntax error)\n");
		return 2;
	}

	if(prgstream != stdin) {
		fclose(prgstream);
	}

	if(compile) {
		sol_ser_stmt(compstream, program);
		return 0;
	}

	if(!sol_state_init(&state)) {
		printf("State init error (internal bug)\n");
		result = 2;
		clean = 0;
		goto out_results;
	}

	if(printtree) {
		st_print(&state, program);
	}

	sol_exec(&state, program);

out_results:

	if(sol_has_error(&state)) {
		printf("Error: ");
		ob_print(state.error);
		printf("\n");
		result = 1;
	}

	if(state.ret) {
		printf("Toplevel return: ");
		ob_print(state.ret);
		printf("\n");
		if(sol_is_int(state.ret)) {
			result = state.ret->ival;
		}
	}
	st_free(program);
	if(clean) sol_state_cleanup(&state);

	return result;
}
