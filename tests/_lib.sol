func assert(x, msg)
	if !x then
		error("Assertion failed: " + tostring(msg))
	end
end

func assert_eq(x, y, msg)
	assert(x == y, msg)
end

func assert_none(x, msg)
	assert_eq(None, x, msg)
end

func assert_not_none(x, msg)
	assert(None != x, msg)
end

func warn(msg)
	io.stderr:write("Warning: " + tostring(msg) + "\n")
end

func warn_if(cond, msg)
	if cond then
		warn(msg)
	end
end

print("(test library loaded successfully)")
