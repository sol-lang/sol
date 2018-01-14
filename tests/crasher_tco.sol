execfile("tests/_lib.sol")

func blow_up_stack(n, accum)
	if n > 0 then
		return blow_up_stack(n - 1, accum + 1)
	else
		return accum
	end
end

print('TCO test (will take a long time, sorry)')
assert_eq(blow_up_stack(5, 0), 5, "blow_up_stack 5 deep")
assert_eq(blow_up_stack(5000, 0), 5000, "blow_up_stack 5000 deep")
assert_eq(blow_up_stack(50000, 0), 50000, "blow_up_stack 50000 deep")
assert_eq(assert.closure._test_count, 3, "ran three tests")
