#include "codificador.h"
#include "decodificador.h"


int main(int argc, char * argv[]){
    if (argc != 3){
        printf("%s\n", "Uso: ./compresor nombre_archivo opcion (1: comprimir, 2: descomprimir)");
        exit(1);
    }

    int opcion = atoi(argv[2]);
    printf("%d\n", opcion);

    if(opcion == 1){
        printf("COMPRIMIENDO EL ARCHIVO: %s\n", argv[1]);
        comprimir_archivo(argv[1]);
    }
    else if(opcion == 2){
        printf("DESCOMPRIMIENDO EL ARCHIVO: %s\n", argv[1]);
        decodificar_archivo(argv[1]);
    }

    return 0;
}
