#include <fcntl.h> // open
#include <unistd.h> // read
#include <sys/stat.h> // stat
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ssize_t obtener_tam(char *);

struct Nodo {
    unsigned long long frecuencia;
    int numero;
    struct Nodo *izq;
    struct Nodo *der;
    char valor_izq;
    char valor_der;
    struct Nodo *siguiente;
};

struct Nodo *insertar_nodo(struct Nodo *, unsigned long long, int);

int main(){
    int archivo = open("imagen.jpg", O_RDWR);
    ssize_t tam = obtener_tam("imagen.jpg");
    printf("El tam es %ld\n", tam);
    unsigned char buffer[tam];
    unsigned long long frecuencias[256] = {0};
    read(archivo, buffer, tam);

    for (int i = 0; i<tam; i++){
        frecuencias[buffer[i]]++;
    }

    struct Nodo *lista = (struct Nodo*)malloc(sizeof(struct Nodo));
    lista->frecuencia = frecuencias[0];
    lista->numero = 0;
    lista->siguiente = NULL;
    for (int i = 1; i < 256; i++)
        lista = insertar_nodo(lista, frecuencias[i], i);
    
    struct Nodo *auxiliar = lista;
    while (auxiliar->siguiente != NULL){
        printf("Lista ordenada frecuencia de %d es :%llu\n", auxiliar->numero, auxiliar->frecuencia);
        auxiliar = auxiliar->siguiente;
    }

    struct Nodo *auxiliar2;
    struct Nodo *indice = lista;
    int tomar = 1;
    int i = 0;
    while (i<256) {
        if (tomar) {
            auxiliar = lista;
            auxiliar2 = lista->siguiente;
            struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
            nuevo->frecuencia = auxiliar->frecuencia + auxiliar2->frecuencia;
            nuevo->izq = auxiliar;
            nuevo->der = auxiliar2;
            tomar = 0;
        }
        indice = indice->siguiente;
        i-++;
    }
    return 0;
}

struct Nodo *insertar_nodo(struct Nodo *inicio, unsigned long long frecuencia, int numero) {
    struct Nodo *temp = (struct Nodo*)malloc(sizeof(struct Nodo));
    temp->numero = numero;
    temp->frecuencia = frecuencia;
    if (frecuencia < inicio->frecuencia) {
        temp->siguiente = inicio;
        return temp;
    }

    struct Nodo *prev = inicio;
    struct Nodo *aux = inicio->siguiente;
    while(aux != NULL && (aux->frecuencia < frecuencia)) {
        prev = aux;
        aux = aux->siguiente;
    }
    
    temp->siguiente = aux;
    prev->siguiente = temp;
    return inicio;
}

ssize_t obtener_tam(char *archivo) {
    struct stat datos_archivo;
    stat(archivo, &datos_archivo);
    return datos_archivo.st_size;
} 