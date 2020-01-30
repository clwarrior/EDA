//Claudia Guerrero García-Heras (DG07)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;



int resolver(vector<vector<int>> const & m, int fun, int & cant, int & min, vector<int> v) {
	if (fun == m.size()){
		if (cant < min)
			min = cant;

		return min;
	}
	else{
		for (unsigned int i = 0; i < m.size(); ++i) {
			if (v[i] == 0){
				v[i] = 1;
				int cantaux = cant + m[fun][i];
				int funaux = fun + 1;
				vector<int> w(v.size());
				resolver(m, funaux, cantaux, min, v);
				v[i]=0;
			}
		}
		return min;
	}
}


bool resuelveCaso() {
	int n;
	cin >> n;
	if (n==0)
		return false;
	vector<vector<int>> m(n, vector<int>(n));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> m[i][j];
		}
	}
	vector<int> v(n);//vector que marca actividades ya seleccionadas para un funcionario
	for (int &x : v){
		x=0;
	}
	int cant = 0;
	int min=0;
	for (int i = 0; i < n; ++i){//inicializacion del valor minimo de tiempo
		min += m[i][i];
	}
	int sol = resolver(m, 0, cant, min, v);

	cout << sol << '\n';

	return true;

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("C:/Users/Claudia/OneDrive/UNIVERSIDAD/DOBLE/EDA/Juez/p21prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 
	


	while (resuelveCaso())
		;


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
#endif
	//system("PAUSE");
	return 0;
}