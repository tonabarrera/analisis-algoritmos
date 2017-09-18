/*****************************************************************
Titulo: funciones.c
Descripcion: Contiene la definición de las funciones declaradas en el archivo funciones.h.
Fecha: 11-sep-17
Versión: 2.0
Autor: Los chilakillers
*****************************************************************/
#include "funciones.h"

/****************************************************************
    BUSQUEDA BINARIA
    -Este algoritmo recibe como parametro un arreglo de numeros que se supone ordenado, un numero entero a buscar,
      un numero izquierda que marca el indice izquierdo y un numero entero derecha que marca el indice derecho

    -Se basa en el hecho de que podemos dividir el arreglo a la mitad, comparar y descartar una mitad,
    despues podemos aplicar la misma logica a la mitad que nos queda, esto de modo recursivo.

    -Retorna el indice del elemento encontrado o -1 si no se encuentra
****************************************************************/
int busqueda_binaria(int * numeros, int n, int izquierda, int derecha){
    if(numeros == NULL){return -1;} //revisamos que el arreglo de numeros no sea nulo
    if(izquierda > derecha){return -1;} //revisamos que el incide izquierdo no sea mayor que el derecho, lo que indica que o no se encontro el elemento

    int m = (derecha + izquierda) / 2; //tomamos un indice que este a la mitad del arreglo

    if(numeros[m] > n){return busqueda_binaria(numeros, n, izquierda, m-1);} // si numeros[m] > n, no tiene caso seguir buscando a la derecha, pues solo encontramos numeros mas grandes
    if(numeros[m] < n){return busqueda_binaria(numeros, n, m+1, derecha);} // si numeros[m] < n, no tiene caso seguir buscando a la izquierdo, pues solo encontramos numeros mas pequeños
    if(numeros[m] == n){return m;} //numeros[m] = n, ya lo encontramos
    return -1; //esto es para evitar el warning, en realidad no deberia llegar a este punto
}
/***************************************************************
    FIN del algoritmo de BUSQUEDA BINARIA
***************************************************************/

/**************************************************************
    BUSQUEDA ARBOL
    - Este algoritmo recibe como parametro un arbol binario que contiene los numeros "ordenados",
    un numero a buscar.
    - Se basa en recorrer el arbol desde la raiz y decidir a que nodo hijo (izquierda/derecha)
    debe de moverse.
    - Retorna uno si lo encuentra o -1 si no lo encuentra.
***************************************************************/
int busqueda_arbol(struct Arbol *arbol, int dato){
    if(arbol == NULL)
        return -1; // No se encontro el elemento
    if(dato == arbol->elemento) // Si el numero lo encuentra retorna 1
        return 1;
    if(dato > arbol->elemento)
        return busqueda_arbol(arbol->derecha, dato);
    else
        return busqueda_arbol(arbol->izquierda, dato);
    return -1; // No se encontro el elemento
}

//Estas funciones son axuliares

//recibe un arreglo numeros que contiene los numeros desordenados
//recibe un numero que equivale al tamanio del arreglo
//devuelve cero si se realizo correctamente
int llenar_arreglo(int ** numeros, int n){ //saca n elementos del archivo y los pone en el arreglo
    if(numeros == NULL){return error(ARREGLO_NULO, "llenar_arreglo");} //valida que el arreglo en el que vamos a guardar los numeros no sea nulo

    int i = 0; //crea un enetero igualado a cero
    char * auxiliar = (char *)malloc(33 * sizeof(char)); //creamos la variable auxiliar para leer los numeros

    for(i = 0; i < n; i++){ //llenando el arreglo de numeros
        scanf("%s", auxiliar); //lee un numero
        *(*(numeros) + i) = atoi(auxiliar); //convierte el numero de cadena de caracteres a entero y lo guarda en el arreglo
    }

    return 0; //retorna cero
}

//recibe un arreglo numeros que contiene los numeros desordenados
//recibe un numero que equivale al tamanio del arreglo
//devuelve cero si se realizo correctamente
int imprimir_arreglo(int * numeros, int n){ //imprime el arreglo que recibe como parametro
    if(numeros == NULL){return error(ARREGLO_NULO, "imprimir_arreglo");} //valida que el arreglo no este vacio

    int i = 0; //crea una variable de tipo entero igualada a cero

    printf("%s\n", "El arreglo es:"); //imprime "el arreglo es:"
    for(i = 0; i < n; i++){ //itera desde 0 hasta n
        printf("%d\n", numeros[i]); //imprime el numero de la posicion i del arreglo
    }

    return 0; //retorna cero
}


int error(int clase_error, char*info_extra){ //esta clase maneja los mensajes de error
    if(clase_error == 0){
        printf("%s\n", "Argumentos insuficientes.");
    }
    else if(clase_error == 1){
        printf("No es posible enviar un arreglo nulo como parametro de la funcion: %s.\n", info_extra);
    }
    else if(clase_error == 2){
        printf("EL archivo: %s, es nulo.\n", info_extra);
    }
    else if(clase_error == 3){
        printf("Imposible leer mas datos en el archivo: %s\n", info_extra);
    }
    exit(1);
    return 1;
}
