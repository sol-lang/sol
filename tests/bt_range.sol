execfile("tests/_lib.sol")

assert_eq([0, 1, 2, 3, 4], range(5), "range 5")
assert_eq(50, #range(50), "len range 50")
assert_eq(0, #range(0), "Empty range")
