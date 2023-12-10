/*
Ejemplo Listas STL (list, deque, forward_list)

*/

#include <list>
#include <forward_list>
#include <iostream>
#include <deque>

using namespace std;

int main(){
  list<int> l;
  l.push_back(5);
  l.push_back(10);
  l.push_back(12);
  l.push_back(15);

  int i = 0;
  for(list<int>::iterator it = l.begin(); it != l.end(); ++it){
    cout << "Valor Posición " << i++ << ": " << *it << " " << endl;
  }
  
  cout << "Tamaño: " << l.size() << endl;

  list<int>::iterator it = l.begin();
  it++;
  it++;
  l.insert(it, 13);


  cout << "Tamaño: " << l.size() << endl;
  cout << "Elementos Lista:" << endl;

  for(it = l.begin(); it != l.end(); it++){
    cout << *it << " ";
  }
  cout << endl;

  if(l.empty())
    cout << "Lista Vacía" << endl;
  else
    cout << "Lista No Vacía" << endl;

  it = l.begin();
  it = l.erase(it);
  it++;
  it++;
  it = l.erase(it);

  cout << "Elementos Lista:" << endl;

  for(it = l.begin(); it != l.end(); it++){
    cout << *it << " ";
  }
  cout << endl;

  cout << "****************************************" << endl;

  forward_list<int> l2;
  l2.push_front(15);
  l2.push_front(12);
  l2.push_front(10);
  l2.push_front(5);

  i = 0;
  for(forward_list<int>::iterator it = l2.begin(); it != l2.end(); ++it){
    cout << "Valor Posición " << i++ << ": " << *it << " " << endl;
  }

  forward_list<int>::iterator it2 = l2.begin();
  it2++;
  it2++;
  l2.insert_after(it2, 13);

  cout << "Elementos Lista:" << endl;

  for(it2 = l2.begin(); it2 != l2.end(); it2++){
    cout << *it2 << " ";
  }
  cout << endl;

  if(l2.empty())
    cout << "Lista Vacía" << endl;
  else
    cout << "Lista No Vacía" << endl;

  l2.pop_front();
  it2 = l2.begin();
  it2++;
  it2 = l2.erase_after(it2);

  cout << "Elementos Lista:" << endl;

  for(it2 = l2.begin(); it2 != l2.end(); it2++){
    cout << *it2 << " ";
  }
  cout << endl;

  cout << "****************************************" << endl;

  deque<int> d;
  d.push_back(5);
  d.push_back(10);
  d.push_back(12);
  d.push_back(15);

  i = 0;
  for(deque<int>::iterator it1 = d.begin(); it1 != d.end(); ++it1){
    cout << "Valor Posición " << i++ << ": " << *it1 << " " << endl;
  }
  
  cout << "Tamaño: " << d.size() << endl;

  deque<int>::iterator it1 = d.begin();
  it1++;
  it1++;
  d.insert(it1, 13);

  cout << "Tamaño: " << d.size() << endl;
  cout << "Elementos Lista:" << endl;

  for(it1 = d.begin(); it1 != d.end(); it1++){
    cout << *it1 << " ";
  }
  cout << endl;

  if(d.empty())
    cout << "Lista Vacía" << endl;
  else
    cout << "Lista No Vacía" << endl;

  it1 = d.begin();
  it1 = d.erase(it1);
  it1++;
  it1++;
  it1 = d.erase(it1);

  cout << "Elementos Lista:" << endl;

  for(it1 = d.begin(); it1 != d.end(); it1++){
    cout << *it1 << " ";
  }
  cout << endl;

  cout << "****************************************" << endl;

  return 0;
}
