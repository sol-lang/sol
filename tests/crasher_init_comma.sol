execfile("tests/_lib.sol")

assert_eq([0], [,,,,0], "initial comma in list")
d = {,,a=7}
assert_eq(d.a, 7, "initial comma in map")

ident = lambda(,x) x end

assert_eq("hi", ident(,"hi"), "initial comma in funcdecl/call")
