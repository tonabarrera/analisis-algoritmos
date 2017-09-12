/*****************************************************************
Titulo: funciones.c
Descripcion: Contiene la definición de las funciones declaradas en el archivo funciones.h.
Fecha: 11-sep-17
Versión: 2.0
Autor: Los chilakillers
*****************************************************************/
#include "funciones.h"

int ordenamiento_burbuja(int ** numeros, int n){ //aqui empieza el ordenamiento_burbuja
    if(numeros == NULL){return error(ARREGLO_NULO, "ordenamiento_burbuja");} //valida que el arrelgo de numeros no sea vacio

    //inician las variables auxiliares
    int i = 0;
    int j = 0;
    int temp = 0;

    //en este algoritmos recorreremos todo el arreglo comparando cada numero
    //con el numero de la derecha para ver quien es el mayor
    for(i = 1; i < n; i++){
        for(j = 0; j < (n-1); j++){
            if(numeros[0][j] > numeros[0][j+1]){ //hacemos un swap en si el numero de la derecha es menor que el numero de la izquierda
                //hacemos el swap de las posiciones
                temp = numeros[0][j];
                numeros[0][j] = numeros[0][j+1];
                numeros[0][j+1] = temp;
            }
        }
    }

    return 0; //retorna cero
}

// Recibe un arreglo de numeros y un 
// valor que indica cuantos elementos hay en el arreglo
// Ordena el arreglo de numeros utilizando 
// el ordenamiento burbuja mejorado cuya principal
// caracteristica es el uso de una bandera indicando si ocurre algun intercambio
// Devuelve 0 si se realizo correctamente 
// y si ocurre un error termina la ejecucion e imprime el error
int ordenamiento_burbuja_mejorado(int **numeros, int n) {
    if(numeros == NULL) return error(ARREGLO_NULO, "ordenamiento_burbuja_mejorado");

    short cambio = 1;
    int i, j;
    int temporal = 0;

    for (i=1; i<n && cambio; i++) {
        cambio = 0;
        for (j=0; j<n-i; j++) {
            if (numeros[0][j+1] < numeros[0][j]) {
                temporal = numeros[0][j];
                numeros[0][j] = numeros[0][j+1];
                numeros[0][j+1] = temporal;
                cambio = 1;
            }
        }
    }
    return 0;
}


int ordenamiento_insercion(int ** numeros, int n){ //aqui comienza el ordenamiento_insercion
    if(numeros == NULL){return error(ARREGLO_NULO, "ordenamiento_insercion");} //valida que el arreglo de numeros no sea vacio

    //inicializa las variables auxiliares
    int i = 0;
    int j = 0;
    int temporal = 0;

    for(i = 1; i < n; i++){
        temporal = numeros[0][i];
        j = i - 1;
        while( (numeros[0][j] > temporal) && (j >= 0) ){ //siempre que la variable temporal sea mayor seguiremos bajando en el arrelgo
            numeros[0][j+1] = numeros[0][j];
            j--; //decrementamos j
        }
        numeros[0][j+1] = temporal; //ponemos a la variable temporal en el lugar que le toca
    }

    return 0; //retorna cero
}

// Recibe un arreglo de numeros y un valor 
// que indica cuantos elementos hay en el arreglo
// Ordena el arreglo de numeros utilizando el 
// ordenamiento de arbol por seleccion cuya principal
// caracteristica es buscar el numero más pequeño y ponerlo en su lugar correcto
// Devuelve 0 si se realizo correctamente y si 
// ocurre un error termina la ejecucion e imprime el error
int ordenamiento_seleccion(int **numeros, int n) {
    if(numeros == NULL) return error(ARREGLO_NULO, "ordenamiento_seleccion");

    int k, i, p, temporal;
    for (k=0; k<n-1; k++) {
        p=k;
        for (i=k+1; i<n; i++) {
            if (numeros[0][i]<numeros[0][p]) {
                p=i;
            }
        }
        if (p!=k) {
            temporal = numeros[0][p];
            numeros[0][p] = numeros[0][k];
            numeros[0][k] = temporal;
        }
    }
    return 0;
}

//el ordenamiento shel comienza aqui
//es una version mejorada del ordenamiento por incersion
int ordenamiento_shell(int ** numeros, int n){ //inicia la declaracion de la funcion ordenamiento_shell
    if(numeros == NULL){return error(ARREGLO_NULO, "ordenamiento_insercion");} //valida que el arreglo de numeros a ordenar no sea vacio

    //crea las variables auxiliares
    int i = 0;
    int k = n / 2;
    int v = 0;
    int j = 0;

    while(k >= 1){ //cuando k = 1, se volvera un simple ordenamiento por incersion
        for(i = k; i < n; i++){ //en este ciclo nos aseguramos de por saltos ir ordenando de poco a poco el arreglo
            v = numeros[0][i];
            j = i - k;
            while(j >= 0 && numeros[0][j] > v){ //este paso es igual que el ordenamiento por incersion
                numeros[0][j+k] = numeros[0][j];
                j -= k;
            }
            numeros[0][j+k] = v;
        }
        k /= 2; //dividimos a k entre dos
    }

    return 0; //retorna cero
}

// Recibe un arreglo de numeros y un valor que indica cuantos elementos hay en el arreglo
// Ordena el arreglo de numeros utilizando el ordenamiento de arbol mejorado cuya principal
// caracteristica es utilizar un arbol binario de busqueda y despues recorrerlo en inorden
// Devuelve 0 si se realizo correctamente 
// y si ocurre un error termina la ejecucion e imprime el error
int ordenamiento_arbol(int **numeros, int n) {
    if(numeros == NULL) return error(ARREGLO_NULO, "ordenamiento_arbol");

    int i;
    struct Arbol *arbol = NULL;
    for (i = 0; i<n; i++)
        insertar(&arbol, numeros[0][i]);

    guardar_inorden(arbol, numeros);

    return 0;
}


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
