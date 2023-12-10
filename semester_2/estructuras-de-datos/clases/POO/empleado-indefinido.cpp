/*
Definición Clase Empleado Indefinido
Marzo 10 de 2023

*/

#include "empleado-indefinido.h"


EmpleadoIndefinido::EmpleadoIndefinido(): Empleado(){

}

EmpleadoIndefinido::EmpleadoIndefinido(char* ce, char* no, char* f, char* c, char* cc, char* fc, double s) : Empleado(ce, no, f, c){
  codigoContrato = cc;
  fechaContrato = fc;
  salario = s;
}

void EmpleadoIndefinido::setSalario(double s){
  if(s > salario)
    salario = s;
}

char* EmpleadoIndefinido::getCodigoContrato(){
  return codigoContrato;
}

char* EmpleadoIndefinido::getFechaContrato(){
  return fechaContrato;
}

double EmpleadoIndefinido::calcularPago(){
  return salario;
}
