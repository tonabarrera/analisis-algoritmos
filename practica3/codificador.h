#ifndef __CODIFICADOR__
#define __CODIFICADOR__

#include <fcntl.h> // open
#include <unistd.h> // read, write
#include <sys/stat.h> // stat
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
* Tam. maximo de bytes que se van a leer y escribir
*/
#define TAM_MAX_BLOQUE 256
int bits_buffer;
unsigned char buffer_salida[TAM_MAX_BLOQUE];
const unsigned char *VALORES[257];

/*
* Estructura que funge como nodo de lista, arbol, madre y padre a la vez
* sus componentes son los siguientes
* numero.- Hace referencia a un byte por lo que puede tomar 256 valores
* frecuencia .- Apariciones que tiene el numero
* izq.- Apuntador al nodo izquierdo hijo
* der.- Apuntador al nodo derecho hijo
* siguiente.- Siguiente nodo en una lista
*/
struct Nodo {
    int numero;
    unsigned long long frecuencia;
    struct Nodo *izq;
    struct Nodo *der;
    struct Nodo *siguiente;
};

/*
* Funcion que inserta un nodo de forma ordenada en una lista,
* recibe una lista, el valor a insertar 
* y devuelve una nueva lista ordenada
*/
struct Nodo *insertar_nodo_lista(struct Nodo *, unsigned long long, int);

/*
* Imprime una lista, recibe como parametro la lista e imprimir 
*/
void mostrar_lista(struct Nodo *);

void construir_tabla(struct Nodo *, char *);
/*
* Construye la tabla de simbolos recorriendo el arbol 
* en preorden, un nodo raiz, la secuencia de bits, 
* la longitud de la secuencia de bits y un apuntador
* a un archivo donde se escribe la tabla
*/
void llenar_tabla(struct Nodo *, char *, int, FILE *);

/*
* Escribe un simbolo y su secuencia de bits en un archivo
* recibe el byte, su secuencia de bits, la longitud
* de la secuencia de bits y un apuntador al archivo de la
* tabla
*/
void agregar_simbolo_tabla(int, char *, int, FILE *);

ssize_t obtener_tam_archivo(char *archivo);
/*
* Crea el arbol que utiliza el algoritmo Huffman con la lista
* que se le pasa como parametro, devuelve la raiz del arbol
*/
struct Nodo *crear_arbol(struct Nodo *);
/*Escribe un bit en nuestro buffer de escritura, esto se
* realiza mediante una mascara de bits para poder modificar
* la el valor del bit con base  la posicion de este*/
void escribir_bit(int, int);
/*
* Funcion principal que recibe el nombre del archivo
* y realiza su compresion utilizando el algoritmo Huffman
*/
int comprimir_archivo(char *);
/*
* Escribe el archivo comprimido recibiendo como parametro 
* el nombre del archivo a comprimir
*/
void crear_comprimido(char *);
#endif