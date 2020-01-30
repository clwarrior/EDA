//Claudia Guerrero(DG07)

#include <iostream>
#include<vector>
using namespace std;

//Coste: O(log n) siendo n el tamaño del vector de entrada ya que en cada llamada recursiva reducimos el tamaño
//del vector de entrada a analizar (controlado por ini y fin) a la mitad
//T(n)={cte1 si ini=fin; T(n/2)+cte2 si ini !=fin}
//
//Sean n = tamaño del vector de entrada
//P : {exist w : 0 <= w <= n : (forall k : 0 <= k < w : v[k]>v[k+1]) and (forall j : w <= j < n : v[j]<v[j+1])}
//fun minim(vector<int> v, int ini, int fin) return m
//Q : {r = min(i : 0 <= i < n : v[i]}

int minim(vector<int>& v, int ini, int fin){
	if (ini == fin)
		return v[ini];
	else{
		int m = (ini + fin) / 2;
		if (v[m] > v[m + 1])
			minim(v, m + 1, fin);
		else
			minim(v, ini, m);
	}
}

bool resuelveCaso() {
	int num;
	cin >> num;
	vector<int> v(num);
	for (int &x : v)
		cin >> x;
	if (!std::cin)
		return false;

	int sol = minim(v, 0, v.size()-1);
	cout << sol<<'\n';

	return true;
}



int main(){
	while (resuelveCaso())
		;
	return 0;
}