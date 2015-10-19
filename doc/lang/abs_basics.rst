Absolute Basics
===============

This chapter is intended to give you just enough orientation of the Sol language to read the examples to follow.

Sol has just one comment type, and it is a line comment; it is preceded by two dashes (--), and appears as follows::

    -- This is a comment
    --Whitespace to the right is recommended, but not required.
    -- Anything to the right of the dashes until the end of the line is completely ignored by the parser.

Interactively, and in many examples, the `prepr` `function <functions>` is used to print convenient forms of the value or values given to it as parameters::

    prepr(1)      -- Outputs "1" (without enclosing quotes) to stdout
    prepr(13.3)   -- Outputs "13.3" to stdout"
    prepr("hi!")  -- Outputs '"hi!"' (without enclosing single quotes) to stdout

Alternatively, the `interpreter` will print the resulting value of any evaluation entered at its prompt.
