#include <stdio.h>
#include "ast.h"
#include "parser.tab.h"

int main(int argc, char **argv) {
    stmt_node *program;
    sol_state_t state;
    char *c;
    int printtree = 0;
	FILE *prgstream = stdin;

    if(argc>1) {
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
					if(argc<2) {
						printf("r option requires file\n");
						return 1;
					}
					prgstream = fopen(argv[2], "r");
            }
            c++;
        }
    }
    
    if(!prgstream) {
		printf("No input program (check filenames)\n");
		return 1;
	}

    program = sol_compile_file(prgstream);
	
	if(prgstream!=stdin) fclose(prgstream);

	sol_state_init(&state);
    if(printtree) st_print(&state, program);

    if(program) {
        sol_exec(&state, program);
		if(sol_has_error(&state)) {
			printf("Error: ");
			ob_print(state.error);
			printf("\n");
		}
		//st_free(program);
		sol_state_cleanup(&state);
        return 0;
    }

    printf("NULL program (probably a syntax error)\n");

    return 1;
}
