#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*//NO FINAL
void resolver(int n, int & s, int & pospow) {
	if (n <= 9) {
		s = n;
		pospow = 0;
	}
	else {
		resolver(n / 10, s, pospow);
		pospow += 1;
		s += n % 10 * pow(10, pospow);
	}
}*/

//FINAL
int resolver(int n, int suma) {
	if (n == 0) {
		return suma;
	}
	else {
		return resolver(n / 10, suma * 10 + n % 10);
	}
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (!std::cin)
		return false;
	int s = 0, pospow=0;
	int sol=resolver(n, pospow);
	cout << sol << '\n';
	return true;
}

int main() {
	while (resuelveCaso())
		;
	return 0;
}