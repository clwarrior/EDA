#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

#include "2.h"

// O (n*log(n)) siendo n el numero de peliculas dado
bool resuelveCaso() {
	int npeliculas;
   cin >>npeliculas;
   
   if (npeliculas == 0) 
      return false;
   
   // leemos los horarios de las peliculas
   vector<pelicula> p(npeliculas);
   for (int i = 0;i < npeliculas;++i) {
	   horas com, dur;
	   cin >> com >> dur;
	   string name;
	   getline(cin, name);
	   pelicula peli = pelicula(name, com, dur);
	   p[i]=peli;
   }
   
   // ordenamos y mostramos
   sort(p.begin(), p.end());
   for (int i = 0;i < p.size();++i) {
	   cout << p[i].horaComienzo() + p[i].duracion() << ' ' << p[i].nombre()<<'\n';

   }
   cout << "---\n";
   return true;
}

int main() {
   // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("C:/Users/Claudia/OneDrive/UNIVERSIDAD/DOBLE/EDA/Juez/2_prueba.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   

   while (resuelveCaso());
   
   // restablecimiento de cin
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("pause");
#endif
   return 0;
}
