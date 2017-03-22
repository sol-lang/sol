chr2hex_t = {}
hex2chr_t = {}

for i in range(10) do
	c = chr(ord('0') + i)
	chr2hex_t[c] = i
	hex2chr_t[i] = c
end

for i in [10, 11, 12, 13, 14, 15] do
	c = chr(ord('A') + i - 10)
	chr2hex_t[c] = i
	hex2chr_t[i] = c
end

func new_reg()
	return {
		V = [0] * 16,
		I = 0,
		IP = 512,
		ST = 0,
		DT = 0,
	}
end

func new_mem()
	return [
		240, 144, 144, 144, 240,  -- 0
		32, 96, 32, 32, 112,      -- 1
		240, 16, 240, 128, 240,   -- 2
		240, 16, 240, 16, 240,    -- 3
		144, 144, 240, 16, 16,    -- 4
		240, 128, 240, 16, 240,   -- 5
		240, 128, 240, 144, 240,  -- 6
		240, 16, 32, 64, 64,      -- 7
		240, 144, 240, 144, 240,  -- 8
		240, 144, 240, 16, 240,   -- 9
		240, 144, 240, 144, 144,  -- A
		224, 144, 224, 144, 224,  -- B
		240, 128, 128, 128, 240,  -- C
		224, 144, 144, 144, 224,  -- D
		240, 128, 240, 128, 240,  -- E
		240, 128, 240, 128, 128,  -- F
	] + [0] * 4016
end

func mem_int(mem, i, bytes)
	r = 0
	while (bytes > 0) && (i < 4096) do
		r = (r << 8) | mem[i]
		i += 1
		bytes -= 1
	end
	return r
end

func load_buffer(mem, addr, s)
	if None == addr then addr = 512 end
	idx = 0
	while (idx < s:size()) && (addr < 4096) do
		mem[addr] = s:get(buffer.type.byte, idx)
		addr += 1
		idx += 1
	end
end

func load_stream(mem, addr, str)
	load_buffer(mem, addr, str:read_buffer(io.ALL))
end

func get_bit(v, i)
	return (v >> i) & 1
end

func new_disp(w, h)
	if w == None then w = 64 end
	if h == None then h = 32 end
	return {
		fb = [0] * (64 * 32),
		w = w,
		h = h,
	}
end

func disp_blit(b, x, y, v)
	idx = y * (b.w) + x
	changed = 0
	for bit in range(8) do
		if (idx >= 0) && (idx < (b.w) * (b.h)) then
			oldb = b.fb[idx]
			b.fb[idx] ^= if v & 128 then 1 else 0 end
			changed = changed || ((!oldb) && (b.fb[idx]))
			idx += 1
			v = v << 1
		end
	end
	return changed
end

func print_sprite(m, i, n)
	if None == n then n = 15 end
	fake_fb = new_disp(8, n)
	for idx in range(n) do
		disp_blit(fake_fb, 0, idx, m[i + idx])
	end
	print(disp_render(fake_fb))
end

NL = chr(10)
CSI = chr(27) + '['

func clear_screen()
	io.stdout:write(CSI+'H'+CSI+'2J')
end

func disp_render(d)
	s = ''
	for row in range(d.h) do
		s = s + disp_render_row(d, row) + NL
	end
	return s
end

func disp_render_row(d, r)
	t = ''
	for col in range(d.w) do
		idx = r * (d.w) + col
		if d.fb[idx] then
			t += '*'
		else
			t += ' '
		end
	end
	return t
end

func unused_syscall(state, n)
	state:log("unknown syscall " + tostring(n))
end

func clear_disp(state, n)
	state.disp = new_disp()
end

func ret(state, n)
	state:jump(state:pop())
end

func new_sys()
	sys = [unused_syscall] * 4096
	sys[224] = clear_disp
	sys[238] = ret
	return sys
end

func new_state()
	return {
		reg = new_reg(),
		mem = new_mem(),
		disp = new_disp(),
		sys = new_sys(),
		jumped = false,
		trace = false,
		jump = func(self, ip)
			self.reg.IP = ip
			self.jumped = true
		end,
		skip = func(self)
			self.reg.IP += 2
		end,
		stack = [],
		push = func(self, v)
			self.stack:insert(#(self.stack), v)
			if (#self.stack) > 16 then
				self:log("stack overflow: " + tostring(self.stack))
			end
		end,
		pop = func(self)
			if (#self.stack) == 0 then
				self:log("stack underflow")
				return 0
			end
			return self.stack:remove((#self.stack) - 1)
		end,
		keys = [0] * 16,
		buffer = [],
		log = func(self, msg)
			self.buffer:insert(#(self.buffer), msg)
		end,
		breaks = [],
		-- wchan = None
	}
end

func new_insn(n)
	return {
		nib = [(n >> 12) & 15, (n >> 8) & 15, (n >> 4) & 15, n & 15],
		byte = {high = (n >> 8) & 255, low = n & 255},
		addr = n & 4095,
		n = n,
	}
end

func rand(n=0)
	n = ((n * 17) + 1569752) % 3707765549
	n = (n << 1) | (((n >> 3) & 1) ^ ((n >> 6) & 1))
	n = (n << 1) | (((n >> 8) & 1) ^ ((n >> 5) & 1))
	n = ((n * 7) + 67293512) % 3747882443
	n = (n << 1) | (((n >> 7) & 1) ^ ((n >> 2) & 1))
	n = (n << 1) | (((n >> 4) & 1) ^ ((n >> 3) & 1))
	return n
end

func seed(n)
	rand.closure.n = n
end

func bad_op(state, ins)
	state:log("bad insn: " + tostring(ins.n) + " " + tostring(ins.nib))
end

insns = {
	[0] = func insn0(state, ins)
		state.sys[ins.addr](state, ins.addr)
	end,
	[1] = func insn1(state, ins)
		state:jump(ins.addr)
	end,
	[2] = func insn2(state, ins)
		state:push(state.reg.IP + 2)
		state:jump(ins.addr)
	end,
	[3] = func insn3(state, ins)
		if state.reg.V[ins.nib[1]] == ins.byte.low then
			state:skip()
		end
	end,
	[4] = func insn4(state, ins)
		if state.reg.V[ins.nib[1]] != ins.byte.low then
			state:skip()
		end
	end,
	[5] = func insn5(state, ins)
		if state.reg.V[ins.nib[1] ]== state.reg.V[ins.nib[2]] then
			state:skip()
		end
	end,
	[6] = func insn6(state, ins)
		state.reg.V[ins.nib[1]] = ins.byte.low
	end,
	[7] = func insn7(state, ins)
		state.reg.V[ins.nib[1]] = (state.reg.V[ins.nib[1]] + (ins.byte.low)) & 255
	end,
	[8] = func insn8(state, ins)
		{
			[0] = func insn8_0(state, ins)
				state.reg.V[ins.nib[1]] = state.reg.V[ins.nib[2]]
			end,
			[1] = func insn8_1(state, ins)
				state.reg.V[ins.nib[1]] |= state.reg.V[ins.nib[2]]
			end,
			[2] = func insn8_2(state, ins)
				state.reg.V[ins.nib[1]] &= state.reg.V[ins.nib[2]]
			end,
			[3] = func insn8_3(state, ins)
				state.reg.V[ins.nib[1]] ^= state.reg.V[ins.nib[2]]
			end,
			[4] = func insn8_4(state, ins)
				sum = state.reg.V[ins.nib[1]] + (state.reg.V[ins.nib[2]])
				state.reg.V[ins.nib[1]] = sum & 255
				state.reg.V[15] = if (sum >> 8) then 1 else 0 end
			end,
			[5] = func insn8_5(state, ins)
				diff = state.reg.V[ins.nib[1]] - (state.reg.V[ins.nib[2]])
				state.reg.V[ins.nib[1]] = diff & 255
				state.reg.V[15] = if (diff >> 8) then 1 else 0 end
			end,
			[6] = func insn8_6(state, ins)
				state.reg.V[15] = state.reg.V[ins.nib[1]] & 1
				state.reg.V[ins.nib[1]] = (state.reg.V[ins.nib[1]] >> 1)
			end,
			[7] = func insn8_7(state, ins)
				state.reg.V[15] = if state.reg.V[ins.nib[2]] > (state.reg.V[ins.nib[1]]) then 1 else 0 end
				state.reg.V[ins.nib[1]] = (stat.reg.V[ins.nib[2]] - (state.reg.V[ins.nib[1]]))
			end,
			[8] = bad_op, [9] = bad_op, [10] = bad_op, [11] = bad_op, [12] = bad_op, [13] = bad_op,
			[14] = func insn8_14(state, ins)
				state.reg.V[15] = (state.reg.V[ins.nib[1]] & 128) >> 7
				state.reg.V[ins.nib[1]] = (state.reg.V[ins.nib[1]] << 1) & 255
			end,
			[15] = bad_op,
		}[ins.nib[3]](state, ins)
	end,
	[9] = func insn9(state, ins)
		if state.reg.V[ins.nib[1]] != state.reg.V[ins.nib[2]] then
			state:skip()
		end
	end,
	[10] = func insn10(state, ins)
		state.reg.I = ins.addr
	end,
	[11] = func insn11(state, ins)
		state:jump(ins.addr + state.reg.V[0])
	end,
	[12] = func insn12(state, ins)
		state.reg.V[ins.nib[1]] = rand() & ins.byte.low
	end,
	[13] = func insn13(state, ins)
		x = state.reg.V[ins.nib[1]]
		y = state.reg.V[ins.nib[2]]
		n = ins.nib[2]
		i = state.reg.I
		c = 0
		for idx in range(n) do
			if (i >= 0) && (i < 4095) then
				c = c || disp_blit(state.disp, x, y, state.mem[i])
			end
			i += 1
			y += 1
		end
		state.reg.V[15] = c
	end,
	[14] = func insn14(state, ins)
		if ins.byte.low == 158 then
			if state.keys[ins.nib[1]] then
				state:skip()
			end
			return
		end
		if ins.byte.low == 161 then
			if !(state.keys[ins.nib[1]]) then
				state:skip()
			end
			return
		end
		bad_op(state, ins)
	end,
	[15] = func insn15(state, ins)
		if ins.byte.low == 7 then
			state.reg.V[ins.nib[1]] = state.reg.DT
			return
		end
		if ins.byte.low == 10 then
			state:log("waiting on key...")
			state.wchan = {type="key", reg=ins.nib[1]}
			return
		end
		if ins.byte.low == 21 then
			state.reg.DT = state.reg.V[ins.nib[1]]
			return
		end
		if ins.byte.low == 24 then
			state.reg.ST = state.reg.V[ins.nib[1]]
			return
		end
		if ins.byte.low == 30 then
			state.reg.I = (state.reg.I + (state.reg.V[ins.nib[1]])) & 65535
			return
		end
		if ins.byte.low == 41 then
			state.reg.I = 5 * (state.reg.V[ins.nib[1]] & 15)
			return
		end
		if ins.byte.low == 51 then
			if state.reg.I >= 4093 then
				state:log('BCD OOB @' + (state.reg.IP) + ': I=' + (state.reg.I))
				return
			end
			bcd = tostring(state.reg.V[ins.nib[1]])
			while (#bcd) < 3 do bcd = '0' + bcd end
			state.mem[state.reg.I] = ord(bcd[0]) - ord('0')
			state.mem[state.reg.I + 1] = ord(bcd[1]) - ord('0')
			state.mem[state.reg.I + 2] = ord(bcd[2]) - ord('0')
			return
		end
		if (ins.byte.low == 85) || (ins.byte.low == 101)then
			if state.reg.I + (ins.nib[1]) >= 4096 then
				state:log((if ins.byte.low == 85 then 'S' else 'R' end) + 'VC OOB @' + (state.reg.IP) + ': I=' + (state.reg.I) + ', n=' + (ins.nib[1]))
				return
			end
			for n in range(ins.nib[1] + 1) do
				if ins.byte.low == 85 then
					state.mem[state.reg.I + n] = state.reg.V[n]
				else
					state.reg.V[n] = state.mem[state.reg.I + n]
				end
			end
			return
		end
		bad_op(state, ins)
	end,
}

func bad_disas(state, ins)
	nibs = for n in ins.nib do continue n end
	return '.DB ' + nibs:map(lambda(n) hex2chr_t[n] end):reduce(lambda(x, y) x + y end, "")
end

disas = {
	[0] = func disas0(state, ins)
		return 'SYS ' + tostring(ins.addr) + '  ; (' + tostring(state.sys[ins.addr]) + ')'
	end,
	[1] = func disas1(state, ins)
		return 'JMP ' + tostring(ins.addr)
	end,
	[2] = func disas2(state, ins)
		return 'CAL ' + tostring(ins.addr)
	end,
	[3] = func disas3(state, ins)
		return 'SKE V' + tostring(ins.nib[1]) + ', ' + tostring(ins.byte.low)
	end,
	[4] = func disas4(state, ins)
		return 'SKN V' + tostring(ins.nib[1]) + ', ' + tostring(ins.byte.low)
	end,
	[5] = func disas5(state, ins)
		return 'SKE V' + tostring(ins.nib[1]) + ', V' + tostring(ins.nib[2])
	end,
	[6] = func disas6(state, ins)
		return 'MOV V' + tostring(ins.nib[1]) + ', ' + tostring(ins.byte.low)
	end,
	[7] = func disas7(state, ins)
		return 'ADD V' + tostring(ins.nib[1]) + ', ' + tostring(ins.byte.low)
	end,
	[8] = func disas8(state, ins)
		return {
			[0] = func disas8_0(state, ins)
				return 'MOV V' + tostring(ins.nib[1]) + ', V' + tostring(ins.nib[2])
			end,
			[1] = func disas8_1(state, ins)
				return 'BOR V' + tostring(ins.nib[1]) + ', V' + tostring(ins.nib[2])
			end,
			[2] = func disas8_2(state, ins)
				return 'BAN V' + tostring(ins.nib[1]) + ', V' + tostring(ins.nib[2])
			end,
			[3] = func disas8_3(state, ins)
				return 'BXR V' + tostring(ins.nib[1]) + ', V' + tostring(ins.nib[2])
			end,
			[4] = func disas8_4(state, ins)
				return 'ADD V' + tostring(ins.nib[1]) + ', V' + tostring(ins.nib[2])
			end,
			[5] = func disas8_5(state, ins)
				return 'SUB V' + tostring(ins.nib[1]) + ', V' + tostring(ins.nib[2])
			end,
			[6] = func disas8_6(state, ins)
				return 'SHR V' + tostring(ins.nib[1])
			end,
			[7] = func disas8_7(state, ins)
				return 'SBR V' + tostring(ins.nib[1]) + ', V' + tostring(ins.nib[2]) + '  ; (SUB V' + tostring(ins.nib[2]) + ', V' + tostring(ins.nib[1]) + ')'
			end,
			[8] = bad_disas, [9] = bad_disas, [10] = bad_disas, [11] = bad_disas, [12] = bad_disas, [13] = bad_disas,
			[14] = func disas8_14(state, ins)
				return 'SHL V' + tostring(ins.nib[1])
			end,
			[15] = bad_disas
		}[ins.nib[3]](state, ins)
	end,
	[9] = func disas9(state, ins)
		return 'SKN V' + tostring(ins.nib[1]) + ', V' + tostring(ins.nib[2])
	end,
	[10] = func disas10(state, ins)
		return 'MOV I, ' + tostring(ins.addr)
	end,
	[11] = func disas11(state, ins)
		return 'JR0 ' + tostring(ins.addr)
	end,
	[12] = func disas12(state, ins)
		return 'RND V' + tostring(ins.nib[1]) + ', ' + tostring(ins.byte.low)
	end,
	[13] = func disas13(state, ins)
		return 'BLT V' + tostring(ins.nib[1]) + ', V' + tostring(ins.nib[2]) + ', ' + tostring(ins.nib[3])
	end,
	[14] = func disas14(state, ins)
		if ins.byte.low == 158 then
			return 'SKK ' + tostring(ins.nib[1])
		end
		if ins.byte.low == 161 then
			return 'SNK ' + tostring(ins.nib[1])
		end
		return bad_disas(state, ins)
	end,
	[15] = func disas15(state, ins)
		if ins.byte.low == 7 then
			return 'MOV V' + tostring(ins.nib[1]) + ', DT'
		end
		if ins.byte.low == 10 then
			return 'WAK V' + tostring(ins.nib[1])
		end
		if ins.byte.low == 21 then
			return 'MOV DT, V' + tostring(ins.nib[1])
		end
		if ins.byte.low == 24 then
			return 'MOV ST, V' + tostring(ins.nib[1])
		end
		if ins.byte.low == 30 then
			return 'ADD I, V' + tostring(ins.nib[1])
		end
		if ins.byte.low == 41 then
			return 'LDF V' + tostring(ins.nib[1])
		end
		if ins.byte.low == 51 then
			return 'BCD V' + tostring(ins.nib[1])
		end
		if ins.byte.low == 85 then
			return 'SVC ' + tostring(ins.nib[1])
		end
		if ins.byte.low == 101 then
			return 'RVC ' + tostring(ins.nib[1])
		end
		return bad_disas(state, ins)
	end,
	__call = func(self, state, ins)
		return self[ins.nib[0]](state, ins)
	end,
}

func descr_list(l, prf, bias)
	if None == bias then bias = 0 end
	idx = -1
	return (for i in l do idx += 1; continue prf + tostring(idx + bias) + '=' + tostring(i) end):reduce(lambda(x, y) x + " " + y end, ""):sub(1)
end

func descr_state(state, DESCR_CNT = range(15))
	return 'IP=' + tostring(state.reg.IP) + ' I=' + tostring(state.reg.I) + '	[' + descr_list(for idx in DESCR_CNT do continue state.mem[state.reg.I + idx - 7] end, 'M', state.reg.I - 7) + ']	{' + descr_list(state.reg.V, 'V') + '} DT=' + tostring(state.reg.DT) + ' ST=' + tostring(state.reg.ST) + ' stack=' + tostring(state.stack)
end

func step_cpu(state, force)
	ins = new_insn(mem_int(state.mem, state.reg.IP, 2))
	if None != force then
		for brk in state.breaks do
			if brk(state, ins) then
				state.wchan = {type="break", brk=brk}
				return
			end
		end
	end
	if state.trace then state:log((for n in ins.nib do continue hex2chr_t[n] end):reduce(lambda(x, y) x + y end, '') + ': ' + disas(state, ins) + '  ;; ' + descr_state(state)) end
	insns[ins.nib[0]](state, ins)
	if !(state.jumped) then
		state.reg.IP += 2
	end
	state.jumped = false
end

DISP_HEIGHT = (func()
	buf = buffer.new(8)
	io.stdin:ioctl(io.TIOCGWINSZ, buf)
	return buf:get(buffer.type.uint16, 0)
end)()

DEBUG_VALS = {
	s = lambda() step_cpu(state, true) end,  -- XXX Dynamic scope access
	d = lambda(n) for i in range(n) do
		ridx = i - n / 2
		rip = IP + 2 * ridx
		print(
			if rip == IP then '=>' else '  ' end,
			rip, ':',
			disas(state, new_insn(mem_int(mem, IP + 2 * (i - (n / 2)), 2)))
		)
	end end,
	q = lambda() state.running = false end,
}

func run_cpu(state, incnt, tmcnt)
	if None == incnt then incnt = 20 end
	if None == tmcnt then tmcnt = 15 end
	icntrange = range(incnt)
	state.running = true
	while state.running do
		if None == state.wchan then
			for ictr in icntrange do
				step_cpu(state)
				if None != state.wchan then break end
			end
		end
		clear_screen()
		print(disp_render(state.disp))
		io.stdout:write(descr_state(state) + ' ')
		if state.reg.DT > 0 then
			state.reg.DT -= tmcnt
			if state.reg.DT < 0 then state.reg.DT = 0 end
		end
		if state.reg.ST > 0 then
			print('***BEEP***')
			state.reg.ST -= tmcnt
			if state.reg.ST < 0 then state.reg.ST = 0 end
		else
			print('')
		end
		if (None != state.wchan) then
			if state.wchan.type == "key" then
				print('waiting on a key (0-15): ')
				v = toint(io.stdin:read(io.LINE))
				state.reg.V[state.wchan.reg] = v & 255
			elseif state.wchan.type == "break" then
				-- NOP
			else
				error('Unknown wait channel!')
			end
		end
		if (#(state.buffer)) > 0 then
			lctr = state.disp.h + 1
			rem = #(state.buffer)
			midx = 0
			for msg in state.buffer do
				if lctr >= DISP_HEIGHT - 1 then
					io.stdout:write('(...and', rem, 'more [Enter/q])')
					if io.stdin:read(io.LINE):sub(0, -1) == 'q' then break end
					lctr = 0
				end
				print(midx, ':', msg)
				rem -= 1
				midx += 1
				lctr += 1
			end
			while true do
				io.stdout:write('(acknowledge/eval?) ')
				ln = io.stdin:read(io.LINE):sub(0, -1)
				if (#ln) > 0 then
					res = try(parse, ln)
					if res[0] then
						res = try(lambda (nd) nd.stmtlist[0].expr(state.reg + state + DEBUG_VALS) end, res[1])
						if res[0] then
							print(res[1])
						else
							print('Exec error:', res[1])
						end
					else
						print('Parse error:', res[1])
					end
				else
					break
				end
			end
			state.buffer = []
		end
	end
end

SEPARATOR = ('=#' * 38) + '='

func main()
	print('Enter filename to load: ')
	fname = io.stdin:read(io.LINE):sub(0, -1)
	strm = io.open(fname, io.MODE_READ|io.MODE_BINARY)
	state = new_state()
	load_stream(state.mem, None, strm)
	while true do
		io.stdout:write("(init)> ")
		ln = io.stdin:read(io.LINE):sub(0, -1)
		if (#ln) > 0 then
			print(parse(ln).stmtlist[0].expr(state.reg + state))
		else
			break
		end
	end
	res = try(run_cpu, state)
	if !res[0] then
		print('Error occurred:', res[1])
		print(SEPARATOR)
		print('Buffered logs not dumped before error:')
		for msg in state.buffer do print(msg) end
		print(SEPARATOR)
		print('Starting post-mortem debugger...')
		execfile('solid.sol')
		debst = new_debug_state(res)
		postmortem(debst)
	end
end

main()
