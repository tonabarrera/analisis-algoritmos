#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__

    #include <stdio.h>
    #include <stdlib.h>
    #include "arbol.h"


    //la definicion de los tipos de errores que se manejan en el programa
    #define NO_ARGUMENTOS 0
    #define ARREGLO_NULO 1
    #define ARCHIVO_NULO 2
    #define LECTURA_FALLIDA 3
    
    // Nombre del algoritmo
    #define BURBUJA 1
    #define BURBUJA_CHIDO 2
    #define SELECCION 3
    #define INSERCION 4
    #define SHELL 5
    #define ARBOL 6

    //la definicion de las funciones del programa
    int ordenamiento_burbuja(int **, int);
    int ordenamiento_burbuja_mejorado(int **, int);
    int ordenamiento_insercion(int **, int);
    int ordenamiento_seleccion(int **, int);
    int ordenamiento_shell(int **, int);
    int llenar_arreglo(int **, int);
    int ordenamiento_arbol(int **, int);
    int error(int, char*);
    int imprimir_arreglo(int *, int);

#endif
