/*
Prototipo Clase Carro
Marzo 10 de 2023

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

class EmpleadoIndefinido:public Empleado{
  char *codigoContrato, *fechaContrato;
  double salario;

  public:
    EmpleadoIndefinido();
    EmpleadoIndefinido(char*, char*, char*, char*, char*, char*, double);
    void setSalario(double);
    char* getCodigoContrato();
    char* getFechaContrato();
    double calcularPago();
};
