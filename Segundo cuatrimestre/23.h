
#ifndef consultorio_h
#define consultorio_h
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <list>
using namespace std;


using libro = std::string;


class comparador {
public:
	bool operator() (const pair<libro, pair<int, int>> & a, const pair<libro, pair<int, int>> & b) {
		if (a.second.first < b.second.first) return true;
		else if (a.second.first > b.second.first) return false;
		else if (a.second.second > b.second.second) return true;
		else return false;
	}
};

class libreria {

public:
	std::unordered_map<libro, int> libros;
	std::unordered_map<libro, pair<int, int>> ventas; //int vendidos, int ultima venta
	int numeroVenta;

	void nuevoLibro(int n, const libro & l) {
		if (libros.find(l) != libros.end())
			libros[l] += n;
		else
			libros.insert(std::pair<libro, int>(l, n));
	}

	void comprar(const libro & l) {
		if (libros.find(l) == libros.end())
			throw std::invalid_argument("Libro no existente.");
		else if (libros[l] == 0)
			throw std::out_of_range("No hay ejemplares.");
		else {
			--libros[l];
			++ventas[l].first; //
			ventas[l].second = numeroVenta;
			++numeroVenta;
		}
	}

	bool estaLibro(const libro & l) {
		return libros.find(l) != libros.end();
	}

	void elimLibro(const libro & l) {
		libros.erase(l); //
	}

	int numEjemplares(const libro & l) {
		if (libros.find(l) == libros.end())
			throw std::invalid_argument("Libro no existente.");
		else
			return libros[l];
	}

	list<libro> top10() {
		std::vector<pair<libro, pair<int, int>>> top;
		auto i = ventas.begin();
		while (i != ventas.end()) {
			top.emplace_back(*i);
			++i;
		}
		sort(top.begin(), top.end(), comparador());
		list<libro> l;
		for (int i = top.size()-1; i < 10 && i >= 0; --i){
			l.push_back(top[i].first);
		}
		return l;
	}
};

#endif