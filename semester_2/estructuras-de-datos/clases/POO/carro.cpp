/*
Definición Clase Carro
Marzo 10 de 2023

*/

#include <stdio.h>
#include "carro.h"

Carro::Carro(){
  marca = "BMVV";
  modelo = "1980";
  color = "zapote";
  velocidadMax = 20;
  velocidadActual = 0;
  capacidadGas = 10;
  nivelGasolina = 0;
  encendido = false;
}

Carro::Carro(char* mc, char* mo, char* c, double vm, double cg){
  marca = mc;
  modelo = mo;
  color = c;
  velocidadMax = vm;
  capacidadGas = cg;
  velocidadActual = 0;
  nivelGasolina = 0;
  encendido = false;
}

void Carro::prender(){
  if(!encendido)
    encendido = true;
}

void Carro::apagar(){
  if(encendido)
    encendido = false;
}

void Carro::abrirPuerta(){
  printf("Encendiendo el carro!\n");
}

void Carro::acelerar(double v){
  if(v <= velocidadMax)
    velocidadActual = v;
}

void Carro::frenar(){
  velocidadActual = 0;
}

void Carro::setColor(char* nc){
  color = nc;
}

char* Carro::getColor(){
  return color;
}

char* Carro::getMarca(){
  return marca;
}
