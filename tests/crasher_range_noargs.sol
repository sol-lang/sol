execfile('tests/_lib.sol')

assert_eq(try(range)[0], 0, "range with no args causes error")
assert_eq(try(range, [])[0], 0, "range with list arg causes error")
assert_eq(try(range, {})[0], 0, "range with map arg causes error")
