
#ifndef consultorio_h
#define consultorio_h
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>
#include <list>
using namespace std;

class fecha{
private:
	int dia_;
	int hora_;
	int minuto_;
public:
	fecha(int d, int h, int m) { dia_ = d;hora_ = h;minuto_ = m; }

	const int dia(){ return dia_; }
	const int minuto(){ return minuto_;}
	const int hora(){ return hora_; }
	
};

bool operator<(fecha f1, fecha f2){
	if (f1.dia() < f2.dia())
		return true;
	else if (f1.dia() > f2.dia())
		return false;
	else if (f1.hora() < f2.hora())
		return true;
	else if (f1.hora() > f2.hora())
		return false;
	else
		return f1.minuto() < f2.minuto();
}

using medico = std::string;
using paciente = std::string;

class consultorio {

public:
	unordered_map<medico, map<fecha, paciente>> medicos;

	void nuevoMedico(medico const& m) {
		if (medicos.find(m) == medicos.end()) {
			map<fecha, paciente> p;
			medicos.insert(pair<medico, map<fecha, paciente>>(m, p));
		}
	}

	void pideConsulta(paciente p, medico m, fecha f) {
		if (medicos.find(m) == medicos.end())
			throw invalid_argument("Medico no existente");
		else if (medicos[m].find(f) != medicos[m].end())
			throw invalid_argument("Fecha ocupada");
		else
			medicos[m].insert(pair<fecha, paciente>(f, p));
	}

	paciente siguientePaciente(medico m) {
		if (medicos.find(m) == medicos.end())
			throw invalid_argument("Medico no existente");
		else if (medicos[m].empty())
			throw invalid_argument("No hay pacientes");
		else {
			return medicos[m].begin()->second;
		}
		return "";
	}

	void atiendeConsulta(medico m) {
		if (medicos.find(m) == medicos.end())
			throw invalid_argument("Medico no existente");
		else if (medicos[m].empty())
			throw invalid_argument("No hay pacientes");
		else {
			medicos[m].erase(medicos[m].begin());
		}
	}

	list<pair<paciente, fecha>> listaPacientes(medico m, int d) {
		if (medicos.find(m) == medicos.end())
			throw invalid_argument("Medico no existente");
		else {
			list<pair<paciente, fecha>> sol;
			auto i = medicos[m].begin();
			if (!medicos[m].empty()) {
				fecha f = i->first;
				while (f.dia() != d && i != medicos[m].end()) {
					++i;
					if (i != medicos[m].end()) f = i->first;
				}
				while (f.dia() == d && i != medicos[m].end()) {
					sol.push_back(pair<paciente, fecha>(i->second, i->first));
					++i;
					if (i != medicos[m].end()) f = i->first;
				}
			}
			return sol;
		}
		return list<pair<paciente, fecha>>();
	}

};

#endif