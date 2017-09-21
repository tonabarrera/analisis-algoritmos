/*****************************************************************
Titulo: arbol.h
Descripcion: Contiene la declaración de nuestra estructura arbol 
             y las funiones usadas en su creacion.
Fecha: 11-sep-17
Versión: 2.0
Autor: Los chilakillers
*****************************************************************/
#ifndef  __ARBOL__
#define __ARBOL__

#include <stdio.h>
#include <stdlib.h>

// estructura que modela el arbol binario
struct Arbol {
    int valor;
    struct Arbol *derecha;
    struct Arbol *izquierda;
};

// Recibe un doble apuntador a  un nodo en el que se insertara un nuevo nodo
// creado con el valor que se pasa como segundo parametro y finalmente
// retorna 1  si se hizo correctamente y menos uno en caso contrario.
int insertar(struct Arbol **, int);
// Funcion que crea el nodo, recive un doble apuntador 
// en el que se creara el nodo con cierto valor, para 
// despues ser insertado en otro nodo, devuelve - en caso de
// error y 1 si hubo exito
int crear_arbol(struct Arbol **, int);

#endif
