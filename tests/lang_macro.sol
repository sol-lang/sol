execfile("tests/_lib.sol")

macro shitty_eval(x, y)
	--ast.print(x)
	return [x(), y()]
end

assert_eq(shitty_eval(3 + 2, 7 + 9), [5, 16], "macro 1")

macro stupid(ex)
	return ex({this_var_does_not_exist = 77})
end

assert_eq(stupid(this_var_does_not_exist - 7), 70, "macro 2")

stuff = macro lambda(n) n({q = 3}) end
assert_eq(stuff(q), 3, "macro lambda 1")
