#include <fcntl.h> // open
#include <unistd.h> // read, write
#include <sys/stat.h> // stat
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_BLOQUE 7777
int main(int argc, char const *argv[]) {
    int archivo = open("archivo.pdf", O_RDONLY);
    int archivo2 = open("archivo2.txt", O_WRONLY|O_CREAT, 0644);
    unsigned char buffer[TAM_BLOQUE];
    int leidos = 0;
    while ((leidos = read(archivo, buffer, TAM_BLOQUE)) > 0){
        for (unsigned long long i = 0; i<leidos; i++){
            //printf("%d ", buffer[i]);
            write(archivo2, &buffer[i], sizeof(buffer[i]));
        }
    }
    close(archivo);
    close(archivo2);
    return 0;
}