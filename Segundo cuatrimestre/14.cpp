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
bool esPrimo(int n) {
	bool primo = true;
	if (n == 0 || n == 1 )
		primo = false;
	for (int i = 2;i < n / 2 + 1 && primo;++i) {
		if (n%i == 0) {
			primo = false;
		}
	}
	return primo;
}
//Coste lineal respecto del numero de nodos del arbol
void multiploSiete(bintree<int> const& arbol, int & prof, int& realprof,int & num) {
	if (!arbol.empty()) {
		if (!esPrimo(arbol.root())) {
			if (arbol.root() % 7 == 0 && arbol.root()!=0 && (realprof==-1 || prof<realprof)) {
				num = arbol.root();
				realprof = prof;
			}
			else {
				++prof;
				multiploSiete(arbol.left(), prof, realprof, num);
				multiploSiete(arbol.right(), prof,realprof, num);
				--prof;
			}
		}
	}
}


void resuelveCaso(){
	bintree<int> arbol = leerArbol(-1);
	int p=1, rp=-1, n=0;
	multiploSiete(arbol, p, rp, n);
	if (n == 0)
		cout << "NO HAY\n";
	else
		cout << n<<' '<<rp << '\n';
}


int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0;i < numCasos;++i) {
		resuelveCaso();
	}
	return 0;
}