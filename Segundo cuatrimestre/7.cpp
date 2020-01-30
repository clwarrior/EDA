// Claudia Guerrero y Pablo Hidalgo
#include "extQueue_inv.h"
#include <iostream>
using namespace std;

//Coste O(n) lineal, respecto al numero de elementos de la cola
//El coste de lectura es lineal, y el de invertir() y mostrar() tambien, por tanto el coste total O(3n) c O(n) es tambien lineal
void caso(int x){
	//leer
	extQueue_inv<int> q;
	while (x!=0){
		q.push(x);
		cin >> x;
	}
	//duplicar y mostrar
	q.invertir();
	q.mostrar();
}

int main(){
	int x;
	while (cin >> x)
		caso(x);
	return 0;
}