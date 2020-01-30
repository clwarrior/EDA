#include "treemap_eda.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


void show(map<string, int> const& m){
	auto i = m.begin();
	while (i != m.end()){
		cout << i->clave<<' ';
		++i;
	}
	cout << '\n';
}
void resuelveCaso() {
	map<string, int> d;
	string line;
	getline(cin, line);
	stringstream ss(line);
	string clave;
	int valor;
	while (ss >> clave >> valor) {
		map<string, int> ::clave_valor cv = map<string, int> ::clave_valor(clave, valor);
		d.insert(cv);
	}
	getline(cin, line);
	stringstream sss(line);
	map<string, int> added;
	map<string, int> modified;
	while (sss >> clave) {
		sss >> valor;
		map<string, int> ::clave_valor cv = map<string, int> ::clave_valor(clave, valor);
		if (d.contains(clave)){
			if (d.at(clave) != valor)
				modified.insert(cv);
			d.erase(clave);
		}
		else
			added.insert(cv);
	}
	if (!added.empty()){
		cout << "+ ";
		show(added);
	}
	if (!d.empty()){
		cout << "- ";
		show(d);
	}
	if (!modified.empty()){
		cout << "* ";
		show(modified);
	}
	if (added.empty() && d.empty() && modified.empty())
		cout << "Sin cambios\n";
	cout << "----\n";
	
}

int main() {

	int numCasos;
	std::cin >> numCasos;
	char a; cin.get(a);
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	return 0;
}