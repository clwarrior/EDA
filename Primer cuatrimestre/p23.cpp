// Claudia Guerrero (DG07)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;



//Funci�n recursiva que dado un vector y una posici�n de inicio y de fin para su an�lisis devuelve un booleano que indica si est�
//o no parcialmente ordenado. Tiene adem�s un par de par�metros por referencia donde a la llamada de cada funci�n guardamos el maximo
//y el minimo en ese subintervalo para poder usarlo al deshacer las llamadas recursivas

//Coste recurrencia: T(n) = {cte1				si n=1} siendo n = ini-fin = tama�o del vector a analizar en esa llamada recursiva
//							{2*T(n/2) + cte2	si n>1}
bool semiord(vector<int>const& v, int ini, int fin, int & min, int & max) {
	if (ini + 1 == fin){
		if (v[ini] < v[fin]){
			min = v[ini];
			max = v[fin];
		}
		else{
		max = v[ini];
		min = v[fin];
		}
		return v[ini] <= v[fin];
	}
	else{
		//llamamos a la funcion sobre la mitad izda y sobre la dcha
		int minI, minD, maxI, maxD;
		bool ok1 = semiord(v, ini, (fin + ini) / 2, min, max);
		minI = min;
		maxI = max; //Guardamos los valores del maximo y el minimo en la parte izda para no sobreescribirlos
									// al llamar a la funci�n sobre la parte derecha
		bool ok2 = semiord(v, (fin+ini) / 2 + 1, fin, min, max);
		minD = min;
		maxD = max;
		min = minI;
		max = maxD;
		return minI <= minD && maxI <= max && ok1 && ok2;
	}
}


bool resuelveCaso() {
	vector<int> v;
	int x;
	cin >> x;
	while (x!=0) {
		v.emplace_back(x);
		cin >> x;
	}
	if (v.size()==0)
		return false;
	if (v.size() == 1){
		cout << "SI\n";
		return true;
	}
	int a=0, b=0;
	bool sol = semiord(v, 0, v.size()-1, a, b);
	
	if (sol)
		cout << "SI\n";
	else
		cout << "NO\n";
	return true;

}

int main() {
	
#ifndef DOMJUDGE
	std::ifstream in("C:/Users/Claudia/OneDrive/UNIVERSIDAD/DOBLE/EDA/Juez/p23EntradaEjemplo.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 


	while (resuelveCaso())
		;


	
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif 

	return 0;
}