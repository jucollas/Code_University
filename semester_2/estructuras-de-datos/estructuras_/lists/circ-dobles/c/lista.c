#include "lista.h"
 
Lista crearLista(){
  Lista lst;
  lst = NULL;
  return lst;
}
 
Lista anxLista(Lista lst, Elemento elem){
  Lista nuevo, tmp, primero;
   
  nuevo = (Lista) malloc(sizeof(struct nodo));
  nuevo->dato = elem;
   
  nuevo->sig = nuevo;
  nuevo->ant = nuevo;
   
  if(lst == NULL)
    lst = nuevo;
  else{
    primero = lst;
    tmp = lst;
    while(tmp->sig != primero)
      tmp = tmp->sig;
    tmp->sig = nuevo;
    nuevo->ant = tmp;
    nuevo->sig = primero;
    primero->ant = nuevo;
  }
   
  return lst;
}
 
Lista insLista(Lista lst, Elemento elem, int pos){
  Lista nuevo, tmp;
  nuevo = (Lista) malloc(sizeof(struct nodo));
  nuevo->dato = elem;
  nuevo->sig = NULL;
  nuevo->ant = NULL;
   
  if(pos >= 1 && pos <= longLista(lst)){
    if(pos == 1){
      nuevo->sig = lst;
      lst->ant = nuevo;
      lst = nuevo;
    }
    else{
      tmp = lst;
      int i;
      for(i = 0; i < pos-2; i++)
        tmp = tmp->sig;
      nuevo->sig = tmp->sig;
      nuevo->ant = tmp;
      tmp->sig->ant = nuevo;
      tmp->sig = nuevo;
    }
  }
   
  return lst;
}
 
Lista elimLista(Lista lst, int pos){
  Lista tmp;
   
  if(pos >= 1 && pos <= longLista(lst)){
    if(pos == 1){
      tmp = lst->ant;
      lst = lst->sig;
      lst->ant = tmp;
      tmp->sig = lst;
    }
    else{
      tmp = lst;
      int i;
      for(i = 0; i < pos-2; i++)
        tmp = tmp->sig;
 
      Lista sig = tmp->sig->sig;
      tmp->sig = sig;
      sig->ant = tmp;
    }
  }
   
  return lst;
}
 
Elemento infoLista(Lista lst, int pos){
  Lista tmp;
  tmp = lst;
  int i;
   
  for(i = 1; i < pos; i++)
    tmp = tmp->sig;
  return tmp->dato;
}
 
int longLista(Lista lst){
  if(vaciaLista(lst))
    return 0;
  else{
    Lista tmp, primero;
    int cont = 1;
    tmp = lst;
    primero = lst;
     
    while(tmp->sig != primero){
      tmp = tmp->sig;
      cont++;
    }
     
    return cont;
  }
}
 
int vaciaLista(Lista lst){
  return lst == NULL;
}