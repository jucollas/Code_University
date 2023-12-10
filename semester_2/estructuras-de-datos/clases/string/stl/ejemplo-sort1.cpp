/*
Ejemplos sort STL
Marzo 23 de 2023

*/

#include <iostream>
#include <algorithm>
#include <vector>

bool comparador(int i,int j){
  bool ans = i > j;
  return ans;
}

bool comparador2(int i,int j){
  bool ans;
  if(i % 2  == 0 && j % 2 == 0){
    ans = i < j;
  }
  else if(i % 2  != 0 && j % 2 != 0){
    ans = i > j;
  }
  else if(i % 2 == 0)
    ans = true;
  else
    ans = false;
  return ans;
}

int main () {
  int valores[] = {32, 71, 12, 45, 26, 80, 53, 33};
  std::vector<int> vec1(valores, valores + 8);

  // ordenar usando el comparador por defecto (operador <)
  //std::sort(vec1.begin(), vec1.begin() + 5);           //(12 32 45 71) 26 80 53 33
  std::sort(vec1.begin(), vec1.end(), comparador);
  //std::sort(vec1.begin(), vec1.end(), comparador2);

  std::cout << "Vector vec1:";
  for (std::vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  /*
  // ordenar usando la función comparador
  std::sort(vec1.begin() + 4, vec1.end(), comparador); // 12 32 45 71(26 33 53 80)
  
  std::cout << "Vector vec1:";
  for (std::vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
    std::cout << ' ' << *it;
    std::cout << '\n';*/

  return 0;
}
