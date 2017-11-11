#include "codificador.h"
int main(int argc, char *argv[]){
    if (argc != 2){
        printf("%s\n", "No se inserto el nombre del archivo");
        exit(0);
    }
    printf("COMPRIMIENDO EL ARCHIVO: %s\n", argv[1]);
    comprimir_archivo(argv[1]);
    return 0;
}