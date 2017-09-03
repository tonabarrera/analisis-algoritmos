#!/bin/bash
# -*- ENCODING: UTF-8 -*-

gcc -Wall ejecucion.c funciones.c tiempo.c arbol.c

# ./a.out 100 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 1000 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 5000 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 10000 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 50000 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 100000 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 200000 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 400000 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 600000 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 800000 6 < numeros10millones.txt >> salida_arbol.txt
#./a.out 1000000 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 2000000 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 3000000 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 4000000 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 5000000 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 6000000 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 7000000 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 8000000 6 < numeros10millones.txt >> salida_arbol.txt
# ./a.out 9000000 6 < numeros10millones.txt >> salida_arbol.txt
./a.out 10000000 6 < numeros10millones.txt >> salida_arbol.txt

rm *.out

exit