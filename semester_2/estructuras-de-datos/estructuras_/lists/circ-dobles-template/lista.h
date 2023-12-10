/*
 * Autor: Carlos Ramírez
 * Fecha de creación: 30 de Octubre
 * Fecha última modificación: 30 de Octubre
 * Versión: 1.0
 * 
 * Archivo encabezado libreria TAD Lista
 * Representación Estructuras Circulares Dobles con Templates
 */

#ifndef __LISTA_H
#define __LISTA_H

#include <iostream>

using namespace std;

/************************
* ESTRUCTURAS DE DATOS *
************************/
template <class T>
class Nodo{
  public:
    T dato;
    Nodo<T>* sig;
    Nodo<T>* ant;

    ~Nodo();
};

template <class T>
class Lista{
  private:
    Nodo<T>* act;

  public:
    /************************
    * OPERACIONES DEL TAD *
    ************************/

    /* Constructoras */
    Lista();

    /* Modificadoras */
    void anxLista(T elem);
    void insLista(T elem, int pos);
    void elimLista(int pos);

    /* Analizadoras */
    T infoLista(int pos);
    int longLista();
    bool vaciaLista();
};
 
template <class T>
Nodo<T>::~Nodo(){
  cout << "Borrando nodo " << dato << endl;
  sig = NULL;
  ant = NULL;
  delete sig;
  delete ant;
}

template <class T>
Lista<T>::Lista(){
  act = NULL;
}

template <class T>
void Lista<T>::anxLista(T elem){
  Nodo<T> *tmp, *primero;
  Nodo<T>* nuevo = new Nodo<T>;
  nuevo->dato = elem;
  nuevo->sig = nuevo;
  nuevo->ant = nuevo;

  if(act == NULL)
    act = nuevo;
  else{
    tmp = act->ant;
    tmp->sig = nuevo;
    nuevo->ant = tmp;
    nuevo->sig = act;
    act->ant = nuevo;
  }
}

template <class T>
void Lista<T>::insLista(T elem, int pos){
  Nodo<T> *nuevo, *tmp;
  nuevo = new Nodo<T>;
  nuevo->dato = elem;
  nuevo->sig = NULL;
  nuevo->ant = NULL;

  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      tmp = act->ant;
      tmp->sig = nuevo;
      nuevo->ant = tmp;
      nuevo->sig = act;
      act->ant = nuevo;
      act = nuevo;
    }
    else{
      tmp = act;
      for(int i = 0; i < pos - 2; i++)
        tmp = tmp->sig;
      nuevo->sig = tmp->sig;
      nuevo->ant = tmp;
      tmp->sig->ant = nuevo;
      tmp->sig = nuevo;
    }
  }
}

template <class T>
void Lista<T>::elimLista(int pos){
  Nodo<T> *tmp, *borrar, *sig;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1){
      if(act != act->sig){
        tmp = act->ant;
        borrar = tmp->sig;
        act = act->sig;
        act->ant = tmp;
        tmp->sig = act;
      }
      else{
        borrar = act;
        act = NULL;
      }
    }
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
          tmp = tmp->sig;
      borrar = tmp->sig;
      sig = tmp->sig->sig;
      tmp->sig = sig;
      sig->ant = tmp;
    }

    delete borrar;
  }
}

template <class T>
T Lista<T>::infoLista(int pos){
   Nodo<T>* tmp = act;
   
   for(int i = 1; i < pos; i++)
      tmp = tmp->sig;
      
   return tmp->dato;
}

template <class T>
int Lista<T>::longLista(){
  int ans;
  if(vaciaLista())
    ans = 0;
  else{
    Nodo<T>* tmp, *primero;
    int cont = 1;
    tmp = act;
    primero = act;

    while(tmp->sig != primero){
      tmp = tmp->sig;
      cont++;
    }

    ans = cont;
  }
  return ans;
}

template <class T>
bool Lista<T>::vaciaLista(){
   return act == NULL;
}

#endif
