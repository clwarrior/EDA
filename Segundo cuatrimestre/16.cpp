#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

//Coste O(logn)
void resuelveCaso() {
	int ncap;
	cin >> ncap;
	int n;
	int maxi = 0, maxaux=0;
	map<int, int> m; //numero de capitulo, ultima aparicion
	for (int i = 0;i < ncap;++i) {
		cin >> n;
		if (m.find(n)!=m.end()) {
			if (m[n] >= i - maxaux)
				maxaux = min(maxaux, (i - m[n]));
			else
				++maxaux;
			m[n] = i;
		}
		else {
			m.insert(pair<int, int>(n, i));
			++maxaux;
		}
		if (maxaux > maxi)
			maxi = maxaux;
		
	}
	
	cout << maxi << '\n';

}

int main() {

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	return 0;
}