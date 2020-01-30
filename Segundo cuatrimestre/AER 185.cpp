#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <iterator>
#include <set>
using namespace std;



//COSTE O(N*M), siendo N el numero de lineas del caso de prueba, y M el numero maximo de elementos de la linea
bool resuelveCaso() {
	int n;
	cin >> n;
   
   if (n == 0) 
      return false;
   string x;
   set<string> leGusta;
   set<string> puedeNoGustar;
   for (int i = 0;i < n;++i) {
	   cin >> x; 
	   if (x == "SI:") {
		   cin >> x;
		   while (x != "FIN") {
			   leGusta.insert(x);
			   if (puedeNoGustar.count(x) != 0)
				   puedeNoGustar.erase(x);
			   cin >> x;
		   }
	   }
	   else if (x == "NO:") {
		   cin >> x;
		   while (x != "FIN") {
			   if (leGusta.count(x) == 0)
				   puedeNoGustar.insert(x);
			   cin >> x;
		   }
	   } 
   }
   set<string>::iterator i = puedeNoGustar.begin();
   bool first = true;
   while (i != puedeNoGustar.end()) {
	   if (!first)
		   cout << ' ';
	   cout << *i++;
	   first = false;
   }
   cout << '\n';
   return true;
}

int main() {
	
   /*
#ifndef DOMJUDGE
	std::ifstream in("C:/Users/Claudia/OneDrive/UNIVERSIDAD/DOBLE/EDA/Juez/aer 185_prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif */


	while (resuelveCaso())
		;


	/*// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/
   
   return 0;
}
