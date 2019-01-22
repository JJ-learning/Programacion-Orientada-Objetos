#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <cstdlib>
#include "persona.h"
using namespace std;

struct Apuesta{
	int tipo;
	string valor;
	int cantidad;
};

class Jugador: public Persona{
	
	private:
		int dinero_;
		string codigo_;
		list <Apuesta> apuestas_;
	
	public:
		Jugador(string DNI, string codigo, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="",string pais="") :
		Persona (DNI,nombre,apellidos,direccion,localidad,provincia,pais){

			codigo_=codigo;
			dinero_=1000;
		
		}
		
		string getCodigo(){ return codigo_;};
		void setCodigo(string a){ codigo_=a;};
		
		int getDinero (){ return dinero_;};
		void setDinero (int a){ dinero_=a;};
		
		list <Apuesta> getApuestas (){ return apuestas_; };
		void setApuestas ();

};

#endif
