tiempo.o: tiempo.c
	gcc tiempo.c -c -Wall
new-bst-sort.o: new-bst-sort.c
	gcc new-bst-sort.c -c -Wall

compile: new-bst-sort.o tiempo.o
	gcc new-bst-sort.o tiempo.o

# Numeros odernados

ord-1:
	./a.out 10000000 322486 < ../numbers/10m-ordenados.txt

ord-2:
	./a.out 10000000 14700764 < ../numbers/10m-ordenados.txt

ord-3:
	./a.out 10000000 3128036 < ../numbers/10m-ordenados.txt

ord-4:
	./a.out 10000000 6337399 < ../numbers/10m-ordenados.txt

ord-5:
	./a.out 10000000 61396 < ../numbers/10m-ordenados.txt

ord-6:
	./a.out 10000000 10393545 < ../numbers/10m-ordenados.txt

ord-7:
	./a.out 10000000 2417445644 < ../numbers/10m-ordenados.txt

ord-8:
	./a.out 10000000 1295390003 < ../numbers/10m-ordenados.txt

ord-9:
	./a.out 10000000 450057883 < ../numbers/10m-ordenados.txt

ord-10:
	./a.out 10000000 187645041 < ../numbers/10m-ordenados.txt

ord-11:
	./a.out 10000000 1980098116 < ../numbers/10m-ordenados.txt

ord-12:
	./a.out 10000000 152503 < ../numbers/10m-ordenados.txt

ord-13:
	./a.out 10000000 5000 < ../numbers/10m-ordenados.txt

ord-14:
	./a.out 10000000 1493283650 < ../numbers/10m-ordenados.txt

ord-15:
	./a.out 10000000 214826 < ../numbers/10m-ordenados.txt

ord-16:
	./a.out 10000000 1843349527 < ../numbers/10m-ordenados.txt

ord-17:
	./a.out 10000000 1360839354 < ../numbers/10m-ordenados.txt

ord-18:
	./a.out 10000000 2109248666 < ../numbers/10m-ordenados.txt

ord-19:
	./a.out 10000000 2147470852 < ../numbers/10m-ordenados.txt

ord-20:
	./a.out 10000000 0 < ../numbers/10m-ordenados.txt


ord-all:
	echo -e "\n\n Testing for all numbers \n\n"
	ord-1 ord-2 ord-3 ord-4 ord-5 ord-6 ord-7 ord-8 ord-9 ord-10 ord-11 ord-12 ord-13 ord-14 ord-15 ord-16 ord-17 ord-18 ord-19 ord-20

# Numeros desodernados

des-1:
	./a.out 10000000 322486 < ../numbers/10m-desordenados.txt

des-2:
	./a.out 10000000 14700764 < ../numbers/10m-desordenados.txt

des-3:
	./a.out 10000000 3128036 < ../numbers/10m-desordenados.txt

des-4:
	./a.out 10000000 6337399 < ../numbers/10m-desordenados.txt

des-5:
	./a.out 10000000 61396 < ../numbers/10m-desordenados.txt

des-6:
	./a.out 10000000 10393545 < ../numbers/10m-desordenados.txt

des-7:
	./a.out 10000000 2417445644 < ../numbers/10m-desordenados.txt

des-8:
	./a.out 10000000 1295390003 < ../numbers/10m-desordenados.txt

des-9:
	./a.out 10000000 450057883 < ../numbers/10m-desordenados.txt

des-10:
	./a.out 10000000 187645041 < ../numbers/10m-desordenados.txt

des-11:
	./a.out 10000000 1980098116 < ../numbers/10m-desordenados.txt

des-12:
	./a.out 10000000 152503 < ../numbers/10m-desordenados.txt

des-13:
	./a.out 10000000 5000 < ../numbers/10m-desordenados.txt

des-14:
	./a.out 10000000 1493283650 < ../numbers/10m-desordenados.txt

des-15:
	./a.out 10000000 214826 < ../numbers/10m-desordenados.txt

des-16:
	./a.out 10000000 1843349527 < ../numbers/10m-desordenados.txt

des-17:
	./a.out 10000000 1360839354 < ../numbers/10m-desordenados.txt

des-18:
	./a.out 10000000 2109248666 < ../numbers/10m-desordenados.txt

des-19:
	./a.out 10000000 2147470852 < ../numbers/10m-desordenados.txt

des-20:
	./a.out 10000000 0 < ../numbers/10m-desordenados.txt

des-all:
	echo -e "\n\n Testing for all numbers \n\n"
	des-1 des-2 des-3 des-4 des-5 des-6 des-7 des-8 des-9 des-10 des-11 des-12 des-13 des-14 des-15 des-16 des-17 des-18 des-19 des-20

clean:
	rm -f *.o a.out


	