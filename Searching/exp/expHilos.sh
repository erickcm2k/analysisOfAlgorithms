#!/bin/bash
codigo="expHilos.c"
out="expHilos"
numeros="10millones.txt"

gcc $codigo -o -lpthread $out

./$out 10000000 0 < $numeros
./$out 10000000 214282497 < $numeros
./$out 10000000 2147483528 < $numeros