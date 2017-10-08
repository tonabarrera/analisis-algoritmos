#!/bin/bash
# -*- ENCODING: UTF-8 -*-

# Titulo: ordenamiento_burbuja.sh
# Descripcion: Script que se usan en la ejecucion del algoritmo arbol.
# Fecha: 11-sep-17
# Versión: 2.0
# Autor: Los chilakillers

gcc -Wall ejecucion.c funciones.c tiempo.c arbol.c


./a.out 10000000 6 < numeros10millones.txt >> salida_arbol.txt

rm *.out

exit