#include <iostream>
#include <fstream>
using namespace std;



int resolver(long long int n, bool & par, int & suma) {
	if (n <= 9) {
		par = false;
		suma = n;
		return 0;
	}
	else {
		resolver(n/10, par, suma);
		par=!par;
		if (par)
			suma += 3 * (n % 10);
		else
			suma += n % 10;
		n /= 10;
		return 10 - suma % 10;
	}
}


bool resuelveCaso() {
	long long int n;
	cin >> n;
	if (!std::cin)
		return false;
	bool par=true;
	int suma = 0;
	int sol = resolver(n, par, suma);
	cout << sol << '\n';
	return true;

}

int main() {


	while (resuelveCaso())
		;



	return 0;
}