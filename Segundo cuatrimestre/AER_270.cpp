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
	int x;
	cin >> x;
	if (x == 0)
		return false;

	map<string, int> m;
	string n, rdo;
	for (int i = 0;i < x;++i) {
		cin.ignore();
		std::getline(std::cin, n);
		cin >> rdo;
		m.insert(pair<string, int>(n, 0));
		if (rdo == "CORRECTO") {
			++m[n];
		}
		else
			--m[n];
	}

	auto i = m.begin();
	while (i != m.end()) {
		if(i->second!=0)
			cout << i->first << ", " << i->second << '\n';
		++i;
	}

	cout <<"---"<<'\n';
	return true;
}

int main() {

	while (resuelveCaso()) {};

	return 0;
}