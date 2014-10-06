#include <stdio.h>
#include "ast.h"
#include "parser.tab.h"

int main(int argc, char **argv) {
    stmt_node *program;
    sol_state_t state;
    char *c;
    int printtree = 0;

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
            }
            c++;
        }
    }

    program = sol_compile_file(stdin);

    if(printtree) st_print(program);

    if(program) {
        sol_state_init(&state);
        sol_exec(&state, program);
		if(sol_has_error(&state)) {
			printf("Error: ");
			ob_print(state.error);
			printf("\n");
		}
		//st_free(program);
        return 0;
    }

    printf("NULL program (probably a syntax error)\n");

    return 1;
}
