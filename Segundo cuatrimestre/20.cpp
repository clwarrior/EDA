#include "20_consultorio.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;



bool resuelveCaso() {
	int n;
	cin >> n;
	if (!std::cin)
		return false;
	char a; cin.get(a);
	string l, instr, dato, dato2;
	int dia, hora, minuto;
	consultorio c;
	for (int i = 0;i < n;++i) {
		getline(cin, l);
		stringstream ss(l);
		ss >> instr;
		if (instr == "siguientePaciente") {
			ss >> dato;
			try {
				paciente p = c.siguientePaciente(dato);
				cout << "Siguiente paciente doctor " << dato << '\n';
				cout << p << '\n';
			}
			catch (invalid_argument e) {
				cout << e.what() <<'\n';
			}
			cout << "---\n";
		}
		else if (instr == "listaPacientes") {
			ss >> dato >> dia;
			try {
				list<pair<paciente, fecha>> l = c.listaPacientes(dato, dia);
				cout << "Doctor " << dato << " dia "<<dia<<'\n';
				auto i = l.begin();
				while (i != l.end()) {
					cout << i->first << ' ' << setfill('0') << setw(2) << i->second.hora() <<
						':'<< setfill('0') << setw(2) << i->second.minuto() << '\n';
					++i;
				}
			}
			catch (invalid_argument e) {
				cout << e.what() <<'\n';
			}
			cout << "---\n";
		}
		else if (instr == "atiendeConsulta") {
			ss >> dato;
			try {
				c.atiendeConsulta(dato);
			}
			catch (invalid_argument e) {
				cout << e.what() <<'\n';
				cout << "---\n";
			}
		}
		else if (instr == "nuevoMedico") {
			ss >> dato;
			c.nuevoMedico(dato);
		}
		else if (instr == "pideConsulta") {
			ss >> dato >> dato2 >> dia >> hora >> minuto;
			fecha f(dia, hora, minuto);
			try {
				c.pideConsulta(dato, dato2, f);
			}
			catch (invalid_argument e) {
				cout<<e.what() <<'\n';
				cout << "---\n";
			}
		}
	}
	cout << "------\n";
	return true;

}

int main() {
	while (resuelveCaso())
		;
	return 0;
}