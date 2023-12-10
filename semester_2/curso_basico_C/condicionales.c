#include <stdio.h>
int main()
{
	int edad;
	printf("ingresa tu edad\n");
	scanf("%d", &edad);
	if(edad >= 18)
	{
		printf("eres mayor de edad");
	}
	else if(edad == 17)
	{
		printf("casi eres mayor de edad")
	}
	else{
		printf("eres menor de edad\n");
	}
	return 0;
}