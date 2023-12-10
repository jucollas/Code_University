#include <stdio.h>
int main()
{
	int casos;
	printf("ingrese un numero\n");
	scanf("%i", &casos);
	switch(casos)
	{
		case 1:
		printf("primer caso");
		break;

		case 2:
		printf("segundo caso");
		break;

		case 3:
		printf("tercer caso");
		break;

		default:
		printf("caso no reconocido");
		break;
	}
	return 0;
}