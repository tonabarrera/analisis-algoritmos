#include "funciones.h"

int ordenamiento_burbuja(int ** numeros, int n){
    if(numeros == NULL){return error(ARREGLO_NULO, "ordenamiento_burbuja");}

    int i = 0;
    int j = 0;
    int temp = 0;

    for(i = 1; i < n; i++){
        for(j = 0; j < (n-1); j++){
            if(numeros[0][j] > numeros[0][j+1]){
                temp = numeros[0][j];
                numeros[0][j] = numeros[0][j+1];
                numeros[0][j+1] = temp;
            }
        }
    }

    return 0;
}

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


int ordenamiento_insercion(int ** numeros, int n){
    if(numeros == NULL){return error(ARREGLO_NULO, "ordenamiento_insercion");}

    int i = 0;
    int j = 0;
    int temporal = 0;

    for(i = 1; i < n; i++){
        temporal = numeros[0][i];
        j = i - 1;
        while( (numeros[0][j] > temporal) && (j >= 0) ){
            numeros[0][j+1] = numeros[0][j];
            j--;
        }
        numeros[0][j+1] = temporal;
    }

    return 0;
}

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


int ordenamiento_shell(int ** numeros, int n){
    if(numeros == NULL){return error(ARREGLO_NULO, "ordenamiento_insercion");}

    int i = 0;
    int k = n / 2;
    int v = 0;
    int j = 0;

    while(k >= 1){
        for(i = k; i < n; i++){
            v = numeros[0][i];
            j = i - k;
            while(j >= 0 && numeros[0][j] > v){
                numeros[0][j+k] = numeros[0][j];
                j -= k;
            }
            numeros[0][j+k] = v;
        }
        k /= 2;
    }

    return 0;
}

int ordenamiento_arbol(int **numeros, int n) {
    if(numeros == NULL) return error(ARREGLO_NULO, "ordenamiento_arbol");

    int i;
    struct Arbol *arbol = NULL;
    for (i = 0; i<n; i++)
        insertar(&arbol, numeros[0][i]);

    guardar_inorden(arbol, numeros, -1);

    return 0;
}


int llenar_arreglo(FILE * archivo, int ** numeros, int n, char * nombre){ //saca n elementos del archivo y los pone en el arreglo
    if(archivo == NULL){return error(ARCHIVO_NULO, nombre);}
    if(numeros == NULL){return error(ARREGLO_NULO, "llenar_arreglo");}

    int i = 0;
    char auxiliar[33];

    for(i = 0; i < n; i++){ //llenando el arreglo de numeros
        if(fgets(auxiliar, 33, archivo) != NULL){
            *(*(numeros) + i) = atoi(auxiliar);
        }
        else{return error(LECTURA_FALLIDA, nombre);}
    }

    return 0;
}


int imprimir_arreglo(int * numeros, int n){
    if(numeros == NULL){return error(ARREGLO_NULO, "imprimir_arreglo");}

    int i = 0;

    printf("%s\n", "El arreglo es:");
    for(i = 0; i < n; i++){
        printf("%d\n", numeros[i]);
    }

    return 0;
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
