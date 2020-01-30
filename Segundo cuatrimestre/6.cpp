// Claudia Guerrero y Pablo Hidalgo
#include "extendedQueue.h"
#include <iostream>
using namespace std;

void caso(int x){
	//leer
	extendedQueue<int> q;
	while (x){
		q.push(x);
		cin >> x;
	}
	//duplicar y mostrar
	q.duplicar();
	q.mostrar();
}

int main(){
	int x;
	while (cin >> x)
		caso(x);
	return 0;
}