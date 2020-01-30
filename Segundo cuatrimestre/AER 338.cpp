#include <map>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <cctype>
using namespace std;


/*void show(map<string, vector<int>> const& m) {
auto i = m.begin();
while (i != m.end()) {
cout << i->clave << ' ';
for (int j = 0;j < i->valor.size();++j) {
cout << i->valor[j] << ' ';
}
++i;
cout << '\n';
}
}*/

bool resuelveCaso() {
	int x, y;
	cin >> x;
	if (!cin)
		return false;
	cin >> y;
	int rdo;
	int profe=0, copiados=0;
	map<int, int> m; //rdo, ultima aparicion
	for (int i = 0; i < x; ++i) {
		cin >> rdo;	
		//m.insert(pair<int, int>(rdo, i));
		if (m.find(rdo)!=m.end()){
			if (i - m[rdo] <= y)
				++profe;
			++copiados;
		}
		m[rdo] = i;
	}

	cout <<copiados<<' '<<profe<< '\n';
	return true;
}

int main() {

	while (resuelveCaso()) {};

	return 0;
}