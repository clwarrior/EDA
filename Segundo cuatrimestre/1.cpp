//Claudia Guerrero García-Heras (DG07)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

#include "1.h"



int busquedaBin(vector<horas> const& horario, horas const& h, int ini, int fin){
	if (ini == fin){
		return ini;
	}
	else{
		int medio = (ini + fin) / 2;
		if (horario[medio] < h)
			busquedaBin(horario, h, medio + 1, fin);
		else if (h < horario[medio])
			busquedaBin(horario, h, ini, medio);
		else
			return medio;
	}
}

// O(C * log(N)), donde c es el numero de consultas y n el numero de trenes que pasan
bool resuelveCaso() {
	int t, c;
	cin >> t >> c;

	if (t == 0)  // no hay más casos
		return false;
	else {
		vector<horas> horario(t);
		for (horas & h : horario)
			cin >> h;


		for (int i = 0; i < c; ++i) {
			horas consulta;
			try {
				cin >> consulta;
				int pos = busquedaBin(horario, consulta, 0, horario.size());
				if (pos == horario.size())
					cout << "NO\n";
				else
					cout << horario[pos] << '\n';
			}
			catch (invalid_argument ia) {
				cout << "ERROR\n";
			}
		}
		cout << "---\n";
		return true;
	}
}


int main() {

#ifndef DOMJUDGE
	std::ifstream in("p1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}