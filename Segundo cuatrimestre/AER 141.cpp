//Claudia Guerrero (DG07)

//
//  stack_eda.h
//
//  Implementaci�n del TAD pila con array din�mico
//
//  Estructuras de Datos y Algoritmos
//  Facultad de Inform�tica
//  Universidad Complutense de Madrid
//
//  Created by Alberto Verdejo on 6/12/16.
//  Copyright (c) 2016 Alberto Verdejo. All rights reserved.
//

#ifndef stack_eda_h
#define stack_eda_h

#include <stdexcept>

template <class T>
class stack {
	static const int TAM_INICIAL = 10; // tama�o inicial del array din�mico
public:

	// constructor: pila vac�a
	stack() : nelems(0), capacidad(TAM_INICIAL), array(new T[capacidad]) {}

	// destructor
	~stack() {
		libera();
	}

	// constructor por copia
	stack(stack<T> const& other) {
		copia(other);
	}

	// operador de asignaci�n
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

	// consultar si la pila est� vac�a
	bool empty() const {
		return nelems == 0;
	}

protected:

	// n�mero de elementos en la pila
	size_t nelems;

	// tama�o del array
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

#include <iostream>
#include <string>

using namespace std;

bool caso() {
	string c;
	getline(cin, c);
	if (! std::cin) {
		return false;
	}
	stack<char> pila;
	bool balanced = true;
	int i = 0;
	while (i<c.size() && balanced) {
		if (c[i] == '(' || c[i] == '[' || c[i] == '{') {
			pila.push(c[i]);
		}
		else if (c[i] == ')') {
			if (!pila.empty() && pila.top() == '(')
				pila.pop();
			else
				balanced = false;
		}
		else if (c[i] == ']') {
			if (!pila.empty() && pila.top() == '[')
				pila.pop();
			else
				balanced = false;
		}
		else if (c[i] == '}') {
			if (!pila.empty() && pila.top() == '{')
				pila.pop();
			else
				balanced = false;
		}
		++i;
	}
	if (balanced)
		balanced = pila.empty();
	if (balanced)
		cout << "YES\n";
	else
		cout << "NO\n";
	return true;
}

int main() {

	while (caso()) {
	}
	
	return 0;
}