#!/bin/bash
# -*- ENCODING: UTF-8 -*-

gcc ejecucion.c funciones.c tiempo.c arbol.c

./a.out 100 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 1000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 5000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 10000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 50000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 100000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 200000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 400000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 600000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 800000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 1000000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 2000000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 3000000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 4000000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 5000000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 6000000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 7000000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 8000000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 9000000 < numeros10millones.txt >> salidaBubbleSort_simple.txt
./a.out 10000000 < numeros10millones.txt >> salidaBubbleSort_simple.txt

exit
