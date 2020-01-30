#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Añadimos los combinatorios desde 0 hasta b por recurrencia en el vector v
//Coste lineal; llamamos b veces a la funcion recursiva con coste constante

int combinatorio(int a, int b, vector<int>& v) {
	if (b == 0){
		v.emplace_back(1);
		return 1;
	}

	if (b == 1){
		combinatorio(a, b - 1, v);
		v.emplace_back(a);
		return a;
	}

	else{
		combinatorio(a, b - 1, v);
		v.emplace_back(v[b - 1] * ((a-b+1)/float(b)));
		return v[v.size()-1];
	}
}

bool resuelveCaso() {
	int a, b;
	cin >> a >> b;
	if (!std::cin)
		return false;
	vector<int> v;
	int sol = combinatorio(a, b, v);
	cout << sol << '\n';


	return true;

}

int main() {

	while (resuelveCaso())
		;

	return 0;
}