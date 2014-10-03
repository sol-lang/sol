#include <stdio.h>
#include "ast.h"
#include "parser.tab.h"

int main(int argc, char **argv) {
    stmt_node *program;
    sol_state_t state;
	
	if(argc > 1) yydebug = 1;

    program = sol_compile_file(stdin);

    st_print(program);

    if(program) {
        sol_state_init(&state);
        sol_exec(&state, program);
		if(sol_has_error(&state)) {
			printf("Error: ");
			ob_print(state.error);
			printf("\n");
		}
        return 0;
    }

    return 1;
}
