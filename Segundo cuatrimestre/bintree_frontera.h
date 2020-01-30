//Claudia Guerrero (DG07)
#ifndef bintree_frontera_h
#define bintree_frontera_h

#include "bintree_eda.h"
#include <iostream>
using namespace std;

template <class T>
class bintree_frontera : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:
	bintree_frontera() : bintree<T>() {}
	bintree_frontera(bintree_frontera<T> const& l, T const& e, bintree_frontera<T> const& r) : bintree<T>(l, e, r) {}

	vector<T> frontera() {
		vector<T> f;
		frontera(this->root_, f);
		return f;
	}

private:
	void frontera(Link act, vector<T> & f) {
		if (act != nullptr) {
			if (act->left_ == nullptr && act->right_ == nullptr)
				f.push_back(act->elem_);
			frontera(act->left_, f);
			frontera(act->right_, f);
		}
	}


};
#endif

