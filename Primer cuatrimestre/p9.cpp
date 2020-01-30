#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

bool resolver(){
	int n, p;
	cin >> n;
	if (!std::cin)
		return false;
	cin >> p;
	vector<vector<int>> M(n);
	for (int i = 0; i < n; ++i){
		vector<int> v(n);
		for (int j = 0; j < n; ++j){
			cin >> v[j];
		}
		M[i] = v;
	}

	//P : {0 < p <= n < 100}
	//fun resolver1 (matrix M, int n, int p) return int max
	//Q : {max=max((sumatorio) k : a<=k<a+p (sumatorio) kk : b<=kk<b+p: M[k][kk])}
	//
	//Coste resolver1(n) = n^2*p^2-2np^3+p^4
	//Por tanto el coste seria cuadratico O(n^2)
	int max = 0;
	for (int i = 0; i <= n - p; ++i){
		for (int j = 0; j <= n - p; ++j){
			int suma = 0;
			for (int x = i; x < i+p; ++x){
				for (int y = j; y < j+p; ++y){
					suma += M[x][y];
				}
			}
			if (suma > max) max = suma;
		}
	}
	cout << max << '\n';
	
	return true;
}




int main(){
	#ifndef DOMJUDGE
	std::ifstream in("C:/Users/Claudia/Desktop/09EntradaEjemplo.txt"); 
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
	#endif

	while (resolver());
	
	#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	#endif

	return 0;
}