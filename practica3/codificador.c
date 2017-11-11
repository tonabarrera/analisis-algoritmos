#include <fcntl.h> // open
#include <unistd.h> // read, write
#include <sys/stat.h> // stat
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_BLOQUE 256
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

const unsigned char *VALORES[257]; 

struct Nodo *insertar_nodo(struct Nodo *, unsigned long long, int);
void escribir_tabla(int, char *, int, FILE *);
void mostrar_lista(struct Nodo *);
void mostar_arbol(struct Nodo *, char *, int, FILE *);

int bits_in_buffer = 0;
unsigned char buffer_salida[TAM_BLOQUE];
int write_bit(int f, int bit) {
    if (bit)
        buffer_salida[bits_in_buffer >> 3] |= (0x1 << (7 - bits_in_buffer % 8));
    ++bits_in_buffer;
    if (bits_in_buffer == TAM_BLOQUE << 3) {
        ssize_t tam = write(f, buffer_salida, TAM_BLOQUE);
        bits_in_buffer = 0;
        memset(buffer_salida, 0, TAM_BLOQUE);
    }
    return 1;
}

int main(){
    memset(buffer_salida, 0, TAM_BLOQUE);
    int archivo = open("prueba.txt", O_RDONLY);
    unsigned char buffer[TAM_BLOQUE];
    unsigned long long frecuencias[257] = {0};
    frecuencias[256] = 1; // PARA EL FINAL DEL ARCHIVO
    int leidos = 0;
    ssize_t total = 0;
    while ((leidos = read(archivo, buffer, TAM_BLOQUE)) > 0){
        //printf("leidos: %d\n", leidos);
        for (unsigned long long i = 0; i<leidos; i++)
            frecuencias[buffer[i]]++;
        total += leidos;
    }
    close(archivo);

    printf("TOTAL LEIDOS: %ld\n", total);
    struct Nodo *lista = NULL;
    for (int i = 0; i < 257; i++)
        if(frecuencias[i] != 0)
            lista = insertar_nodo(lista, frecuencias[i], i);

    struct Nodo *auxiliar2;
    struct Nodo *auxiliar;
    struct Nodo *indice = lista;
    int tomar = 1;
    struct Nodo *nuevo;
    int clave = -1;
    //mostrar_lista(lista);

    while (indice != NULL) {
        if (tomar) {
            auxiliar = lista;
            auxiliar2 = lista->siguiente;
            nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
            nuevo->frecuencia = auxiliar->frecuencia + auxiliar2->frecuencia;
            nuevo->numero = clave--;
            nuevo->izq = auxiliar;
            nuevo->der = auxiliar2;
            nuevo->valor_izq = '0';
            nuevo->valor_der = '1';
            nuevo->siguiente = NULL;
            if (auxiliar2->siguiente == NULL) {
                lista = nuevo;
                break;
            }
            lista = auxiliar2->siguiente;
            if (nuevo->frecuencia < lista->frecuencia) {
                nuevo->siguiente = lista;
                lista = nuevo;
                tomar = 1;
            } else {
                tomar = 0;
            }
            indice = lista;
        } else {
            if (indice->siguiente == NULL) {
                indice->siguiente = nuevo;
                indice = lista;
                tomar = 1;
            }else if (nuevo->frecuencia < indice->siguiente->frecuencia) {
                nuevo->siguiente = indice->siguiente;
                indice->siguiente = nuevo;
                tomar = 1;
            } else {
                indice = indice->siguiente;
                if (indice->siguiente == NULL) {
                    indice->siguiente = nuevo;
                    indice = lista;
                    tomar = 1;
                }
            }
        }
    }
    //mostrar_lista(lista);
    //printf("%s\n", "IMPRIMIENDO ARBOL");
    char camino[2000];
    FILE *f;
    f = fopen("tabla_codificacion.txt", "w");
    memset(camino, '\0', sizeof(camino));
    mostar_arbol(lista, camino, 0, f);
    fclose(f);
    archivo = open("prueba.txt", O_RDONLY);
    int archivo2 = open("comprimido", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    int algo = 0;
    while ((leidos = read(archivo, buffer, TAM_BLOQUE)) > 0){
        for (unsigned long long i = 0; i<leidos; i++){
            //printf("%s %ld \n", VALORES[buffer[i]], strlen(VALORES[buffer[i]]));
            algo += strlen(VALORES[buffer[i]]);
            for (int j = 0; j< strlen(VALORES[buffer[i]]); j++){
                write_bit(archivo2, VALORES[buffer[i]][j]-'0');
            }
        }
    }
    // METEMOS EL CARACTER FINAL
    for (int j = 0; j< strlen(VALORES[256]); j++){
                write_bit(archivo2, VALORES[256][j]-'0');
    }
    printf("%s %d\n", "SUMAN: ", algo);
    if (bits_in_buffer < TAM_BLOQUE << 3){
        printf("%s %d %s\n", "Faltaron escribir", bits_in_buffer, buffer_salida);
        write(archivo2, buffer_salida, (bits_in_buffer / 8)+1);
    }
    close(archivo2);
    close(archivo);
    return 0;
}

void mostrar_lista(struct Nodo *lista) {
    printf("%s\n", "--------------------------IMPRIMIENDO LISTA----------------------------------");

    struct Nodo *aux = lista;
    while (aux != NULL) {
        printf("Lista: frecuencia de %d es :%llu\n", aux->numero, aux->frecuencia);
        aux = aux->siguiente;
    }
    printf("%s\n", "------------------------FINAL DE IMPRIMIR LISTA------------------------------");

}

void mostar_arbol(struct Nodo * arbol, char *camino, int long_camino, FILE *archivo) {
    if(arbol->izq== NULL && arbol->der == NULL) {
        return;
    }
    char camino_izq[200];
    char camino_der[200];
     memset(camino_izq, '\0', sizeof(camino_izq));
     memset(camino_der, '\0', sizeof(camino_der));
    strcpy(camino_izq, camino);
    strcpy(camino_der, camino);
    camino_izq[long_camino++] = '0';
    camino_der[long_camino-1] = '1';
    mostar_arbol(arbol->izq, camino_izq, long_camino, archivo);
    if (arbol->izq->izq == NULL && arbol->izq->der == NULL){
        //printf("%d %s %ld %d\n", arbol->izq->numero, camino_izq, strlen(camino_izq), long_camino-1);
        escribir_tabla(arbol->izq->numero, camino_izq, long_camino, archivo);
    }
    //camino[long_camino-1] = '1';
    mostar_arbol(arbol->der, camino_der, long_camino, archivo);
    if (arbol->der->izq == NULL && arbol->der->der == NULL){
        //printf("%d %s %ld %d\n", arbol->der->numero, camino_der, strlen(camino_der), long_camino-1);
        escribir_tabla(arbol->der->numero, camino_der, long_camino, archivo);
    }
        
    return;
}

void escribir_tabla(int numero, char *camino, int long_camino, FILE *archivo) {
    char str[5];
    char *string = malloc(sizeof(char) * long_camino);
    sprintf(str, "%d", numero);
    strcpy(string, camino);
    VALORES[numero] = string;
    fprintf(archivo, "%d %s\n", numero, camino);
}

struct Nodo *insertar_nodo(struct Nodo *inicio, unsigned long long frecuencia, int numero) {
    struct Nodo *temp = (struct Nodo*)malloc(sizeof(struct Nodo));
    temp->numero = numero;
    temp->frecuencia = frecuencia;
    if (inicio == NULL){
        temp->siguiente = NULL;
        return temp;
    }
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