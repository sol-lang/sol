API Conventions
===============

This document is intended to be a quick rundown on the necessary information to
start extending and modifying Sol in its source form.

Reference Counting
------------------

Objects in Sol are *reference-counted* for memory management--that is, when
initially allocated (in `sol_alloc_object`), they are set to a reference count
(see the refcnt member) of 1. Every call to `sol_obj_free` will decrement the
reference count of that object, and, when that reference count reaches zero,
the memory is freed (on the assumption that no other references to that object
exist). This does *not* prevent the occurrence of cycles, and Sol has no
protection against this at the moment.

As a general rule, *all* functions that return object pointers return a *new
reference*--the *caller* is expected to `sol_obj_free` that reference when it
is no longer needed (including immediately, for example). It is also the rule
that functions that take object pointers will *borrow* those references as
needed; for example, data structures that store objects will hold a reference.

Sol State
---------

The Sol state (type `sol_state_t`) is a structure that is passed to nearly all
functions in the API, and is responsible for managing all the global state of
the interpreter. Due to this separation, Sol is fully reentrant. Designers
looking to modify Sol in a way that requires the introduction of data across
scopes and call frames may add fields to the state; extenders may use or refer
to the state uniquely to determine context, or use objects stored within that
state to accomplish that task.

Naming
------

Names exported in `sol.h` should be safe to use publicly--that is, they should
have a low chance of conflicting with names used in other programs; the typical
convention is to prefix every such name with "sol_". Names in `ast.h` are not so
restricted, and are typically included in many of the internal C files. `ast.h`
includes `sol.h`, and so only one of the two headers needs to be used. Note that
some references in structures defined in `sol.h` refer to types in `ast.h`, and
these are intentionally left as void pointers; Comments and other documentation
should indicate their true type.

File Structure
--------------

This list represents the file structure at this time, and may not be kept up to
date:

- object.c contains all routines for the runtime, including creation,
  destruction, and manipulation of most objects.
- builtins.c contains the vast majority of built-in functionality, including
  most of the type methods as included in the `sol_ops_t` structures.
- runtime.c contains the interpreter and related routines, including execution
  and evaluation, ones defining the calling convention, and the manipulation of
  ASTs.
- state.c contains state management routines, such as those for initializing
  and finalizing a state, getting or setting errors, and resolving names in
  scopes.  Module, type method, and other initialization is done here.
- gc.c contains the memory management routines.
- astprint.c contains routines for displaying ASTs on stdout.
- solrun.c contains the main() function for the interpreter.
- cdata.c contains definitions of various CDATA (C interface) types--presently,
  only the CStruct (a way for C code to specify struct layouts to Sol
  programs).
- util.c contains utility routines--importantly, a safe call/return trampoline
  for extension code.
