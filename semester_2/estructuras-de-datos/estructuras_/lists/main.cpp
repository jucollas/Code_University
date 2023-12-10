/*
Ejemplos Operaciones sobre TAD Lista
Abril 3 de 2023

*/

#include "estr-simples/c++/lista.h"
//#include "estr-dobles/c++/lista.h"
//#include "circ-simples/c++/lista.h"
//#include "circ-dobles/c++/lista.h"

void printLista(Lista &l){
  int i;
  for(i = 0; i < l.longLista(); ++i)
    printf("%d\n", l.infoLista(i + 1));
}

int sumarLista(Lista &l){
  int i, res = 0;
  for(i = 1; i <= l.longLista(); ++i)
    res += l.infoLista(i);
  return res;
}

int main(){
  Lista l;
  l.anxLista(10);
  l.anxLista(8);
  l.anxLista(13);
  l.anxLista(7);
  l.anxLista(19);

  printLista(l);
  printf("La suma de los elementos en la lista es %d\n", sumarLista(l));

  return 0;
}

