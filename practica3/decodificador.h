#ifndef __DECODIFICADOR_H__
#define __DECODIFICADOR_H__

    #include <fcntl.h> // open
    #include <unistd.h> // read, write
    #include <sys/stat.h> // stat
    #include <sys/types.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    #define TAM_BUFFER 8000

    struct arbol_decodificador{
        unsigned int valor_real;
        struct arbol_decodificador * hijo_izq;
        struct arbol_decodificador * hijo_der;
    };

    int decodificar_archivo(char *);
    int construir_arbol(FILE *, struct arbol_decodificador **);
    int insertar_nodo_arbol(struct arbol_decodificador **, int, char *, int);
    int construir_archivo(struct arbol_decodificador *, char *);
    unsigned int obtener_valor(int, unsigned char *, int *, struct arbol_decodificador *);
    int obtener_bit(unsigned char *, int);

#endif
