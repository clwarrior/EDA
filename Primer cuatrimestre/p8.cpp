#include <iostream>
#include <string>
using namespace std;

void resolver(string cadena, string subcadena){
	//P : {true}
	//fun resolver(string cadena, int a, string subcadena, int b) return r
	//Q : {r= #u : 0<u<a : (forall w: u<w<b : cadena[u+w]==subcadena[w])}
	int result = 0;
	for (int i=0; i <= cadena.length()-subcadena.length(); ++i){
		int j = 0;
		int cont = i;
		bool sigue = true;
		while (j < subcadena.length() && sigue){
			if (cadena[cont] == subcadena[j]){
			++cont;
			++j;
			}
			else sigue=false;
		}
		if (sigue) result += 1;
	}
	cout << result<<'\n';
}

int main(){
	string cadena;
	string subcadena;
	getline(cin, cadena);
	int primero = 0;
	while (cin){
		getline(cin, subcadena);
		resolver(cadena, subcadena);
		getline(cin, cadena);
	}
	return 0;
}