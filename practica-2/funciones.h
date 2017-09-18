/*****************************************************************
Titulo: funciones.h
Descripcion: contiene la declaración de todos nuestros algoritmos de ordenamiento.
Fecha: 11-sep-17
Versión: 2.0
Autor: Los chilakillers
*****************************************************************/
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
    #define BINARIO 1
    #define ARBOL 2
    #define LINEAL 3

    //la definicion de las funciones del programa
    int busqueda_binaria(int *, int, int, int);
    int busqueda_arbol(struct Arbol *, int);
    int llenar_arreglo(int **, int);
    int error(int, char*);
    int imprimir_arreglo(int *, int);

#endif
