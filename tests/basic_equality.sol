execfile("tests/_lib.sol")

assert_eq(1, 1, "int cmp")
assert_eq(-3695, -3695, "int cmp")
assert_eq([1, 2, 3], [1, 2, 3], "list cmp")
assert_neq([1, 2, 3], [4, 5, 6], "list cmp (inverse same len)")
assert_neq([1, 2, 3], [], "list cmp (with empty)")
assert_neq([1, 2, 3], [1, 2], "list cmp (with prefix)")
assert_neq([1, 2, 3], [1, 2, 3, 4], "list cmp (as prefix)")
