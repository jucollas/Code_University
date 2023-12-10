#include <stdio.h>
int main()
{
	int num1,num2,resultado;
	int a = 12;
	int b = 3;
	printf("ingrese primer valor\n");
	scanf("%d",&num1);
	printf("ingrese segundo valor\n");
	scanf("%d", &num2);
	resultado = a*(num1+num2)+ b*(b*num2); 
	printf("el resultado de la suma es: %d\n",resultado);
	return 0;
}