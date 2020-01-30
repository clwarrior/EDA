//Pablo Hidalgo Palencia (DG12) y Claudia Guerrero García-Heras (DG07)

#include "8_persona.h"
#include "8_list_guay.h"

#include <iostream>
using namespace std;

//Coste O(n)
void caso(int num, int emin, int emax){
	listaguay<persona> lista;
	//lectura, coste lineal
	for (int i = 0; i < num; ++i){
		string p;
		int x;
		cin >> x;
		getline(cin, p);
		int pos = p.find(' ');
		string nom = (p.substr(pos+1, p.size()));
		persona nuevo = persona(x, nom);
		lista.push_back(nuevo);
	}
	//eliminacion, coste lineal
	lista.remove_if(
		[emin, emax] (persona p){
		return p.getEdad() >= emin && p.getEdad() <= emax;
	});
	//mostrar rdo, coste lineal
	lista.mostrar();
	cout << "---\n";
}

int main(){
	int num, emin, emax;
	cin >> num >> emin >> emax;
	while (num != 0 || emin != 0 || emax != 0){
		caso(num, emin, emax);
		cin >> num >> emin >> emax;

	}
	return 0;
};