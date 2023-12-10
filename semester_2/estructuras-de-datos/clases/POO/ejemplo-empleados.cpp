/*
Ejemplo Empleados
Marzo 10 de 2023

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "empleado-temporal.h"
#include "empleado-indefinido.h"

int main(){
  Empleado emp1;
  emp1 = Empleado("111111", "Zlatan Ibrahimovich", "03/10/1981", "Operario");

  printf("Información Empleado\n");
  printf("---> Nombre: %s\n", emp1.getNombre());
  printf("---> Fecha de nacimiento: %s\n", emp1.getFechaNacimiento());
  printf("---> Cargo: %s\n", emp1.getCargo());
  printf("---> Salario: %lf\n", emp1.calcularPago());

  EmpleadoTemporal emp2("222222", "Randy Marsch", "07/05/1977", "Geólogo", 45000, 6);

  printf("Información EmpleadoTemporal\n");
  printf("---> Nombre: %s\n", emp2.getNombre());
  printf("---> Fecha de nacimiento: %s\n", emp2.getFechaNacimiento());
  printf("---> Cargo: %s\n", emp2.getCargo());
  printf("---> Salario: %lf\n", emp2.calcularPago(200));

  EmpleadoIndefinido emp3("44444", "Director PC", "11/07/1985", "Profesor", "444", "01/01/2023", 3000000);

  printf("Información EmpleadoTemporal\n");
  printf("---> Nombre: %s\n", emp3.getNombre());
  printf("---> Fecha de nacimiento: %s\n", emp3.getFechaNacimiento());
  printf("---> Cargo: %s\n", emp3.getCargo());
  printf("---> Salario: %lf\n", emp3.calcularPago());
  
  
  
  return 0;
}
