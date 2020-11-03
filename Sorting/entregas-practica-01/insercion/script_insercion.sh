#!/bin/dash
gcc insercion.c -o insercion tiempo.c
./insercion 150000 < numeros10millones.txt >> sal_insercion.txt
./insercion 250000 < numeros10millones.txt >> sal_insercion.txt
./insercion 300000 < numeros10millones.txt >> sal_insercion.txt
./insercion 450000 < numeros10millones.txt >> sal_insercion.txt
./insercion 500000 < numeros10millones.txt >> sal_insercion.txt
./insercion 650000 < numeros10millones.txt >> sal_insercion.txt
./insercion 700000 < numeros10millones.txt >> sal_insercion.txt
./insercion 750000 < numeros10millones.txt >> sal_insercion.txt



