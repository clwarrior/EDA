// Grupo XYZ, Fulano y Mengano
#include <iostream>
#include <vector>
using namespace std;

void resuelveCaso() {

	int length;
	cin >> length;
	vector<int> t(length);
	for (int &x : t)
		cin >> x;
	int peak = 0, valley = 0;
	//complejidad lineal, O(n)
	//recorremos el vector una vez comparando cada valor con en anterior y el siguiente
	//P : {10000>=length>=0 ^ forall t[i] : 0<=i<length : -50 <= t[i] <= 60 ^ peak=0 ^ valley=0}
	for (int i = 1; i < length - 1; ++i){
		if (t[i] > t[i + 1] && t[i] > t[i - 1])
			peak += 1;
		else if (t[i] < t[i + 1] && t[i] < t[i - 1])
			valley += 1;
	}
	//Q : {valley = # i : 0<=i<length : t[i-1]>t[i]<t[i+1] : t[i] ^ peak = # j : 0<=j<length : t[j-1]<t[j]>t[j+1] : t[j]}
	cout << peak << ' ' << valley << '\n';
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}