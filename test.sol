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
	inner.a = a
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
myiter.i = 1

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
execfile('subtest.sol')

print('--- Modulus')

print(5%3)
print(13%5)
print(15%15)

print('--- All done!')
