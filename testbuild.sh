bison -rall -fall -d parser.y
flex tokenizer.lex
gcc -c -g lex.yy.c
gcc -c -g parser.tab.c
gcc -c -g astprint.c
gcc -g lex.yy.o parser.tab.o astprint.o -o astprint
