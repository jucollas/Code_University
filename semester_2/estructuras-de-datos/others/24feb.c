#include <stdio.h>

int cambiar(int* a, int* b, int c){
  int ans;
  *a = *a + *b;
  *b = *b - 5;
  c = *a + 3;
  ans = *a + *b + c;
  printf("*a = %d, *b = %d, c = %d, ans = %d\n", *a, *b, c, ans);
  return ans;
}

int cambiar2(int* a, int b, int c){
  int ans;
  *a *=2;
  b -= 3;
  c = *a + 1;
  ans = *a + b + c;
  printf("*a = %d, b = %d, c = %d, ans = %d\n", *a, b, c, ans);
  return ans;
}



int main(){
  int v = 12;
  int w = 10;
  int z = 1;
  int k = 8;

  printf("v = %d, w = %d, z = %d, k = %d\n", v, w, z, k);
  k = cambiar(&v, &z, k);
  printf("v = %d, w = %d, z = %d, k = %d\n", v, w, z, k);
  w += cambiar2(&w, v, k);
  printf("v = %d, w = %d, z = %d, k = %d\n", v, w, z, k);

  return 0;
}