#include "list_eda.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef newlist_h
#define newlist_h


template<class T>
class listaguay : public list<T>{
	using Nodo = typename deque<T>::Nodo;
public:
	template<class Predicate>
	void remove_if(Predicate pred){
		auto nodo = this->begin();
		while ( nodo != this->end() && !this->empty()){
			if (!pred(*nodo)) {
				auto aux = nodo;
				++nodo;
				this->erase(aux);
			}
			else
				++nodo;
		}
	}
	
	void mostrar(){
		for (auto nodo = this->begin(); nodo != this->end(); ++nodo)
			cout << *nodo;
	}
	
};
#endif