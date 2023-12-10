/* Parcial 2 
 En este archivo se realizaron los cambios respectivos al parcial 2, 
 la mayoria de las funciones fueron cambiadas y se tomo la informacion 
 de jugador como una variable global esto incluye el invetario.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* constantes generales */
#define lenEstadisticas 5
#define lenInventario 6
#define maxInv 10
#define lenAtaques 3
#define ImprovPointInit 2

/* este solo aplica para el boss de 'lacra de las cuevas' */
#define ataquesLacra 2
/* Estructuras */

/* estructura lista (para inventario)*/
typedef struct Node {
	int date;
	struct Node* next;
} Node;

typedef struct List {
	int size;
	Node* firts;
} List;

List createList();
Node* createNode(int data);

/* estructura inventario*/

typedef struct Inventory{
    List items;
    char nameItems[6][30];
    /* mas cosas */
}Inventory;

Inventory createInvetory(char nameItems[6][30]);

/*Estructura de los boses para el bestiario*/
typedef struct Boss{
    char* name;
	char* description;
    int hp;
	int killingReward;
}Boss;

Boss Bossin(char* name, char* description, int hp, int killingReward);

/* estructura para estadisticas */
typedef struct Statistics{
	char* name;
	int lenName;
	int points;
}Statistics;

/* estructura del jugador */
typedef struct Player{
	char* name;
	Inventory inventory;
	int lenItems;
	Statistics* stats;
	int lenStats;
	int improvableStats;
}Player;

Player inicializarPlayer(char* name, int* pointSta, char nameSta[5][35], int improStats, char nameInven[6][30]);

/* Funciones de logica de batalla*/
/*===================================================================================================================================================================================================*/

/* utilidades para usar en general */
int inquirirOpcion(int maximo);
int probabilidad();
void continuar();

/* funciones utilizadas en la batalla. Se intenta que sea escalable */
void batalla(int ataquesBoss[][3], char nombreAtaquesBoss[][25], int numAtaquesBoss, int hpBoss, char nombreBoss[], int puntosPorDerrota);
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

/*=======================================================================================================================================================*/
/*Funciones del menu principal*/

void menuPrincipal();
void bestiario(Boss* jefes);
void antorcha();
void objetos();
void explorar();
void encontarPuntoHabilidad();
void mostrarInventario();
void imprimirDescripcion(char* descripcion);
int inquirirOpcion(int maximo);
void menuEstadisticas();
void mejorarEstadisticas ();
/*=================================================================================================================================================================*/
/* variables globales del jugador */
Player player;


int main(){
	
    int pointSta[5]= {1, 1, 1, 1, 1};
    char nameInsta[lenEstadisticas][35] = { "Salud", "Ataque Rapido", "Ataque Pesado", "probabilidad ataque pesado - parry", "stamina"};
    char nameInve[lenInventario][30] = {"Capa de invisibildad", "Pergamino maldito", "Pocion de energia", "Pocion de fuerza", "Pocion de vida", "Pocion furia demoniaca"};
    player = inicializarPlayer("azrael", pointSta, nameInsta, ImprovPointInit, nameInve);
    /* se inicia el generador de random */
	srand(time(NULL));
	menuPrincipal();
	return 0;
}

/*===============================================================================================================================================================================================================================*/
/*===============================================================================================================================================================================================================================*/
/* Definiciones de la interfaz de las estructuras*/

/* creacion de lista */
List createList() {
	List list;
	list.size = 0;
	list.firts = NULL;
	return list;
}

/* creacion de Nodo */
Node* createNode(int date) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->date = date;
	node->next = NULL; 
	return node;
}

/* insercion ordenda de elementos */
void pushSort(List* list, int num){
    Node* unused = createNode(num);
    Node* ax = list->firts;
    if(ax != NULL){
        if(ax->date >= num){
            unused->next = list->firts;
            list->firts = unused;
        }else{
            while(ax->next != NULL && ax->next->date < num){
                ax = ax->next;
            }
            unused->next = ax->next;
            ax->next = unused;
        }
    }else{
        list->firts = unused;
    }
    list->size++;
}

/*Inicializa al Inventario*/
Inventory createInvetory(char nameItems[6][30]){
    Inventory inv;
    inv.items = createList();
    int i, j;
    for(i = 0; i < 6; ++i){
        for(j = 0; j < strlen(nameItems[i]); ++j)
            inv.nameItems[i][j] = nameItems[i][j];
        inv.nameItems[i][j] = '\0';
    }
        
    return inv;
}

/*Inicializa al jugador*/
Player inicializarPlayer(char* name, int pointSta[5], char nameSta[5][35], int improStats, char nameInven[6][30]){
    Player player;
    player.inventory = createInvetory(nameInven);
    int i;
    player.name = name;
    player.lenStats = 5;
    player.stats = (Statistics*) malloc ( sizeof ( Statistics ) * player.lenStats );
    player.improvableStats = improStats;
    for(i = 0; i < player.lenStats; ++i ){
        (player.stats[i]).name = nameSta[i];
        (player.stats[i]).lenName = strlen(nameSta[i]);
	    (player.stats[i]).points = pointSta[i];
    }
    return player;
}

/*Inicializa al boss de bestiario*/
Boss Bossin(char* name, char* description, int hp, int killingReward){
    Boss boss = {name, description, hp, killingReward};
    return boss;
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
    Boss* jefes = (Boss*)malloc(sizeof(Boss)*5);
    jefes[0] = Bossin("la lacra de las cuevas", "esta bestia antigua, acecha a los mineros que tratan de obtener recursos de esa cueva rica en minerales.por las noches ataca y roba a los forasteros cercanos.", 500, 1);
    jefes[1] = Bossin("el sabio viejo ermitano del bosque", "utiliza su amplia sabiduria en ciencias y magias arcanas de la naturaleza para alejarte de sus tierras y que no vuelvas a ser una posible amenaza para el bosque. toda persona que ha entrado al bosque, no ha vuelto en una pieza.", 3000, 1);
    jefes[2] = Bossin("Seth el prodigio de las tierras muertas.", "Seth aquel que derroto al ejercito de vikingos del legendario Varuna Kal, el unico superviviente de aquella guerra. cualquier persona que ha dignado a hacerle cara, ha muerto.", 10000, 1);
    jefes[3] = Bossin("Ninkasi la promesa de los elfos.", "la guardia principal de toda la cordillera elfica, protectora de el caliz de la perdicion, aquel que tome del caliz sera consumido por los espiritus de los elfos oscuros, a cambio de un gran poder.", 50000, 1);
    jefes[4] = Bossin("Berserk y Femto, los expulsados del firmamento y el Averno.", "este duo tan dispar, nunca ha estado cerca de una derrota, ni siquiera contra centenares de soldados elites de distintas regiones. mientras que Berserk, con su espada gigante evita todo tipo de proteccion que tengas, Femto sera aquel velocista que no te permita respirar y atacara todos tus puntos ciegos. Power up: cuando les falte un 70 porciento de la vida, usaran el objeto divino para entrelazar el mundo con el reino de los cielos llamando a la mano de Dios, para curarlos un poco por cada turno que tengan.", 100000, 1);

	/* caracteristicas del boss 'lacra de las cuevas' */
	int ataquesBoss[ataquesLacra][3] = {{100,100,60},{300,60,40}};
	char nombreLacra[] = "La lacra de la cueva";
	char nombreAtaquesLacra[ataquesLacra][25] = {"cabezaso de lacra","navajazo de lacra"};
	int puntosOtorgadosLagra = 5;
	int hpLacra = 500;

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
				explorar();
				break;
			case 2:
				batalla(ataquesBoss, nombreAtaquesLacra, ataquesLacra, hpLacra, nombreLacra, puntosOtorgadosLagra);
				break;
			case 3:
                menuEstadisticas();
				break;
			case 4:
				mostrarInventario();
				break;
			case 5:
				bestiario(jefes);
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
void explorar(){
	printf("============================ Exploracion =============================\n");
	printf("======================================================================\n");
	int proba = probabilidad();
    objetos();
	/*if (proba <= 20){
		antorcha();
	}else if(proba <= 35){
		encontarPuntoHabilidad();
	}else if(proba <= 50){
		objetos();
	}else{
		printf("has tenido mala suerte :(\n");
	}*/
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
void objetos(){
	if(player.inventory.items.size < 10){
		int rare;
		int proba = probabilidad();
        int ax;
		printf("has encontrado un objeto: ");
		
		if (proba <= 25){
			ax = 5;
			rare = 1;
		}else if(proba <= 50){
			ax = 3;
			rare = 1;
		}else if(proba <= 70){
			ax = 4;
			rare = 1;
		}else if(proba <= 85){
			ax = 2;
			rare = 2;
		}else if(proba <= 95){
			ax = 1;
			rare = 2;
		}else{
			ax = 6;
			rare = 3;
		}
        pushSort(&player.inventory.items, ax);

		printf("%s", player.inventory.nameItems[ax - 1]);
		printf(" | rareza[%d] (para mas informacion mira tu inventario).", rare);
		printf("(%d/10)\n",player.inventory.items.size);

	}else{
		printf("has encontrado un objeto, pero no queda espacio en el inventario\n");
	}
	
}

void encontarPuntoHabilidad(){
    player.improvableStats += 1;
	printf("El Explorador encontro un punto de habilidad (+ 1) [%d]\n", player.improvableStats);
}

/*===============================================================================================================================================================================================================================*/
/*3. Estadiaticas (Opcion del menu principal)*/
/*
Nombre: menuEstadisticas 
Descripcion: muestra las estadisticas del jugador en pantalla y le permite incermentarlas con puntos de habilidad. 
*/

void menuEstadisticas(){
	int i, opcion;

	printf("Tienes %d puntos disponibles para mejorar.\n",player.improvableStats);

	printf(" Nombre | ");
	for ( i = 0 ; i < player.lenStats ; i++ ){
		printf("%s | ", (player.stats[i]).name );
	}
	printf("\n");

	printf(" Puntos | ");
	for ( i = 0 ; i < player.lenStats ; i++ ){
		printf("%*d | ",(player.stats[i]).lenName , (player.stats[i]).points );
	}
	printf("\n");

	printf("[0] Salir | [1] Mejorar habilidad\n");
	opcion = inquirirOpcion( 2 );

	if ( opcion == 1 ){
		if ( player.improvableStats == 0 ){
			printf("No tienes suficientes puntos para mejorar tus habilidades.\n");
		} else {
            fflush(stdin);
            system("cls");
			mejorarEstadisticas();
		}	
	}	
}

void mejorarEstadisticas ( ){
	int opcion, i, aumento;
	printf("Escoge la habilidad que quieres mejorar:\n");
	printf("codigo   puntosObtenidos   nombreHabilidad\n");
	for ( i = 0 ; i < player.lenStats ; i++ ){
		printf("  [%d]            %d            %s\n",i, (player.stats[i]).points ,(player.stats[i]).name);
	}
	opcion = inquirirOpcion( player.lenStats );
	fflush(stdin);
    system("cls");
	printf("\nEscribe los puntos que deses agregarle a tu %s - tienes %d disponibles\n", (player.stats[opcion]).name, player.improvableStats );
	aumento = inquirirOpcion ( player.improvableStats +1 );
	(player.stats[opcion]).points += aumento;
	player.improvableStats -= aumento;
}

/*===============================================================================================================================================================================================================================*/
/*4. Inventario (Opcion del menu principal)*/
/*
Nombre: mostrarInventario
Descripcion: muestra el inventario del jugador en pantalla. 
*/
void mostrarInventario(){
	int i;
	printf("============================ Inventario ==============================\n");
	printf("======================================================================\n");
	printf("----------------------------------------------------------------------\n");
    Node* tmp = player.inventory.items.firts;
	for(i = 0; i < maxInv; ++i){
		printf("%2d. ",(i+1));
		if(tmp != NULL){
            printf("%s", player.inventory.nameItems[(tmp->date) - 1]);
            tmp = tmp->next;
		}else{
			printf("vacio");
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
void bestiario(Boss* jefes){
	int i, flag = 1, opcion;
	printf("============================= Bestiario ==============================\n");
	printf("======================================================================\n");
	printf("Jefes derrotados:\n");
	printf("----------------------------------------------------------------------\n");
	for(i = 0; i < 5; ++i){
		if(jefes[i].killingReward){
			printf("%d. |||%s|||\n", i+1, jefes[i].name);
			printf("vida:%d\n", jefes[i].hp);
			imprimirDescripcion(jefes[i].description);
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
void batalla(int ataquesBoss[][3], char nombreAtaquesBoss[][25], int numAtaquesBoss, int hpBoss, char nombreBoss[], int puntosPorDerrota){
	/* se inicializan todas las caracteristicas propias */
	int ataquesPropios[lenAtaques][4] = {{calcDanoLiviano((player.stats[1]).points),100,20,0},{calcDanoPesado((player.stats[2]).points),calcProbPesado((player.stats[3]).points),40,0},{3*(calcDanoPesado((player.stats[2]).points)), calcProbParry((player.stats[3]).points),10,1}};
	char nombreAtaquesPropios[lenAtaques][15] = {"ataque rapido","ataque pesado","parry"};
	int hp = calcHp((player.stats[0]).points);
	int stamina = calcStamina((player.stats[4]).points);
	int recuperacionStamina = calcRecuperacionStamina((player.stats[4]).points);

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
		player.improvableStats += puntosPorDerrota;
		printf("has obtenido (+%d) puntos de habilidad [%d]\n", puntosPorDerrota, player.improvableStats);
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

/*===============================================================================================================================================================================================================================*/
/*===============================================================================================================================================================================================================================*/