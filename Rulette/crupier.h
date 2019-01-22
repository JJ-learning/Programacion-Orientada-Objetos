#ifndef _CRUPIER_H_
#define _CRUPIER_H_

#include <iostream>
#include <string>
#include "persona.h"

using namespace std;

class Crupier: public Persona{
	private:
		string codigo_;
		
	public:
		Crupier(string DNI,string codigo, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="",string pais="")
		: Persona (DNI,nombre,apellidos,direccion,localidad,provincia,pais){ codigo_=codigo;};
						
		string getCodigo(){ return codigo_;};
		void setCodigo(string a){ codigo_=a;};
};

#endif
