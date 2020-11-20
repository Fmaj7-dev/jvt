CC=clang++
CFLAGS=-I.

vector: vector.cpp
	$(CC) -o $@ $< $(CFLAGS)

c: test.cpp
	$(CC) -o $@ $< $(CFLAGS)
	./c

test: vector
	./vector
