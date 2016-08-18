execfile("tests/_lib.sol")

func f() end
assert_eq(0, #(f.annos), "no annotations")

func f(a: 12): -37 end
assert_eq(12, f.annos.a, "arg annotation (int)")
assert_eq(-37, f.annos[f], "func annotation (int)")

func f(a: "herp"): "derp" end
assert_eq("herp", f.annos.a, "arg annotation (str)")
assert_eq("derp", f.annos[f], "func annotation (str)")

func f(a: [1, 2], b: {c = [3, 4]}): {d = [12, "herps"]} return "asdfghjkl" end
assert_eq([1, 2], f.annos.a, "composite anno a")
assert_eq([3, 4], f.annos.b.c, "composite anno b")
assert_eq([12, "herps"], f.annos[f].d, "composite func anno")
assert_eq("asdfghjkl", f(), "correct call to anno func")

func tc(f)
	return func(*args, f=f)
		for idx in range(#args) do
			argn = f.args[idx]
			if None == argn then continue end
			tspec = f.annos[argn]
			if None == tspec then continue end
			if type(args[idx]) != tspec then
				error("Calling " + tostring(f.name)+ ": arg " + argn + " should be " + tspec)
			end
		end
		return apply(f, args)
	end
end

iadd = tc(lambda(a: 'int', b: 'int'): 'int' a + b end)

assert_eq(5, iadd(2, 3), "conformance")
assert_eq(0, try(iadd, 2.2, 3)[0], "float a")
assert_eq(0, try(iadd, 3, "string")[0], "str b")
assert_eq(0, try(iadd, [], {})[0], "composite a/b")
