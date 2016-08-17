execfile("tests/_lib.sol")

func pop2(a, b, *l) return l end

assert_eq(pop2(1, 2, 3, 4, 5), [3, 4, 5], "rest param")
assert_eq(pop2(1, 2), [], "rest param (at affinity)")
assert_eq(pop2(), [], "rest param, (below affinity)")

func count(i = 0) i += 1; return i end

assert_eq(count(), 1, "count")
assert_eq(count(), 2, "count")
assert_eq(count(), 3, "count")

func rg(start, stop) return func(i=start, stop=stop) if i >= stop then return end; i += 1; return i - 1 end end

assert_eq(for i in rg(3, 10) do continue i end, [3, 4, 5, 6, 7, 8, 9], "iter over count")
