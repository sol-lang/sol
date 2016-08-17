func assert(x, msg, _test_count = 0)
	_test_count += 1
	io.stdout:write('Test ' + tostring(_test_count) + ': ' + msg)
	if !x then
		print("")
		error("Assertion failed: " + tostring(msg))
	end
	print("...passed")
end

func assert_eq(x, y, msg)
	assert(x == y, "equality: " + tostring(x) + " == " + tostring(y) + ": " + msg)
end

func assert_neq(x, y, msg)
	assert(x != y, "inequality: " + tostring(x) + " != " + tostring(y) + ": " + msg)
end

func assert_none(x, msg)
	assert(None == x, "None: " + tostring(x) + ": " + msg)
end

func assert_not_none(x, msg)
	assert(None != x, "Not None: " + tostring(x) + ": " + msg)
end

func warn(msg)
	io.stderr:write("Warning: " + tostring(msg) + "\n")
end

func warn_if(cond, msg)
	if cond then
		warn(msg)
	end
end
