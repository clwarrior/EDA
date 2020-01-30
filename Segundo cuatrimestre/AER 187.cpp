//Claudia Guerrero García-Heras (DG07)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

#ifndef stack_eda_h
#define stack_eda_h

#include <stdexcept>

template <class T>
class stack {
	static const int TAM_INICIAL = 10; // tamaño inicial del array dinámico
public:

	// constructor: pila vacía
	stack() : nelems(0), capacidad(TAM_INICIAL), array(new T[capacidad]) {}

	// destructor
	~stack() {
		libera();
	}

	// constructor por copia
	stack(stack<T> const& other) {
		copia(other);
	}

	// operador de asignación
	stack<T> & operator=(stack<T> const& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	// apilar un elemento
	void push(T const& elem) {
		if (nelems == capacidad)
			amplia();
		array[nelems] = elem;
		++nelems;
	}

	// consultar la cima
	T const& top() const {
		if (empty())
			throw std::domain_error("la pila vacia no tiene cima");
		return array[nelems - 1];
	}

	// desapilar el elemento en la cima
	void pop() {
		if (empty())
			throw std::domain_error("desapilando de la pila vacia");
		--nelems;
	}

	// consultar si la pila está vacía
	bool empty() const {
		return nelems == 0;
	}

protected:

	// número de elementos en la pila
	size_t nelems;

	// tamaño del array
	size_t capacidad;

	// puntero al array que contiene los datos
	T * array;

	void libera() {
		delete[] array;
		array = nullptr;
	}

	void copia(stack const& other) {
		capacidad = other.nelems;
		nelems = other.nelems;
		array = new T[capacidad];
		for (size_t i = 0; i < nelems; ++i)
			array[i] = other.array[i];
	}

	void amplia() {
		T * viejo = array;
		capacidad *= 2;
		array = new T[capacidad];

		for (size_t i = 0; i < nelems; ++i)
			array[i] = std::move(viejo[i]);

		delete[] viejo;
	}
};

#endif // stack_eda_h

#ifndef queue_eda_h
#define queue_eda_h

#include <stdexcept>

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

	// añadir un elemento al final de la cola
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
	}

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

#ifndef _carta
#define _carta

class carta {
private:
	char palo;
	int valor;
public:
	bool siguiente(carta const & c) const {
		return palo == c.getPalo() && ((valor == c.getValor() + 1 && valor != 10 ) || (valor == c.getValor() + 3 && valor == 10));
	}
	// constructoras
	carta() : palo('N'), valor(0) {}
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

inline istream & operator >> (istream & entrada, carta & h) {
	h.read(entrada);
	return entrada;
}

#endif



bool resuelveCaso() {
	//lectura
	int palos;
	cin >> palos;
	if (palos==0)
		return false;
	queue<carta> mazo;
	for (int i = 0; i < palos * 10;++i) {
		carta c;
		cin >> c;
		mazo.push(c);
	}
	//juego
	stack<carta> visibles;
	vector<stack<carta>> v;
	stack<carta> O;
	stack<carta> C;
	stack<carta> E;
	stack<carta> B;
	v.emplace_back(O);
	v.emplace_back(C);
	v.emplace_back(E);
	v.emplace_back(B);
	bool gana=false, vueltamazo=false;
	while (!vueltamazo && !gana) {
		vueltamazo = true;
		while (!mazo.empty()) {
			//intentamos colocar todas las cartas visibles posibles
			bool puesto = true;
			while (puesto && !visibles.empty()) {
				puesto = false;
				for (int i = 0;i < 4;++i) {
					if (visibles.top().siguiente(v[i].top())) {
						v[i].push(visibles.top());
						visibles.pop();
						puesto = true;
						vueltamazo = false;
					}
				}
			}
			//levantamos dos
			visibles.push(mazo.front());
			mazo.pop();
			if (!mazo.empty()) {
				visibles.push(mazo.front());
				mazo.pop();
			}
		}
		stack<carta> stackaux;
		while (!visibles.empty()) {
			stackaux.push(visibles.top());
			visibles.pop();
		}
		queue<carta> newmazo;
		while (!stackaux.empty()) {
			mazo.push(stackaux.top());
			stackaux.pop();
		}
		gana = (visibles.empty() && mazo.empty());
	}
	if (vueltamazo)
		cout << "PIERDE\n";
	else if (gana)
		cout << "GANA\n";
	else
		cout<<"wtf\n";
	return true;

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
	while (resuelveCaso())
		;

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}