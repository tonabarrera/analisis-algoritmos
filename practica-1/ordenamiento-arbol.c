#include <stdio.h>
#include "arbol.h"

void ordenar(int[], int);

int main(void){
    int numeros[] = {777, 90, 666, 42,
        43, 123, 159, 753, 1010, 4020, 0};
    ordenar(numeros, 11);
    for (int i = 0; i<11; i++)
        printf("%d ", numeros[i]);
    return 0;
}

void ordenar(int numeros[], int n) {
    int i;
    struct Arbol *arbol = NULL;
    for (i = 0; i<n; i++)
        insertar(&arbol, numeros[i]);

    guardar_inorden(arbol, numeros, -1);
}
