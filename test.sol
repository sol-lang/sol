a = 1
while a < 10 do
	print(a)
	a += 1
end

func mul9(b)
	for i in range(#b) do
		b[i] *= 9
	end
end

l = [1 2 3 4 5]
mul9(l)
for i in l do print(i) end

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
	[1 + 5] = 1 + 5
}

print(d)

func bad(x)
	x.c()
end

test1 = {c = func() end}
test2 = {}

print(try(bad, test1))
print(try(bad, test2))

print(d["integer"])
print(d.integer)
d.integer += 5
print(d.integer)
