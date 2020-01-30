
#include "23.h"
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <list>
using namespace std;



bool resuelveCaso(){
	int x;
	cin >> x;
	if (!cin)
		return false;
	char a; cin.get(a);
	libreria libr;
	string s, action, libroact;
	int num;
	for (int i = 0; i < x; ++i){
		getline(cin, s);
		stringstream ss(s);
		ss >> action;
		if (action == "estaLibro"){
			getline(ss, libroact);
			if (libr.estaLibro(libroact))
				cout << "El libro " << libroact << " esta en el sistema\n";
			else
				cout << "No existe el libro " << libroact << " en el sistema\n";
			cout << "---\n";
		}
		else if (action == "numEjemplares"){
			getline(ss, libroact);
			try{
				num =libr.numEjemplares(libroact);
				cout << "Existen " << num << " ejemplares del libro " << libroact << '\n';
			}
			catch (invalid_argument){
				cout << "No existe el libro " << libroact << " en el sistema\n";
			}
			cout << "---\n";
		}
		else if (action == "top10"){
			list<libro> lista = libr.top10();
			auto i = lista.begin();
			while (i != lista.end()){
				cout << *i << '\n'; //¿?
				++i;
			}
			cout << "---\n";
		}
		else if (action == "nuevoLibro"){
			ss >> num;
			getline(ss, libroact);
			libr.nuevoLibro(num, libroact);
		}
		else if (action == "comprar"){
			getline(ss, libroact);
			try{
				libr.comprar(libroact);
			}
			catch (invalid_argument e){
				cout << e.what()<<'\n';
			}
			catch (out_of_range e ){
				cout << e.what()<<'\n';

			}
		}
		else if (action == "elimLibro"){
			getline(ss, libroact);
			libr.elimLibro(libroact);
		}
		
	}
	cout << "------\n";
	return true;
}




int main(){
	while (resuelveCaso()){};
}
