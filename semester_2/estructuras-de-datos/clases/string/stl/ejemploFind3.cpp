#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>       // std::string

class Estudiante{
  public:
      std::string nombre;
      double nota;

      Estudiante(std::string nom, double val){
        nombre = nom;
        nota = val;
      }

      bool operator ==(const Estudiante& est) const{
          return nombre == est.nombre;
      }
};

int main(){
    std::vector<Estudiante> vec;
    Estudiante est1("Novita", 4.5);
    vec.push_back(est1);
    vec.push_back(Estudiante("Vicky", 1.5));
    vec.push_back(Estudiante("Leono", 3.2));
    vec.push_back(Estudiante("Munra el inmortal", 1.4));
    vec.push_back(Estudiante("Agnes", 5.0));
    vec.push_back(Estudiante("Aldebaran", 1.8));
    vec.push_back(Estudiante("Dokho", 4.8));
    vec.push_back(Estudiante("Mascara de la muerte", 2.8));

    std::cout << "Listado estudiantes:" << std::endl;
    for(int i = 0; i < vec.size(); i++)
      std::cout << vec[i].nombre << " " << vec[i].nota << std::endl;

    std::vector<Estudiante>::iterator pos = std::find(vec.begin(), vec.end(), Estudiante("Dokho", 0));

    if (pos != vec.end()) 
       std::cout << "Hay un estudiante con nombre Dokho en la posicion " << pos - vec.begin() << "." << std::endl;
    else
       std::cout << "Ningún estudiante se llama Dokho." << std::endl;
 
    pos = std::find(vec.begin(), vec.end(), Estudiante("Accane", 0));

    if (pos != vec.end())
       std::cout << "Hay una estudiante con nombre Accane en la posicion " << pos - vec.begin() << "." << std::endl;
    else
       std::cout << "Ninguna estudiante se llama Accane." << std::endl;

    return 0;
}
