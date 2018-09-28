import sys

filepath = "./"

# basename
basename = sys.argv[1]
if '/' in basename:
  basename = basename[basename.rindex('/')+1:]
if basename.endswith(".bitstring"):
  basename = basename[:-10]

# load raw bits
fl_raw = open("bitstrings/"+basename+".bitstring", "r").read()

fp_out = open("headers/"+basename+".h", 'w')

fp_out.write("#include \"sound_struct.h\"\n\n")

fp_out.write("const uint8_t sound_%s_data[] PROGMEM = {\n  " % basename)
idx = 0
for fl in fl_raw:
  fp_out.write("0x%02x, " % ord(fl))
  idx += 1
  if idx % 8 == 0:
    fp_out.write("\n  ")

dt_size = len(fl_raw)
dt_samples = int(open("bitstrings/"+basename+".bitstring.samples").read().strip())

fp_out.write("\n};\n")

fp_out.write("sound_t sound_%s = { %d, %d, (PGM_P) sound_%s_data };\n" % (basename, dt_samples, dt_size, basename));

fp_out.close()
