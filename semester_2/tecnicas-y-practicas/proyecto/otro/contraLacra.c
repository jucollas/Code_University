#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* constantes generales */
#define lenEstadisticas 5
#define lenInventario 6
#define maxInv 10
#define lenAtaques 3

/* este solo aplica para el boss de 'lacra de las cuevas' */
#define ataquesLacra 2

/* utilidad para usar con el menu cuando en explorar se encuentra una fuente*/
void fuenteHabilidad(int * estadisticas, char nombreEstadisticas[][15]);

/* utilidades para usar en general */
int inquirirOpcion(int maximo);
int probabilidad();

/* funciones utilizadas en la batalla. Se intenta que sea escalable */
void batalla(int * estadisticas, int * inventario, char nombreInventario[][26], int ataquesBoss[][3], char nombreAtaquesBoss[][25], int numAtaquesBoss, int hpBoss, char nombreBoss[]);
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
void printArr(int * arr, int n);

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
int main(){
	/* se inicia el generador de random */
	srand(time(NULL));

	/* para las estadisticas */
	int estadisticas[lenEstadisticas];
	char nombreEstadisticas[lenEstadisticas][15] = {"vida","espada de pluma","fuerza","agilidad","stamina"};

	int inventario[lenInventario];
	char nombreInventario[lenInventario][26] = {"pocion de salud", "pocion de energia", "pocion de fuerza", "pergamino maldito","capa de invisibilidad", "pocion de furia demoniaca"};

	/* caracteristicas del boss 'lacra de las cuevas' */
	int ataquesBoss[ataquesLacra][3] = {{100,100,60},{300,60,40}};
	char nombreLacra[] = "la lacra de la cueva";
	char nombreAtaquesLacra[ataquesLacra][25] = {"golpe de lacra","apuñalada de lacra"};
	int hpLacra = 500;

	/* inicia el inventario y las estadisticas */
	inicializar(estadisticas, inventario);

	/* la batalla */
	batalla(estadisticas, inventario, nombreInventario, ataquesBoss, nombreAtaquesLacra, ataquesLacra, hpLacra, nombreLacra);
	return 0;
}

/*
Nombre: batalla
Descripcion: maneja la logica de la batalla, poniendo valores a estadisticas de batalla como el hp y 
				stamina desde las 'estadisticas'. Determina los turnos y demas.
*/
void batalla(int * estadisticas, int * inventario, char nombreInventario[][26], int ataquesBoss[][3], char nombreAtaquesBoss[][25], int numAtaquesBoss, int hpBoss, char nombreBoss[]){
	/* se inicializan todas las caracteristicas propias */
	int ataquesPropios[lenAtaques][4] = {{calcDanoLiviano(estadisticas[1]),100,20,0},{calcDanoPesado(estadisticas[2]),calcProbPesado(estadisticas[3]),40,0},{3*(calcDanoPesado(estadisticas[2])), calcProbParry(estadisticas[3]),10,1}};
	char nombreAtaquesPropios[lenAtaques][15] = {"ataque rapido","ataque pesado","parry"};
	int hp = calcHp(estadisticas[0]);
	int stamina = calcStamina(estadisticas[4]);
	int recuperacionStamina = calcRecuperacionStamina(estadisticas[4]);

	/* asuntos directamente de la batalla */
	int danoBoss, danoPropio, reactivo;
	while ((hp > 0) && (hpBoss > 0)){
		printf("\n-------------------------------------------------------------------------------------------\n");
		printf("Tienes %d de vida              -             %s tiene %d de vida\n",hp, nombreBoss, hpBoss);
		printf("Tienes %d de stamina\n\n",stamina);
		reactivo = turnoPropio(ataquesPropios, nombreAtaquesPropios, &danoPropio, &stamina);
		/* meter lo de inventario - pociones*/
		danoBoss = turnoBoss(ataquesBoss, nombreAtaquesBoss, numAtaquesBoss, nombreBoss);
		descontarHp(&hp, &hpBoss, danoPropio, danoBoss,nombreBoss, reactivo);
		stamina += recuperacionStamina;
	}
	/* si hpBoss < 0 && hp < 0, igual has muerto, por lo que da lo mismo: te ha vencido */
	if (hp > 0){
		printf("\nFelicitaciones por vencer a %s!!\n\n",nombreBoss);
	} else {
		printf("\n%s te ha vencido\n\n",nombreBoss);
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
				printf("\nHas recibido plenamente el ataque de %s. Te ha quitado %d de vida\n",nombreBoss,danoBoss);
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

/*
Nombre: fuenteHabilidad
Descripcion: le pregunta al jugador cual estadistica quiere mejorar (y la mejora), cuando se 
				encuentra una fuente de habilidad.
*/
void fuenteHabilidad(int * estadisticas, char nombreEstadisticas[][15]){
	int opcion, i;
	printf("\nHas obtenido una fuente de habilidad. Escoge la habilidad que quieres mejorar:\n");
	printf("codigo   puntosObtenidos   nombreHabilidad\n");
	for (i = 0;i < lenEstadisticas; i++){
		printf("  [%d]            %d            %s\n",i, estadisticas[i],nombreEstadisticas[i]);
	}
	opcion = inquirirOpcion(lenEstadisticas);
	estadisticas[opcion] += 1;
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
utilidades varias:
*/
void printArr(int * arr, int n){
	int i;
	for (i = 0;i < n;i++){
		printf(" %d |",arr[i]);
	}
	printf("\n");
}
void inicializar(int * estadisticas, int * inventario){
	iniciarArr(estadisticas, lenEstadisticas, 0);
	iniciarArr(inventario, lenInventario, 2);
}

void iniciarArr(int * arr, int n, int val){
	int i;
	for (i = 0;i < n;i++){
		arr[i] = val;
	}
}