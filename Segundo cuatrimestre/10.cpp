//Claudia Guerrero (DG07)
#include "bintree_frontera.h"
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
bintree_frontera<T> leerArbol(T vacio) {
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


void resuelveCaso() {
	bintree_frontera<int> arbol = leerArbol(-1);
	vector<int> sol = arbol.frontera();
	for (int i = 0;i < sol.size();++i)
		cout << sol[i] << ' ';
	cout << '\n';
}

int main() {

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	return 0;
}