Simple Expressions
==================

Literals
--------

A *literal* is a leaf in an expression; it is a value in the source of a Sol program which evaluates to itself. Literals in Sol come in exactly four flavors:

* Integer literals, represented by contiguous digits, possibly preceded by a
  negation, like `0`, `123456`, `-314159`, and the like.
* Floating point literals, represented by a pair of contiguous digits separated
  by one radix mark, again possibly preceded by a negation, like `1.0`,
  `-0.256`, `999.9`, and the like.
* String literals, bound on either side by a single or double quote (they must
  match), and containing every interim character (including newline), like
  `"hello world"`, `'this string has two backslashes: \\'`, and the like.
  Naturally, a string may not contain its own terminator, though it can be
  introduced by concatenating strings with different terminators.
* The special literal `None`, a value only ever equal to itself and which
  cannot be reassigned by the user program. It is frequently used to represent
  the absence of a value, such as the value of a function which does not
  explicitly return a value.

The following source fragment demonstrates some of the literals::

    a = 123
