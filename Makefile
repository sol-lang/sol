CFLAGS= -g -DDEBUG_CC
OBJ= lex.yy.o parser.tab.o dsl/seq.o dsl/list.o dsl/array.o dsl/generic.o astprint.o runtime.o gc.o object.o state.o builtins.o solrun.o

all: $(OBJ)
	git submodule init && git submodule sync && git submodule update
	gcc $(CFLAGS) $? -o sol -lm -ldl

%.o: %.c
	gcc -c -o $@ $? $(CFLAGS)

clean:
	rm -f *.o dsl/*.o sol
