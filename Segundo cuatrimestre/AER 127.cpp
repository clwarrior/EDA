#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#ifndef queue_eda_h
#define queue_eda_h

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class queue {
public:

	// constructor: cola vacía
	queue() : prim(nullptr), ult(nullptr), nelems(0) {}

	// destructor
	~queue() {
		libera(); prim = ult = nullptr;
	}

	// constructor por copia
	queue(queue<T> const& other) : prim(nullptr), ult(nullptr) {
		copia(other);
	}

	// operador de asignación
	queue<T> & operator=(queue<T> const& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	// anadir un elemento al final de la cola
	void push(T const& elem) {
		Nodo* nuevo = new Nodo(elem, nullptr);

		if (ult != nullptr)
			ult->sig = nuevo;
		ult = nuevo;
		if (prim == nullptr) // la cola estaba vacía
			prim = nuevo;
		++nelems;
	}

	// consultar el primero de la cola
	T const& front() const {
		if (empty())
			throw std::domain_error("la cola vacia no tiene primero");
		return prim->elem;
	}

	// eliminar el primero de la cola
	void pop() {
		if (empty())
			throw std::domain_error("eliminando de una cola vacia");
		Nodo* a_borrar = prim;
		prim = prim->sig;
		if (prim == nullptr) // la cola se ha quedado vacía
			ult = nullptr;
		delete a_borrar;
		--nelems;
	}

	// consultar si la cola está vacía
	bool empty() const {
		return nelems == 0;
	};


	void elimContar(int const& ninos, int const&  salto, int const& camas) {
		Nodo* act = this->ult;
		for (int i = 0;i < ninos - camas;++i) {
			for (int j = 0;j < salto;++j) {
				if (act->sig == nullptr) {
					act = this->prim;
				}
				else
					act = act->sig;
			}
			Nodo* next;
			Nodo* aux;
			if (act->sig == nullptr) {
				next = this->prim->sig;
				aux = prim;
				this->prim = prim->sig;
			}
			else if (act->sig->sig == nullptr) {
				aux = ult;
				next = this->prim;
				this->ult = act;
				act->sig = nullptr;
			}
			else {
				aux = act->sig;
				next = act->sig->sig;
				act->sig = next;
			}
			delete aux;
			//act = next;
		}
	};

	void mostrar() {
		Nodo* act = this->prim;
		bool primero = true;
		while (act != nullptr) {
			if (primero) primero = false;
			else cout << ' ';
			string s = act->elem;
			cout << s;
			act = act->sig;
		}
	};

protected:

	/*
	Nodo que almacena internamente el elemento (de tipo T),
	y un puntero al nodo siguiente, que puede ser nullptr si
	el nodo es el último de la lista enlazada.
	*/
	struct Nodo {
		Nodo() : sig(nullptr) {}
		Nodo(T const& elem, Nodo* si = nullptr) : elem(elem), sig(si) {}
		T elem;
		Nodo* sig;
	};

	// punteros al primer y último elemento
	Nodo* prim;
	Nodo* ult;

	// número de elementos en la cola
	size_t nelems;

	void libera() {
		while (prim != nullptr) {
			Nodo* aux = prim;
			prim = prim->sig;
			delete aux;
		}
	}

	void copia(queue const& other) {
		if (other.empty()) {
			prim = ult = nullptr;
			nelems = 0;
		}
		else {
			Nodo* act = other.prim;
			Nodo* ant;
			prim = new Nodo(act->elem);
			ant = prim;
			while (act->sig != nullptr) {
				act = act->sig;
				ant->sig = new Nodo(act->elem);
				ant = ant->sig;
			}
			ult = ant;
			nelems = other.nelems;
		}
	}
};

#endif // queue_eda_h

void resuelveCaso() {
	queue<string> nombres;
	string x;
	cin >> x;
	int tam=0;
	while (x != "F") {
		nombres.push(x);
		cin >> x;
		++tam;
	}
	int camas, pal;
	cin >> camas >> pal;
	
	if(camas>=tam) cout << "TODOS TIENEN CAMA\n";
	else if(camas<=0) cout << "NADIE TIENE CAMA\n";
	
	else {
		nombres.elimContar(tam, pal-1, camas);
		nombres.mostrar();
			cout << '\n';
	}
	}

int main() {


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	return 0;
}