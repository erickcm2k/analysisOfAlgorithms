#!/bin/bash
ev="100 600 1000 3000 5000 8000 10000 20000 50000 80000 100000 150000 200000 250000 350000 400000 600000 700000 800000 900000 1000000 2000000"
CODIGO="burbujaSimple.c"
AUX="tiempo.c"
BACK="BACKsimple.txt"
OUT="burbujaSimple"
FILE="numeros10millones.txt"
gcc $CODIGO $AUX -o $OUT

#echo "**********BurbujaSimple**********" > $BACK
#echo "prueba con 500000"
#echo -e "\n**********prueba con 500,000**********" >> $BACK
#./$OUT 500000 < $FILE >> $BACK

for num in $ev; do
	echo "va en el $num"
	echo -e "\n**********prueba con $num**********" >> $BACK
	./$OUT $num < $FILE >> $BACK	
done
