#include <stdio.h>
int main()
{
	char t = 'a';
	int a = 20;
	short e = -1;
	unsigned int u = 25;
	long r = 123;
	float f = 23.123456;
	double d = 1233445.1234456;
	printf("%c\n", t);
	printf("%i\n", a);
	printf("%i\n", e);
	printf("%i\n", u);
	printf("%li\n", r);
	printf("%.2f\n", f);
	printf("%lf\n", d);
	return 0;
}