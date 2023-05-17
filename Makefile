all: files.o
	gcc -o trab1 *.o

files.o:
	gcc -c *.c

clean:
	rm -f *.o

valgrind:
	valgrind ./trab1