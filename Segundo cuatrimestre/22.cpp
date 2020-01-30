#include <string>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include "21.h"
using namespace std;




bool resuelveCaso(){
	string instr;
	cin >> instr;
	if (!cin)
		return false;
	
	string cancion, autor;
	int n;
	iPud ipud;
	while (instr != "FIN"){

		if (instr == "play"){
			cancion = ipud.play();
			if (cancion == "")
				cout << "No hay canciones en la lista\n";
			else
				cout << "Sonando " << cancion << '\n';
		}
		else if (instr == "totalTime")
			cout << "Tiempo total " << ipud.totalTime()<<'\n';
		else if (instr == "recent"){
			cin >> n;
			list<string> rec = ipud.recent(n);
			if (rec.empty())
				cout << "No hay canciones recientes\n";
			else{
				cout << "Las " << n << " mas recientes\n";
				for (auto i = rec.begin(); i != rec.end(); ++i){
					cout <<'\t'<< *i << '\n';
				}
			}
		}
		else if (instr == "addSong"){
			cin >> cancion >> autor >> n;
			try{
				ipud.addSong(cancion, autor, n);
			}
			catch (invalid_argument & e){
				cout << "ERROR addSong\n";
			}
		}
		else if (instr == "deleteSong"){
			cin >> cancion;
			try{
				ipud.deleteSong(cancion);
			}
			catch (invalid_argument & e){
				cout << "ERROR deleteSong\n";
			}
		}
		else if (instr == "addToPlaylist"){
			cin >> cancion;
			try{
				ipud.addToPlaylist(cancion);
			}
			catch (invalid_argument & e){
				cout << "ERROR addToPlaylist\n";
			}
		}
		else if (instr == "current"){
			try{
				ipud.current();
			}
			catch (invalid_argument& e){
				cout << "ERROR current\n";
			}
		}
		cin >> instr;
	}
	cout << "----\n";
	return true;
}







int main(){
	while (resuelveCaso()){};
	return 0;
}