gcc -c -g dsl/seq.c
gcc -c -g dsl/list.c
gcc -c -g dsl/array.c
gcc -c -g dsl/generic.c
gcc -c -g lex.yy.c
gcc -c -g parser.tab.c
gcc -c -g astprint.c
gcc -c -g runtime.c
gcc -c -g gc.c
gcc -c -g object.c
gcc -c -g state.c
gcc -c -g builtins.c
gcc -c -g solrun.c
gcc -g *.o -o sol -lm -ldl
