#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include <iostream>
#include <set>
using namespace std;

// O(log N), donde N es el numero de entrada
int siguiente(int n) {
	int sol = 0;
	while (n > 0) {
		sol += pow((n % 10), 3);
		n /= 10; 
	}
	return sol;
}



bool resuelveCaso() {
	int n;
	cin >> n;
   
   if (n == 0) 
      return false;

   set<int> cjto;
   while (n != 1 && cjto.count(n) == 0) {
		cjto.insert(n);
		cout << n << " - ";
		n = siguiente(n); 
	}
   bool cubif = (n == 1);
   if(cubif)
	   cout << n << " -> cubifinito.\n";
   else
	   cout << n << " -> no cubifinito.\n";
   return true;
}

int main() {

   
   while (resuelveCaso());
   
   return 0;
}
