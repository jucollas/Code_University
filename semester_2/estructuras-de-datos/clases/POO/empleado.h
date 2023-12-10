/*
Prototipo Clase Carro
Marzo 10 de 2023

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#ifndef EMPLEADO_H
//#define EMPLEADO_H

class Empleado{
  char *cedula, *nombre, *fechaNacimiento, *cargo;

  public:
    Empleado();
  Empleado(char*, char*, char*, char*);
    void setNombre(char*);
    void setCedula(char*);
    void setFechaNacimiento(char*);
    void setCargo(char*);
    char* getNombre();
    char* getCedula();
    char* getFechaNacimiento();
    char* getCargo();
    double calcularPago();
};

//#endif
