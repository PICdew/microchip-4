GCCFLAGS=-g -Os -Wall -mmcu=atmega328p
#LINKFLAGS=-Wl,-u,vfprintf -lprintf_flt -Wl,-u,vfscanf -lscanf_flt
LINKFLAGS=
AVRDUDEFLAGS=-c avr109 -p m328p -b 115200 -P /dev/ttyUSB0
LOCALLINKOBJECTS=realtimeclock.o huffcode.o
LINKOBJECTS=${LOCALLINKOBJECTS} ../libnerdkits/delay.o ../libnerdkits/uart.o

all:	halloween_audio-upload

clean:
	make -C sound/ clean
	rm -f huffcode.c halloween_audio.o huffcode.o realtimeclock.o halloween_audio.ass halloween_audio.hex

size: halloween_audio.hex
	avr-size halloween_audio.hex

huffcode.c:
	make -C sound/

halloween_audio.hex:	halloween_audio.c ${LOCALLINKOBJECTS} huffcode.c
	make -C ../libnerdkits
	avr-gcc ${GCCFLAGS} ${LINKFLAGS} -o halloween_audio.o halloween_audio.c ${LINKOBJECTS}
	avr-objcopy -O ihex halloween_audio.o halloween_audio.hex

huffcode.o: huffcode.c
	avr-gcc ${GCCFLAGS} -o huffcode.o -c huffcode.c

realtimeclock.o: realtimeclock.c
	avr-gcc ${GCCFLAGS} -o realtimeclock.o -c realtimeclock.c

halloween_audio.ass:	halloween_audio.hex
	avr-objdump -S -d halloween_audio.o > halloween_audio.ass
	
halloween_audio-upload:	halloween_audio.hex
	avrdude ${AVRDUDEFLAGS} -U flash:w:halloween_audio.hex:a
