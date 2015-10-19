.. Sol documentation master file, created by
   sphinx-quickstart on Mon Oct 19 11:40:28 2015.

Welcome to Sol's documentation!
===============================

Sol is an eccentric language modelled on the best of Python and Lua--so it
looks (and performs) a little bit like Javascript! The entire source tree is
fairly small and suitable for static linking, containing just a (featureful)
core runtime and a Bison-Flex parser.

Sol is an interpreted language that uses a reference-counting garbage
collector; it was initially built for `iiag <https://github.com/iiag/iiag>`_,
and can still be found as a working proof-of-concept for integration in its
`legacy "sol" branch <https://github.com/iiag/iiag-legacy/tree/sol/src>`_.

Contents:

.. toctree::
   :maxdepth: 2

   User's Manual <lang/index>
   Developer's Manual <src/index>
   genindex
