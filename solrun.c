#include <stdio.h>
#include "ast.h"
#include "parser.tab.h"

int main(int argc, char **argv) {
	stmt_node *program;
	sol_state_t state;
	char *c;
	int printtree = 0;
	FILE *prgstream = stdin;
	int result = 0;

	if(argc > 1) {
		c = argv[1];
		while(*c) {
			switch(*c) {
				case 'd':
					yydebug = 1;
					break;

				case 't':
					printtree = 1;
					break;

				case 'r':
					if(argc < 2) {
						printf("r option requires file\n");
						return 2;
					}
					prgstream = fopen(argv[2], "r");
			}
			c++;
		}
	}

	if(!prgstream) {
		printf("No input program (check filenames)\n");
		return 2;
	}

	program = sol_compile_file(prgstream);
	
	if(!program) {
		printf("NULL program (probably a syntax error)\n");
		return 2;
	}

	if(prgstream != stdin) {
		fclose(prgstream);
	}

	sol_state_init(&state);
	if(printtree) {
		st_print(&state, program);
	}

	sol_exec(&state, program);

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
	sol_state_cleanup(&state);

	return result;
}
