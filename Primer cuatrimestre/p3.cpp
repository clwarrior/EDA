#include <iostream>
#include <vector>
using namespace std;

bool menores (vector<int> a, int n, int p){
	bool result;
	int max1, min2;
	if (p + 1 == n) result = true;
	else {
		max1 = a[0];
		min2 = a[p + 1];
		for (int i = 1; i <= p; ++i){
			if (a[i] > max1) max1 = a[i];
		}
		for (int i = p + 1; i < n; ++i){
			if (a[i] < min2) min2 = a[i];
		}
		if (max1 < min2) result = true;
		else result = false;
	}
	return result;
}

int main(){
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i){
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) cin>> x;
		int p;
		bool Encontrado = false;
		for (int i = 0; i < n && !Encontrado; ++i){
			Encontrado = menores(a, n, i);
			if (Encontrado) p = i;
		}
		cout << p<<'\n';
	}
	return 0;

}


