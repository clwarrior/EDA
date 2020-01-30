#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include "3_complejos.h"
// O(n) en el peor de los casos, que es que el numero sea de mandelbrot, siendo n el numero de iteraciones dado
void resuelveCaso() {
	float x, y;
	cin >> x >> y;
	complejos c(x, y);
	int n;
	cin >> n;
	complejos zlast = complejos(0, 0);
	complejos zn = c;
	for (int i = 0;i < n && zn.modulo() <= 2 ;++i){
		zn = zlast*zlast + c;
		zlast = zn;
	}
	if (zn.modulo() <= 2)
		cout << "SI\n";
	else
		cout << "NO\n";
}

int main() {
  /* // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif*/
   
   int numCasos;
   cin >> numCasos;
   for (int i = 0;i < numCasos;++i) { resuelveCaso(); }
   
   /*// restablecimiento de cin
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("pause");
#endif*/
   return 0;
}
