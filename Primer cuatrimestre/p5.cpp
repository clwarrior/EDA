#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void resuelveCaso(int n, vector<string> v){
	//coste lineal O(f(n))=O(n)
	//P : {}
	//proc resuelveCaso (int n, vector<string> v, out f1, out f2)
	//Q : {f2-f1 = MAX a, b : 0 <= a <= b < n && secuencia(a, b)}
	//secuecia(a, b) = {FORALL k : a <= k <= b : v[k]=="FFFFFF"}
	int pos1=-1, pos2=-1, max=-1, maxaux, f1=0, f2=-1;
	for (int i = 0; i < n; ++i){
		if (v[i] == "FFFFFF"){
			if (pos1 == -1){
				pos1 = i;
				pos2 = i;
				maxaux = pos2 - pos1;
			}
			else if (v[i - 1] == "FFFFFF"){
				pos2 += 1;
				maxaux += 1;
			}
		}
		else if (pos1 != -1){
			if (maxaux > max){
				f1 = pos1;
				f2 = pos2;
				max = maxaux;
			}
			pos1 = -1;
		}
	}
	if (pos2 == n - 1 && maxaux>max){
		f1 = pos1;
		f2 = pos2;
		max = maxaux;
	}
	cout << f1 << ' ' << f2<<'\n';
}

bool resolver(){
	int numCasos;
	int n;
	cin >> numCasos >> n;
	if (!std::cin)
		return false;
	for (int i = 0; i < numCasos; ++i){
		vector<string> v(n);
		for (string &c : v)
		cin >> c;
		resuelveCaso(n, v);
	}
	cout << '\n';
	return true;
	
}

int main() {

	while (resolver());


	return 0;
}


