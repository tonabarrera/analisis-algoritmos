#include "arbol.h"

int insertar(struct Arbol **arbol, int valor) {
    struct Arbol *arbol_nuevo = NULL;
    if (arbol == NULL) return -1;

    if (*arbol == NULL) {
        int existe_arbol_nuevo = crear_arbol(&arbol_nuevo, valor);
        if (existe_arbol_nuevo == -1) return -1;
        *arbol = arbol_nuevo;
    } else if (valor < ((*arbol)->valor))
        insertar(&((*arbol)->izquierda), valor);
    else if (valor > ((*arbol)->valor))
        insertar(&((*arbol)->derecha), valor);
    return 1;
}

int crear_arbol(struct Arbol **nuevo, int valor) {
    struct Arbol *auxiliar = NULL;
    auxiliar = (struct Arbol*)malloc(sizeof(struct Arbol));

    if (auxiliar == NULL) return -1;

    auxiliar->izquierda = NULL;
    auxiliar->derecha = NULL;
    auxiliar->valor = valor;
    *nuevo = auxiliar;
    return 1;
}

int guardar_inorden(struct Arbol *arbol, int **numeros, int n) {
    if (arbol == NULL) return n+1;

    n = guardar_inorden(arbol->izquierda, numeros, n);
    numeros[0][n] = arbol->valor;
    guardar_inorden(arbol->derecha, numeros, n);
}
