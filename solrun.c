#include <stdio.h>
#include "ast.h"

int main(int argc, char **argv) {
    stmt_node *program;
    sol_state_t state;

    program = sol_compile_file(stdin);

    st_print(program);

    if(program) {
        sol_state_init(&state);
        sol_exec(&state, program);
        return 0;
    }

    return 1;
}
