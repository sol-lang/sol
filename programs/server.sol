http = {
	ERRORS = {
		[400] = "Bad Request",
		[500] = "Server Error",
	}
}

NL = '
'
CR = chr(13)

func get_request()
	result = {}

	httpline = io.stdin:read(io.LINE)
	httpline = httpline:split(NL)[0]
	httpline = httpline:split(CR)[0]
	parts = httpline:split(" ")

	if (3 != (#parts)) || (parts[2] != "HTTP/1.1") then
		error(400)
	end

	result.method = parts[0]
	result.path = parts[1]
	result.protocol = parts[2]

	return result
end

out = try(get_request)
success = out[0]
value = out[1]

if success then
	print('HTTP/1.1 200 OK
Content-type: text/plain

Hello from Sol! You sent in these values:', value)
else
	if type(value) == "int" then
		print('HTTP/1.1 ' + tostring(value) + ' ' + (http.ERRORS[value]) + '
Content-type: text/plain

Error ' + tostring(value) + ': ' + (http.ERRORS[value]))
	else
		print('HTTP/1.1 500 Server Error
Content-type: text/plain

Internal error: ' + tostring(value))
	end
end

