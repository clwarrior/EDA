
#ifndef _POLINOMIO
#define _POLINOMIO

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <stdexcept>  // invalid_argument
using namespace std;

class monomio {
public:
	int exponente;
	int coeficiente;
	bool operator<(monomio & m) {
		return exponente < m.exponente;
	}
	monomio() {
		exponente = 0;
		coeficiente = 0;
	}
	monomio(int c, int e) {
		coeficiente = c;
		exponente = e;
	}
};
class polinomio {
private:
	vector<monomio> _poli;
public:
   polinomio() : _poli(){}
   
   polinomio(vector<monomio> const& p) {
	   _poli = p;
   }
   
   

   void add(monomio & m) {
	   _poli.emplace_back(monomio());

	   if (_poli.size() == 1) {
		   _poli[0] = m;
	   }

	   else {
		   int pos = 0;
		   while (pos < _poli.size()-1 && _poli[pos] < m) {
			   ++pos;
		   }
		   for (int i = _poli.size()-1;i > pos;--i) {
			   _poli[i] = _poli[i - 1];
		   }
		   _poli[pos] = m;
	   }
   }

   int evalua(int valor) const {
	   int sol=0;
	   for (int i = 0;i < _poli.size();++i) {
		   sol += pow(valor, _poli[i].exponente) * _poli[i].coeficiente;
	   }
	   return sol;
   }
};



#endif
