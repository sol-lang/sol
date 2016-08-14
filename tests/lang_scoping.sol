execfile("tests/_lib.sol")

_G = debug.globals()
_G.a = 10
assert_eq(a, 10, "debug.globals write")

b = 7
assert_eq(_G.b, 7, "debug.globals read")

func()
	assert_eq(a, 10, "scope inheritance (a)")
	assert_eq(b, 7, "scope inheritance (b)")

	_L = debug.locals()
	_L.a = 17
	assert_eq(a, 17, "debug.locals write")

	b = 3
	assert_eq(_L.b, 3, "debug.locals read")

	assert_eq(#debug.scopes(), 2, "debug scope count")
end()

assert_eq(a, 10, "scope leak (direct)")
assert_eq(b, 7, "scope leak (direct)")
assert_eq(_G.a, 10, "scope leak (indirect)")
assert_eq(_G.b, 7, "scope leak (indirect)")

func()
	_LG = debug.globals()
	_LG.a = 13
	_LG.b = 14
	assert_eq(a, 13, "scope inheritance after outer write")
	assert_eq(b, 14, "scope inheritance after outer write")

	a = 9
	b = 7
	assert_eq(a, 9, "local write")
	assert_eq(b, 7, "local write")
end()

assert_eq(a, 13, "outer write persistence")
assert_eq(b, 14, "outer write persistence")


-- FIXME: Attempting to repr these scopes causes an inf recursion
assert(debug.locals() == debug.globals(), "root scope locals == globals")
