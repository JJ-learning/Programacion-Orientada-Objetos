#ifndef RULETA_H
#define RULETA_H

#include <iostream>
#include <string>
#include <list>
#include <cstdlib>
#include <fstream>
#include "jugador.h"
#include "crupier.h"

using namespace std;

class Ruleta{

	private:
		int banca_;
		int bola_;
		list <Jugador> jugadores_;
		Crupier crupier_;
	
	public:
		inline Ruleta (Crupier c):crupier_(c){
	
			bola_=-1;
			banca_=1000000;
		};
		
		inline int getBanca(){ return banca_;};
		bool setBanca(int aux);
		
		inline int getBola (){ return bola_;};
		bool setBola(int aux);
		
		inline Crupier getCrupier(){ return crupier_;};
		inline void setCrupier (Crupier aux){crupier_=aux;};
		
		inline list <Jugador> getJugadores(){ return jugadores_;};
		bool addJugador (Jugador j);
		int deleteJugador (string DNI);
		int deleteJugador (Jugador j);
		void leeJugadores ();
		void escribeJugadores();
		
		void giraRuleta();
		void getPremios();
		bool getColor(int num);
};

#endif
