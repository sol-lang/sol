-- Simple package manager script

package = {
	path = ['./', '/usr/share/sol/'],
	extensions = ['.sol', ''],
	loaded = {},
	loading = {},
	load = func(self, file)
		result = try(io.open, file, io.MODE_READ)
		if !result[0] then return None end
		stream = result[1]
		program = parse(stream:read(io.ALL))
		return self:load_node(program)
	end,
	load_node = func(self, node)
		environ = {}
		node(environ)
		return environ
	end,
	import = func(self, name)
		if None != self.loading[name] then
			error('Already loading: '+name)
		end
		self.loading[name] = True
		if None != self.loaded[name] then return self.loaded[name] end
		for path in self.path do
			for extension in self.extensions do
				module = self:load(path + name + extension)
				if None != module then
					self.loaded[name] = module
					self.loading[name] = None
					return module
				end
			end
		end
		self.loading[name] = None
		error('Module not found')
	end,
}

--None  -- Separator

func()
	stream = try(io.open, '/etc/sol/path', io.MODE_READ)
	if stream[0] then
		stream = stream[1]
		while !stream:eof() do
			line = stream:read(io.LINE)
			line = line:sub(0, -1)
			if #line then
				package.path:insert(#package.path, line)
			end
		end
	end
end()
