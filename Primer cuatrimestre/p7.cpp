#include <iostream>
#include <vector>
//#include <iomanip>
#include <fstream>
//#include <assert.h>
//#include <stdio.h>
//#include <algorithm>
using namespace std;

bool resuelveCaso() {
	vector<int> v;
	int x;
	cin >> x;
	while (x != 0){
		v.emplace_back(x);
		cin >> x;
	}
	if (v.size()==0)
		return false;

	//coste lineal O(n) siendo n la longitud del vector v
	//P : {lenght(v) > 0}
	//fun (vect v) return vect s
	//Q : {forall x : exist s[i] = x : x=([sumatorio] k : 0<=k<=i : v[k])}
	
	vector<int> s(v.size());
	s[0] = v[0];
	for (int i = 1; i < s.size(); ++i){
		s[i] = s[i - 1] + v[i];
	}
	
	for (int &x : s)
		cout << x << ' ';
	cout << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}