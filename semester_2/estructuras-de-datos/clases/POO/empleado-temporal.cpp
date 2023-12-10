/*
Definición Clase Empleado
Marzo 10 de 2023

*/

#include "empleado-temporal.h"


EmpleadoTemporal::EmpleadoTemporal(): Empleado(){

}

EmpleadoTemporal::EmpleadoTemporal(char* ce, char* no, char* f, char* c, double pp, int m) : Empleado(ce, no, f, c){
  pagoPorHora = pp;
  mesesContrato = m;
}

void EmpleadoTemporal::setPagoPorHora(double pp){
  pagoPorHora = pp;
}

void EmpleadoTemporal::setMesesContrato(int m){
  mesesContrato = m;
}

double EmpleadoTemporal::getPagoPorHora(){
  return pagoPorHora;
}

int EmpleadoTemporal::getMesesContrato(){
  return mesesContrato;
}

double EmpleadoTemporal::calcularPago(int horas){
  double p = horas * pagoPorHora;
  return p;
}
