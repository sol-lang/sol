execfile("tests/_lib.sol")

f = lambda(x)
	if x == 0 then
		"foo"
	elseif x == 1 then
		"bar"
	else
		"baz"
	end
end

g = lambda(x)
	if x == 'a' then
		7
	elseif x == 'b' then
		14
	end
end

assert_eq(f(0), "foo", "if/elseif/else, if branch")
assert_eq(f(1), "bar", "if/elseif/else, elseif branch")
assert_eq(f(2), "baz", "if/elseif/else, else branch 1")
assert_eq(f(7), "baz", "if/elseif/else, else branch 2")

assert_eq(g('a'), 7, "if/elseif, if branch")
assert_eq(g('b'), 14, "if/elseif, elseif branch")
assert_eq(g(3), None, "if/elseif, no branch")
