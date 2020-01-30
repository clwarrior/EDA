
//
//  conjunto.h
//

#ifndef conjunto_h
#define conjunto_h

#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>    // std::move

template <class T>
class set {
public:
	set(size_t tam = TAM_INICIAL); // constructor
	set(set<T> const& other); // constructor por copia
	set<T> & operator=(set<T> const& other); // operador de asignación
	~set(); // destructor
	bool insert(T e);
	bool contains(T e) const;
	void erase(T e);
	bool empty() const;
	size_t size() const;

	//nuevo
	T consultarMenor() const;
	void eliminarMenor();
	T k_esimoMayor(int k) const;

private:
	const static size_t TAM_INICIAL = 8;
	size_t contador;
	size_t capacidad;
	T * datos;
	void amplia();
	void libera();
	void copia(set<T> const& other);
};

template <class T>
set<T>::set(size_t tam) : contador(0), capacidad(tam), datos(new T[capacidad]) {}

template <class T>
set<T>::~set() { libera(); }

template <class T>
void set<T>::libera() { delete[] datos; datos = nullptr; }

/** Constructor por copia */
template <class T>
set<T>::set(set<T> const& other) {
	copia(other);
}

/** Operador de asignación */
template <class T>
set<T> & set<T>::operator=(set<T> const& other) {
	if (this != &other) {
		libera();
		copia(other);
	}
	return *this;
}

template <class T>
void set<T>::copia(set<T> const& other) {
	capacidad = other.capacidad;
	contador = other.contador;
	datos = new T[capacidad];
	for (size_t i = 0; i < contador; ++i)
		datos[i] = other.datos[i];
}

template <class T>
bool set<T>::insert(T e) {
	bool done = false;
	if (!contains(e)) {
		if (contador == capacidad)
			amplia();
		int pos = 0;
		while (pos < contador && datos[pos]<e) {
			++pos;
		}
		for (int i = contador ; i > pos ; --i) {
			datos[i] = datos[i - 1];
		}
		datos[pos] = e;
		++contador;
		done = true;
	}
	return done;
}

template <class T>
bool set<T>::contains(T e) const {
	size_t i = 0;
	while (i < contador && datos[i] != e)
		++i;
	return i < contador;
}

template <class T>
void set<T>::amplia() {
	T * nuevos = new T[2 * capacidad];
	for (size_t i = 0; i < capacidad; ++i)
		nuevos[i] = std::move(datos[i]);
	delete[] datos;
	datos = nuevos;
	capacidad *= 2;
}

template <class T>
void set<T>::erase(T e) {
	size_t i = 0;
	while (i < contador && datos[i] != e)
		++i;
	if (i < contador) {
		datos[i] = datos[contador - 1];
		--contador;
	}
	else
		throw std::domain_error("El elemento no esta");
}


template <class T>
bool set<T>::empty() const {
	return contador == 0;
}

template <class T>
size_t set<T>::size() const {
	return contador;
}

//metodos nuevos
template <class T>
T set<T>:: consultarMenor() const {
	return datos[0];
}
template <class T>
T set<T>::k_esimoMayor(int k) const {
	return datos[contador - k];
}
template <class T>
void set<T>::eliminarMenor() {
	for (int i = 0; i < contador; ++i) {
		datos[i] = datos[i + 1];
	}
	--contador;
}

#endif // conjunto_h