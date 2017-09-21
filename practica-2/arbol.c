/*****************************************************************
Titulo: arbol.c
Descripcion: Contiene la definicion de las funciones declaradas en el archivo arbol.h.
Fecha: 11-sep-17
Versión: 2.0
Autor: Los chilakillers
*****************************************************************/
#include "arbol.h"

// Recibe un doble apuntador a  un nodo en el que se insertara un nuevo nodo
// creado con el valor que se pasa como segundo parametro y finalmente
// retorna 1  si se hizo correctamente y menos uno en caso contrario.
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

// Funcion que crea el nodo, recive un doble apuntador 
// en el que se creara el nodo con cierto valor, para 
// despues ser insertado en otro nodo, devuelve - en caso de
// error y 1 si hubo exito
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
