execfile("tests/_lib.sol")

assert_eq(try(apply)[0], 0, "apply with no args causes error")
assert_eq(try(apply, print, 7)[0], 0, "apply with non-list (int) causes error")
assert_eq(try(apply, print, {})[0], 0, "apply with non-list (map) causes error")
assert_eq(try(apply, print, "foo")[0], 0, "apply with non-list (strbuf) causes error")
