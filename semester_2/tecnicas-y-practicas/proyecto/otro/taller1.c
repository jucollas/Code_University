#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menuPrincipal();
void bestiario(char jefesDescri[5][2][600], int jefesLife[5][2]);
void antorcha();
void objetos(int invet[10], int itemsAndHabili[3], char nameItems[6][25]);
int probabilidad();
void explorar(int invet[10], int itemsAndHabili[3], char nameItems[6][25]);
void encontarPuntoHabilidad(int puntoHabilidad[1]);
void inventario(int invet[10], char nameItems[6][25]);
void imprimirDescripcion(char* descripcion);
void continuar();

int main(){
	menuPrincipal();
	return 0;
}

void continuar(){
	printf("Presiona enter para continuar...");
	getchar();

}

void combate(int estadisticas[3], int itemsAndHabili, char jefes[5][4][1000], int zona){
	int flag = 1;
	int vidaJugador = estadisticas[0];
	int vidajefe = 50;
	int estamina = estadisticas[2];
	printf("Esta va a ser una noche terrible... \n");
	printf("ha despertado %s\n", jefes[zona][1]);
	continuar();
	printf("ha iniciado el combate.\n");
	continuar();
	while(flag){
		printf("======================================================================\n");	
		printf("============================= Combate ================================\n");
		printf("|Estadisticas|");
		printf("----------------------------------------------------------------------\n");
		printf("         | vida | estamina |");
		printf("jugador:  %d/%d  %d ", estadisticas[0],vidaJugador, estamina);
		printf("----------------------------------------------------------------------\n");
		printf("%");
		printf("======================================================================\n");	
		printf("|     1.Ataque Ligero     |     2.Ataque Pesado     |     3.Parry     |\n");

	}
	

}

void inventario(int invet[10], char nameItems[6][25]){
	int i;
	printf("============================ Inventario ==============================\n");
	printf("======================================================================\n");
	printf("----------------------------------------------------------------------\n");
	for(i = 0; i < 10; ++i){
		printf("%d. ",(i+1));
		if(invet[i] != 0){
			printf("%s", nameItems[(invet[i]-1)]);

		}else{
			printf("vacio\n");
		}
		printf("\n");
		printf("----------------------------------------------------------------------\n");
	}

}

void imprimirDescripcion(char* descripcion){
	int i = 0, cont = 0;
	printf("Descripcion:\n");
	while(descripcion[i] != '\0'){
		printf("%c", descripcion[i]);
		if (cont == 69){
			printf("\n");
			cont = 0;
		}
		++cont;
		++i;
	}
	printf("\n");
}

void antorcha(){
	char opcion;
	int flag = 1;
	int op;
	printf("El aventurero a encontrado una antorcha!!!!!\n");
	printf("Desea guardar la partida (y/n): ");
	while (flag){
		fflush(stdin);
		scanf("%c", &opcion);

		if(opcion == 'y'){
			printf("Guardando la partida.....\n");
			flag = 0;
		}else if(opcion == 'n'){
			printf("OK.\n");
			flag = 0;
		}else{
			printf("opcion no valida, intente de nuevo:\n");
			printf("Desea guardar la partida (y/n):\n");
		}
	}

}

void objetos(int invet[10], int itemsAndHabili[3], char nameItems[6][25]){
	if(itemsAndHabili[1] < 10){
		int rare;
		int proba = probabilidad();	
		printf("has encontrado un objeto: ");
		
		if (proba <= 25){
			invet[itemsAndHabili[1]] = 1;
			rare = 1;
		}else if(proba <= 50){
			invet[itemsAndHabili[1]] = 2;
			rare = 1;
		}else if(proba <= 70){
			invet[itemsAndHabili[1]] = 3;
			rare = 1;
		}else if(proba <= 85){
			invet[itemsAndHabili[1]] = 4;
			rare = 2;
		}else if(proba <= 95){
			invet[itemsAndHabili[1]] = 5;
			rare = 2;
		}else{
			invet[itemsAndHabili[1]] = 6;
			rare = 3;
		}
		printf("%s", nameItems[(invet[itemsAndHabili[1]]- 1)]);
		printf(" | rareza[%d] (para mas informacion mira tu inventario).", rare);
		itemsAndHabili[1] += 1;
		printf("(%d/10)\n",itemsAndHabili[1]);

	}else{
		printf("has encontrado un objeto, pero no queda espacio en el inventario\n");
	}
	
}

int probabilidad(){
	int ans;
	srand(time(NULL));
	ans = rand() % 100;
	//printf("%d", ans);
	return ans;
}

void encontarPuntoHabilidad(int itemsAndHabili[3]){
	itemsAndHabili[2] += 1;
	printf("El Explorador encontro un punto de habilidad (+ 1) [%d]\n", itemsAndHabili[2] );
}

void explorar(int invet[10], int itemsAndHabili[3], char nameItems[6][25]){
	printf("============================ Exploracion =============================\n");
	printf("======================================================================\n");
	int proba = probabilidad();
	if (proba <= 20){
		antorcha();
	}else if(proba <= 35){
		encontarPuntoHabilidad(itemsAndHabili);
	}else if(proba <= 50){
		objetos(invet, itemsAndHabili, nameItems);
	}else{
		printf("has tenido mala suerte :(\n");
	}
}

void bestiario(char jefesDescri[5][2][600], int jefesLife[5][2]){
	int i, flag = 1, opcion;
	printf("============================= Bestiario ==============================\n");
	printf("======================================================================\n");
	printf("Jefes derrotados:\n");
	printf("----------------------------------------------------------------------\n");
	for(i = 0; i < 5; ++i){
		if(jefesLife[i][0]){
			printf("%d. |||%s|||\n", i+1, jefesDescri[i][0]);
			printf("vida:%d\n", jefesLife[i][1]);
			imprimirDescripcion(jefesDescri[i][1]);
			//printf("%s\n",jefesDescri[i][1]);
			printf("----------------------------------------------------------------------\n");
		}
	}
}

void menuPrincipal(){
	char jefesDescri[5][2][600] = {{"la lacra de las cuevas", "esta bestia antigua, acecha a los mineros que tratan de obtener recursos de esa cueva rica en minerales.por las noches ataca y roba a los forasteros cercanos."},
							  {"el sabio viejo ermitaño del bosque", "utiliza su amplia sabiduria en ciencias y magias arcanas de la naturaleza para alejarte de sus tierras y que no vuelvas a ser una posible amenaza para el bosque. toda persona que ha entrado al bosque, no ha vuelto en una pieza."},
							  {"Seth el prodigio de las tierras muertas.", "Seth aquel que derroto al ejercito de vikingos del legendario Varuna Kal, el unico superviviente de aquella guerra. cualquier persona que ha dignado a hacerle cara, ha muerto."},
							  {"Ninkasi la promesa de los elfos.", "la guardia principal de toda la cordillera elfica, protectora de el caliz de la perdicion, aquel que tome del caliz sera consumido por los espiritus de los elfos oscuros, a cambio de un gran poder."},
							  {"Berserk y Femto, los expulsados del firmamento y el Averno.", "este duo tan dispar, nunca ha estado cerca de una derrota, ni siquiera contra centenares de soldados elites de distintas regiones. mientras que Berserk, con su espada gigante evita todo tipo de proteccion que tengas, Femto sera aquel velocista que no te permita respirar y atacara todos tus puntos ciegos. Power up: cuando les falte un 70 porciento de la vida, usaran el objeto divino para entrelazar el mundo con el reino de los cielos llamando a la mano de Dios, para curarlos un poco por cada turno que tengan."}};
	int jefesLife[5][2] = {{1, 500}, {1, 3000}, {1, 10000}, {1, 50000}, {1, 100000}};

	int invet[10];
	int itemsAndHabili[3] = {0, 0, 0};
	srand(time(NULL));
	char nameItems[6][25] = {"Pocion de vida", "Pocion de energia", "Pocion de fuerza", "Pergamino maldito", "Capa de invisibildad", "Pocion furia demoniaca"};

	int opcion;
	int flag = 1;
	while (flag){
		system("cls");
		fflush(stdin);
		printf("======================================================================\n");
		printf("=========================== Menu principal ===========================\n");
		printf("|1.Explorar|2.Avanzar|3.Estadisticas|4.Inventario|5.Bestiario|6.Salir|\n");
		printf("======================================================================\n");
		printf("ingrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");
		switch(opcion){
			case 1:
				explorar(invet, itemsAndHabili, nameItems);
				break;
			case 2:
				printf("funcion: Avanzar (por definir)\n");
				break;
			case 3:
				printf("funcion: Estadísticas (por definir)\n");
				break;
			case 4:
				inventario(invet, nameItems);
				break;
			case 5:
				bestiario(jefesDescri, jefesLife);
				break;
			case 6:
				printf("funcion: Salir (por definir)\n");
				break;
			default:
				printf("opcion no valida\n");
		}
		fflush(stdin);
		printf("======================================================================\n");
		continuar();
	}

}