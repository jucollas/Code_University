#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Estudiante{
  public:
      std::string nombre;
      double nota;

      Estudiante(std::string nom, double val){
        nombre = nom;
        nota = val;
      }

      bool operator <(const Estudiante& est) const{
          return nota < est.nota;
      }
};

bool comparar(Estudiante est1, Estudiante est2){
    return est1.nota < est2.nota;
}

int main(){
    vector<Estudiante> vec;
    Estudiante est1("Novita", 4.5);
    vec.push_back(est1);
    vec.push_back(Estudiante("Vicky", 1.5));
    vec.push_back(Estudiante("Leono", 3.2));
    vec.push_back(Estudiante("Munra el inmortal", 1.4));
    vec.push_back(Estudiante("Agnes", 5.0));
    vec.push_back(Estudiante("Aldebaran", 1.8));
    vec.push_back(Estudiante("Dokho", 4.8));
    vec.push_back(Estudiante("Mascara de la muerte", 2.8));

    std::sort(vec.begin(), vec.end());

    std::cout << "Listado estudiantes:" << std::endl;
    for(int i = 0; i < vec.size(); i++)
      std::cout << vec[i].nombre << " " << vec[i].nota << std::endl;

    if(binary_search(vec.begin(), vec.end(), Estudiante("", 3.2)))
       cout << "Hay un estudiante con nota 3.2." << endl;
    else
       cout << "No hay ningun estudiante con nota 3.2." << endl;

    if(binary_search(vec.begin(), vec.end(), Estudiante("", 4.9)))
       cout << "Hay un estudiante con nota 4.9." << endl;
    else
       cout << "No hay ningun estudiante con nota 4.9." << endl;
 
    return 0;
}
