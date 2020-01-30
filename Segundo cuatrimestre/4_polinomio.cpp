#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include "4_polinomio.h"

// O(M log N), donde M es el número de consultas y N el número de trenes
bool resuelveCaso() {
	int c, e;
	cin >> c>> e;
   if (! std::cin)  // no hay más casos
      return false;
   
   // leemos 
   polinomio p;
   while (c != 0 || e != 0) {
	   monomio m = monomio(c, e);
	   p.add(m);
	   cin >> c >> e;
   }
   int numValores;
   float valor;
   cin >> numValores;
   for (int i = 0;i < numValores;++i) {
	   cin >> valor;
	   cout << p.evalua(valor) <<' ';
   }
   cout << '\n';
   return true;
}

int main() {

   
   while (resuelveCaso());
   

   return 0;
}
