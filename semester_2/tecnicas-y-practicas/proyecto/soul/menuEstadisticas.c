#include <stdio.h>
#include <stdlib.h>

#define PointInit 3
#define ImprovPointInit 10
#define InvInit 3

/*typedef struct BossAtack BossAtack;*/
typedef struct Boss Boss;
typedef struct Inventory Inventory;
typedef struct Statistics Statistics;
/*typedef struct PlayerAtacks PlayerAtacks;*/
typedef struct Player Player;

/*
struct BossAtack{
	char * name;
	int damage;
	int impactProbability;
	int choosingProbability;
};
*/
struct Boss{
	char * name;
	char * description;
	/*BossAtack * atacks;
	int nAtacks;
	*/
	int hp;
	char* entrance;
	int defeated;
	int killingReward;
};

struct Inventory{
	int amount;
	char* name;
	/* otras cosas */
};

struct Statistics{
	char* name;
	int lenName;
	int points;
};
/*
struct PlayerAtacks{
	char* name;

	int reactive;
	int stamina;

	int damageStatDependence;
	int * damageCalcFunction;
	int damageTerms;

	int probStatDependence;
	int * probCalcFunction;
	int probTerms;
};
*/
struct Player{
	char* name;

	Inventory* items;
	int lenItems;
	Statistics* stats;
	int lenStats;
	int improvableStats;
	/*PlayerAtacks* atacks;
	int lenAtacks;
	*/
};

void inicializar( );
int inquirirOpcion(int maximo);
void menuEstadisticas();
void mejorarEstadisticas ();
void continuar();

/* variables globales del jugador */
Player player;

int main(){
	inicializar();
	while ( 1 ){
		menuEstadisticas();
	}
}

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

	continuar();
	if ( opcion == 1 ){
		if ( player.improvableStats == 0 ){
			printf("No tienes suficientes puntos para mejorar tus habilidades.\n");
			continuar();
		} else {
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
	continuar();
	printf("\nEscribe los puntos que deses agregarle a tu %s - tienes %d disponibles\n", (player.stats[opcion]).name, player.improvableStats );
	aumento = inquirirOpcion ( player.improvableStats +1 );
	(player.stats[opcion]).points += aumento;
	player.improvableStats -= aumento;
	continuar();
}

/*
Nombre: inquirirOpcion
Descripcion: le pregunta al usuario por una opcion entre 0 y maximo. Lo hace cuantas veces sea 
				necesario.
*/
int inquirirOpcion(int maximo){
	int opcion;
	char t;
	do {
		printf(" > ");
		scanf("%d", &opcion);
		t = getc(stdin);		
	} while ((opcion < 0) || (opcion >= maximo));
	return opcion;
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

void inicializar( ){
	char* nombre = "azrael";
	player.name = nombre;
	player.lenItems = 6;
	player.items = (Inventory*) malloc ( sizeof ( Inventory ) * 6 );
	char* it1 = "pocion de vida";
	(player.items[0]).name = it1;
	(player.items[0]).amount = InvInit;
	char* it2 = "pocion de energia";
	(player.items[1]).name = it2;
	(player.items[1]).amount = InvInit;
	char* it3 = "pocion de fuerza";
	(player.items[2]).name = it3;
	(player.items[2]).amount = InvInit;
	char* it4 = "pergamino maldito";
	(player.items[3]).name = it4;
	(player.items[3]).amount = InvInit;
	char* it5 = "capa de invisibilidad";
	(player.items[4]).name = it5;
	(player.items[4]).amount = InvInit;
	char* it6 = "pocion furia demoniaca";
	(player.items[5]).name = it6;
	(player.items[5]).amount = InvInit;

	player.lenStats = 5;
	player.improvableStats = ImprovPointInit;

	player.stats = (Statistics*) malloc ( sizeof ( Statistics ) * player.lenStats );
	char* st1 = "salud";
	(player.stats[0]).name = st1;
	(player.stats[0]).lenName = 5;
	(player.stats[0]).points = PointInit;

	char* st2 = "ataque rapido";
	(player.stats[1]).name = st2;
	(player.stats[1]).lenName = 13;
	(player.stats[1]).points = PointInit;

	char* st3 = "ataque pesado";
	(player.stats[2]).name = st3;
	(player.stats[2]).lenName = 13;
	(player.stats[2]).points = PointInit;

	char* st4 = "probabilidad ataque pesado - parry";
	(player.stats[3]).name = st4;
	(player.stats[3]).lenName = 34;
	(player.stats[3]).points = PointInit;

	char* st5 = "stamina";
	(player.stats[4]).name = st5;
	(player.stats[4]).lenName = 7;
	(player.stats[4]).points = PointInit;

}