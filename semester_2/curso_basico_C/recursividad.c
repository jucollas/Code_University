#include <stdio.h>
long factorial(long number);
int main()
{
	int number;
	printf("ingrese un numero: ");
	scanf("%i", &number);
	printf("el factorial es %ld", factorial(number));
	return 0;
}

long factorial(long number)
{
	int ans;
	if (number <= 1)
	{
		ans = 1;
	}else{
		ans = number * factorial(number - 1);
	}
	return ans;
}