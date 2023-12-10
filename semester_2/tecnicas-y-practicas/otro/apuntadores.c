#include <stdio.h>

int main(){
	int i;
	int* e = &i;
	printf("%x", e);
	return 0;
}