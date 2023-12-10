/*
Ejemplo POO Carro
Marzo 10 de 2023

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Carro{
  char *marca, *modelo, *color;
  double velocidadMax, velocidadActual, capacidadGas, nivelGasolina;
  bool encendido;

  public:
    Carro(){
      marca = "BMVV";
      modelo = "1980";
      color = "zapote";
      velocidadMax = 20;
      velocidadActual = 0;
      capacidadGas = 10;
      nivelGasolina = 0;
      encendido = false;
    }

    Carro(char* mc, char* mo, char* c, double vm, double cg){
      marca = mc;
      modelo = mo;
      color = c;
      velocidadMax = vm;
      capacidadGas = cg;
      velocidadActual = 0;
      nivelGasolina = 0;
      encendido = false;
    }

    void prender(){
      if(!encendido)
	encendido = true;
    }

    void apagar(){
      if(encendido)
	encendido = false;
    }

    void abrirPuerta(){
      printf("Encendiendo el carro!\n");
    }

    void acelerar(double v){
      if(v <= velocidadMax)
	velocidadActual = v;
    }

    void frenar(){
      velocidadActual = 0;
    }

    void setColor(char* nc){
      color = nc;
    }

    char* getColor(){
      return color;
    }

    char* getMarca(){
      return marca;
    }
};

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
