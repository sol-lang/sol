if [ ! -f .submodule_stamp ]; then
    git submodule init && git submodule sync && git submodule update
    touch .submodule_stamp
fi

if [ -z "$CFLAGS" ]; then
    CFLAGS=-g
fi

gcc -c $CFLAGS dsl/seq.c
gcc -c $CFLAGS dsl/list.c
gcc -c $CFLAGS dsl/array.c
gcc -c $CFLAGS dsl/generic.c
gcc -c $CFLAGS lex.yy.c
gcc -c $CFLAGS parser.tab.c
gcc -c $CFLAGS astprint.c
gcc -c $CFLAGS runtime.c
gcc -c $CFLAGS gc.c
gcc -c $CFLAGS object.c
gcc -c $CFLAGS state.c
gcc -c $CFLAGS builtins.c
gcc -c $CFLAGS solrun.c
gcc $CFLAGS *.o -o sol -lm -ldl
