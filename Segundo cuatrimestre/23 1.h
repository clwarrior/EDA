
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
#include <set>
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
	unordered_map<libro, int> libros;
	set<pair<libro, pair<int, int>>> vendiventas; //int vendidos, int ultima venta
	unordered_map<libro, set<pair<libro, pair<int, int>>>::iterator> ventas;
	int numeroVenta;

	void nuevoLibro(int n, const libro & l) {
		if (libros.find(l) != libros.end())
			libros[l] += n;
		else{
			//auto i = pair<libro, pair<int, int>>(l, pair<int, int>(0, 0));
			//vendiventas.insert(i);
			
			libros.insert(pair<libro, int>(l, n));
		}
	}

	void comprar(const libro & l) {
		if (libros.find(l) == libros.end())
			throw std::invalid_argument("Libro no existente.");
		else if (libros[l] == 0)
			throw std::out_of_range("No hay ejemplares.");
		else {
			--libros[l];
			/*auto aux = ventas[l]->second.first;
			++aux; 
			aux = ventas[l]->second.second;
			aux = numeroVenta;*/
			vendiventas[l].second.fi


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
		list<libro> l;
		auto cont = vendiventas.begin();
		for (int i=0; i < 10 && cont!=vendiventas.end(); ++i){
			l.push_back(cont->first);
		}
		return l;
	}
};

#endif