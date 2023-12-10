#include <stdio.h>

void ajedrez();
void lineasHor();
void imprimirAltaCorte(char bando, int r);
void imprimirPeones(char bando);
void cuadriculas();

int main(){
	ajedrez();
	return 0;
}

void cuadriculas(){
	int i;
	for(i = 0; i < 8; ++i){
		printf("|    ");
	}
	printf("|\n");
}

void imprimirPeones(char bando){
	int i;
	for(i = 0; i < 8; ++i){
		printf("| P%c ",bando);
	}
	printf("|\n");
}

void imprimirAltaCorte(char bando, int r){
	int i;
	char altaCorte[8] = {'T','C','A','K','Q','A','C','T'};
	if (r == 1){
		for(i = 0; i < 8; ++i){
			printf("| %c%c ",altaCorte[i],bando);
		}
	}else{
		for(i = 7; i >= 0; --i){
			printf("| %c%c ",altaCorte[i],bando);
		}	
	}
	
	printf("|\n");
}

void lineasHor(){
	int i;
	for(i = 0; i < 41; ++i){
		printf("-");
	}
	printf("\n");
}

void ajedrez(){
	int i;
	lineasHor();
	for (i = 0; i < 8; ++i){

		if (i == 0){
			imprimirAltaCorte('W', 1);
			lineasHor();
			imprimirPeones('W');
		}else if(i == 7){
			lineasHor();
			imprimirPeones('B');
			lineasHor();
			imprimirAltaCorte('B',-1);
		}else{
			lineasHor();
			cuadriculas();
		}
		

	}
	lineasHor();

}