#include <iostream>
#include <vector>
#include <string>
using namespace std;
void resuelveCaso(){
	int n, p;
	int max1, min2;
	cin >> n >> p;
	vector<int> a;
	int aux;
	for (int i = 0; i<n; ++i) {
		cin >> aux;
		a.push_back(aux);
	}
	string result;
	if (p + 1 == n) result = "SI";
	else {
		max1 = a[0];
		min2 = a[p + 1];
		for (int i = 1; i <= p; ++i){
			if (a[i] > max1) max1 = a[i];
		}
		for (int i = p + 1; i < n; ++i){
			if (a[i] < min2) min2 = a[i];
		}
		if (max1 < min2) result = "SI";
		else result = "NO";
	}
	cout << result + '\n';
}
int main(){
	int casos;
	cin >> casos;
	for (int i = 0; i<casos; ++i){
		resuelveCaso();
	}
	return 0;
}


