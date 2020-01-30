//Claudia Guerrero (DG07)
#include "bintree_eda.h"
#include <iostream>
#include <memory> 
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Coste: O(n) siendo n el numero de nodos del arbol, coste lineal ya que recorremos una sola vez el arbol

template <class T>
bintree<T> leerArbol(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return{ iz, raiz, dr };
	}
}

//Coste lineal
bool excursionistas(bintree<int> t, int & eq, int & maxex, int actex, int& exruta) {
	if (!t.empty()) {
		/*if (actex == 0 && t.root() != 0) { //Falta calcular el numero de rutas
			++eq;
		}*/

		actex += t.root();
		bool leave1 = excursionistas(t.right(), eq, maxex, actex, exruta);
		int eq1 = eq;
		bool leave2 = excursionistas(t.left(), eq, maxex, actex, exruta);
		int eq2 = eq;
		if (t.root() != 0 && eq1 == 0 && eq2 == 0)
			eq = 1;
		else
			eq = eq1 + eq2;
		if (!leave1 && !leave2) { //Si es una hoja
			if (actex > maxex)
				maxex = actex;
			exruta = actex;
		}
		actex -= t.root();
		return true;
	}
	else
		eq = 0;
		return false;
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	int eq=0, maxex=0, actex=0, exruta=0;
	excursionistas(arbol, eq, maxex, actex, exruta);
	cout << eq << ' ' << maxex << '\n';
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("p12.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}