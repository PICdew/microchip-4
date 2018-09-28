from math import *
import sys

# create a huffman table for the actual distribution

# generate initial symbol probabilities
symbols = {}
for fn in sys.argv[1:]:
  tsym = [int(x.strip()) for x in open(fn, 'r').read().split()]
  
  for s in tsym:
    if not symbols.has_key(s):
      symbols[s] = 0.0
    symbols[s] += 1.0
  
# rescale and
# calculate theoretical entropy
theoreticalentropy = 0.0  
ttl = sum([symbols[i] for i in symbols.keys()])
for i in symbols.keys():
  symbols[i] = symbols[i] / ttl
  if symbols[i] > 0:
    theoreticalentropy += - symbols[i] * log(symbols[i]) / log(2.0)

# display probabilities
#for i in sorted(symbols.keys()):
#  print i, symbols[i]

# generate initial table
# tuples (probability, [ (symbol, rep), ...])
hufflist = []
for i in symbols.keys():
  hufflist.append(  (symbols[i], [(i, '')] )  )
  
# reduce table as we go
while len(hufflist) > 1:
  # sort by ascending probabiltiies
  hufflist.sort(key = lambda x: x[0])
  # take the two smallest ones.
  x1 = hufflist.pop(0)
  x2 = hufflist.pop(0)
  # for all the symbols, preprend 0 or 1
  newprob = x1[0] + x2[0] # add probabilities
  newsymreps = []
  for x in x1[1]:
    newsymreps.append( (x[0], '0'+x[1]) )
  for x in x2[1]:
    newsymreps.append( (x[0], '1'+x[1]) )

  # add this entry back into the list
  hufflist.append(  (newprob, newsymreps) )

# now print out the entry
allsymreps = hufflist[0][1]
allsymreps.sort(key = lambda x: x[0])

huffmancodeentropy = 0.0

for x in allsymreps:
  print x[0], "\t", x[1]
  huffmancodeentropy += symbols[x[0]] * len(x[1])

print "# Theoretical entropy: \t", theoreticalentropy, "bits per symbol"
print "# Huffman code avg.len:\t", huffmancodeentropy, "bits per symbol"
