.POSIX:

all: bin/pinc

include config.mk

bin/pinc:
	$(PINK) -nosourcemap -o pin.c pinc/
	$(CC) pin.c -o bin/pinc