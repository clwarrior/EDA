//Claudia Guerrero (DG07)
#include "bintree_minimo.h"
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
bintree_minimo<T> leerArbol(T vacio) {
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


bool resuelveCaso(){
	char tipo;
	cin >> tipo;
	if (!cin)
		return false;
	if(tipo=='N'){
		bintree_minimo<int> arbol = leerArbol(-1);
		int sol = arbol.minimo();
		cout << sol << '\n';
	}
	else if (tipo == 'P') {
		bintree_minimo<string> arbol = leerArbol((string)"#");
		string sol = arbol.minimo();
		cout << sol << '\n';
	}
	return true;
}


int main() {
	while(resuelveCaso());
	return 0;
}