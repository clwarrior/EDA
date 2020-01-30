
#ifndef _COMPLEJOS
#define _COMPLEJOS

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stdexcept>  // invalid_argument
using namespace std;

class complejos {
private:

	float _real;
	float _complejo;

public:

	// constructoras
	complejos() : _real(0), _complejo(0) {}
	complejos(float r, float c) {
		_real = r;
		_complejo = c;
	}

	// observadoras
	float real() const { return _real; }
	float complejo() const { return _complejo; }

	// operaciones
	complejos operator+(complejos const& n) const {
		return complejos(_real + n._real, _complejo + n._complejo);
	}
	complejos operator*(complejos const& n) const {
		return complejos(_real * n._real - _complejo*n._complejo, _real*n._complejo + n._real*_complejo);
	}

	float modulo() const {
		return sqrt(_real*_real + _complejo*_complejo);
	}
};

#endif