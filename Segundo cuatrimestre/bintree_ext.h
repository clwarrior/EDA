#ifndef EXTENDEDTREE_H
#define EXTENDEDTREE_H

#include "bintree_eda.h"
#include <iostream>
using namespace std;

template <class T>
class bintree_ext : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:	
	bintree_ext() : bintree<T>() {}
	bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

	size_t nNodos() {
		return nodos(this->root_);
	}
	size_t nAltura() {
		return altura(this->root_);
	}
	size_t nHojas() {
		int n = 0;
		hojas(this->root_, n);
		return n;
	}

private:

	static size_t nodos(Link r) {
		if (r==nullptr)
			return 0;
		else {
			return nodos(r->right_) + nodos(r->left_) + 1;
		}
	}

	static size_t altura(Link r) {
		if (r == nullptr) {
			return 0;
		}
		else {
			return 1 + std::max(altura(r->left_), altura(r->right_));
		}
	}

	static void hojas(Link r, int & n) {
		if (r != nullptr) {
			if (r->right_ == nullptr && r->left_ == nullptr)
				++n;
			else {
				hojas(r->right_, n);
				hojas(r->left_, n);
			}
		}
	}






};

#endif