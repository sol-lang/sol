execfile("tests/_lib.sol")

s = "abcde fghijklmnopqrstuvwxyz"
q = "00000 0000000000000000000"

assert_eq(s, s, "string equality with embedded NUL")
assert_eq(#s, 27, "string length with embedded NUL")

assert_eq(q, q, "string equality with embedded NUL 2")
assert_eq(#q, 25, "string length with embedded NUL 2")
