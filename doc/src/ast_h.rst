Internal Definitions (ast.h)
============================

For historical reasons, this header file is called "ast.h"--the definitions of
the AST nodes are not namespace-safe (they aren't prefixed with `sol_`), and so
this file is not generally meant to be included by end users unless strictly
required.

.. doxygenfile:: ast.h
