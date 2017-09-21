#!/bin/bash
# -*- ENCODING: UTF-8 -*-

# Titulo: busqueda_arbol.sh
# Descripcion: Script que se usan en la ejecucion del algoritmo de busqueda usando un arbol binario.
# Fecha: 17-sep-17
# Versión: 1.0
# Autor: Los chilakillers

gcc -Wall ejecucion.c funciones.c tiempo.c arbol.c

./a.out 100 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 1000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 5000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 10000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 50000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 100000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 200000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 400000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 600000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 800000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 1000000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 2000000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 3000000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 4000000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 5000000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 6000000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 7000000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 8000000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 9000000 2 < numeros10millones.txt >> salida_arbol.txt
./a.out 10000000 2 < numeros10millones.txt >> salida_arbol.txt

rm *.out

exit