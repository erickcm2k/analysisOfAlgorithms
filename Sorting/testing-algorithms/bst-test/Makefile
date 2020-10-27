tiempo.o: tiempo.c
	gcc tiempo.c -c -Wall
new-bst-sort.o: new-bst-sort.c
	gcc new-bst-sort.c -c -Wall

compile: new-bst-sort.o tiempo.o
	gcc new-bst-sort.o tiempo.o

100:
	./a.out 100 < ../../numbers/10m.txt

1k:
	./a.out 1000 < ../../numbers/10m.txt

5k:
	./a.out 5000 < ../../numbers/10m.txt

10k:
	./a.out 10000 < ../../numbers/10m.txt

50k:
	./a.out 50000 < ../../numbers/10m.txt

100k:
	./a.out 100000 < ../../numbers/10m.txt

200k:
	./a.out 200000 < ../../numbers/10m.txt

400k:
	./a.out 400000 < ../../numbers/10m.txt

500k:
	./a.out 500000 < ../../numbers/10m.txt

600k:
	./a.out 600000 < ../../numbers/10m.txt


800k:
	./a.out 800000 < ../../numbers/10m.txt

1m:
	./a.out 1000000 < ../../numbers/10m.txt

2m:
	./a.out 2000000 < ../../numbers/10m.txt

3m:
	./a.out 3000000 < ../../numbers/10m.txt

4m:
	./a.out 4000000 < ../../numbers/10m.txt

5m:
	./a.out 5000000 < ../../numbers/10m.txt

6m:
	./a.out 6000000 < ../../numbers/10m.txt

7m:
	./a.out 7000000 < ../../numbers/10m.txt

8m:
	./a.out 8000000 < ../../numbers/10m.txt

9m:
	./a.out 9000000 < ../../numbers/10m.txt

10m:
	./a.out 10000000 < ../../numbers/10m.txt

test-all:
	echo -e "\n\n Testing for all numbers \n\n"
	make 100 1k 5k 10k 50k 200k 400k 600k 800k 1m 2m 3m 4m 5m 6m 7m 8m 9m 10m

clean:
	rm -f *.o a.out