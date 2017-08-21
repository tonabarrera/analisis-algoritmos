#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__

    #include <stdio.h>
    #include <stdlib.h>

    //la definicion de los tipos de errores que se manejan en el programa
    #define NO_ARGUMENTOS 0
    #define ARREGLO_NULO 1
    #define ARCHIVO_NULO 2
    #define LECTURA_FALLIDA 3

    //la definicion de las funciones del programa
    int ordenamiento_burbuja(int **, int);
    int ordenamiento_insercion(int **, int);
    int ordenamiento_shell(int **, int);
    int llenar_arreglo(FILE *, int **, int, char *);
    int error(int, char*);
    int imprimir_arreglo(int *, int);

#endif
