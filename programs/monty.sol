TOK = {LPAREN = 1, RPAREN = 2, INT = 3, BOOL = 4, NAME = 5, QUOTE = 6, EOF = 7}
keys = []
for k in TOK do keys:insert(#keys, k) end
for k in keys do TOK[TOK[k]]=k end

token = {
	new = func (type, value)
		return {type = type, value = value, __index = token}
	end,
	pretty = func(self)
		tname = TOK[self.type]
		tval = tostring(self.value)
		return '{'+tname+':'+tval+'}'
	end
}

tokenizer = {
	WS = " "+chr(8)+chr(9)+chr(10),
	NAMESET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ=+-*/.<>?!@$%^~",
	DIGITS = "0123456789",
	EOF = {},
	new = func (str)
		res = {str = str, pushed = None, __index = tokenizer}
		res:init()
		return res
	end,
	init = func(self)
		--print('In init, self is', self)
		res.cur = res:token()
		res.next = res:token()
	end,
	next_char = func(self)
		if self.pushed == None then
			--print('In next_char, self is', self)
			--print('In next_char, self.str is', self.str)
			if self.str:eof() then return self.EOF end
			res = self.str:read(1)
		else
			--print('Retrieving from pushback', self.pushed)
			res = self.pushed[0]
			self.pushed = self.pushed:sub(1)
			if self.pushed == "" then self.pushed = None end
		end
		--print(res)
		return res
	end,
	push_back = func(self, s)
		--print('Pushing back', s)
		if s == self.EOF then print('WARNING: Attempted to push_back EOF'); return end
		if self.pushed == None then
			self.pushed = s
		else
			self.pushed = s + self.pushed
		end
		--print('self.pushed:', self.pushed)
	end,
	token = func (self)
		--print('In token, self is', self)
		--print('In token, self.str is', self.str)
		c = self:next_char()
		while !(c == self.EOF) do
			if c == "" then return token.new(TOK.EOF, None) end
			if c == "(" then return token.new(TOK.LPAREN, c) end
			if c == ")" then return token.new(TOK.RPAREN, c) end
			if self.NAMESET:find(c) >= 0 then
				--print('{NAME}')
				name = c
				c = self:next_char()
				while 1 do
					found = 0
					if self.NAMESET:find(c) >= 0 then found = 1 end
					if self.DIGITS:find(c) >= 0 then found = 1 end
					if !found then break end
					name += c
					c = self:next_char()
					if c == self.EOF then continue end
				end
				self:push_back(c)
				return token.new(TOK.NAME, name)
			end
			if self.DIGITS:find(c) >= 0 then
				val = c
				c = self:next_char()
				while self.DIGITS:find(c) >= 0 do
					val += c
					c = self:next_char()
					if c == self.EOF then continue end
				end
				self:push_back(c)
				return token.new(TOK.INT, toint(val))
			end
			if c == "#" then
				c = self:next_char()
				if c == "t" then return token.new(TOK.BOOL, 1) end
				if c == "f" then return token.new(TOK.BOOL, 0) end
				error("Invalid value for bool literal: "+c)
			end
			if c == "'" then return token.new(TOK.QUOTE, c) end
			if self.WS:find(c) >= 0 then
				c = self:next_char()
				continue
			end
			if c == ";" then
				c = self:next_char()
				while 1 do
					if c == chr(10) then break end
					c = self:next_char()
				end
				c = self:next_char()
				continue
			end
			error("Invalid character in token stream: "+c)
		end
		return token.new(TOK.EOF, None)
	end,
	advance = func(self)
		self.cur = self.next
		self.next = self:token()
	end
}



ttreegen = {
	new = func(tok)
		return {tok = tok, __index = ttreegen}
	end,
	generate = func(self, consume)
		res = self.TT_DISPATCH[self.tok.cur.type](self, self.tok.cur)
		if None == consume then self.tok:advance() end
		return res
	end,
	TT_DISPATCH = {
		[TOK.LPAREN] = func(self, tok)
			toklist = []
			self.tok:advance()
			tok = self.tok.cur
			while 1 do
				if tok.type == TOK.RPAREN then break end
				if tok.type == TOK.EOF then error('Encountered EOF while matching delimiter') end
				toklist:insert(#toklist, self.TT_DISPATCH[tok.type](self, tok))
				self.tok:advance()
				tok = self.tok.cur
			end
			return toklist
		end,
		[TOK.RPAREN] = func(self, tok)
			error("Unexpected right parenthesis")
		end,
		[TOK.INT] = func(self, tok)
			return tok
		end,
		[TOK.BOOL] = func(self, tok)
			return tok
		end,
		[TOK.NAME] = func(self, tok)
			return tok
		end,
		[TOK.QUOTE] = func(self, tok)
			self.tok:advance()
			tok.quoting = self:generate(0)
			return tok
		end,
		[TOK.EOF] = func(self, tok)
			return None
		end
	}
}

EX = {CALL=1, ASSIGN=2, FUNCDECL=3, SCOPE=4, IFELSE=5, DATUM=6, LIT=7, REF=8, LIST=9}
keys = []
for k in EX do keys:insert(#keys, k) end
for k in keys do EX[EX[k]]=k end

node = {
	new = func(type, value)
		return {type=type, value=value, __index=node}
	end,
	pretty = func(self) return self.PRETTY_DISPATCH[self.type](self) end
	PRETTY_DISPATCH = {
		[EX.CALL] = func(self)
			return '<CALL NAME='+(self.value.name)+' ARGS='+tostring(self.value.args:copy():map(func(i) if !(None == i) then return i:pretty() else return tostring(i) end end))+'>'
		end,
		[EX.ASSIGN] = func(self)
			return '<ASSIGN NAME='+(self.value.name)+' VALUE='+(self.value.value:pretty())+'>'
		end,
		[EX.FUNCDECL] = func(self)
			return '<FUNCDECL PARAMS='+tostring(self.value.params)+' BODY='+(self.value.body:pretty())+'>'
		end,
		[EX.SCOPE] = func(self)
			return '<SCOPE '+(self.value:copy():map(func(i) return i:pretty() end))+'>'
		end,
		[EX.IFELSE] = func(self)
			return '<IFELSE COND='+(self.value.cond:pretty())+' IFT='+(self.value.ift:pretty())+' IFF='+(self.value.iff:pretty())+'>'
		end,
		[EX.DATUM] = func(self)
			return '#'+tostring(self.value)
		end,
		[EX.LIT] = func(self)
			if type(self.value) == 'list' then
				return '/'+tostring(self.value:copy():map(func(i) return i:pretty() end))
			end
			return '/'+tostring(self.value)
		end,
		[EX.REF] = func(self)
			--print('In EX.REF, self is', self)
			res = '@'+tostring(self.value)
			--print('In EX.REF, returning', res)
			return res
		end,
		[EX.LIST] = func(self)
			--print('In EX.LIST, self is', self)
			return '<LIST '+(self.value:copy():map(func(i) return i:pretty() end))+'>'
		end
	}
}

parser = {
	new = func(ttgen)
		return {ttgen = ttgen, __index = parser}
	end,
	parse = func(self, tt)
		if type(tt) == 'map' then
			--print('In parse, self is', self)
			--print('In parse, tt is', tt)
			--print('In parse, dispatch to', self.TT_PARSE_DISPATCH[tt.type])
			res = self.TT_PARSE_DISPATCH[tt.type](self, tt)
		else
			name = tt[0]
			if !(name.type == TOK.NAME) then
				error('Expected name as first element of expression-list')
			end
			rest = tt:copy()
			rest:remove(0)
			sc = self.SCALL_DISPATCH[name.value]
			if !(None == sc) then
				sc = None
				res = self.SCALL_DISPATCH[name.value](self, rest)
			else
				res = node.new(EX.CALL, {name=name.value, args=rest:map(func(i) return self:parse(i) end)})
			end
		end
		--print('In parse, returning', res:pretty())
		return res
	end,
	TT_PARSE_DISPATCH = {
		[TOK.INT] = func(self, tok)
			return node.new(EX.LIT, tok.value)
		end,
		[TOK.BOOL] = func(self, tok)
			return node.new(EX.LIT, tok.value)
		end,
		[TOK.NAME] = func(self, tok)
			--print('In TOK.NAME, tok is', tok)
			res =  node.new(EX.REF, tok.value)
			--print('In TOK.NAME, returning', res)
			return res
		end,
		[TOK.QUOTE] = func(self, tok)
			return self:parse_datum(tok.quoting)
		end
	},
	SCALL_DISPATCH = {
		define = func(self, args)
			name = args[0]
			if !(name.type == TOK.NAME) then error('Define: expected name as first argument') end
			value = self:parse(args[1])
			return node.new(EX.ASSIGN, {name=name.value, value=value})
		end,
		["if"] = func(self, args)
			cond = self:parse(args[0])
			ift = self:parse(args[1])
			iff = self:parse(args[2])
			return node.new(EX.IFELSE, {cond=cond, ift=ift, iff=iff})
		end,
		begin = func(self, args)
			args:map(func(i) return self:parse(i) end)
			return node.new(EX.LIST, args)
		end,
		lambda = func(self, args)
			--print('Lambda args:', args)
			params = args[0]
			if !(type(params) == 'list') then error('Lambda: expected parameters as first argument (got '+tostring(params)+')') end
			params:map(func(i)
				if !(type(i) == 'map') then error('Lambda: expected name token in argument list (got sublist)') end
				if !(i.type == TOK.NAME) then error('Lambda: expected name token in argument list (got '+(i:pretty())+')') end
				return i.value
			end)
			body = args:copy()
			body:remove(0)
			--print('Lambda body:', body)
			body:map(func(i) return self:parse(i) end)
			return node.new(EX.FUNCDECL, {params=params, body=node.new(EX.LIST, body)})
		end,
		let = func(self, args)
			defs = args[0]
			if !(type(defs) == 'list') then error('Let: expected list of bindings are first argument') end
			defs:map(func(i)
				if !(type(i) == 'list') then error('Let: expected a binding entry') end
				return self.SCALL_DISPATCH.define(self, i)
			end)
			body = args:copy()
			body:remove(0)
			body:map(func(i) return self:parse(i) end)
			return node.new(EX.SCOPE, defs+body)
		end,
		letrec = func(self, args)
			defs = args[0]
			if !(type(defs) == 'list') then error('Let: expected list of bindings are first argument') end
			defs:map(func(i)
				if !(type(i) == 'list') then error('Let: expected a binding entry') end
				return self.SCALL_DISPATCH.define(self, i)
			end)
			body = args:copy()
			body:remove(0)
			body:map(func(i) return self:parse(i) end)
			return node.new(EX.LIST, defs+body)
		end
	}
	parse_datum = func(self, tt)
		if type(tt) == 'map' then
			return self.TT_PARSE_DATUM_DISPATCH[tt.type](self, tt)
		else
			list = []
			for tok in tt do
				list:insert(#list, self:parse_datum(tok))
			end
			return node.new(EX.LIT, list)
		end
	end,
	TT_PARSE_DATUM_DISPATCH = {
		[TOK.INT] = func(self, tok)
			return node.new(EX.LIT, tok.value)
		end,
		[TOK.BOOL] = func(self, tok)
			return node.new(EX.LIT, tok.value)
		end,
		[TOK.NAME] = func(self, tok)
			return node.new(EX.LIT, tok.value)
		end,
		[TOK.QUOTE] = func(self, tok)
			return self:parse(tok.quoting)
		end
	},
	run = func(self)
		tt = self.ttgen:generate()
		list = []
		while 1 do
			if None == tt then break end
			--if type(tt) == 'list' then
				list:insert(#list, self:parse(tt))
			--end
			tt = self.ttgen:generate()
		end
		--print('In run, list is', list)
		return node.new(EX.LIST, list)
	end
}

converter = {
	new = func(p)
		return {parser=p, __index = converter}
	end,
	make = func(self, node)
		--print('In make, node is a', EX[node.type], 'of value', node)
		res = self.MAKE_DISPATCH[node.type](self, node)
		--print('In make, returning', res)
		if type(res) == "astnode" then ast.print(res) end
		return res
	end,
	MAKE_DISPATCH = {
		[EX.CALL] = func(self, node)
			e = parse('f()').stmtlist[0].expr
			e.expr.ident = node.value.name
			args = node.value.args:copy():map(func(i) return self:make(i) end)
			--print('In EX.CALL, replacement args are', args)
			e.args = args
			--print('In EX.CALL, args are', e.args)
			return e
		end,
		[EX.ASSIGN] = func(self, node)
			e = parse('a = b').stmtlist[0].expr
			e.ident = node.value.name
			e.value = self:make(node.value.value)
			return e
		end,
		[EX.FUNCDECL] = func(self, node)
			e = parse('func() None None end').stmtlist[0].expr
			params = node.value.params
			--print('In EX.FUNCDECL, params are', params)
			e.args = params
			--print('In EX.FUNCDECL, args are', e.args)
			e.body.stmtlist = self:make(node.value.body)
			return e
		end,
		[EX.SCOPE] = func(self, node)
			e = parse('(func() None None end)()').stmtlist[0].expr
			node.type = EX.LIST
			e.expr.body.stmtlist = self:make(node)
			node.type = EX.SCOPE
			return e
		end,
		[EX.IFELSE] = func(self, node)
			e = parse('(func() if None then return None else return None end end)()').stmtlist[0].expr
			e.expr.body.stmtlist[0].cond = self:make(node.value.cond)
			e.expr.body.stmtlist[0].iftrue.stmtlist[0].ret = self:make(node.value.ift)
			e.expr.body.stmtlist[0].iffalse.stmtlist[0].ret = self:make(node.value.iff)
			return e
		end,
		[EX.DATUM] = func(self, node) error('EX.DATUM: Not implemented') end,
		[EX.LIT] = func(self, node)
			if type(node.value) == 'list' then
				e = parse('[None]').stmtlist[0].expr
				e.list = node.value:copy():map(func(i) return self:make(i) end)
			else
				e = parse('None').stmtlist[0].expr
				if type(node.value) == "int" then
					e.littype = ast.LIT_INT
					e.ival = node.value
				end
				if type(node.value) == "string" then
					e.littype = ast.LIT_STRING
					e.str = node.value
				end
			end
			return e
		end,
		[EX.REF] = func(self, node)
			e = parse('a').stmtlist[0].expr
			e.ident = node.value
			return e
		end,
		[EX.LIST] = func(self, node)
			e = parse('func() None end').stmtlist[0].expr
			l = node.value:copy()
			l:map(func(i)
				s = parse('None').stmtlist[0]
				s.expr = self:make(i)
				return s
			end)
			lastidx = (#l) - 1
			r = parse('return None').stmtlist[0]
			r.ret = l[lastidx].expr
			l[lastidx] = r
			--print('In EX.LIST, e is now' e)
			e.body.stmtlist = l
			return e.body.stmtlist
		end
	},
	run = func(self)
		list = self:make(self.parser:run())
		res = parse('(func() None None end)()')
		--print('In run, list is', list)
		--for i in list do ast.print(i) end
		res.stmtlist[0].expr.expr.body.stmtlist = list
		return res
	end
}

_G = debug.globals()
_G['+'] = func(a, b) return a + b end
_G['-'] = func(a, b) return a - b end
_G['*'] = func(a, b) return a * b end
_G['/'] = func(a, b) return a / b end
_G['<'] = func(a, b) return a < b end
_G['>'] = func(a, b) return a > b end
_G['<='] = func(a, b) return a <= b end
_G['>='] = func(a, b) return a >= b end
_G['=='] = func(a, b) return a == b end
_G['eq'] = _G['==']
_G['or'] = func(a, b) return a || b end
_G['and'] = func(a, b) return a && b end
