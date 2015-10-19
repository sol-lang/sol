User Includes (sol.h)
=====================

This header file includes all the standard functionality of Sol in such a way
that user applications can safely call into the library. All types and
functions exported from here are prefixed with `sol_` (possibly further
prefixed by a number of underscores), so as to minimize namespace collision.

.. doxygenfile:: sol.h
