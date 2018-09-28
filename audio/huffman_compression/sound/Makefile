all: encoding headers

clean:
	rm -f huffmancode.txt
	rm -f symbols/*.symbols
	rm -f bitstrings/*.bitstring
	rm -f bitstrings/*.bitstring.samples
	ls headers/*.h | grep -v "sound_struct.h" | xargs -n 1 --no-run-if-empty rm -I

encoding: orig/*.wav *.py
	mkdir -p symbols
	mkdir -p bitstrings
	ls orig/*.wav | xargs -n 1 python encoder_p1.py
	python huffmangen_exp.py symbols/*.symbols > huffmancode.txt
	python huffman_to_c_3.py > ../huffcode.c
	ls orig/*.wav | xargs -n 1 python encoder_p2.py

headers: encoding
	ls bitstrings/*.bitstring | xargs -n 1 python bitstring_to_c.py

.PHONY: clean encoding headers
