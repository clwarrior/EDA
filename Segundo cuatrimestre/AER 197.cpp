#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//
//  deque_eda.h
//
//  Implementación del TAD cola doble con nodos doblemente enlazados
//  y nodo fantasma (circular)
//
//  Estructuras de Datos y Algoritmos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Created by Alberto Verdejo on 6/12/16.
//  Copyright (c) 2016 Alberto Verdejo. All rights reserved.
//

#ifndef deque_eda_h
#define deque_eda_h


#include <stdexcept>
#include <cassert>

template <class T>
class deque {
public:

	// constructor: cola doble vacía
	deque() : fantasma(new Nodo()), nelems(0) {
		fantasma->sig = fantasma;
		fantasma->ant = fantasma;
	}

	// destructor
	~deque() {
		libera();
	}

	// constructor por copia
	deque(deque<T> const& other) : fantasma(nullptr) {
		copia(other);
	}

	// operador de asignación
	deque<T> & operator=(deque<T> const& that) {
		if (this != &that) {
			libera();
			copia(that);
		}
		return *this;
	}

	// operador de comparación
	bool operator==(deque<T> const& that) const {
		if (nelems != that.nelems)
			return false;
		Nodo* p1 = fantasma->sig;
		Nodo* p2 = that.fantasma->sig;
		while ((p1 != fantasma) && (p2 != that.fantasma)) {
			if (p1->elem != p2->elem)
				return false;
			p1 = p1->sig;
			p2 = p2->sig;
		}
		return (p1 == fantasma) && (p2 == that.fantasma);
	}

	bool operator!=(deque<T> const& that) const {
		return !(*this == that);
	}

	// añadir un elemento por el principio
	void push_front(const T &e) {
		inserta_elem(e, fantasma, fantasma->sig);
		++nelems;
	}

	// añadir un elemento por el final
	void push_back(const T &e) {
		inserta_elem(e, fantasma->ant, fantasma);
		++nelems;
	}

	// consultar el primer elemento de la dcola
	T const& front() const {
		if (empty())
			throw std::domain_error("la dcola vacia no tiene primero");
		return fantasma->sig->elem;
	}

	// consultar el último elemento de la dcola
	T const& back() const {
		if (empty())
			throw std::domain_error("la dcola vacia no tiene ultimo");
		return fantasma->ant->elem;
	}

	// eliminar el primer elemento
	void pop_front() {
		if (empty())
			throw std::domain_error("eliminando el primero de una dcola vacia");
		borra_elem(fantasma->sig);
		--nelems;
	}

	// elminar el último elemento
	void pop_back() {
		if (empty())
			throw std::domain_error("eliminando el ultimo de una dcola vacia");
		borra_elem(fantasma->ant);
		--nelems;
	}

	// consultar si la dcola está vacía
	bool empty() const {
		return nelems == 0;
	}

	// consultar el tamaño de la dcola
	size_t size() const {
		return nelems;
	}

protected:
	/*
	Nodo que almacena internamente el elemento (de tipo T),
	y dos punteros, uno al nodo anterior y otro al nodo siguiente.
	*/
	struct Nodo {
		Nodo() : ant(nullptr), sig(nullptr) {}
		Nodo(const T &elem, Nodo* ant, Nodo* sig) : elem(elem), ant(ant), sig(sig) {}
		T elem;
		Nodo* ant;
		Nodo* sig;
	};

	// puntero al nodo fantasma
	Nodo* fantasma;

	// número de elementos
	size_t nelems;

	void libera() {
		// primero rompemos la circularidad
		fantasma->ant->sig = nullptr;
		fantasma->ant = nullptr;
		while (fantasma != nullptr) {
			Nodo* aux = fantasma;
			fantasma = fantasma->sig;
			delete aux;
		}
	}

	void copia(deque<T> const& other) {
		fantasma = new Nodo();
		fantasma->sig = fantasma;
		fantasma->ant = fantasma;
		nelems = 0;

		Nodo* act = other.fantasma->sig;
		while (act != other.fantasma) {
			push_back(act->elem);
			act = act->sig;
		}
	}

	// insertar un nuevo nodo entre anterior y siguiente
	static Nodo* inserta_elem(T const& e, Nodo* anterior, Nodo* siguiente) {
		Nodo* nuevo = new Nodo(e, anterior, siguiente);
		anterior->sig = nuevo;
		siguiente->ant = nuevo;
		return nuevo;
	}

	// eliminar el nodo n
	static void borra_elem(Nodo* n) {
		assert(n != nullptr);
		n->ant->sig = n->sig;
		n->sig->ant = n->ant;
		delete n;
	}
};

#endif // deque_eda_h

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

	void volcar_pila(stack<char> & pila, deque<char> & dcola) {
		while (!pila.empty()) {
			dcola.push_back(pila.top());
			pila.pop();
		}
	}

	bool es_vocal(char a) {
		return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' ||a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U';
	}

	string codifica(string const& mensaje) {
		// primera fase, invertir consonantes entre vocales
		deque<char> X;
		stack<char> pila_consonantes; // para darles la vuelta
		for (char c : mensaje) {
			if (es_vocal(c)) {
				volcar_pila(pila_consonantes, X);
				X.push_back(c);
			}
			else {
				pila_consonantes.push(c);
			}
		}
		volcar_pila(pila_consonantes, X);
		// segunda fase
		string resultado;
		size_t cont = 0;
		while (!X.empty()) {
			if (cont % 2 == 0) {
				resultado.push_back(X.front()); X.pop_front();
			}
			else {
				resultado.push_back(X.back()); X.pop_back();
			}
			++cont;
		}
		return resultado;
	}

	string descodifica(string const& mensaje) {
		// deshacer segunda fase
		deque<char> x;
		stack<char> aux;
		for (int i = 0;i < mensaje.size();++i) {
			if (i % 2 == 0) {
				x.push_back(mensaje[i]);
			}
			else
				aux.push(mensaje[i]);
		}
		volcar_pila(aux, x);
		string mmedio;
		while (!x.empty()) {
			mmedio += x.front();
			x.pop_front();
		}
		// , deshacer primera fase, invertir consonantes entre vocales
		stack<char> pila_consonantes; // para darles la vuelta
		deque<char> xx;
		for (char c : mmedio) {
			if (es_vocal(c)) {
				volcar_pila(pila_consonantes, xx);
				xx.push_back(c);
			}
			else {
				pila_consonantes.push(c);
			}
		}
		volcar_pila(pila_consonantes, xx);
		string resultado;
		while(!xx.empty()) {
			resultado += xx.front();
			xx.pop_front();
		}
		return resultado;
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




bool resuelveCaso() {
	string x;
	getline(cin, x);
	if (!std::cin)
		return false;
	cout << x << " => ";
	stack<char> m;
	string rdo = m.descodifica(x);
	cout << rdo <<'\n';
	return true;

}

int main() {


	while (resuelveCaso())
		;


	return 0;
}