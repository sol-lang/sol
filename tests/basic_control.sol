execfile("tests/_lib.sol")

if 0 then
	error("Iftrue on a false constant")
else
	print("Iffalse on a false contant (pass)")
end

if 1 then
	print("iftrue on a true constant (pass)")
else
	error("iffalse on a true constant")
end

iters = 0
for i in range(5) do iters += 1 end
assert_eq(iters, 5, "for over range")

func count(start, stop, step)
	if None == step then step = 1 end
	func inner()
		if i >= stop then return StopIteration end
		i += step
		return i - 1
	end
	inner.closure.stop = stop
	inner.closure.i = start
	inner.closure.step = step
	return inner
end

iters = 0
for i in count(0, 10) do iters += 1 end
assert_eq(iters, 10, "for over iterator function")

iters = 0
for i in count(0, 10, 2) do iters += 1 end
assert_eq(iters, 5, "for over iterator function")
