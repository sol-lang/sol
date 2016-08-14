execfile("tests/_lib.sol")

a = 3
assert_eq(a, a, "a (reflexive)")
assert_eq(3, a, "a")
assert_eq(a, 3, "a")

l = [0 9 3 1]
assert_eq(l, l, "l (reflexive)")
assert_eq([0, 9, 3, 1], l, "l")
