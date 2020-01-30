//Claudia Guerrero
//Para hallar el vector p evitando usar bucles anidados, recorremos el vector
//original dos veces. Una de izda a dcha guardando en un vector aux de igual tamaño al original el
//valor maximo hasta esa posicion (incluida) del vector original. Y otra de dcha a izda
//guardando en el el vector aux1 el minimo de todas las posiciones recorridas.
//Por ultimo comparamos ambos vectores y vemos que posiciones cumplen la especificacion dada y 
//los acumulamos en el vector p que devolvemos.


#include <iostream>
#include <vector>
using namespace std;

void resuelveCaso(vector<int> a, int n){
	//coste lineal O(n)
	vector<int> p;
	vector<int> aux(n);
	aux[0]=a[0];
	int max1 = a[0];
	for (int i = 1; i < n; ++i){
		if (a[i] > max1)
			max1 = a[i];
		aux[i]=max1;
	}
	vector<int> aux1(n);
	int min2 = a[n-1];
	aux1[n - 1] = a[n - 1];
	for (int i = n-2; i >0; --i){
		if (a[i] < min2)
			min2 = a[i];
		aux1[i]=min2;
	}
	for (int i = 0; i < n-1; ++i){
		if (aux[i] < aux1[i+1])
			p.emplace_back(i);
	}

	for (int c : p)
		cout << c<<' ';
	cout << '\n';
}

int main(){
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i){
		int n;
		cin >> n;
		vector<int> a(n);
		for (int & c : a)
			cin >> c;
		resuelveCaso(a, n);
	}
	return 0;
}


