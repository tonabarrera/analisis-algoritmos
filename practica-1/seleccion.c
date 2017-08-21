#include <stdio.h>
void ordenar(int[], int);

int main(void){
    int numeros[] = {7, 90, 666, 43, 42, 777, 8, 4020, 1010, 951};
    ordenar(numeros, 10);
    for (int i=0; i<10; i++) {
        printf("%d\n", numeros[i]);
    }
    return 0;
}

void ordenar(int numeros[], int n) {
    int k, i, p, temporal;
    for (k=0; k<n-1; k++) {
        p=k;
        for (i=k+1; i<n; i++) {
            if (numeros[i]<numeros[p]) {
                p=i;
            }
        }
        if (p!=k) {
            temporal = numeros[p];
            numeros[p] = numeros[k];
            numeros[k] = temporal;
        }
    }
}
