//Claudia Guerrero García-Heras (DG07)

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int suma(int s, vector<int> & v, vector<vector<int>> & m, int n){
	//Caso base en el cual, lo que queremos sumar es cero, esto va a ser siempre una combinacion posible
	if (s == 0){
		if(m[s][n] == -1)
			m[s][n] = 1;
		return m[s][n];
	}
	//Caso base en que hallamos llegado al primer numero del vector, diferenciamos entre si el mismo es la
	//cantidad que queremos sumar o no
	if (n == 0){
		if (m[s][n] == -1){
			if (v[n] == s)
				m[s][n] = 1;
			else
				m[s][n] = 0;
		}
		return m[s][n];
	}
	//Caso recursivo 1, en el tratamos la opcion de que el numero que estamos tratando sea mayor que el que queremos
	//sumar, por tanto, solo haría falta una llamada recursiva, ya que ese numero no le tendriamos en cuenta
	else if (s - v[n] < 0){
		if (m[s][n - 1] == -1)
			m[s][n - 1] = suma(s, v, m, n - 1);
		return m[s][n - 1];
	}
	//Caso recursivo 2, caso total en el que calculamos todas las combinaciones posibles
	else{
		if (m[s][n - 1] == -1)
			m[s][n - 1] = suma(s, v, m, n - 1);

		if (m[s - v[n]][n - 1] == -1)
			m[s - v[n]][n - 1] = suma(s-v[n], v, m, n - 1);

		return m[s][n - 1] + m[s - v[n]][n - 1];
	}
}


bool resuelveCaso() {
	long int num, s;
	cin >> num >> s;

	if (!std::cin)
		return false;

	vector<int> v(num);
	for (int &x : v)
		cin >> x;
	vector<vector<int>> m(s+1, vector<int>(num));
	for (int i = 0; i < num; ++i){
		for (int j = 0; j <= s; ++j){
				m[j][i] = -1;
		}
	}
	int sol=0;
	if (v.size() != 0)
		sol = suma(s, v, m, v.size() - 1);
	cout << sol << '\n';
	return true;

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("C:/Users/Claudia/OneDrive/UNIVERSIDAD/DOBLE/EDA/Juez/p17prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 

	
	while (resuelveCaso())
		;

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
#endif

	return 0;
}