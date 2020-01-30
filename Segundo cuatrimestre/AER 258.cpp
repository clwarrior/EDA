//Claudia Guerrero García-Heras (DG07)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

int maximoBestia(vector<int> v, int ini, int k) {
	int max = 0;
	for (int a = ini ;a < ini + k;++a) {
		if (v[a] > max) {
			max = v[a];
		}
	}
	return max;
}

bool resuelveCaso() {
	int sobre, k;
	cin >> sobre >> k;
	if (sobre==0)
		return false;
	vector<int> s;
	int x;	
	for (int i = 0;i < sobre;++i) {
		cin >> x;
		s.push_back(x);
	}
	if (k != 0) {
		bool primero = true;
		int max=0;
		for (int i = 0;i < sobre - k + 1;++i) {
			if (primero) {
				max=maximoBestia(s, i, k);
			}
			else {
				if (max == s[i - 1]) {
					max=maximoBestia(s, i, k);
				}
				else
					if (s[i + k] > max)
						max = s[i + k];
			}

			if (!primero)
				cout << ' ';
			cout << max;
			primero = false;
		}
	}
	else 
		cout << '\n';
	cout << '\n';
	return true;

}

int main() {



	while (resuelveCaso())
		;



	return 0;
}