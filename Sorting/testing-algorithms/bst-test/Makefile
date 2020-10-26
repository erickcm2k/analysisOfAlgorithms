tiempo.o: tiempo.c
	gcc tiempo.c -c -Wall
bst-sort.o: bst-sort.c
	gcc bst-sort.c -c -Wall

a.out: bst-sort.o tiempo.o
	gcc bst-sort.o tiempo.o

run: a.out
	./a.out

10k:
	./a.out < ../../numbers/10k.txt

100k:
	./a.out < ../../numbers/100k.txt

clean:
	rm -f *.o a.out