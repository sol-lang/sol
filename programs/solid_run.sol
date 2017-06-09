execfile('solid.sol')
io.stdout:write('Enter filename to run: ')
__fname = io.stdin:read(io.LINE):sub(0, -1)
__result = try(execfile, __fname)
if __result[0] then
	print('Subprogram exited successfully')
else
	print('Subprogram terminated with an error: ', __result[1])
	__debst = new_debug_state(__result)
	postmortem(__debst)
end
