#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* constantes generales */
#define lenEstadisticas 5
#define lenInventario 6
#define maxInv 10
#define lenAtaques 3

/* Funciones de logica de batalla*/
/*===================================================================================================================================================================================================*/

/* este solo aplica para el boss de 'lacra de las cuevas' */
#define ataquesLacra 2

typedef struct zona zona;

struct zona{
	char name[10];
	int pos[3];
	int jefe;
};

zona* iniciarmapa(){

	zona* mapa = (zona*)malloc(sizeof(zona)*5);
	zona zona1 = {"valle", }
}




zona * mapa = malloc

/* utilidades para usar en general */
int inquirirOpcion(int maximo);
int probabilidad();
void continuar();

/* funciones utilizadas en la batalla. Se intenta que sea escalable */
void batalla(int * estadisticas, int * inventario, int* nPointHabi, char nameItems[6][25], int ataquesBoss[][3], char nombreAtaquesBoss[][25], int numAtaquesBoss, int hpBoss, char nombreBoss[], int puntosPorDerrota);
void descontarHp(int * hp, int * hpBoss, int danoPropio, int danoBoss, char nombreBoss[], int reactivo);
int turnoPropio(int ataquesPropios[][4], char nombreAtaquesPropios[][15], int * danoPropio, int * stamina);
int turnoBoss(int ataquesBoss[][3], char nombreAtaquesBoss[][25], int numAtaquesBoss, char nombreBoss[]);

/* funciones para calcular el daño, hp y demas caracteristicas de la batalla que dependen de las estadisticas */
int calcDanoLiviano(int puntos);
int calcDanoPesado(int puntos);
int calcProbPesado(int puntos);
int calcProbParry(int puntos);
int calcHp(int puntos);
int calcStamina(int puntos);
int calcRecuperacionStamina(int puntos);

/* funciones cuya utilidad se ciñe unicamente a este archivo. NO son pensadas para utilizarlas en una version final */
void inicializar(int * estadisticas, int * inventario);
void iniciarArr(int * arr, int n, int val);

/*=======================================================================================================================================================*/
/*Funciones del menu principal*/

void menuPrincipal();
void bestiario(char jefesDescri[5][2][600], int jefesLife[5][2]);
void antorcha();
void objetos(int invet[10], int itemsAndHabili[3], char nameItems[6][25]);
void explorar(int invet[10], int *nitems, int * nPointHabi, char nameItems[6][25]);
void encontarPuntoHabilidad(int puntoHabilidad[1]);
void mostrarInventario(int invet[10], char nameItems[6][25]);
void imprimirDescripcion(char* descripcion);
/*=================================================================================================================================================================*/

int main(){
	/* se inicia el generador de random */
	srand(time(NULL));
	menuPrincipal();
	return 0;
}

/*===============================================================================================================================================================================================================================*/
/*===============================================================================================================================================================================================================================*/
/* Menu pincipal */

/*
Nombre: menuPrincipal
Descripcion: despliega el menu pricipal y captura una de las opciones disponibles para redirigir a la funciones correspondientes.
*/
void menuPrincipal(){
	/* informacion de jefes*/
	char jefesDescri[5][2][600] = {{"la lacra de las cuevas", "esta bestia antigua, acecha a los mineros que tratan de obtener recursos de esa cueva rica en minerales.por las noches ataca y roba a los forasteros cercanos."},
							  {"el sabio viejo ermitano del bosque", "utiliza su amplia sabiduria en ciencias y magias arcanas de la naturaleza para alejarte de sus tierras y que no vuelvas a ser una posible amenaza para el bosque. toda persona que ha entrado al bosque, no ha vuelto en una pieza."},
							  {"Seth el prodigio de las tierras muertas.", "Seth aquel que derroto al ejercito de vikingos del legendario Varuna Kal, el unico superviviente de aquella guerra. cualquier persona que ha dignado a hacerle cara, ha muerto."},
							  {"Ninkasi la promesa de los elfos.", "la guardia principal de toda la cordillera elfica, protectora de el caliz de la perdicion, aquel que tome del caliz sera consumido por los espiritus de los elfos oscuros, a cambio de un gran poder."},
							  {"Berserk y Femto, los expulsados del firmamento y el Averno.", "este duo tan dispar, nunca ha estado cerca de una derrota, ni siquiera contra centenares de soldados elites de distintas regiones. mientras que Berserk, con su espada gigante evita todo tipo de proteccion que tengas, Femto sera aquel velocista que no te permita respirar y atacara todos tus puntos ciegos. Power up: cuando les falte un 70 porciento de la vida, usaran el objeto divino para entrelazar el mundo con el reino de los cielos llamando a la mano de Dios, para curarlos un poco por cada turno que tengan."}};
	int jefesLife[5][2] = {{1, 500}, {1, 3000}, {1, 10000}, {1, 50000}, {1, 100000}};

	/* caracteristicas del boss 'lacra de las cuevas' */
	int ataquesBoss[ataquesLacra][3] = {{100,100,60},{300,60,40}};
	char nombreLacra[] = "La lacra de la cueva";
	char nombreAtaquesLacra[ataquesLacra][25] = {"cabezaso de lacra","navajazo de lacra"};
	int puntosOtorgadosLagra = 5;
	int hpLacra = 500;

	/*================================================================*/
	/*informacion base de juego*/
	char nameItems[lenInventario][25] = {"Pocion de vida", "Pocion de energia", "Pocion de fuerza", "Pergamino maldito", "Capa de invisibildad", "Pocion furia demoniaca"};
	char nombreEstadisticas[lenEstadisticas][16] = {"vida","ataque rapido","ataque pesado","suerte de ataque","stamina"};

	/*================================================================*/
	/*jugador*/
	int inventario[maxInv];
	int nitems = 0;
	int nPointHabi = 0;
	int estadisticas[lenEstadisticas];
	inicializar(estadisticas, inventario);

	/*================================================================*/
	/*variables de logica*/
	int opcion;
	int flag = 1;
	/*================================================================*/

	while (flag){
		system("cls"); /*Borra lo anterior en consola*/
		fflush(stdin); /*limpia el la entrada de datos por consola*/
		printf("======================================================================\n");
		printf("=========================== Menu principal ===========================\n");
		printf("|1.Explorar|2.Avanzar|3.Estadisticas|4.Inventario|5.Bestiario|6.Salir|\n");
		printf("======================================================================\n");
		printf("ingrese una opcion: ");
		scanf("%d", &opcion);/*captura una opcion a elegir*/
		system("cls");
		switch(opcion){
			case 1:
				explorar(inventario, &nitems, &nPointHabi, nameItems);
				break;
			case 2:
				batalla(estadisticas, inventario, &nPointHabi, nameItems, ataquesBoss, nombreAtaquesLacra, ataquesLacra, hpLacra, nombreLacra, puntosOtorgadosLagra);
				break;
			case 3:
				printf("funcion: Estadísticas (por definir)\n");
				break;
			case 4:
				mostrarInventario(inventario, nameItems);
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
		printf("======================================================================\n");
		continuar();
	}

}
/*===============================================================================================================================================================================================================================*/
/* 1.explorar (Opcion de menu principal)*/

/*
Nombre: explorar
Descripcion: dependiendo del valor que retorne la funcion probalibidad() se redirige a otras funciones especificas, que representan los posibles resultados que tiene "explorar". 
*/
void explorar(int invet[10], int *nitems, int * nPointHabi, char nameItems[6][25]){
	printf("============================ Exploracion =============================\n");
	printf("======================================================================\n");
	int proba = probabilidad();
	if (proba <= 20){
		antorcha();
	}else if(proba <= 35){
		encontarPuntoHabilidad(nPointHabi);
	}else if(proba <= 50){
		objetos(invet, nitems, nameItems);
	}else{
		printf("has tenido mala suerte :(\n");
	}
}

/*
Nombre: antorcha
Descripcion: muestra texto al jugador en pantalla y le pregunta si desea guardar el juego. 
*/
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
			printf("___________________________________\n");
			printf("opcion no valida, intente de nuevo:\n");
			printf("Desea guardar la partida (y/n):");
		}
	}

}
/*
Nombre: objetos
Descripcion: dependiendo del valor que retorne probalidad añade un tipo item al inevntario y muestra en pantalla en nombre del item y su rareza . 
*/
void objetos(int invet[10], int* nitems, char nameItems[6][25]){
	if(*nitems < 10){
		int rare;
		int proba = probabilidad();	
		printf("has encontrado un objeto: ");
		
		if (proba <= 25){
			invet[*nitems] = 1;
			rare = 1;
		}else if(proba <= 50){
			invet[*nitems] = 2;
			rare = 1;
		}else if(proba <= 70){
			invet[*nitems] = 3;
			rare = 1;
		}else if(proba <= 85){
			invet[*nitems] = 4;
			rare = 2;
		}else if(proba <= 95){
			invet[*nitems] = 5;
			rare = 2;
		}else{
			invet[*nitems] = 6;
			rare = 3;
		}
		printf("%s", nameItems[(invet[*nitems]- 1)]);
		printf(" | rareza[%d] (para mas informacion mira tu inventario).", rare);
		*nitems += 1;
		printf("(%d/10)\n",*nitems);

	}else{
		printf("has encontrado un objeto, pero no queda espacio en el inventario\n");
	}
	
}


void encontarPuntoHabilidad(int * nPointHabi){
	*nPointHabi += 1;
	printf("El Explorador encontro un punto de habilidad (+ 1) [%d]\n", *nPointHabi);
}
/*===============================================================================================================================================================================================================================*/
/*4. Inventario (Opcion del menu principal)*/
/*
Nombre: mostrarInventario
Descripcion: muestra el inventario del jugador en pantalla. 
*/
void mostrarInventario(int *invet, char nameItems[6][25]){
	int i;
	printf("============================ Inventario ==============================\n");
	printf("======================================================================\n");
	printf("----------------------------------------------------------------------\n");
	for(i = 0; i < maxInv; ++i){
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
/*===============================================================================================================================================================================================================================*/
/*5. bestiario (Opcion del menu principal)*/

/*
Nombre: bestiario
Descripcion: muestra la informacion de los jefes derrotados.
*/
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
			printf("----------------------------------------------------------------------\n");
		}
	}
}

/*
Nombre: bestiario
Descripcion: imprime la descripcion de los jefes derrotados de manera justificada.
*/
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

/*===============================================================================================================================================================================================================================*/
/*===============================================================================================================================================================================================================================*/
/*Logica de batalla*/

/* la manera que funcionan distintas estructuras de arrays */
/*
estadisticas:
[0] salud
[1] ataque rapido
[2] daño ataque pesado
[3] probabilidad ataque pesado - parry
[4] stamina
*/
/*
inventario:
[0] pocion salud
[1] pocion energia
[2] pocion fuerza
[3] pergamino maldito
[4] capa invisibilidad 
[5] pocion furia demonica
*/
/*
ataquesBoss: Se refiere a los ataques del boss
cada ataquesBoss[i] contiene la informacion a un ataque particular
ataquesBoss[i][0] contiene el daño
ataquesBoss[i][1] contiene la probabilidad de pegar el ataque
ataquesBoss[i][2] contiene la probabilidad de escoger el ataque
asimismo, 'descripcionAtaquesBoss' se refiere a un i de 'ataquesBoss'.
descripcionAtaquesBoss[i] nombre del ataque
*/
/*
ataquesPropios: los ataques que se pueden hacer
ataquesPropios[i] la informacion referente a un ataque en particular
ataquesPropios[i][0] daño del ataque
ataquesPropios[i][1] probabilidad del ataque
ataquesPropios[i][2] stamina requerida
ataquesPropios[i][3] si es 0,  implica que es parry o esquivar, si no es 0, es la probabilidad del parry/esquivar
*/

/*
Nombre: batalla
Descripcion: maneja la logica de la batalla, poniendo valores a estadisticas de batalla como el hp y 
				stamina desde las 'estadisticas'. Determina los turnos y demas.
*/
void batalla(int * estadisticas, int * inventario, int* nPointHabi, char nameItems[6][25], int ataquesBoss[][3], char nombreAtaquesBoss[][25], int numAtaquesBoss, int hpBoss, char nombreBoss[], int puntosPorDerrota){
	/* se inicializan todas las caracteristicas propias */
	int ataquesPropios[lenAtaques][4] = {{calcDanoLiviano(estadisticas[1]),100,20,0},{calcDanoPesado(estadisticas[2]),calcProbPesado(estadisticas[3]),40,0},{3*(calcDanoPesado(estadisticas[2])), calcProbParry(estadisticas[3]),10,1}};
	char nombreAtaquesPropios[lenAtaques][15] = {"ataque rapido","ataque pesado","parry"};
	int hp = calcHp(estadisticas[0]);
	int stamina = calcStamina(estadisticas[4]);
	int recuperacionStamina = calcRecuperacionStamina(estadisticas[4]);

	/*mensaje ´pre-enfrentamiento*/
	printf("Esta va a ser una noche terrible... \n");
	printf("ha despertado %s\n", nombreBoss);
	printf("------------------------------------\n");
	continuar();
	printf("ha iniciado el combate.\n");
	printf("------------------------------------\n");
	continuar();

	/* asuntos directamente de la batalla */
	int danoBoss, danoPropio, reactivo;
	while ((hp > 0) && (hpBoss > 0)){
		printf("======================================================================\n");	
		printf("============================= Combate ================================\n");
		printf("\n--------------------------------------------------------------------\n");
		printf("Tienes %d de vida           -          %s tiene %d de vida\n",hp, nombreBoss, hpBoss);
		printf("Tienes %d de stamina\n\n",stamina);
		printf("======================================================================\n");	
		reactivo = turnoPropio(ataquesPropios, nombreAtaquesPropios, &danoPropio, &stamina);
		printf("----------------------------------------------------------------------\n");	
		/* meter lo de inventario - pociones*/
		danoBoss = turnoBoss(ataquesBoss, nombreAtaquesBoss, numAtaquesBoss, nombreBoss);
		printf("----------------------------------------------------------------------\n");	
		descontarHp(&hp, &hpBoss, danoPropio, danoBoss,nombreBoss, reactivo);
		printf("----------------------------------------------------------------------\n");	

		stamina += recuperacionStamina;
		continuar();
	}
	/* si hpBoss < 0 && hp < 0, igual has muerto, por lo que da lo mismo: te ha vencido */
	if (hp > 0){
		printf("------------------------------------------------------------\n");
		printf("$ Felicitaciones por derrotar a %s!!!!! $\n",nombreBoss);
		printf("------------------------------------------------------------\n");
		continuar();
		*nPointHabi += puntosPorDerrota;
		printf("has obtenido (+%d) puntos de habilidad [%d]\n", puntosPorDerrota, *nPointHabi);
	} else {
		printf("\n%s te ha derrotado\n\n",nombreBoss);
	}
}

/*
Nombre: turnoPropio
Descripcion: le pregunta al usuario el movimiento que desea usar en su turno.
*/
int turnoPropio(int ataquesPropios[][4], char nombreAtaquesPropios[][15], int * danoPropio, int * stamina){
	int i, opcion, reactivo;
	
	/* para mostrarle las opciones al usuario y que elija que ataque usar */
	printf("Escoge un ataque:\n");
	printf("codigo  dano  probabilidadDeImpacto  gastoDeStamina\n");
	for (i = 0;i < lenAtaques;i++){
		if (*stamina >= ataquesPropios[i][2]){
			printf("  [%d]   %d            %d%%                 %d       %s\n",i,ataquesPropios[i][0],ataquesPropios[i][1],ataquesPropios[i][2], nombreAtaquesPropios[i]);
		}
	}
	printf("======================================================================\n");	
	/*para evitar casos de que escojan uno que no puedan realizar*/
	do{
		opcion = inquirirOpcion(lenAtaques);
	} while (ataquesPropios[opcion][2] > *stamina);
	
	*stamina -= ataquesPropios[opcion][2];
	/* revisa si el ataque funciona con 'delay' como el parry o una futura esquivada */
	if (ataquesPropios[opcion][3] == 1){
		*danoPropio = ataquesPropios[opcion][0];
		reactivo = ataquesPropios[opcion][1];
	} else{
		reactivo = 0;
		if (ataquesPropios[opcion][1] > probabilidad()){
			*danoPropio = ataquesPropios[opcion][0];
			printf("\nHas infligido %d de dano\n",*danoPropio);
		} else{
			printf("\nHas fallado tu ataque de %s\n",nombreAtaquesPropios[opcion]);
			*danoPropio = 0;
		}

	}
	return reactivo;
}

/*
Nombre: turnoBoss
Descripcion: hace que el boss escoja utilizando probabilidades un ataque a usar
*/
int turnoBoss(int ataquesBoss[][3], char nombreAtaquesBoss[][25], int numAtaquesBoss, char nombreBoss[]){
	int prob = probabilidad(),  i = 0, probAcum = 0, ans;
	while ((probAcum < prob) && (i < numAtaquesBoss)){
		probAcum += ataquesBoss[i][2];
		i++;
	}
	i--;

	if (ataquesBoss[i][1] > probabilidad()){
		printf("\n%s te ataca con %s\n",nombreBoss, nombreAtaquesBoss[i]);
		ans = ataquesBoss[i][0];
	} else {
		printf("\n%s falla por poco su ataque de %s\n",nombreBoss, nombreAtaquesBoss[i]);
		ans = 0;
	}
	return ans;
}

/*
Nombre: descontarHp
Descripcion: descuenta la vida tanto al jugador como al boss. Toma en cuenta asuntos como 'parry'
*/
void descontarHp(int * hp, int * hpBoss, int danoPropio, int danoBoss, char nombreBoss[], int reactivo){
	if (reactivo == 0){
		*hp -= danoBoss;
		*hpBoss -= danoPropio;
		printf("\n%s te ha quitado %d de vida\n",nombreBoss,danoBoss);
	} else {
		if (danoBoss > 0){
			/* el que sea reactivo depende de la probabilidad de bloquarlo unicamente si fuiste atacado */
			if (probabilidad() < reactivo){
				*hpBoss -= danoPropio;
				printf("\nHas esquivado a %s, quitandole %d de vida en el proceso\n",nombreBoss,danoPropio);
			} else {
				*hp -= danoBoss;
				printf("\nHas recibido el ataque de %s. Te ha quitado %d de vida\n",nombreBoss,danoBoss);
			}
		} else {
			printf("\n%s ha fallado. No hizo falta una defensa\n",nombreBoss);
		}
	}
}

/*
Nombre: calcRecuperacionStamina
Descripcion: calcula la recuperacion de stamina por turno segun las estadisticas
*/
int calcRecuperacionStamina(int puntos){
	int ans = puntos * 2;
	ans += 10;
	return ans;
}
/*
Nombre: calcStamina
Descripcion: calcula la stamina total segun las estadisticas
*/
int calcStamina(int puntos){
	int ans = puntos * 15;
	ans += 250;
	return ans;
}
/*
Nombre: calcHp
Descripcion: calcula la salud total segun las estadisticas
*/
int calcHp(int puntos){
	int ans = puntos * 250;
	ans += 500;
	return ans;
}
/*
Nombre: calcDanoLiviano
Descripcion: calcula el daño del ataque liviano segun las estadisticas
*/
int calcDanoLiviano(int puntos){
	int ans = puntos *50;
	ans += 50;
	return ans;
}
/*
Nombre: calcDanoPesado
Descripcion: calcula el daño del ataque pesado segun las estadisticas
*/
int calcDanoPesado(int puntos){
	int ans = puntos *150;
	ans += 150;
	return ans;
}
/*
Nombre: calcProbPesado
Descripcion: calcula la probabilidad de hacer un ataque pesado segun las estadisticas
*/
int calcProbPesado(int puntos){
	int ans = puntos*2;
	ans += 40;
	return ans;
}
/*
Nombre: calcProbParry
Descripcion: calcula la probabilidad de hacer un parry segun las estadisticas
*/
int calcProbParry(int puntos){
	int ans = puntos *2;
	ans += 30;
	return ans;
}


/*===============================================================================================================================================================================================================================*/
/*===============================================================================================================================================================================================================================*/
/*Funciones de Uso General*/
/*
Nombre: inquirirOpcion
Descripcion: le pregunta al usuario por una opcion entre 0 y maximo. Lo hace cuantas veces sea 
				necesario.
*/
int inquirirOpcion(int maximo){
	int opcion;
	do {
		printf(" > ");
		scanf("%d",&opcion);		
	} while ((opcion < 0) || (opcion >= maximo));
	return opcion;
}

/*
Nombre: probabilidad
Descripcion: genera un numero aleatorio entre 0 y 99
*/
int probabilidad(){
	int ans;
	ans = rand() % 100;
	return ans;
}

/*
Nombre: continuar
Descripcion: muestra un mensajen pantalla para continuar, captura cualquier caracter y el texto de la terminal.
*/
void continuar(){
	fflush(stdin);
	printf("Presiona enter para continuar...");
	getchar();
	system("cls");
}

/*
Nombre: inicializar
Descripcion: le da el valor 0 a cada posion de los arrglos de estadisticas he inventrios (para garantizar ausencia de errores en ejecucion del programa).
*/
void inicializar(int * estadisticas, int * inventario){
	iniciarArr(estadisticas, lenEstadisticas, 0);
	iniciarArr(inventario, maxInv, 0);
}
/*
Nombre: iniciarArr
Descripcion: le da el valor del 'val' a cada posion de arreglo 'arr' 
*/
void iniciarArr(int * arr, int n, int val){
	int i;
	for (i = 0;i < n;i++){
		arr[i] = val;
	}
}

/*===============================================================================================================================================================================================================================*/
/*===============================================================================================================================================================================================================================*/