#include <stdio.h>
void ordenar(int[], int);
int main(void){
    int numeros[] = {8, 90, 42, 777, 666, 43};
    ordenar(numeros, 6);
    for (int i=0; i<6; i++)
        printf("%d\n", numeros[i]);
    return 0;
}

void ordenar(int numeros[], int n) {
    short cambio = 1;
    int i, j, temporal;
    for (i=1; i<n && cambio; i++) {
        cambio = 0;
        for (j=0; j<=n-i; j++) {
            if (numeros[j+1]<numeros[j]) {
                temporal = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = temporal;
                cambio = 1;
            }
        }
    }
}
