sol
===

Sol a scripting language (whose name is subject to change) that aims to take the best of Lua and Python, and look a little bit like Javascript in the process :) . Sol's most outstanding features include:

* A rather lightweight, [mostly] re-entrant, multi-user runtime that is in the process of being optimized and made cross-platform.
* A Flex/Bison compiler--yes, it is a compiled language, not an interpreted one, but the runtime has access to the compiler--with the source files distributed (you'll need Flex and Bison to rebuild the grammar, but you don't need it to build the rest of the language).
* A dead simple API that's a bit reminiscent of Python's, but without all the calisthenics.
* Support for multiple paradigms, including object orientation.
* Near-total type agnosticism in the runtime: objects are usually tested for features, not types.
* Some neat language features, like C-style scoping and closures.

Here's a taste of what the language itself looks like:

```lua
-- This is a comment, and there's an assignment below!
a = 1
while a < 10 do
  print("a is:", a)
  a += 1
end

-- "Pythonic" for loops; any expression can be used, so long as it
-- returns a function that will be called until it returns None
for i in range(10) do print(i) end -- Note Lua-ish keyword delimiting

-- "func" seems like a good compromise between "def" and "function" :D
-- (This is a currying add function)
func outer(a)
  return func inner(b, a=a)
    return a+b
  end
end

-- Alternatively...
outer = lambda(a) lambda(b, a=a) a + b end end

-- (...and this is an iterator)
func count(j)
  inner = func (i = 0, max = j)  -- Function definitions are expressions, like in Lua
    if i >= max then
      return  -- If no value is given, None is implied
    else
      i += 1
      return i - 1
    end
  end
  return inner
end

-- Python-style list definitions (and a separate list type), and Lua-style
-- method calls--an eclectic mix.
print([1, 2, 3, 4, 5]:map(func (i) return i*3 end))

-- Lua-like map definitions
print({a=1, b=2, ["c"]=3, [4]=5, ["with more spaces"]={health=100, speed=2}})
-- ...and metamethods
object = {__index = func(obj, idx) print("Index", obj, "with", idx); return idx end,
          __setindex = func(obj, idx, val) print("Set index", idx, "of", obj, "to", val) end,
          __call = func(obj, arg1, arg2) print("Called", obj, "with args", arg1, arg2); return arg1+arg2 end}
-- No metatables, but __index can be assigned to another map, which has nearly the same effect

-- Lua-ish error handling
func bad(x)
  x.i=5
  return "thing"
end

res = try(bad, {}) -- Returns 1 (or true), "thing"
res = try(bad, None) -- Reurns 0 (or false), "Undefined method" -- you can't index None
res = try(bad) -- Also fails; unbound arguments are assigned to None by default
res = try(error, 1234) -- Fails, returning [0, 1234] -- errors can be any object

-- Full suppport for self-modifying code, and invoking the compiler
func a() return 0 end
func b() return 2 end

temp = a.stmt
a.stmt = b.stmt
b.stmt = temp
-- a now returns 2, and b now returns 0

code = parse('print("Hi!"); return 4')
a.stmt = code
b.stmt = code
-- a and b now return 4 (and print "Hi!")

parse('print("Good day!")')() -- Does the thing; shortcut is "exec"
q = parse('8 + 13 * 2').stmtlist[0].expr() -- Returns the value (should be...34?); shortcut "eval"
-- Runs the thing in the environment; the passed map can be modified by the code
-- (as if the keys were local variables)
z = parse('8 + a - b').stmtlist[0].expr({a=5, b=7})
```

That's a really brief taste; you can look at the `test.sol` file for a larger collection of Sol code, which also happens to be the test suite. If you'd like to run it on your machine, read on.

Buiding/Installation
--------------------

First off, *you should clone this repository with --recursive* if you want to get the submodules in one go. If you've already cloned it, don't worry; just run this:

```
git submodule init
git submodule update
```

This should pull in the requisite build dependencies. (For more on this, see git's documentation on [Cloning a Project with Submodules](http://git-scm.com/book/en/v2/Git-Tools-Submodules#Cloning-a-Project-with-Submodules).)

A typical `make` should suffice to build the project. There is no `make install` yet, as there's no agreed-upon location for its support files. The executable runtime `sol` should be in the working directory (it is explicitly ignored, and won't be committed to the repo).

Running
-------

The entire `main` function is inside the tiny `solrun.c` file--you can appreciate how simple the API is by the meager size of this file :) . This file is painfully simple; it expects the program as input on stdin, compiles it when it reaches the end of file, and (assuming there are no syntax errors) runs the program afterward. You can easily see how this can be embedded in an existing application, which leads me to the next section...

Extending
---------

If you're looking to embed Sol in an application (which is more-or-less what it was designed for), you'll want to read both `sol.h` and `solrun.c`; most of the API is fairly intuitive. The whole process of setting up an extended Sol environment (inside an application, for example), can be roughly described by this process:

1. **Initialize the state.** Allocate a `sol_state_t` somewhere (the stack is fine) and pass a pointer to `sol_state_init`. This large function (in `state.c`) initializes the default runtime and all of its amenities.
2. **Define custom types.** Sol supports a special object type called `SOL_CDATA` whose `sol_ops_t` structure--representation which operations the object supports--is user defined. You can use this to implement custom types; the most straightforward methods are probably `index` and `setindex`, as well as `call`; see `builtins.c` for some implementations. You'll note that almost all of the members are `sol_cfunc_t`; I'll get to this in the next step.
3. **Define functions.** Functions that can be called from the runtime are mostly `sol_cfunc_t`, which take a `sol_state_t` pointer to the state (with all the runtime-global information) and a `sol_object_t` pointer to a `SOL_LIST` containing the arguments. The arguments are well-defined for all operations except call (again, see the builtins), and all functions implemented in the `sol_ops_t` structure can expect to have an object of the appropriate type as the first argument (item in the list). Functions can also be exposed directly to the runtime (as callable functions) by creating a `SOL_CFUNCTION` object (using `sol_new_cfunc`), in which case the argument list is entirely dictated by the Sol program. All functions are expected to return a value, even if the value is unused by the runtime (e.g., the `setindex` call). If no particular value is appropriate, return `sol_incref(state->None)`.
4. **Bind names.** You can assign names in the global scope by using `sol_state_assign` and `sol_state_assign_name`. (You can also assign them in the local scope, which starts out the same as the global scope, by using the `_l` variants of these functions.) If you'd prefer not to pollute the global namespace with your functions (a good choice), you can use an intermediate map to hold your functions and assign it, or register it as a module using `sol_register_module` (and its `_name` variant). The only difference in this approach is that modules are always available at *above* the global level and cannot be overwritten by Sol programs (they can be shadowed by locals, though).
5. **Compile and execute programs.** Compiling Sol programs is state-agnostic, and is accessible via the functions in `ast.h` (notably, `sol_compile` and `sol_compile_file`). These return `stmt_node` pointers which contain the entirety of the Sol program (a type also defined in `ast.h`). You can pass this to `sol_exec` (with the runtime state) to run the program. You can also use `sol_comp_as_expr` to get an `expr_node` pointer (or `NULL`, if this cannot be done), and evaluate the expression with `sol_eval` to get a `sol_object_t` value back.
6. **Clean up.** Call `sol_state_cleanup` with the state when you're done for the day.

Although step 1 should definitely precede steps 5 and 6, steps 2-4 are optional (though helpful), and this process can be repeated with independent states as many times as needed, and as many programs as needed can be executed arbitrarily many times in step 5 before cleaning up. It should be noted that Sol code can also do arbitrary code execution of your functions and yet more Sol code (including compilation), so you should treat anything Sol can modify as volatile at the execution points, and check the state for errors on return (the `sol_has_error` macro and `sol_clear_error` function will be your friends)--a state with errors will refuse to run any code, for potentially mysterious reasons.

Todo
----

Most of what needs to be done is addressing these issues:

**Sol leaks memory.** As confirmed with Valgrind (running memcheck), a normal Sol run loses some objects. A great deal of work has been invested in finding and fixing these bugs, but they remain elusive. If you have any insight into something which causes Sol to leak, please file an issue!

**Sol is slow.** Sol pressures the heap pretty heavily by creating a new object ("returning a new reference") for most operations. At least one bottleneck was addressed with the "icache" (integer cache), which speeds up comparisons significantly, but Sol nonetheless rapidly creates, destroys, and copies strings in very critical execution paths. The map implementation is particularly egregious, and is currently an associative array.

**The API is unstable.** There will definitely be some changes to the API, mostly to *help* with integration. At present, some operations on behalf of Sol embedders are a little messy and require intrinsic knowledge of the language specifics. The refcounting scheme, as mentioned previously, requires about four lines of code per function that should be a one-liner, for example.

**C-strings are deprecated.** At some point, Sol will move over to Pascal-ish strings (length/pointer to buffer). This will allow embedded NUL characters.

**The parser is broken.** Bison (Yacc) reports "reduce/reduce" conflicts (a lot of them, actually). This is not a good thing, though things appear to work somehow. Also, this code is responsible for the pointer clone problem which needs to be addressed. Finally, the tokenizer does not properly interpret escapes (doing it the "right" way somehow breaks the parser), making it difficult to embed things like double quotes.

After those (but more practically, with them), the following will be coming:

**Proper foreign-function support.** I'm adding a few new object types to allow calling into libraries (shared objects/dynamic libs). These will need Windows implementations that will come later. Presently, the C-style memory management works, but requires the Sol executable to be compiled with the appropriate compiler to generate the "sizeof" entries properly.

**Type registration.** Currently the `sol_objtype_t` enumeration contains all the types that Sol defines intrinsically, though most of the code only cares about which operations are supported. Embedders cannot specify additional members of this enumeration, borrowing the `SOL_CDATA` type instead. This may be fixed later.

**Code consolidation and refactoring.** There are quite a few instances of repetitive code that need to be addressed, and can be refactored out into functions in their own right. This should also improve usability.

Contributing
------------

By all means, use Sol in whatever project you care to use it in, however you care to link it in, if you think it will be useful in the slightest! If you find bugs, or have features you want to see, submit issues or (better yet) pull requests, and I'll get to them when I can. Finally, feel free to send me messages (however you care, though my email at grahamnorthup at yahoo.com will work :P). Happy programming!
