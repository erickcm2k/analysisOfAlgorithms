tiempo.o: tiempo.c
	gcc tiempo.c -c -Wall
bst-search.o: bst-search.c
	gcc bst-search.c -c -Wall

compile: bst-search.o tiempo.o
	gcc bst-search.o tiempo.o

# Numeros desodernados

1m:
	./a.out 1000000 < ../numbers/10m-desordenados.txt

2m:
	./a.out 2000000 < ../numbers/10m-desordenados.txt

3m:
	./a.out 3000000 < ../numbers/10m-desordenados.txt

4m:
	./a.out 4000000 < ../numbers/10m-desordenados.txt

5m:
	./a.out 5000000 < ../numbers/10m-desordenados.txt

6m:
	./a.out 6000000 < ../numbers/10m-desordenados.txt

7m:
	./a.out 7000000 < ../numbers/10m-desordenados.txt

8m:
	./a.out 8000000 < ../numbers/10m-desordenados.txt

9m:
	./a.out 9000000 < ../numbers/10m-desordenados.txt

10m:
	./a.out 10000000 < ../numbers/10m-desordenados.txt

test-all:
	echo -e "\n\n Testing for all numbers \n\n"
	make 1m 2m 3m 4m 5m 6m 7m 8m 9m 10m

clean:
	rm -f *.o a.out


	