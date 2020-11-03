#!/bin/dash
gcc seleccion.c -o seleccion tiempo.c
./seleccion 150000 < numeros10millones.txt >> sal_seleccion.txt
./seleccion 250000 < numeros10millones.txt >> sal_seleccion.txt
./seleccion 300000 < numeros10millones.txt >> sal_seleccion.txt
./seleccion 450000 < numeros10millones.txt >> sal_seleccion.txt
./seleccion 500000 < numeros10millones.txt >> sal_seleccion.txt
./seleccion 650000 < numeros10millones.txt >> sal_seleccion.txt
./seleccion 700000 < numeros10millones.txt >> sal_seleccion.txt
./seleccion 750000 < numeros10millones.txt >> sal_seleccion.txt