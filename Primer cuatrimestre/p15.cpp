#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Coste: lineal respecto del numero de entrada,
// se llama a la función recursivamente n veces y el coste de cada ejecucucion es cte
// construimos la serie de fibonacci hasta n en el vector auxiliar usado como memoria auxiliar
// partiendo de los casos base n=0 y n=1.

//VERSION NO FINAL
long long int fibonacci(int n, vector<long long int> & v){
	if (n == 0){
		v.emplace_back(0);
		return 0;
	}
	if (n == 1){
		fibonacci(n - 1, v);
		v.emplace_back(1);
		return 1;
	}
	else{
		fibonacci(n - 1, v);
		v.emplace_back(v[n - 2] + v[n - 1]);
		return v[v.size() - 1];
	}
}



	bool resuelveCaso() {
		int a;
		cin >> a;
		if (!std::cin)
			return false;
		vector<long long int> v;
		long long int sol = fibonacci(a, v);

		cout << sol << '\n';


		return true;

	}
	int main(){
/*#ifndef DOMJUDGE
		std::ifstream in("C:/Users/Claudia/OneDrive/UNIVERSIDAD/DOBLE/EDA/Juez/p15prueba.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif */


		while (resuelveCaso())
			;

/*#ifndef DOMJUDGE 
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
#endif*/
		return 0;
	}