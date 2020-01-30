//Claudia Guerrero García-Heras (DG07)
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resolver(int n, int m, int ini, vector<char> & v) {
	if (v.size() == m){
		for (int i = 0; i < v.size(); ++i){
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
	else{
		for (int i = ini; i <= n - m +ini && i<n ; ++i){
			v.emplace_back(char(int('a') + i));
			resolver(n, m, i + 1, v);
			v.pop_back();
		}
	}

}


bool resuelveCaso() {
	int n, m;
	cin >> n >> m;

	if (!std::cin)
		return false;
	vector<char> v;
	resolver(n, m, 0, v);



	return true;

}

int main() {

	while (resuelveCaso())
		;

	return 0;
}