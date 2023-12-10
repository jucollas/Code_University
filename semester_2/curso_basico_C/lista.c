#include <stdio.h>
int main()
{
	int NumberPackges;
	scanf("%i", &NumberPackges);
	int lista[NumberPackges];
	for(int i = 0; i < NumberPackges; i += 1)
	{
		scanf("%i", &lista[i]);
	}
	printf("[");
	for(int i = 0; i < NumberPackges; i += 1)
	{

		printf("%i", lista[i]);
		if (i < NumberPackges - 1)
		{
			printf(",");
		}
	}
	printf("]");
	return 0;
}