bison -rall -fall -d parser.y
flex tokenizer.lex
gcc -c -g lex.yy.c
gcc -c -g parser.tab.c
gcc -c -g astprint.c
gcc -c -g runtime.c
gcc -c -g object.c
gcc -c -g state.c
gcc -c -g builtins.c
gcc -c -g solrun.c
gcc -g -lm *.o -o sol
