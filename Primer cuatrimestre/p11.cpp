#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



int resolver(vector<vector<int>> M, int n, int m) {
	//El coste de la función pertenece al orden de O(n*m) siendo n y m las dimensiones de la matriz de entrada
	//ya que en el peor caso (same=true siempre) cada bucle da m y n vueltas respecticamente
	int max = 0, maxaux = 0;
	for (int i = 0; i < m; ++i){
		int j = 1;
		
		bool same = true;
		while (j < n && same){
			
			if (M[j][i] != M[j-1][i])
					same = false;
			++j;
		}
		
		if (same){
			if (maxaux>0 && M[0][i] != M[0][i - 1]){
				if (maxaux > max)
					max = maxaux;
				maxaux = 1;
			}
			else
				++maxaux;
		}
		if (!same || i==m-1) {
			if (maxaux>max)
				max = maxaux;
			maxaux = 0;
		}
	}
	return max;
}


bool resuelveCaso() {
	int n;
	cin >> n;
	if (!std::cin)
		return false;
	int m;
	cin >> m;
	vector<vector<int>> M(n);
	for (int i = 0; i < n; ++i){
		vector<int> v(m);
		for (int &x : v)
			cin >> x;
		M[i] = v;
	}

	int sol = resolver(M, n, m);
	cout <<sol<<'\n';
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	#ifndef DOMJUDGE
	std::ifstream in("C:/Users/Claudia/Desktop/DOBLE/EDA/p11prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif

	return 0;
}