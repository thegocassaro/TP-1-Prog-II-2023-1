all: files.o
	gcc -o trab1 *.o -lm

files.o:
	gcc -c *.c

clean:
	rm -f *.o

input1:
	./trab1 < inputs/input1 > output1

input2:
	./trab1 < inputs/input2 > output1

input3:
	./trab1 < inputs/input3 > output1

valgrind:
	valgrind ./trab1 < inputs/input3 > output1