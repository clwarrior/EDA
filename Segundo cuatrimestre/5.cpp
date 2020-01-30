#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

#include "5.h"

// COSTE O(n) siendo n el numero de elementos a analizar
bool resuelveCaso() {
	char c;
	int k;
	cin >> c >> k; 

	if (!std::cin)
		return false;

	if (c == 'N'){
		set<int> cjto;
		int x;
		cin >> x;
		while (x != -1) {
			if(cjto.size()<k)
				cjto.insert(x); //Coste O(k)
			else if (cjto.size() == k && x > cjto.k_esimoMayor(k)) {
				if(cjto.insert(x))
					cjto.eliminarMenor(); //Coste O(k)
			}
			cin >> x;
		}
	

		for (int i = 0;i < k;++i) {
			cout<<cjto.consultarMenor()<<' ';
			cjto.eliminarMenor();
		}
		cout << '\n';
	}
	else if (c == 'P'){
		set<string> cjto;
		string x;
		cin >> x;
		while (x != "FIN") {
			if (cjto.size() < k)
				cjto.insert(x);
			else if (cjto.size() == k && x > cjto.k_esimoMayor(k)) {
				if(cjto.insert(x))
					cjto.eliminarMenor();
			}
			cin >> x;
		}

		for (int i = 0;i < k;++i) {
			cout << cjto.consultarMenor() << ' ';
			cjto.eliminarMenor();
		}
		cout << '\n';
	}
	
	return true;
}

int main() {

   
   while (resuelveCaso());
   

   return 0;
}
