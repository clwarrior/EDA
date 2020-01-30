#include <string>
#include <iostream>
using namespace std;

#ifndef PERSONA
#define PERSONA
class persona {
private:
	string _nombre;
	int _edad;
public:
	persona() : _edad(0), _nombre() {}
	persona(int e, string n) : _edad(e), _nombre(n) {}
	string getNombre() const {
		return _nombre;
	}
	int getEdad() const {
		return _edad;
	}
};

inline ostream & operator<<(ostream & flujo, persona const & p){
	flujo << p.getNombre() << '\n';
	return flujo;
}
#endif