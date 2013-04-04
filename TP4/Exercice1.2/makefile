all : hello

hello : hello.o main.o
	gcc hello.o main.o -o hello

hello.o : hello.c
	gcc -c hello.c -o hello.o

main.o : main.c hello.h
	gcc -c main.c -o main.o

clean :
	rm *.o


