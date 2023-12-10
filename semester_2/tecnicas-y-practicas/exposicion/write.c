#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *archivo;
    char *buffer;
    long int nChar;
    size_t n;

    scanf("%d\n", &nChar);
    ++nChar;
    buffer = (char*) malloc(nChar * sizeof(char));
    fgets(buffer, nChar, stdin);

    // Abrir el archivo binario para escritura
    archivo = fopen("datos.bin", "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    n = fwrite(buffer, sizeof(char), nChar, archivo);
    if (n != nChar) {
        printf("Error al escribir en el archivo\n");
        return 1;
    }
    
    // Cerrar el archivo
    fclose(archivo);

    return 0;
}
