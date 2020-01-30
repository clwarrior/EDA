#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void funcion(vector<vector<int>> const& precios, vector<int> & marcas, int & pmin, int & cont, int&  prod, vector<int>const& minOpt) {
	for (int i=0;i<precios.size();++i){
		if (marcas[i] < 3) {
			//cout << "Compro el producto " << prod << " en el super " << i << " y con este he comprado " << marcas[i] << " productos\n";
			++marcas[i];
			cont += precios[i][prod];
			++prod;
			if (prod == precios[0].size()) {
				if (cont < pmin) {
					pmin = cont;
				}
			}
			else if(cont + minOpt[prod] < pmin){
				funcion(precios, marcas, pmin, cont, prod, minOpt);
			}
			--marcas[i];
			--prod;
			cont -= precios[i][prod];
		}
	}
}


void resuelveCaso() {
	int nSuper, nProd;
	cin >> nSuper >> nProd;
	vector<vector<int>> precios(nSuper, vector<int>(nProd));
	for (int i = 0; i < nSuper ;++i) {
		for (int j = 0;j < nProd ;++j) {
			cin >> precios[i][j];
		}
	}
	vector<int> marcas(nSuper);
	for (int i = 0;i < nSuper;++i)
		marcas[i] = 0;
	int pmin = 2147483647;

	vector<int> minOpt(nProd+1);
	minOpt[nProd] = 0;
	int contador;
	for (int i = nProd-1;i > 0;--i) {
		contador = 2147483647;
		for (int j = 0;j < nSuper;++j) {
			if (precios[j][i] < contador)
				contador = precios[j][i];
		}
		minOpt[i] = minOpt[i + 1] + contador;
	}

	int cont = 0, prod=0;
	funcion(precios, marcas, pmin, cont, prod, minOpt);
	cout << pmin << '\n';
}

int main() {
	#ifndef DOMJUDGE
	std::ifstream in("C:/Users/Claudia/OneDrive/UNIVERSIDAD/DOBLE/EDA/Juez/p28.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif 
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
	#endif

	return 0;
}