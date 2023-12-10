#include <stdio.h>
int main()
{
	int a = 20;
	float f = 45.3;
	float suma = (float)a + f;
	printf("ENTERO %i\n",a);
	printf("FLOTANTE %.2f\n", (float)a);
	printf("DOUBLE %.3f\n", (double)a);
	printf("CARACTER %c\n",(char)a);
	printf("suma %.2f", suma);
	return 0;
}
