#include <iostream>
#include <vector>
using namespace std;

//Coste:
//P : {0 <= b <= a}
//fun combinatorio (int a, int b, vector<vector<int>>& m) return r
//Q : {r = a! / (b!*(a-b)!)}

int combinatorio(int a, int b, vector<vector<int>>& m){
	if (b == 0 || b==a)
		return 1;

	else if (m[b][a]!=-1){
		return m[b][a];
	}
	else{
		m[b - 1][a - 1] = combinatorio(a - 1, b - 1, m);
		m[b][a - 1] = combinatorio(a - 1, b, m);
		return m[b - 1][a - 1] + m[b][a - 1];
	}
}


bool resuelveCaso(){
	int a, b;
	cin >> a >> b;
	if (!std::cin)
		return false;
	
	vector<vector<int>> m(b+1, vector<int>(a+1));
	for (int i = 0; i < b+1; ++i){
		for (int j = 0; j < a+1; ++j){
			m[i][j] = -1;
		}
	}

	int sol = combinatorio(a, b, m);
	cout << sol << '\n';

	return true;

}

int main(){


	while (resuelveCaso())
		;

	return 0;
}