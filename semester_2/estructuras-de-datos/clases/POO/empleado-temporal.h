/*
Prototipo Clase Carro
Marzo 10 de 2023

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

class EmpleadoTemporal:public Empleado{
  double pagoPorHora;
  int mesesContrato;

  public:
    EmpleadoTemporal();
    EmpleadoTemporal(char*, char*, char*, char*, double, int);
    void setPagoPorHora(double);
    void setMesesContrato(int);
    double getPagoPorHora();
    int getMesesContrato();
    double calcularPago(int);
};
