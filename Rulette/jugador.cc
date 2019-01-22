#include "jugador.h"

void Jugador::setApuestas (){

	list <Apuesta>::iterator i;
	char t[100];
	char v[100];
	char c[100];
	string fichero=getDNI()+".txt";
	struct Apuesta aux;
	
	//Abro el fichero
	ifstream f (fichero.c_str());
	
	//Limpio la lista
	apuestas_.clear();
	
	//Relleno la lista con los elementos del fichero
	while (!f.eof()){
		f.getline (t,100,',');
		aux.tipo=atoi(t);
		
		f.getline (v,100,',');
		aux.valor=string(v);
		
		f.getline (c,100,'\n');
		aux.cantidad=atoi(c);
		
		if (!f.eof())
			apuestas_.push_back(aux);
		
	}
	
	f.close();

}
