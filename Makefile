all: files.o
	gcc -o trab1 *.o

files.o:
	gcc -c *.c

clean:
	rm -f *.o

input:
	./trab1 < input1 > output1

valgrind:
	valgrind ./trab1