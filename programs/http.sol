func printerr(a)
	io.stderr:write(tostring(a))
end

while 1 do
	printerr(io.stdin:read(io.LINE))
end
