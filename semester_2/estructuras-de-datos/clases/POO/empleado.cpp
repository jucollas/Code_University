/*
Definición Clase Empleado
Marzo 10 de 2023

*/

#include "empleado.h"


Empleado::Empleado(){

}

Empleado::Empleado(char* ce, char* no, char* f, char* c){
  cedula = ce;
  nombre = no;
  fechaNacimiento = f;
  cargo = c;
}

void Empleado::setNombre(char* no){
  nombre = no;
}

void Empleado::setCedula(char* ce){
  cedula = ce;
}

void Empleado::setFechaNacimiento(char* f){
  fechaNacimiento = f;
}

void Empleado::setCargo(char* c){
  cargo = c;
}

char* Empleado::getNombre(){
  return nombre;
}

char* Empleado::getCedula(){
  return cedula;
}

char* Empleado::getFechaNacimiento(){
  return fechaNacimiento;
}

char* Empleado::getCargo(){
  return cargo;
}

double Empleado::calcularPago(){
  return 0;
}
