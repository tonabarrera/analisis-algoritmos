#!/bin/bash
# -*- ENCODING: UTF-8 -*-

# Titulo: ordenamiento_burbuja.sh
# Descripcion: Script que se usan en la ejecucion del algoritmo arbol.
# Fecha: 11-sep-17
# Versión: 2.0
# Autor: Los chilakillers

gcc -Wall ejecucion.c funciones.c tiempo.c arbol.c

./a.out 100 3 < 10millones.txt >> salida_lineal.txt
./a.out 1000 3 < 10millones.txt >> salida_lineal.txt
./a.out 5000 3 < 10millones.txt >> salida_lineal.txt
./a.out 10000 3 < 10millones.txt >> salida_lineal.txt
./a.out 50000 3 < 10millones.txt >> salida_lineal.txt
./a.out 100000 3 < 10millones.txt >> salida_lineal.txt
./a.out 200000 3 < 10millones.txt >> salida_lineal.txt
./a.out 400000 3 < 10millones.txt >> salida_lineal.txt
./a.out 600000 3 < 10millones.txt >> salida_lineal.txt
./a.out 800000 3 < 10millones.txt >> salida_lineal.txt
./a.out 1000000 3 < 10millones.txt >> salida_lineal.txt
./a.out 2000000 3 < 10millones.txt >> salida_lineal.txt
./a.out 3000000 3 < 10millones.txt >> salida_lineal.txt
./a.out 4000000 3 < 10millones.txt >> salida_lineal.txt
./a.out 5000000 3 < 10millones.txt >> salida_lineal.txt
./a.out 6000000 3 < 10millones.txt >> salida_lineal.txt
./a.out 7000000 3 < 10millones.txt >> salida_lineal.txt
./a.out 8000000 3 < 10millones.txt >> salida_lineal.txt
./a.out 9000000 3 < 10millones.txt >> salida_lineal.txt
./a.out 10000000 3 < 10millones.txt >> salida_lineal.txt

rm *.out

exit
