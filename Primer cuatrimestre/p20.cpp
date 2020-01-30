#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Coste : T(n) = {cte1				si n=0} 
//				 {T(n-1) + cte2		si n>0}
//siendo n = tamaño del vector de naves desordenado empezando por la derecha
//siendo cte2 <= n

int resolver(vector<int>& v, int pos, int& cont) {

}


bool resuelveCaso() {
	int numNaves;
	cin >> numNaves;
	vector<int> naves(numNaves);
	for (int &x : naves)
		cin >> x;
	if (!std::cin)
		return false;
	int cont = 0;
	int sol = resolver(naves, 0, cont);
	cout << sol << "\n";

	return true;

}

int main() {


	while (resuelveCaso())
		;


	return 0;
}