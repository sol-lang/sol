execfile("tests/_lib.sol")

assert_eq(0 || 0, 0, "LOR")
assert_eq(1 || 0, 1, "LOR")
assert_eq(0 || 1, 1, "LOR")
assert_eq(1 || 1, 1, "LOR")

assert_eq(0 && 0, 0, "LAND")
assert_eq(1 && 0, 0, "LAND")
assert_eq(0 && 1, 0, "LAND")
assert_eq(1 && 1, 1, "LAND")
