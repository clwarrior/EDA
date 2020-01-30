#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include "horas.h"

// O(M log N), donde M es el número de consultas y N el número de trenes
bool resuelveCaso() {
   int t, c;
   cin >> t >> c;
   
   if (t == 0)  // no hay más casos
      return false;
   
   // leemos los trenes
   vector<horas> trenes(t);
   for (horas & h : trenes)
      cin >> h;
   
   // se resuelven las consultas
   for (int i = 0; i < c; ++i) {
      horas consulta;
      try {
         cin >> consulta;
         auto pos = lower_bound(trenes.begin(), trenes.end(), consulta);
         if (pos == trenes.end())
            cout << "NO\n";
         else
            cout << *pos << '\n';
      } catch (invalid_argument ia) {
         cout << "ERROR\n";
      }
   }
   cout << "---\n";
   return true;
}

int main() {
   // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
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
