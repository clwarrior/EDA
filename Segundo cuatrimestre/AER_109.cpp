#include <map>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <cctype>
using namespace std;


/*void show(map<string, vector<int>> const& m) {
	auto i = m.begin();
	while (i != m.end()) {
		cout << i->clave << ' ';
		for (int j = 0;j < i->valor.size();++j) {
			cout << i->valor[j] << ' ';
		}
		++i;
		cout << '\n';
	}
}*/

bool resuelveCaso() {
	string x, y;
	int rdox, rdoy, npartidos=0;
	cin >> x;
	if (x == "FIN")
		return false;

	map<string, int> m;
	cin >> x;
	while (x != "FIN") {
		++npartidos;
		cin >> rdox >> y >> rdoy;
		m.insert(pair<string, int>(x, 0));
		m.insert(pair<string, int>(y, 0));
		if (rdox > rdoy) {
			m[x]+=2;
			++m[y];
		}
		else {
			++m[x];
			m[y]+=2;
		}
		cin >> x;
	}

	auto i = m.begin();
	string max = i->first;
	int maxi = i->second;
	++i;
	while (i != m.end()) {
		if (i->second > maxi) {
			max = i->first;
			maxi = i->second;
		}
		else if(i->second == maxi) {
			max = "EMPATE";
		}
		++i;
	}

	cout <<max<<' '<< m.size()*(m.size() - 1) - npartidos<<'\n';
	return true;
}

int main() {

	while (resuelveCaso()) {};

	return 0;
}