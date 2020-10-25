tiempo.o: tiempo.c
	gcc tiempo.c -c -Wall
main.o: main.c
	gcc main.c -c -Wall

a.out: main.o tiempo.o
	gcc main.o tiempo.o

run: a.out
	./a.out testSize

clean:
	rm -f *.o a.out