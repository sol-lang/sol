override CFLAGS:= -g $(BUILD_DEFINES) $(CFLAGS)
override LDFLAGS:= -lfl -lm -ldl -lreadline $(LDFLAGS)
OBJ= lex.yy.o parser.tab.o dsl/seq.o dsl/list.o dsl/array.o dsl/generic.o astprint.o runtime.o gc.o object.o state.o builtins.o solrun.o ser.o

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

ifdef NO_HELP
	override CFLAGS+= -DNO_HELP
else
	OBJ+= sol_help.o
endif

ifndef STDOUT_FILENAME
	STDOUT_FILENAME:=/dev/fd/1
endif

include VERSION_INFO
include ARCH_INFO

BUILD_DEFINES:= -DSOL_BUILD_HOST="\"$(shell uname -n)\"" -DSOL_BUILD_KERNEL="\"$(shell uname -s)\"" -DSOL_BUILD_ARCH="\"$(shell uname -m)\"" -DSOL_BUILD_REV="\"$(shell git rev-parse --short HEAD)$(shell git diff-index --quiet HEAD || echo '-dirty')\""

SOL_VER:=$(MAJOR).$(MINOR)$(RELEASE)$(PATCH)$(SUFFIX)
LINKED_VERS:=sol sol$(MAJOR) sol$(MAJOR).$(MINOR)

.PHONY: install install_bin install_bindir install_lib install_libdir uninstall uninstall_bin uninstall_lib all test clean docs

all: dsl $(LINKED_VERS)

install: install_bindir install_libdir install_bin install_lib

install_bin: sol$(SOL_VER) $(LINKED_VERS)
	install $? $(DESTDIR)/bin/

install_lib: programs tests
	cp -r $? $(DESTDIR)/lib/sol$(SOL_VER)/

install_bindir: 
	install -d $(DESTDIR)/bin/

install_libdir:
	install -d $(DESTDIR)/lib/sol$(SOL_VER)/

uninstall: uninstall_bin uninstall_lib

uninstall_bin:
	rm $(DESTDIR)/bin/sol$(SOL_VER) || true
	for fname in $(LINKED_VERS); do rm $(DESTDIR)/bin/$$fname || true; done

uninstall_lib:
	rm -r $(DESTDIR)/lib/sol$(SOL_VER)/{programs,tests}

$(LINKED_VERS): sol$(SOL_VER)
	rm $@; ln -s $? $@
	
sol$(SOL_VER): $(OBJ)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

test: all $(sort $(patsubst tests/%.sol,test_%,$(wildcard tests/*.sol))) $(sort $(patsubst tests/%.sol,testcomp_%,$(wildcard tests/*.sol)))


test_%: tests/%.sol
	./sol r $?

testcomp_%: tests/%.sol
	./sol rc $? $(STDOUT_FILENAME) | ./sol C

profile: all prof profile-boot $(sort $(patsubst tests/%.sol,profile_%,$(wildcard tests/*.sol))) profilecomp-boot $(sort $(patsubst tests/%.sol,profilecomp_%,$(wildcard tests/*.sol)))

prof:
	mkdir prof

profile-boot: programs/test.sol
	LLVM_PROFILE_FILE=prof/boot.prof ./sol r $?

profile_%: tests/%.sol
	LLVM_PROFILE_FILE=prof/sol.$(basename $(notdir $?)).prof ./sol r $?

profilecomp-boot: programs/test.sol
	LLVM_PROFILE_FILE=prof/bootcomp.comp.prof ./sol rc $? $(STDOUT_FILENAME) | LLVM_PROFILE_FILE=prof/bootcomp.run.prof ./sol C

profilecomp_%: tests/%.sol
	LLVM_PROFILE_FILE=prof/solcomp.$(basename $(notdir $?)).comp.prof ./sol rc $? $(STDOUT_FILENAME) | LLVM_PROFILE_FILE=prof/solcomp.$(basename $(notdir $?)).run.prof ./sol C

prof/sol.html: profile
	llvm-profdata merge -sparse prof/*.prof -o prof/sol.prof.merged
	llvm-cov show -instr-profile prof/sol.prof.merged ./sol -format=html > $@

all-profile: prof/sol.html

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
