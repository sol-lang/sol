import sys
from collections import defaultdict

f = open('gclog.txt', 'r')

incs = defaultdict(lambda: 0)
decs = defaultdict(lambda: 0)
refs = defaultdict(lambda: 0)
seenrefs = {}
types = {}

lineno = 0

for line in f:
	lineno += 1
	if lineno % 10000 == 0:
		print 'Processing line', lineno
	if line[0] == '=':
		continue
	parts = line.split('\t')
	if parts[1] == 'I':
		incs[parts[0]] += 1
		refs[parts[3]] += 1
		types[parts[3]] = parts[2]
		seenrefs[parts[3]] = parts[6]
	elif parts[1] == 'D':
		decs[parts[0]] += 1
		refs[parts[3]] -= 1
		types[parts[3]] = parts[2]
		seenrefs[parts[3]] = parts[6]

incpairs = incs.items()
decpairs = decs.items()
refpairs = refs.items()

incpairs.sort(key=lambda it: it[1], reverse=True)
decpairs.sort(key=lambda it: it[1], reverse=True)
refpairs.sort(key=lambda it: it[1], reverse=True)

for k in seenrefs:
	seenrefs[k] = int(seenrefs[k])

totincs = sum((i[1] for i in incpairs))
totdecs = sum((i[1] for i in decpairs))
totliving = sum((i[1] for i in refpairs))
totsol = sum(seenrefs.itervalues())

out = open('gcstat.txt', 'w')
sys.stdout = out

print '=== Totals ==='
print '= Increfs:', totincs
print '= Decrefs:', totdecs
print '= Diff:', totincs - totdecs
print '= Living (our estimate):', totliving
print '= Living (according to Sol):', totsol

print '=== Functions, sorted by increments ==='
print '= %-30s%-8s%-8s'%('name', 'incs', 'decs')
for func, inccnt in incpairs:
	print '%-32s%-8d%-8d'%(func, inccnt, decs[func])

print '=== Functions, sorted by decrements ==='
print '= %-30s%-8s%-8s'%('name', 'decs', 'incs')
for func, deccnt in decpairs:
	print '%-32s%-8d%-8d'%(func, deccnt, incs[func])

print '=== Objects alive at cleanup ==='
print '= %-14s%-16s%-8s%-8s'%('addr', 'type', 'refs', 'solrefs')
for addr, refcnt in refpairs:
	print '%-16s%-16s%-8d%-8d'%(addr, types[addr], refcnt, seenrefs[addr])
