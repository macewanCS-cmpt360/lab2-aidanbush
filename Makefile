CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -D_POSIX_C_SOURCE=200809L

.PHONY: all clean

all: q1 q2 q3

%: %.c

clean:
	$(RM) q{1,2,3} del
