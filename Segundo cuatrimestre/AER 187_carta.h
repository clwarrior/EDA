
#ifndef _carta
#define _carta

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument
using namespace std;

class carta {
private:
	char palo;
	int valor;
public:
   // constructoras
	carta(char p, int v) {
		palo = p;
		valor = v;
	}
	char getPalo() const { return palo; }
	int getValor() const { return valor; }

   // operador de comparacion
   bool operator<(carta const& c) const {
	   return valor < c.getValor();
   }
   
   // leer y escribir
   void read(std::istream & input = std::cin) {
      int v; char p;
      input >> v >> p;
	  valor = v;
	  palo = p;
   }
};

inline istream & operator>>(istream & entrada, carta & h) {
   h.read(entrada);
   return entrada;
}

#endif
