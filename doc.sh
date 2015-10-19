#!/bin/sh

# Required PyPI packages: sphinx, breathe
# Required ext packages: doxygen

doxygen Doxyfile
sphinx-build -b html . ./_build
