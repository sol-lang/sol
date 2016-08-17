execfile("tests/_lib.sol")

func dont_call_me(a) error("dont_call_me was called: " + tostring(a)) end

('after func_decl')  -- SHOULD be just a ST_EXPR
assert(1, "After funcdecl")

dont_call_me
('after st_expr')
assert(1, "After st_expr")
