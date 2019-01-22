#ifndef _PERSONA_H_
#define _PERSONA_H_

#include <iostream>
#include <string>

using namespace std;

class Persona{
	private:
		string DNI_;
		string nombre_;
		string apellidos_;
		string direccion_;
		string localidad_;
		string provincia_;
		string pais_;
	
	
	public:
		Persona(string DNI, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="",string pais=""){

	DNI_=DNI;
	nombre_=nombre;
	apellidos_=apellidos;
	direccion_=direccion;
	localidad_=localidad;
	provincia_=provincia;
	pais_=pais;	
		
};
		
		string getDNI(){ return DNI_;};
		void setDNI(string a){ DNI_=a;};
		
		string getNombre(){ return nombre_;};
		void setNombre(string a){ nombre_=a;};
		
		string getApellidos(){ return apellidos_;};
		void setApellidos(string a){ apellidos_=a;};
		
		string getDireccion(){ return direccion_;};
		void setDireccion(string a){ direccion_=a;};
		
		string getLocalidad(){ return localidad_;};
		void setLocalidad(string a){ localidad_=a;};
		
		string getProvincia(){ return provincia_;};
		void setProvincia(string a){ provincia_=a;};
		
		string getPais(){ return pais_;};
		void setPais(string a){ pais_=a;};
		
		string getApellidosyNombre(){ return apellidos_+","+" "+nombre_; };
		
};

#endif
