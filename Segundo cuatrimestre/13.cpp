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

//Coste O(n) siendo n el nuemero de nodos del arbol
bool caudal(bintree<int> t, int & c, int & nav) {
	if (!t.empty()) {
		bool leave1 = caudal(t.right(), c, nav);
		int caudalR = c;		
		bool leave2 = caudal(t.left(), c, nav);
		int caudalL = c;
		if (leave1 || leave2){//Si no es una hoja
			if (caudalR >= 3)
				++nav;
			if (caudalL >= 3)
				++nav;
			c = max(0, caudalL + caudalR - t.root());
		}
		else 
			c = 1;
		return true;
	}
	else{
		c = 0;
		return false;
	}
	return true;
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	int c = 0, nav=0;
	caudal(arbol, c, nav);
	cout << nav << '\n';
}

int main() {


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	return 0;
}