func dump(obj, indent)
	if None == indent then
		indent = 0
		seen = {}
	end
	io.stdout:write(" "*indent)
	if type(obj) == "list" then
		buf = buffer.fromobject(obj)
		addr = buf:address()
		if None != seen[obj] then
			print("...("+addr+")")
			return
		end
		seen[obj] = 1
		print("[")
		for elem in obj do
			dump(elem, indent+2)
		end
		print(" "*indent+"] =("+addr+")")
		return
	end
	if type(obj) == "map" then
		buf = buffer.fromobject(obj)
		addr = buf:address()
		if None != seen[obj] then
			print("...("+addr+")")
			return
		end
		seen[obj] = 1
		print("{")
		for key in obj do
			io.stdout:write(" "*(indent+2))
			prepr(key, ":")
			dump(obj[key], indent+4)
		end
		print(" "*indent+"} =("+addr+")")
		return
	end
	prepr(obj)
end

dump.closure.seen = {}
