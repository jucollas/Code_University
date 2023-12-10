/*
Ejemplo POO Carro
Marzo 10 de 2023

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carro.h"

int main(){
  Carro carro1, carro2("Mazda", "Mazda 6", "Rojo", 250, 25);

  printf("Información carro:\n");
  //printf("---> Marca: %s\n", carro1.marca);
  printf("---> Marca: %s\n", carro1.getMarca());
  //printf("---> Color: %s\n", carro1.color);
  printf("---> Color: %s\n", carro1.getColor());

  printf("Información carro:\n");
  //printf("---> Marca: %s\n", carro2.marca);
  printf("---> Marca: %s\n", carro2.getMarca());
  //printf("---> Color: %s\n", carro2.color);
  printf("---> Color: %s\n", carro2.getColor());

  return 0;
}
