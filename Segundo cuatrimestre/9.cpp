
#include "bintree_ext.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Coste: O(n) donde n es el numero de nodos del arbol (coste lineal respecto al numero de nodos del arbol)

template <class T>
bintree_ext<T> leerArbol(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return bintree_ext<T>();
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return bintree_ext<T>(iz, raiz, dr);
	}
}


void resuelveCaso() {
	bintree_ext<char> arbol=leerArbol('.');
	size_t nodos=0, hojas=0, altura=0;
	nodos = arbol.nNodos();
	hojas = arbol.nHojas();
	altura = arbol.nAltura();
	cout << nodos << ' ' << hojas << ' ' << altura << '\n';
}

int main() {

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	return 0;
}