#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *archivo;
    char* buffer;
    long int len;
    size_t n;

    // Abrir el archivo binario para lectura
    archivo = fopen("datos.bin", "rb");

    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    // Se mueve el puntero del archivo a la posición final
    fseek(archivo, 0, SEEK_END);

    // Se obtiene la posición actual del puntero (tamaño del archivo)
    len = ftell(archivo);
    
    buffer = (char*) malloc(len * sizeof(char));

    // Se mueve el puntero al principio del archivo
    rewind(archivo);

    // Leer un bloque de 100 bytes desde el archivo
    n = fread(buffer, sizeof(char), len, archivo);
    if (n != len) {
        printf("Error al leer desde el archivo\n");
        return 1;
    }
    // Cerrar el archivo
    fclose(archivo);

    // Imprimir los datos leídos
    for (int i = 0; i < len; i++) {
        printf("%c", buffer[i]);
    }
    printf("\n");

    return 0;
}