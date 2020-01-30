
#ifndef _HORAS
#define _HORAS

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdexcept>  // invalid_argument
using namespace std;

class horas {
private:
   int _hora;
   int _minuto;
   int _segundo;
   static bool check(int h, int m, int s) {
      return 0 <= h && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60;
   }
public:
   // constructoras
   horas() : _hora(0), _minuto(0), _segundo(0){}
   
   horas(int h, int m, int s) {
      if (check(h, m, s)) {
         _hora = h; _minuto = m; _segundo = s;
      }
      else
         throw invalid_argument("argumentos incorrectos para una hora");
   }
   
   // observadoras
   int hora() const { return _hora; }
   int minuto() const { return _minuto; }
   int segundo() const { return _segundo; }
   
   // operador de comparacion
   bool operator<(horas const& h) const {
      if (_hora < h._hora) return true;
      else if (h._hora < _hora) return false;
      else if (_minuto < h._minuto) return true;
      else if (h._minuto < _minuto) return false;
      else return _segundo < h._segundo;
   }

   //operador de igualdad
   bool operator==(horas const& h) const {
	   return _hora == h._hora && _minuto == h._minuto && _segundo == h._segundo;
   }

   // operador de suma
   horas operator+(horas const& h) const {
	   horas sol;
	   sol._segundo = (_segundo + h._segundo) % 60;
	   sol._minuto = (_minuto + h._minuto + (_segundo + h._segundo) / 60) % 60;
	   sol._hora = (_hora + h._hora + ((_minuto + h._minuto + (_segundo + h._segundo) / 60) / 60));
	   if (sol._hora >= 24) {
		   throw out_of_range("suma de horas excede dia actual");
	   }
	   return sol;
   }
   
   // leer y escribir
   
   void read(std::istream & input = std::cin) {
      int h, m, s; char c;
      input >> h >> c >> m >> c >> s;
      if (check(h, m, s)) {
         _hora = h; _minuto = m; _segundo = s;
      }
      else
         throw invalid_argument("argumentos incorrectos para una hora");
      
   }
   void print(std::ostream& o = std::cout) const {
      o << setfill('0') << setw(2) << _hora << ':'
      << setfill('0') << setw(2) << _minuto << ':'
      << setfill('0') << setw(2) << _segundo;
   }
};
#endif

#ifndef _PELICULA
#define _PELICULA

class pelicula {
private:
	string _nombre;
	horas _horaComienzo;
	horas _duracion;
public:
	pelicula() : _nombre(""), _horaComienzo(horas()), _duracion(horas()) {}
	pelicula(string n, horas hc, horas d) {
		_nombre = n;
		_horaComienzo = hc;
		_duracion = d;
	}
	// observadoras
	horas horaComienzo() const { return _horaComienzo; }
	horas duracion() const { return _duracion; }
	string nombre() const {	return _nombre; }

	bool operator<(pelicula const& p) const {
		if (horaComienzo() + duracion() < p.horaComienzo() + p.duracion())
			return true;
		else if (_horaComienzo + _duracion == p._horaComienzo + p._duracion) {
			return _nombre < p._nombre;
		}
		else return false;
	}
};

// los operadores de inserción y extracción no son métodos
// se declaran inline para poder ponerlos en el .h
inline ostream & operator<<(ostream & salida, horas const& h) {
   h.print(salida);
   return salida;
}

inline istream & operator>>(istream & entrada, horas & h) {
   h.read(entrada);
   return entrada;
}

#endif
