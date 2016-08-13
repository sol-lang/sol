print('--- Empty functions')

func f() end

print(f())

print('--- While loop')
a = 1
while a < 10 do
	print(a)
	a += 1
end

print("--- Range")

func mul9(b)
	for i in range(#b) do
		b[i] *= 9
	end
end

l = [1 2 3 4 5]
print(range(#l))
print("--- Iter list")
for i in l do print(i) end
print("--- Index list")
for i in range(#l) do print(i, l[i]) end
print('--- mul9')
mul9(l)
for i in l do print(i) end
print('--- Iter mul9')
for i in range(#l) do print(i, l[i]) end

print("--- Mapgen")

PI = 3.14159265358979

d = {
	integer = 1
	string = "hello"
	submap = {
		stamina = 100
		health = 42.0
	}
	sublist = [1 1 2 3 5 8],
	["this time with spaces"] = PI*2,
	[1 + 5] = 1 + 5,
	[1 + 9] = 1 + 9
}

print(d)
print('--- Map iter')
for i in d do print(i, d[i]) end

print('--- try')

func bad(x)
	print(x)
	return x.c()
end

test1 = {c = func() return 15 end}
test2 = {}

print(try(bad, test1))
print(try(bad, test2))

print(bad(test1))
--print(bad(test2))

print('--- Induced errors')

func raise(x)
	error(x)
end

print(try(raise, "lp0 on fire"))

print('--- Indexing')

print(d["integer"])
print(d.integer)
d.integer += 5
print(d.integer)

print('--- Function binding')

func outer(a)
	func inner(b)
		return a+b
	end
	inner.closure.a = a
	return inner
end

i = outer(5)
print(i(3), i(4), i(5))
j = outer(8)
print(j(3), j(4), j(5))

print('--- Iterators')

func myiter()
	if i>10 then return StopIteration end
	i+=1
	return i-1
end
myiter.closure.i = 1

for i in myiter do print(i) end

print('--- Method calls')

d = {a = func(a, b) print(a, b) end}

d.a(1, 2)
d:a(3)

print('--- Special methods')

d = {__index = func(obj, key) print('Index', obj, key) return key end,
     __setindex = func(obj, key, val) print('SetIndex', obj, key, val) end,
     __call = func(obj, arg1, arg2) print('Call', obj, arg1, arg2) return arg1 end}

print(d[3], d[5])

d.a = 7

print(d("q", "r"))

e = {a=1, b=2}
d = {__index = e, __setindex = e}

print(d, d.a, d.b)

d.c = 5
d.b = 7

print(d, e)

print('--- Data sharing')

d = {}
e = [1 2 3 4 5]
d.a = e
d.b = e

print(d)

e[2]=7
e[3]="c"

print(d)

d.a:insert(#(d.a), "q")
d.b:remove(1)
d.a[3]="f"

print(d)

print('--- Arithmetic structure operations')

print('ab'+'cd')
print('l'+'ol'*32)
print([1 2 3]+[4 5])
print([1 2 3]*5)
print({a=1 b=2}+{c=3})

print('--- Map/filter')

l = [1 2 3 4 5]
print(l)

l:map(func (i) return i*3 end)
print(l)

l:filter(func (i) return i & 1 end)
print(l)

print('--- Map/filter chain')

print([1 2 3 4 5]:map(func (i) return i * 3 end):filter(func (i) return i & 1 end))

print('--- Exec/eval')

exec('print("Hello from exec!")')
print(eval('5 + 3'))
execfile('programs/subtest.sol')

print('--- Modulus')

print(5%3)
print(13%5)
print(15%15)

print('--- Special function manipulation')

func foo(x)
	return x
end

print(foo)
foo.name = "bar"
print(foo)

func something()
	return i
end

something.closure = {i=[1, 2, 3]}
print(something())

cl = something.closure
cl.i:insert(0, "b")
print(something())

print('--- Function body swapping')

func a()
	return 0
end

func b()
	return 2
end

print(a, a())
print(b, b())

print(a.stmt)
print(b.stmt)

temp = a.stmt
a.stmt = b.stmt
b.stmt = temp

print(a, a())
print(b, b())

newbody = parse('return 4')
print(newbody)

a.stmt = newbody
b.stmt = newbody

print(a, a())
print(b, b())

print('--- More complicated ASTs')

print(outer, outer.stmt, outer.stmt.stmtlist)

print('--- Exec- and eval-by-parse')

parse('print("Hello from parse()!")')()
print(parse('5 + 3').stmtlist[0].expr())

print('--- Mutating ASTs')

func f()
	return 5 + 7
end

print(f, f.stmt, f())

f.stmt.stmtlist[0].ret.right.ival = 11

print(f, f.stmt, f())

func g()
	a=1
	b=2
	print("a=", a, ", b=", b)
end

print(g, g.stmt, g())

g.stmt.stmtlist[1].expr.value = parse('a').stmtlist[0].expr

print(g, g.stmt, g())

print('--- AST Environments')

code = parse('print("a is", a, "and b is", b"); a = 4; b = 5')
print(code)
code()

d = {a=1, b=2}
print(d)
code(d)
print(d)
e = {a="hello", b=["world"]}
print(e)
code(e)
print(e)

e = {a=1, b=2}
d = {__index = e}
print(d)
print(e)
code(d)
print(d)
print(e)

print('--- Basic buffers')

print('(buffer.fromstring = ', buffer.fromstring, ')')
b = buffer.fromstring("Hello, world!")
print(b)
print('(b.get = ', b.get, ')')
print(b:get(buffer.type.cstr))
b:set(buffer.type.char, "Q")
b:set(buffer.type.char, "L", 2)
print(b:get(buffer.type.cstr))
print(b:get(buffer.type.cstr, 5))
print(b:get(buffer.type.uint32))
--b:set(buffer.type.double, 1.243416560929)
b:set(buffer.type.uint32, 1886545252)
print(b:get(buffer.type.uint32))
print(b:get(buffer.type.cstr))
q = buffer.fromaddress(b:address(), b:size())
print(q:get(buffer.type.cstr))
q:set(buffer.type.cstr, "Goodbye!")
print(q:get(buffer.type.cstr), b:get(buffer.type.cstr))

s = "A string!"
b = buffer.fromobject(s)
prepr(s)
print('...is a', buffer.objtype[b:get(buffer.type.int, 0)])
print('(buffer.sizeof.ptr = ', buffer.sizeof.ptr, ')')
print('(buffer.sizeof.int = ', buffer.sizeof.int, ')')
print('(buffer.sizeof.int*2 = ', buffer.sizeof.int*2, ')')
print('(buffer.sizeof.int*2 + buffer.sizeof.ptr = ', buffer.sizeof.int*2 + (buffer.sizeof.ptr), ')')
bs = b:get(buffer.type.ptr, buffer.sizeof.int*2 + (buffer.sizeof.ptr))
print('...string buffer:', bs)
print('...with value:', bs:get(buffer.type.cstr))

print('--- IO redirection')

oldstdout = io.stdout
io.stdout = io.open('stdout', io.MODE_WRITE|io.MODE_TRUNCATE)

print('A line!')
print('An object:', {a=1, b=2, c="turkey"})
print('Something mysterious :o')
io.stdout:write('Writing directly to a file :D')
io.stdout:flush()

io.stdout = oldstdout

print('...restored stdout.')

f = io.open('stdout', io.MODE_READ)
s = f:read(io.ALL)
print('Buffered output was:')
prepr(s)
f = None

print('...second time.')

io.stdout = io.open('stdout', io.MODE_WRITE|io.MODE_TRUNCATE)

print('Hey there!')
print('l'+'ol'*32)
io.stdout:flush()

io.stdout = oldstdout

print('...restored.')
print('Output was:')
prepr(io.open('stdout', io.MODE_READ):read(io.ALL))

print('--- Substrings')

s = 'This is a test!'
prepr(s)
prepr(s:sub(1, -1))
prepr(s:sub(3, -3))
prepr(s:sub(3, 5))
prepr(s:sub(3, 11))
prepr(s:sub(-1000, -1000))

print('--- Splitting')
s = 'This is a test!'
prepr(s)
prepr(s:split(' '))
prepr(s:split('i'))
prepr(s:split('0'))
prepr(s:split('aeiou'))

l = s:split(' ')
for i in l do
	prepr(i, type(i))
end

print('--- Continue/break')

l = range(10)
for i in l do
	print(i)
	if i >= 5 then break end
end

print('---')

for i in l do
	if i%2 == 0 then continue end
	print(i)
end

print('--- All done!')
