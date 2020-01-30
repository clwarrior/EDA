//Claudia Guerrero García-Heras (DG07)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;


void resolver(int t, vector<vector<int>> const& canciones, vector<bool> & marcas, int contP, int tC1, int tC2, int pmax) {
	for (int i = 0;i < canciones.size() ;++i) {
		if (marcas[i] == false) {
			if (tC1 + canciones[i][0] <= t || tC2 + canciones[i][0] <= t){
				marcas[i] = true;
				contP += canciones[i][1];
				if (tC1 + canciones[i][0] <= t) {
					tC1 += canciones[i][0];
					if (contP > pmax)
						pmax = contP;
					resolver(t, canciones, marcas, contP, tC1, tC2, pmax);

				}
			}
			else 
				tC2 += canciones[i][0];
				contP += canciones[i][1];

			}
			
			
			marcas[i] = false;
		}

	}

}


bool resuelveCaso() {
	int n, t;
	cin >> n;
	if (n==0)
		return false;
	cin >> t;
	vector<vector<int>> canciones(n, vector<int>(2));
	for (int i = 0 ; i < n ; ++i) {
		for (int j = 0; j < 2; ++j) {
			cin >> canciones[i][j];
		}
	}
	vector<bool> marcas(n);
	for (int i = 0;i < n;++i) {
		marcas[i] = false;
	}
	int contP = 0, pmax = 0, tiempoCara1 = 0, tiempoCara2=0;
	resolver(t, canciones, marcas, contP, tiempoCara1, tiempoCara2 , pmax);



	return true;

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("C:/Users/Claudia/OneDrive/UNIVERSIDAD/DOBLE/EDA/Juez/p24.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 


	while (resuelveCaso())
		;

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}