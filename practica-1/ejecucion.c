#include "funciones.h"

int main(int size, char**args){ // los argumentos son, archivo n_elementos
    if(size < 3){return error(NO_ARGUMENTOS, NULL);} //verificamos si tiene los argumentos suficientes

    FILE * archivo = fopen(args[1], "r");
    int n = atoi(args[2]);
    int * numeros = malloc(n*sizeof(int));

    if(archivo == NULL){return error(ARCHIVO_NULO, args[1]);}

    llenar_arreglo(archivo, &numeros, n, args[1]);
    //ordenamiento_burbuja(&numeros, n);
    //ordenamiento_insercion(&numeros, n);
    ordenamiento_shell(&numeros, n);
    imprimir_arreglo(numeros, n);

    return 0;
}
