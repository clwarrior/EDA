//Claudia Guerrero (DG07)
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int operar(int op, int a, int b){
	switch (op){
	case 0:
		a = a + b;
		break;
	case 1:
		a = a - b;
		break;
	case 2:
		a = a * b;
		break;
	case 3:
		a = a / b;
		break;
	}
	return a;
}

int desoperar(int op, int a, int b){
	switch (op){
	case 0:
		a = a - b;
		break;
	case 1:
		a = a + b;
		break;
	case 2:
		if (b == 0)
			a = 0;
		else
			a = a / b;
		break;
	case 3:
		a = a * b;
		break;
	}
	return a;
}

void resolver(vector<int> const& v, int n, int k, int cant, bool & existe) {
	for (int i = 0; i < 4 && !existe; ++i){
		if ((i == 3 && v[k+1]!=0 && cant%v[k+1] == 0) || i < 3){
			int cantAux;
			if (i == 2 && v[k + 1] == 0)
				cantAux = cant;
			cant = operar(i, cant, v[k + 1]);
			if (k == 3){
				if (cant == n)
					existe = true;
			}
			else
				resolver(v, n, k + 1, cant, existe);
			if (i == 2 && v[k + 1] == 0)
				cant = cantAux;
			else
				cant = desoperar(i, cant, v[k + 1]);
		}
	}
}

bool resuelveCaso() {
	int n;
	cin >> n;

	if (!std::cin)
		return false;

	vector<int> v(5);
	for(int &x : v)
		cin >> x;
	bool existe=false;
	resolver(v, n, 0, v[0], existe);

	if (existe)
		cout << "SI\n";

	else
		cout << "NO\n";

	return true;

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("C:/Users/Claudia/OneDrive/UNIVERSIDAD/DOBLE/EDA/Juez/p26.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 


	while (resuelveCaso())
		;

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);


#endif
	//system("PAUSE");
	return 0;
}