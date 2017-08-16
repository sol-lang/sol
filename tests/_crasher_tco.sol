execfile("tests/_lib.sol")

func blow_up_stack(n)
	return if n > 0 then
		1 + blow_up_stack(n - 1)
	else
		0
	end
end

assert_eq(blow_up_stack(5), 5, "blow_up_stack 5 deep")
assert_eq(blow_up_stack(5000), 5000, "blow_up_stack 5000 deep")
assert_eq(blow_up_stack(5000000), 5000000, "blow_up_stack 5000000 deep")
