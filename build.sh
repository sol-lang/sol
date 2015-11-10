#!/bin/sh
if [ ! -f .submodule_stamp ]; then
    git submodule init && git submodule sync && git submodule update
    touch .submodule_stamp
fi

if [ -z "$CFLAGS" ]; then
	# Valid flags to add here:
	# -DDEBUG_GC : Turn on debug GC (all memory allocates/frees go to a file, use gcstat.py to get statistics)
	# -DSOL_ICACHE_MIN : Minimum integer to cache in the state
	# -DSOL_ICACHE_MAX : Maximum integer to cache in the state (if MAX < MIN, caching is disabled)
    CFLAGS="-g -DDEBUG_GC"
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
gcc $CFLAGS *.o -o solace -lm -ldl
