execfile("tests/_lib.sol")

assert_eq(5, for i in range(10) do if i == 5 then break i end end, "break with value")
assert_eq([0, 2, 4, 6, 8], for i in range(5) do continue 2 * i end, "continue with value")
