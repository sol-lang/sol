execfile("tests/_lib.sol")

func rec_tostring(v)
	return for i in v do
		continue if type(i) == "list" then
			rec_tostring(i)
		else
			tostring(i)
		end
	end
end

l = [ [1, 2, 3], [4, 5, 6], [7, 8, 9] ]
q = [ ["1", "2", "3"], ["4", "5", "6"], ["7", "8", "9"] ]

assert_eq(rec_tostring(l), q, "nested continue-map fors")
