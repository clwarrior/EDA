#include <iostream>
#include <vector>
using namespace std;

int resolver(int n, int t, vector<int> v) {
	//O(f(n))=n
	//coste lineal, ya que hay varios bucles, pero no estan anidados
	int a = -1, b = -1;
	//primero acumulo en un vector aux las posiciones de los intervalos que son candidatos a solucion
	//los voy manejando con los contadores a y b
	vector<int> aux;
	for (int i = 0; i < n; ++i){
		if (v[i] > t){
			if (a == -1){
				a = i;
				b = i;
			}
			else b += 1;
		}
		else if (a != -1) {
			aux.emplace_back(a);
			aux.emplace_back(b);
			a = -1;
			b = -1;
		}
	}
	//me aseguro de que si este intervalo acaba en la ultima posicion este incluido
	if (a != -1) {
		aux.emplace_back(a);
		aux.emplace_back(b);
	}
	//y ahora teniendo en cuenta la forma en que guarde los intervalos, compruebo que suecuencia es mas larga
	int max = -1;
	int sol1=0, sol2=0;
	for (int i = 0; i < aux.size()-1; ++++i){
		if (aux[i + 1] - aux[i]>max){
			max = aux[i + 1] - aux[i];
			sol1 = aux[i];
			sol2 = aux[i + 1];
		}
	}
	cout << sol1 <<' '<< sol2<<'\n';
	return 0;
}
void resuelveCaso() {
	int n, t;
	cin >> n >> t;
	vector<int> v(n);
	for (int &x : v)
		cin >> x;
	resolver(n, t, v);
}

int main() {

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}