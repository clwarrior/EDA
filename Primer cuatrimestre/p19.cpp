//Claudia Guerrero(DG07)

#include <iostream>
#include<vector>
#include <string>
#include <fstream>
using namespace std;

//Coste: T(n)={cte1					si n=1} siendo n = tamaño a tratar del vector del vector de entrada
//            {2*T(n/2) + cte2		si n>1}

bool degradado(vector<int> const & v, int i, int j, int& suma){
	if (i + 1 == j){
		suma = v[i] + v[j];
		if (v[i] < v[j])
			return true;
		else
			return false;
	}
	else{
		int sumaI, sumaD;
		bool ok1 = degradado(v, i, (i + j) / 2, suma);
		sumaI = suma;
		bool ok2 = degradado(v, (i + j) / 2 + 1, j, suma);
		sumaD = suma;
		suma = sumaI + sumaD;
		return ok1 && ok2 && sumaI < sumaD;
	}
}




bool resuelveCaso() {
	int i, j;
	cin >> i >> j;
	if (!std::cin)
		return false;
	bool deg = true;
	int a = 0;
	while (a < i) {

		vector<int> v(j);
		for (int &x : v)
			cin >> x;
		if (deg && v.size()!=1){
			int s;
			deg = degradado(v, 0, v.size() - 1, s);
		}
		++a;
	}
	if (deg || j==1)
		cout << "SI\n";
	else
		cout << "NO\n";

	return true;
}



int main(){
#ifndef DOMJUDGE
	std::ifstream in("C:/Users/usuario_local/Downloads/19EntradaEjemplo.txt");
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