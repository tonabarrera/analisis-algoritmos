#ifndef  __ARBOL__
#define __ARBOL__

#include <stdio.h>
#include <stdlib.h>

struct Arbol {
    int valor;
    struct Arbol *derecha;
    struct Arbol *izquierda;
};

int insertar(struct Arbol **, int);
int crear_arbol(struct Arbol **, int);
int guardar_inorden(struct Arbol *, int[], int);
#endif
