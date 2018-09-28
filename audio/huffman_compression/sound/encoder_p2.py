from math import log

import array
import sys

filepath = "./"

# basename
basename = sys.argv[1]
if '/' in basename:
  basename = basename[basename.index('/')+1:]
if basename.endswith(".wav"):
  basename = basename[:-4]

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
  huffmancode[int(flsp[0])] = flsp[1]
  
# open input
this_delta = [int(x.strip()) for x in open(filepath+"symbols/"+basename+".symbols", 'r').read().split()]

# create bitstring
out_bitstring = ""
for i in this_delta:
  out_bitstring += huffmancode[i]

# pad to a multiple of 8 bits
bitrem = len(out_bitstring) % 8
if bitrem != 0:
  out_bitstring += "0" * (8 - bitrem)

# convert to bytes
out_bytes = ""
for i in xrange(0, len(out_bitstring), 8):
  # little endian
  tbits = out_bitstring[i:i+8]
  tb = 0
  for j in xrange(8):
    if tbits[j] == '1':
      tb += (1<<j)
  out_bytes += chr(tb)

fp_out = open(filepath+"bitstrings/"+basename+".bitstring", 'w')
fp_out.write(out_bytes)

fps_out = open(filepath+"bitstrings/"+basename+".bitstring.samples", 'w')
fps_out.write('%d' % len(this_delta))

#print out_bitstring
print len(out_bitstring), "bits"
print "compressed from original ", 8*len(this_delta)
