CC=gcc
CFLAGS=-Wall -std=c99 -pedantic

.PHONY: all clean

all: q1

%: %.c

clean:
	$(RM) q1
