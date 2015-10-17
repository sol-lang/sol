# GDB Sol extensions

import gdb.printing
import sys
import traceback

class _CatchExceptions(object):
    def __init__(self):
        self.excs = []
    def print_eidx(self, idx):
        traceback.print_exception(*self.excs[idx])
    def __enter__(self):
        pass
    def __exit__(self, t, v, tb):
        if t is not None:
            self.excs.append((t, v, tb))
guard = _CatchExceptions()

class DslArray(gdb.Function):
    '''Returns the (DSL_DATATYPE[]) array base of a dsl_array or dsl_seq (if it wraps an array), else NULL'''

    def __init__(self):
        super(DslArray, self).__init__('dsl_array')

    def invoke(self, val):
        with guard:
            stype = str(val.type)
            tp = gdb.lookup_type('sol_object_t').pointer()
            if str(val.type).startswith('dsl_seq'):
                if str(val['type']) != 'DSL_SEQ_ARRAY':
                    return gdb.Value(0).cast(tp.pointer())
                val = val['array']
            if str(val.type).startswith('dsl_array'):
                return val['data'].dereference().cast(tp.array(val['len']))
            return gdb.Value(0).cast(tp.pointer())
DslArray.instance = DslArray()

class DslLen(gdb.Function):
    '''Returns the length of a DSL sequence'''

    def __init__(self):
        super(DslLen, self).__init__('dsl_array')

    def invoke(self, val):
        with guard:
            stype = str(val.type)
            if stype.startswith('dsl_seq'):
                return int(gdb.lookup_symbol('dsl_seq_len')[0].value()(val))
            if stype.startswith('dsl_array'):
                return int(gdb.lookup_symbol('dsl_array_len')[0].value()(val))
            if stype.startswith('dsl_list'):
                return int(gdb.lookup_symbol('dsl_list_len')[0].value()(val))
            return -1
DslLen.instance = DslLen()

class SolObj(gdb.Function):
    '''Casts the argument to a sol_object_t *'''

    def __init__(self):
        super(SolObj, self).__init__('sol_obj')

    def invoke(self, val):
        with guard:
            return val.cast(gdb.lookup_type('sol_object_t').pointer())
SolObj.instance = SolObj()

class SolObjectPrettyPrinter(object):
    STYPE_TO_DISPHINT = {
            'SOL_SINGLET': 'string',
            'SOL_INTEGER': 'number',
            'SOL_FLOAT': 'number',
            'SOL_STRING': 'string',
            'SOL_LIST': 'array',
            'SOL_MAP': 'map',
            'SOL_MCELL': 'map',
            'SOL_FUNCTION': 'function',
            'SOL_CFUNCTION': 'function',
            'SOL_STMT': 'syntax',
            'SOL_EXPR': 'syntax',
    }

    def __init__(self, obj):
        self.obj = obj

    def display_hint(self):
        return self.STYPE_TO_DISPHINT.get(str(self.obj['type']), 'string')

    def to_string(self):
        with guard:
            return getattr(self, 'str_'+str(self.obj['type']), self.str_default)(self.obj)

    def str_default(self, obj):
        return '<Unknown object %r type %s>'%(obj, str(obj['type']))

    def str_SOL_SINGLET(self, obj):
        return obj['str']

    def str_SOL_INTEGER(self, obj):
        return str(obj['ival'])

    def str_SOL_FLOAT(self, obj):
        return str(obj['fval'])

    def str_SOL_STRING(self, obj):
        return obj['str']

    def str_SOL_LIST(self, obj):
        return '[List len=%d]'%(DslLen.instance.invoke(obj['seq']),)

    def str_SOL_MAP(self, obj):
        return '{Map len=%d}'%(DslLen.instance.invoke(obj['seq']),)

    def str_SOL_MCELL(self, obj):
        return '<{[%s] = %s}>'%(SolObjectPrettyPrinter(obj['key']).to_string(), SolObjectPrettyPrinter(obj['val']).to_string())

    def str_SOL_FUNCTION(self, obj):
        return '<Function %s>'%(obj['fname'],)

    def str_SOL_CFUNCTION(self, obj):
        return '<CFunction %r>'%(obj['cfunc'],)

    def str_SOL_STMT(self, obj):
        return str(obj['node'].cast(gdb.lookup_type('stmt_node').pointer())['type'])

    def str_SOL_EXPR(self, obj):
        return str(obj['node'].cast(gdb.lookup_type('expr_node').pointer())['type'])

    def children(self):
        with guard:
            stype = str(self.obj['type'])
            if stype in ('SOL_LIST', 'SOL_MAP'):
                if str(self.obj['seq']['type']) == 'DSL_SEQ_ARRAY':
                    tp = gdb.lookup_type('sol_object_t').pointer()
                    lseq = DslLen.instance.invoke(self.obj['seq'])
                    arr = self.obj['seq']['array']['data'].dereference().cast(tp.array(lseq))
                    if stype == 'SOL_LIST':
                        return  [(str(i), arr[i]) for i in range(lseq)]
                    else:
                        return sum([[(str(i)+'k', arr[i]['key']), (str(i)+'v', arr[i]['val'])] for i in range(lseq)], [])
            if stype == 'SOL_FUNCTION':
                return [('stmt', self.obj['func'].cast(gdb.lookup_type('stmt_node').pointer))]
            return []

    @classmethod
    def check_printable(cls, obj):
        with guard:
            stype = str(obj.type)
            if stype.startswith('sol_object_t') or stype.startswith('struct sol_tag_object_t'):
                return cls(obj)
            return None

# pp = gdb.printing.RegexpCollectionPrettyPrinter('Sol')
# pp.add_printer('sol_object_t', '^sol_object_t.*$', SolObjectPrettyPrinter)
# pp.add_printer('sol_tag_object_t', '^struct sol_tag_object_t.*$', SolObjectPrettyPrinter)
# gdb.printing.register_pretty_printer(gdb.current_objfile(), pp)
gdb.current_objfile().pretty_printers.append(SolObjectPrettyPrinter.check_printable)

print('Sol extensions loaded!')
