#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>       // std::string

using namespace std;

class Estudiante{
  public:
    std::string nombre;
    double nota;
    int edad;

  Estudiante(std::string nom){
    nombre = nom;
  }

  Estudiante(std::string nom, double val, int ed){
      nombre = nom;
      nota = val;
      edad = ed;
  }

  bool operator <(const Estudiante& est){
    //bool ans = nombre.size() > est.nombre.size();
    bool ans;
    if(nombre.size() != est.nombre.size())
      ans = nombre.size() > est.nombre.size();
    else if(edad != est.edad)
      ans = edad > est.edad;
    else{
      ans = nota < est.nota;
    }
    return ans;
  }

  bool operator ==(const Estudiante& est){
    bool ans = nombre == est.nombre;
    return ans;

  }
};

bool comparar(Estudiante est1, Estudiante est2){
  return est1.nota > est2.nota;
}

int main(){
  std::vector<Estudiante> vec;
  Estudiante est1("Novita", 4.5, 10);
  vec.push_back(est1);
  vec.push_back(Estudiante("Vicky", 1.5, 40));
  vec.push_back(Estudiante("Leono", 3.2, 40));
  vec.push_back(Estudiante("Kenny", 4.2, 8));
  vec.push_back(Estudiante("Munra el inmortal", 1.4, 8));
  vec.push_back(Estudiante("Kartman", 1.0, 8));
  //std::sort(vec.begin(), vec.end());
  std::sort(vec.begin(), vec.end(), comparar);

  std::cout << "Listado estudiantes:" << std::endl;
  for(int i = 0; i < vec.size(); i++)
    std::cout << vec[i].nombre << " " << vec[i].nota << std::endl;

  int arreglo[] = {34, 1, 23, 18, 12, 40, 50, 11};
  int c = 4;
  std::sort(arreglo, arreglo + c);
  for(int i = 0; i < 8; ++i)
    std::cout << arreglo[i] << " ";
  std::cout << std::endl;

  vector<Estudiante>::iterator it = find(vec.begin(), vec.end(), Estudiante("Kenny"));
  if(it == vec.end())
    cout << "No está" << endl;
  else
    cout << "Si está " << it - vec.begin() << endl;
  
  return 0;
}
