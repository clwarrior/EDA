#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct intervalo {
	int inicio, fin;
};

istream& operator >> (istream& in, intervalo& p) {
	in >> p.inicio >> p.fin;
	return in;
}

bool operator== (intervalo const& p1, intervalo const& p2) {
	return p1.inicio == p2.inicio && p1.fin == p2.fin;
}

//Para ordenar soluciones
class comp {
public:
	bool operator()(vector<intervalo> const& v1, vector<intervalo> const& v2) {
		int i = 0;
		while (i < v1.size() && i < v2.size() && v1[i] == v2[i]) ++i;
		if (i < v1.size() && i < v2.size() && !(v1[i] == v2[i])) {
			if (v1[i].inicio < v2[i].inicio) return true;
			else if (v1[i].inicio > v2[i].inicio) return false;
			else if (v1[i].fin < v2[i].fin) return true;
			else if (v1[i].fin >= v2[i].fin) return false;
		}
		if (i < v1.size() || v1.size() == v2.size()) return false;
		else return true;
	}
};


void print(intervalo i) {
	cout << '[' << i.inicio << ", " << i.fin << "] ";
}

void resolver(vector<intervalo> const& v, int const r, vector<vector<intervalo>> & m, vector<intervalo> & aux, int ini) {
	for (int i = ini;i < v.size();++i) {
		bool compatible=false;
		for (int j = 0;j < aux.size();++j) {
			compatible = aux[j].fin < v[i].inicio;
		}
		if (compatible || aux.size() == 0) {
			aux.emplace_back(v[i]);
			if (aux.size() >= r)
				m.emplace_back(aux);
			resolver(v, r, m, aux, ++ini);
			aux.pop_back();
		}
	}
}


bool resuelveCaso() {
	int n, r;
	cin >> n >> r;
	if (!std::cin)
		return false;

	vector<intervalo> v(n);
	for (intervalo& x : v)
		cin >> x;
	vector<intervalo> aux;
	vector < vector<intervalo>> m;
	resolver(v, r, m, aux, 0);

	sort(m.begin(), m.end(), comp());
	
	cout << m.size() << '\n';
	for (int i = 0;i < m.size();++i) {
		for (int j = 0;j < m[i].size();++j) {
			cout << '[' << m[i][j].inicio << "," << m[i][j].fin << "]";
		}
		cout << '\n';
	}
	return true;

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("C:/Users/Claudia/OneDrive/UNIVERSIDAD/DOBLE/EDA/Juez/p32.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 


	while (resuelveCaso())
		;

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}