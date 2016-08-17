execfile("tests/_lib.sol")

func count(v, c=0, lv=0)
	c += 1
	lv = v
end

d = {method = count}
d:method()

assert_eq(d, count.closure.lv, "method called with self")
assert_eq(1, count.closure.c, "method evaluated once (expr is map)")

func count(c = 0)
	c += 1
	return {v = c, method = func(self) return self.v end}
end

assert_eq(count():method(), count.closure.c, "method evaluation consistent")
assert_eq(1, count.closure.c, "method evaluated once (expr is call)")
