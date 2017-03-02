CFLAGS= -g $(BUILD_DEFINES)
LDFLAGS= -lm -ldl -lreadline
OBJ= lex.yy.o parser.tab.o dsl/seq.o dsl/list.o dsl/array.o dsl/generic.o astprint.o runtime.o gc.o object.o state.o builtins.o solrun.o ser.o sol_help.o

ifndef CC
	CC:= gcc
endif

ifndef OBJCOPY
	OBJCOPY:= objcopy
endif

ifndef OBJDUMP
	OBJDUMP:= objdump
endif

ifndef DESTDIR
	DESTDIR:= /usr/local/
endif

include VERSION_INFO
include ARCH_INFO

BUILD_DEFINES:= -DSOL_BUILD_HOST="\"$(shell uname -n)\"" -DSOL_BUILD_KERNEL="\"$(shell uname -s)\"" -DSOL_BUILD_ARCH="\"$(shell uname -m)\"" -DSOL_BUILD_REV="\"$(shell git rev-parse --short HEAD)$(shell git diff-index --quiet HEAD || echo '-dirty')\""

SOL_VER:=$(MAJOR).$(MINOR)$(RELEASE)$(PATCH)
LINKED_VERS:=sol sol$(MAJOR) sol$(MAJOR).$(MINOR)

.PHONY: install install_bin all test clean docs

all: dsl $(LINKED_VERS)

install: install_bin

install_bin: sol$(SOL_VER) $(LINKED_VERS)
	install $? $(DESTDIR)/bin/

uninstall: uninstall_bin

uninstall_bin:
	rm $(DESTDIR)/bin/sol$(SOL_VER)
	for fname in $(LINKED_VERS); do rm $(DESTDIR)/bin/$$fname; done

$(LINKED_VERS): sol$(SOL_VER)
	rm $@; ln -s $? $@
	
sol$(SOL_VER): $(OBJ)
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@

test: all $(sort $(patsubst tests/%.sol,test_%,$(wildcard tests/*.sol))) $(sort $(patsubst tests/%.sol,testcomp_%,$(wildcard tests/*.sol)))


test_%: tests/%.sol
	./sol r $?

testcomp_%: tests/%.sol
	./sol rc $? /dev/fd/1 | ./sol C

dsl:
	git submodule init && git submodule sync && git submodule update

VERSION_INFO: sol.h
	perl -n -e '/#define SOL_VERSION "([[:digit:]]+)\.([[:digit:]]+)(.)([[:digit:]]+)"/ && print "MAJOR:=$$1\nMINOR:=$$2\nRELEASE:=$$3\nPATCH:=$$4\n"' $? > $@

ARCH_INFO: gc.o
	$(OBJDUMP) -f $? | perl -n -e '/file format ([^-]+-(.+))$$/ && print "HOST_ARCH:=$$2\nHOST_ELF:=$$1\n"' > $@

%.o: %.c
	$(CC) -c -o $@ $? $(CFLAGS)

%.o: %.txt | ARCH_INFO
	$(OBJCOPY) -B i386 -I binary -O $(HOST_ELF) $? $@

%.tab.c %.tab.h: %.y
	bison -rall -fall -d $?

lex.yy.c: tokenizer.lex parser.tab.h
	flex $<

clean:
	rm -f *.o dsl/*.o sol

docs: Doxyfile 
	doxygen Doxyfile
	sphinx-build -b html . ./_build
