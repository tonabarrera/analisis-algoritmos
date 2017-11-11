#include <fcntl.h> // open
#include <unistd.h> // read, write
#include <sys/stat.h> // stat
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1
int bits_in_buffer = 0;
unsigned char buffer[MAX_BUFFER_SIZE];
int write_bit(int f, int bit) {
    if (bit)
        buffer[bits_in_buffer >> 3] |= (0x1 << (7 - bits_in_buffer % 8));
    ++bits_in_buffer;

    if (bits_in_buffer == MAX_BUFFER_SIZE << 3) {
        ssize_t tam = write(f, buffer, MAX_BUFFER_SIZE);
        printf("ESCRITOS %ld\n", tam);
        bits_in_buffer = 0;
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }
    return 1;
}

int main(int argc, char const *argv[]) {
    memset(buffer, 0, MAX_BUFFER_SIZE);
    char *a = "01100001";
    int archivo2 = open("archivo2.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    for (int i = 0; i < 8; i++){
        printf("%d %d %c \n", (int)a[i], a[i], a[i]);
        write_bit(archivo2, a[i]-'0');
    }
    close(archivo2);
    return 0;
}