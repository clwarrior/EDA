#include "treemap_eda.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


void show (vector<pair<int, string>> const& v) {
	auto i = v.end();
	--i;
	while (i != v.begin()) {
		cout << i->second << ' '<<i->first <<'\n';
		--i;
	}
	cout << i->second << ' ' << i->first << '\n';
}

class comparador{
public:
	bool operator() (const pair<int, string> & a, const pair<int, string> & b){
		if (a.first < b.first)
			return true;
		else if (a.first == b.first)
			return a.second > b.second;
		else
			return false;
	}
};

bool resuelveCaso() {
	map<string, map<string, int>> d;
	map<string, int> a;
	string x, deporte;
	cin >> x;
	if (!cin)
		return false;
	while (x != "_FIN_") {
		if (isupper(x[0])) {
			deporte = x;
			d.insert(x);
			cin >> x;
			while (islower(x[0])) {
				if (!d[deporte].contains(x)) {
					if (!a.contains(x)) {
						d[deporte].insert(x);
						a.insert(x);
					}
					else if (a.at(x) == 0) {
						auto i = d.begin();
						while (i != d.end()) {
							i->valor.erase(x);
							++i;
						}
						++a[x];
					}
				}
				cin >> x;
			}
		}
	}
	vector<pair<int, string>> v;
	
	auto i = d.begin();
	while (i != d.end()) {
		v.emplace_back(i->valor.size(), i->clave);
		++i;
	}
	sort(v.begin(), v.end(), comparador());
	show(v);
	cout << "***\n";
	return true;
}

int main() {

	while (resuelveCaso()) {
	};

	return 0;
}