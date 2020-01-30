//Claudia Guerrero García-Heras (DG07)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

//Funcion que resuelve el problema por recurencia,
//Coste: T(n) = {cte1					si n=2} siendo n = fin - ini +1 = tamaño a analizar del vector en esa llamada de
//				{2*T(n/2) + cte2		si n>2}								la función recursiva
bool caucasico(vector<int> const & v, int ini, int fin, int&n) {
	if (ini + 1 == fin){
		n = 0;
		if (v[ini] % 2 == 0)
			++n;
		if (v[fin] % 2 == 0)
			++n;
		return true; //siempre es cierto por que la diferencia de numero de elementos pares puede ser 1 o 0 (<2)
					//ya que cada mitad tiene un único elemento
	}
	else{
		int paresI, paresD;
		caucasico(v, ini, (fin + ini) / 2, n);
		paresI = n;
		caucasico(v, (fin + ini) / 2 + 1, fin, n);
		paresD = n;
		n = paresD + paresI;
		return abs(paresD - paresI) <= 2;
	}

}

bool resuelveCaso() {
	vector<int> v;
	int x;
	cin >> x;
	while (x != 0){
		v.emplace_back(x);
		cin >> x;
	}
	if (v.size()==0)
		return false;
	int n;
	bool sol = true;
	if (v.size() > 1)
		sol = caucasico(v, 0, v.size()-1, n);

	if (sol)
		cout << "SI\n";
	else
		cout << "NO\n";

	return true;

}

int main() {
/*#ifndef DOMJUDGE
	std::ifstream in("C:/hlocal/p25.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif */

	while (resuelveCaso())
		;

/*#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/
	return 0;
}