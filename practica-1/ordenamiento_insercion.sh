#!/bin/bash
# -*- ENCODING: UTF-8 -*-

# Titulo: ordenamiento_burbuja.sh
# Descripcion: Script que se usan en la ejecucion del algoritmo de insercion.
# Fecha: 11-sep-17
# Versión: 2.0
# Autor: Los chilakillers

gcc -Wall ejecucion.c funciones.c tiempo.c arbol.c

./a.out 100 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 1000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 5000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 10000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 50000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 100000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 200000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 400000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 600000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 800000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 1000000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 2000000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 3000000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 4000000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 5000000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 6000000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 7000000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 8000000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 9000000 4 < numeros10millones.txt >> salida_insercion.txt
./a.out 10000000 4 < numeros10millones.txt >> salida_insercion.txt

rm *.out

exit
