#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//Coste:

int funcion(int num, int ini, int fin, vector<int> v){
	if (ini > fin)
		return -1;
	else{
		int medio = (ini + fin) / 2;
		if (v[medio] - medio > num)
			return funcion(num, ini, medio - 1, v);
		else if (v[medio] - medio == num)
			return v[medio];
		else if (v[medio] - medio < num)
			return funcion(num, medio + 1, fin, v);
	}
}


void resuelveCaso() {
	int tam, num;
	cin >> tam >> num;
	vector<int> v(tam);
	for (int & x : v)
		cin >> x;

	int sol = funcion(num, 0, tam-1, v);

	if (sol != -1)
		cout << sol << '\n';
	else
		cout << "NO\n";

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("C:/Users/Claudia/Desktop/DOBLE/EDA/p14prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}