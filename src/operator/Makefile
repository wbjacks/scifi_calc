CC=gcc
CFLAGS=-Wall -pedantic -std=c99 -g -ggdb
SOURCES=operator.c operator.h ../util/matrix.c ../util/matrix.h
CFILES=operator.c ../util/matrix.c

all:
	make clean; make operator; make run;

operator:$(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(CFILES)
	
clean:
	rm -f temp
	rm -f *~
	rm -f *.*~
	rm -f operator
	rm -f *.o
	rm -f *.swp 
	rm -f *#
	rm -f core*

run:
	./operator
