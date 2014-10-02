a = 1
while a < 10 do
	print(a)
	a += 1
end

func mul9(b)
	for i in range(len(b)) do
		b[i] *= 9
	end
end

l = [1 2 3 4 5]
mul9(l)
for i in iter(l) do print(i) end

d = {
	integer = 1
	string = "hello"
	submap = {
		stamina = 100
		health = 42.0
	}
	sublist = [1 1 2 3 5 8],
	["this time with spaces"] = 2*PI,
	[1 + 5] = 1 + 5
}

d["integer"]
d.integer
d.integer += 5
