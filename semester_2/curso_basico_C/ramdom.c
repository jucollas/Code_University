#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	srand(time(NULL));   // Initialization, should only be called once.
	int r = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.
	printf("%i\n", r );
	return 0;
}
