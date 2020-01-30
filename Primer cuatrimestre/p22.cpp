#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;

void mover(int i, int & fila, int & columna) {
	switch (i) {
	case 0:
		++columna;
		break;
	case 1:
		++fila;
		break;
	case 2:
		--columna;
		break;
	case 3:
		--fila;
		break;
	}
}
void desmover(int i, int & fila, int & columna) {
	switch (i) {
	case 0:
		--columna;
		break;
	case 1:
		--fila;
		break;
	case 2:
		++columna;
		break;
	case 3:
		++fila;
		break;
	}
}
int menorCaminoQueQueda(int f1, int c1, int f2, int c2) {
	int menorCaminoQueda = abs(c2 - c1) + abs(f2 - f1) + 1;
	if (f1 == f2 || c1 == c2)
		--menorCaminoQueda;
	return menorCaminoQueda;
}
void resolver(vector<vector<int>>const& m, vector<vector<bool>>& marcas, int const& hmax, int f1, int lastf1, int c1, int lastc1, int const f2, int const c2, int & cont, int& mini) {
	for (int i = 0; i < 4; ++i) {
		mover(i, f1, c1);
		if (f1 >= 0 && f1 < m.size() && c1 >= 0 && c1 < m.size()) {
			if (abs(m[f1][c1] - m[lastf1][lastc1]) <= hmax && marcas[f1][c1] == false) {
				marcas[f1][c1] = true;
				++cont;
				if (f1 == f2 && c1 == c2) {
					if (cont < mini)
						mini = cont;
				}
				else if (cont + menorCaminoQueQueda(f1, c1, f2, c2) < mini && mini != 2)
					resolver(m, marcas, hmax, f1, f1, c1, c1, f2, c2, cont, mini);
				marcas[f1][c1] = false;
				--cont;
			}
		}
		desmover(i, f1, c1);
	}
}

bool resuelveCaso() {
	int n, hmax, f1, c1, f2, c2;
	cin >> n >> hmax >> f1 >> c1 >> f2 >> c2;
	if (!std::cin)
		return false;
	vector<vector<int>> m(n, vector<int>(n));
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			cin >> m[i][j];
		}
	}
	vector<vector<bool>> marcas(n, vector<bool>(n));
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			marcas[i][j]=false;
		}
	}
	marcas[f1][c1] = true;
	int cont = 1, mini = n*n + 1;
	if (f1 == f2 && c1 == c2)
		mini = 1;
	else
		resolver(m, marcas, hmax, f1, f1, c1, c1, f2, c2, cont, mini);

	if (mini == n*n + 1)
		cout << "NO\n";
	else
		cout << mini << "\n";
	return true;

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("C:/Users/Claudia/OneDrive/UNIVERSIDAD/DOBLE/EDA/Juez/p22.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 


	while (resuelveCaso())
		;

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}