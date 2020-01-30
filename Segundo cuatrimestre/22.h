
#ifndef ipud_h
#define ipud_h

#include <string>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

class iPud{
private:
	unordered_map<string, pair<string, int>> canciones;
	unordered_map<string, list<string>::iterator> cancionesPlayList;
	unordered_map<string, list<string>::iterator> cancionesReproducidas;
	list<string> playList;
	int duracionPlayList=0;
	list<string> reproducidas;

public:
	void addSong(string s, string a, int d){
		if (canciones.find(s) != canciones.end()) {
			throw invalid_argument("");
		}
		else
			canciones[s] = pair<string, int>(a, d);
	}

	void addToPlaylist(string s){
		if (canciones.find(s) == canciones.end())
			throw invalid_argument("");
		else if (cancionesPlayList.find(s) == cancionesPlayList.end()) {
			playList.push_back(s);
			cancionesPlayList[s] = --playList.end();
			duracionPlayList += canciones[s].second;
		}
	}

	string current(){
		if (playList.empty())
			throw invalid_argument("");
		else
			return playList.front();
	}

	string play(){
		string s = "";
		if (!playList.empty()){
			s = playList.front();
			duracionPlayList -= canciones[s].second;
			playList.pop_front();
			cancionesPlayList.erase(s);
			if (cancionesReproducidas.find(s) == cancionesReproducidas.end()) {
				reproducidas.push_back(s);
				cancionesReproducidas[s] = --reproducidas.end();
			}
			else {
				reproducidas.erase(cancionesReproducidas[s]);
				reproducidas.push_back(s);
				cancionesReproducidas[s] = --reproducidas.end();
			}
			
		}
		return s;
	}

	int totalTime(){
		return duracionPlayList;
	}

	list<string> recent(int n) {
		list<string> sol;
		if (!reproducidas.empty()) {
			auto it = reproducidas.end();
			--it;
			for (int i = 0; i < n && it != reproducidas.begin(); ++i) {
				sol.push_back(*it);
				--it;
			}
			if(it == reproducidas.begin())
				sol.push_back(*it);
		}
		return sol;
	}

	void deleteSong(string s) {
		if (cancionesPlayList.find(s) != cancionesPlayList.end()) {
			duracionPlayList -= canciones[s].second;
			playList.erase(cancionesPlayList[s]);
			cancionesPlayList.erase(s);
		}
		if (canciones.find(s) != canciones.end())
			canciones.erase(s);	
		if (cancionesReproducidas.find(s) != cancionesReproducidas.end()){
			reproducidas.erase(cancionesReproducidas[s]);
			cancionesReproducidas.erase(s);
		}
	}


};
#endif