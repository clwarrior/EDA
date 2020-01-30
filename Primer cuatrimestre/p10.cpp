#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

void resuelveCaso() {
	int n, p;
	cin >> n >> p;
	vector<int> v(n);
	for (int &x : v)
		cin >> x;
		int maxvalor=0;
	
	//El coste de la funcion O(f(n))=O(n)
	for (int i = 0; i < p; ++i)
		maxvalor += v[i];
	int aux=maxvalor;
	int pos = 0;
	for (int i = p; i < n; ++i){
		aux = aux + v[i] - v[i - p];
		if (aux >= maxvalor){
			maxvalor = aux;
			pos = i - p + 1;
		}
	}
	cout << pos << ' ' << maxvalor << '\n';

}

int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	return 0;
}