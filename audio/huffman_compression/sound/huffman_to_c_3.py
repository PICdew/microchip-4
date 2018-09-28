import sys

filepath = "./"

# load huffman code
huffmancode = {}
fl_huff = open("huffmancode.txt", "r").read().split("\n")
for fl in fl_huff:
  fl = fl.strip()
  if len(fl) == 0 or fl.startswith("#"):
    continue
  flsp = fl.split()
  if len(flsp) != 2:
    print "parse error: ", flsp
    sys.exit(1)    
  huffmancode[flsp[1]] = int(flsp[0])

# sort by length
allkeys = huffmancode.keys()
allkeys.sort(key = lambda x: len(x))

minlen = len(allkeys[0])
maxlen = len(allkeys[-1])

# construct a tree

hufftree = [None, None]

def place_in_tree(startnode, keyref, value):
  # recursive.
  if keyref == '0':
    # left leaf
    startnode[0] = value
  elif keyref == '1':
    # right leaf
    startnode[1] = value
  else:
    # recursive case
    nextnodeid = ord(keyref[0]) - ord('0')
    if type(startnode[nextnodeid]) is not list:
      startnode[nextnodeid] = [None, None]
    place_in_tree(startnode[nextnodeid], keyref[1:], value)

for k in allkeys:
  place_in_tree(hufftree, k, huffmancode[k])

print "#include <inttypes.h>"
print ""
print "extern uint8_t get_next_bit();"
print ""
print "int16_t get_next_symbol() {"

def print_tree(level, startnode, keyref):
  print ("  " * level) + "if(get_next_bit() == 1) {"

  if type(startnode[1]) is int:
    print ("  " * (level + 1)) + "return %d; // %s" % (startnode[1], keyref + '1')
  elif type(startnode[1]) is list:
    # descend
    print_tree(level+1, startnode[1], keyref + '1')
  
  print ("  " * level) + "} else {"

  if type(startnode[0]) is int:
    print ("  " * (level + 1)) + "return %d; // %s" % (startnode[0], keyref + '0')
  elif type(startnode[0]) is list:
    # descend
    print_tree(level+1, startnode[0], keyref + '0')

  print ("  " * level) + "}"
  
print_tree(1, hufftree, '')

print "}"
