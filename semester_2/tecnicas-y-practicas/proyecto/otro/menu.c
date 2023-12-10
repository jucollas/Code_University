#include <stdio.h>


int main(){
	int option;
	printf("1.NUEVO JUEGO || 2.CONTINUAR || 3.SALIR\n");
	printf("DIGITA TU OPCION:");
	scanf("%d", &option);
	switch(option){
		case 1:
			printf("Hola de nuevo0");
			break;
		case 2:
			printf("Bienvenido nuevo jugador");
			break;
		case 3:
			printf("bye.");
			break;
		default:
			printf("error");
			break;
	}
}