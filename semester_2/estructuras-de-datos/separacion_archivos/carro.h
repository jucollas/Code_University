/*
Prototipo Clase Carro
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
    Carro();
    Carro(char*, char*, char*, double, double);
    void prender();
    void apagar();
    void abrirPuerta();
    void acelerar(double);
    void frenar();
    void setColor(char*);
    char* getColor();
    char* getMarca();
};
