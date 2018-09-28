from math import log

import array
import sys
import wave

filepath = "./"

eqn_order = 1

# basename
basename = sys.argv[1]
if '/' in basename:
  basename = basename[basename.index('/')+1:]
if basename.endswith(".wav"):
  basename = basename[:-4]

# open input
fp_in = wave.open(filepath+"orig/" + basename + ".wav", "r")
print fp_in.getnchannels(), "channels"
print fp_in.getsampwidth(), "byte width"
print fp_in.getframerate(), "samples per second"

# read input entirely into memory
frameraw = fp_in.readframes(fp_in.getnframes())
frameval = array.array("h", frameraw)

# process to generate output
frameval_8bit = list(0 for x in range(eqn_order))
for x in frameval:
  tv = int(x >> 8)
  frameval_8bit.append(tv)

# decompose into second derivative output
this_delta = list(0 for x in range(eqn_order))
for i in xrange(eqn_order, len(frameval_8bit)):
  if eqn_order == 2:
    dv = frameval_8bit[i] - 2*frameval_8bit[i-1] + frameval_8bit[i-2]
  elif eqn_order == 1:
    dv = frameval_8bit[i] - frameval_8bit[i-1]
  this_delta.append(dv)

# write out
fp_out = open(filepath+"symbols/"+basename+".symbols", 'w')
for i in this_delta:
  fp_out.write("%d\n" % i)
