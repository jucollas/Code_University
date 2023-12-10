/*
Ejemplos sort STL
Marzo 23 de 2023

*/

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>       // std::string

int main(){
  int arreglo[] = {2, 4, 12, 10, 9, 8, 11, 23, 5};
  int n = 9;

  std::sort(arreglo, arreglo + n);

  for(int i = 0; i < n; i++)
    std::cout << arreglo[i] << " ";
  std::cout << std::endl;

  return 0;
}
