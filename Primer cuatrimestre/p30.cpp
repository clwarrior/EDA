#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



int resolver(vector<int> const& v, int ini, int fin) {
	if (ini == fin)
		return v[ini];

	else {
		if (v[(ini + fin) / 2] > v[ini])
			return resolver(v, ini, (ini + fin) / 2 - 1);
		if (v[(ini + fin) / 2] < v[ini])
			return resolver(v, (ini + fin) / 2, fin);
		if (v[(ini + fin) / 2] == v[ini]) {
			if (v[ini] < v[fin])
				return v[ini];
			else
				return v[fin];
		}
	}
}


bool resuelveCaso() {
	int n;
	cin >> n;
	if (!std::cin)
		return false;
	vector<int> v(n);
	for (int&x : v)
		cin >> x;

	int sol = resolver(v, 0, n-1);
	cout << sol << '\n';
	return true;

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("C:/Users/Claudia/OneDrive/UNIVERSIDAD/DOBLE/EDA/Juez/p30.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 


	while (resuelveCaso())
		;

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}