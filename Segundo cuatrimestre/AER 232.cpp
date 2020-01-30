#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <fstream>
#include <iomanip>
using namespace std;

//cjto .h
#ifndef _FECHA
#define _FECHA

int diasMes(int mes) {
	int numDiasMes = 0;
	switch (mes) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		numDiasMes = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		numDiasMes = 30;
		break;
	case 2:
		numDiasMes = 28;
		break;
	}
	return numDiasMes;
}

class fecha {
private:
	int _dia;
	int _mes;
	int _anyo;

public:
	// constructoras
	fecha() : _dia(0), _mes(0), _anyo(0) {}

	fecha(int d, int m, int a) {
		_dia = d; _mes = m; _anyo = a;
	}

	// observadoras
	int dia() const { return _dia; }
	int mes() const { return _mes; }
	int anyo() const { return _anyo; }

	// leer y escribir

	void read(std::istream & input = std::cin) {
		int d, m, a;
		input >> d >> m >> a;
		_dia = d; _mes = m; _anyo = a;
	}

	bool aniversario(fecha const& f) const {
		return _dia == f._dia && _mes == f._mes;
	}
	bool operator<(fecha const& f) const {
		if (_mes < f._mes) return true;
		else if (_mes == f._mes) return _dia < f._dia;
		else return false;
	}


	int diasHastaFecha() const {
		int dias = _dia;
		for (int i = 1 ;i < _mes; ++i) {
			dias += diasMes(i);
		}
		return dias;
	}
};


inline istream & operator >> (istream & entrada, fecha & f) {
	f.read(entrada);
	return entrada;
}

#endif


//cjto .cpp

// O(1)
bool resuelveCaso() {
	fecha nacimiento, actual;
	cin >> nacimiento >> actual;;
   
   if (nacimiento.dia() == 0)  // no hay más casos
      return false;
   
   if (nacimiento.aniversario(actual))
	   cout << 0;
   else {
	   int sol;
	   if (nacimiento < actual) {
		   cout<< 364 * (actual.anyo() - nacimiento.anyo()) + actual.diasHastaFecha() - nacimiento.diasHastaFecha();
	   }
	   else 
		   cout<< 364 * (actual.anyo() - nacimiento.anyo()) - nacimiento.diasHastaFecha() + actual.diasHastaFecha()+1;
   }

   cout <<"\n";
   return true;
}

int main() {   
   while (resuelveCaso());
   return 0;
}
