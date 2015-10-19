Language Reference
==================

The Sol language is an interpreted language with fair syntactic similarity to
Lua and Python, but has enough quirks that some constructs might not be clear.
This guide should be considered definitive to the syntax of the language, but
you should be aware that the namespace under which the language is run may
differ between applications, and that you should consult those applications'
manuals for more information. Only under the basic interpreter (`solrun.c`, or
`sol` from the command line), the `standard library <stdlib>` is well
defined.

.. toctree::
    
    abs_basics
    simple_exprs
    control_flow
    lists_maps
    functions
    stdlib
