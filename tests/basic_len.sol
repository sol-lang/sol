execfile("tests/_lib.sol")

assert_eq(0, #[], "empty list")
assert_eq(0, #{}, "empty map")

assert_eq(2, #[1, 2], "list len")
assert_eq(3, #{a=1, b=2, c=[3, 4, 5]}, "map len")
