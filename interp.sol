-- The Solterpreter! A simple command-line interface for the compiler.

print('Solterpreter/Viperpreter v0.1')
print('(Runtime version ', debug.version, ')')

__interp = {
	running = 1,
	buffer = '',
	ps1 = '>>> ',
	ps2 = '... ',
	stmt_stack=0,
}

func exit()
	__interp.running=0
end

quit = exit

while __interp.running do
	if #__interp.buffer then
		io.stdout << __interp.ps2
	else
		io.stdout << __interp.ps1
	end
	__interp.line = io.stdin:read(io.LINE)
	__interp.line = __interp.line:sub(0, -1)
	--prepr(__interp.line)
	if (__interp.line:sub(-4, None)=="then") then
		__interp.buffer+=__interp.line+" "
		__interp.stmt_stack+=1
	else
		if (__interp.line:sub(-2, None)=="do") then
			__interp.buffer+=__interp.line+" "
			__interp.stmt_stack-=1
		else
			if __interp.line:sub(-1, None)=="\" then
				__interp.buffer+=__interp.line:sub(0, -1)+" "
			else
				__interp.buffer+=__interp.line+" "
				if __interp.line:sub(-3, None)=="end" then
					__interp.stmt_stack-=1
				end
				if __interp.stmt_stack<=0 then
					__interp.stmt_stack=0
					__interp.program = try(parse, __interp.buffer)
					if !__interp.program[0] then
						print('Syntax error')
					else
						if __interp.program[1].stmtlist[0].type == ast.ST_EXPR then
							__interp.program[1] = __interp.program[1].stmtlist[0].expr
							__interp.isexpr = 1
						else
							__interp.isexpr = 0
						end
						__interp.result = try(__interp.program[1])
						if !__interp.result[0] then
							print(__interp.result[1])
						else
							if __interp.isexpr then
								prepr(__interp.result[1])
							end
						end
					end
					__interp.buffer=''
				end
			end
		end
	end
end
