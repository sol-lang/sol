execfile("tests/_lib.sol")

assert_eq("true", if 1 then "true" else "false" end, "iftrue")
assert_eq("false", if 0 then "true" else "false" end, "iffalse")
