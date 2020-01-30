//Claudia Guerrero (DG07)
#ifndef bintree_minimo_h
#define bintree_minimo_h

#include "bintree_eda.h"
#include <iostream>
using namespace std;

template <class T>
class bintree_minimo : public bintree<T> {
	using Link = typename bintree<T>::Link;

public:
	bintree_minimo() : bintree<T>() {}
	bintree_minimo(bintree_minimo<T> const& l, T const& e, bintree_minimo<T> const& r) : bintree<T>(l, e, r) {}

	T minimo() {
		T mini = this->root_->elem_;
		minimo(this->root_, mini);
		return mini;
	}

private:
	void minimo(Link act, T & mini) {
		if (act != nullptr) {
			if (act->elem_ < mini)
				mini = act->elem_;
			minimo(act->left_, mini);
			minimo(act->right_, mini);
		}
	}


};
#endif

