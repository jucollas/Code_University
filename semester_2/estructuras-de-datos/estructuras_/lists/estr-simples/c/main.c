#include "lista.h"
#include <stdio.h>


int main(){
  Lista l;
  l = crearLista();

  l = anxLista(l, 5); 
  l = anxLista(l, 10);
  l = anxLista(l, 12);
  l = anxLista(l, 15);
  
  printf("Valor posición 0: %i\n", infoLista(l, 1));
  printf("Valor posición 1: %i\n", infoLista(l, 2));
  printf("Valor posición 2: %i\n", infoLista(l, 3));
  printf("Tamaño: %i\n", longLista(l));

  l = insLista(l, 13, 2);
  
  printf("Tamaño: %i\n", longLista(l));
  
  printf("Elementos Lista:\n");
  int i;
  for(i=1; i<=longLista(l); i++){
    printf("%i ", infoLista(l, i));
  }
  printf("\n");
  
  if(vaciaLista(l))
    printf("Lista Vacía\n");
  else
    printf("Lista No Vacía\n");
  
  l = elimLista(l, 1);
  l = elimLista(l, 3);
  
  printf("Elementos Lista:\n");
  for(i=1; i<=longLista(l); i++){
    printf("%i ", infoLista(l, i));
  }
  printf("\n");

  return 0;
}
