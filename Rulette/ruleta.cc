#include "ruleta.h"

bool Ruleta:: setBanca (int aux){

	if (aux>0){
		banca_=aux;
		return true;
	}else{
		return false;
	}

}

bool Ruleta:: setBola (int aux){

	if (aux>=0 && aux<=36){
		bola_=aux;
		return true;
	}else{
		return false;
	}

}

bool Ruleta:: addJugador (Jugador j){
	
	list <Jugador>::iterator i;
	string fichero;
	
	for (i=jugadores_.begin();i!=jugadores_.end();++i){
		if ((*i).getDNI()==j.getDNI()){
			return false;
		}	
	}
	
	fichero=j.getDNI()+".txt";
	jugadores_.push_back(j);
	
	ifstream f (fichero.c_str());
	f.close();
	
	return true;
}

int Ruleta::deleteJugador (string DNI){
	
	list <Jugador>::iterator i;
	
	if (jugadores_.empty())
		return -1;
	
	for (i=jugadores_.begin();i!=jugadores_.end();++i){
		if ((*i).getDNI()==DNI){
			jugadores_.erase(i);
			return 1;
		}	 
	}
	
	return -2;	
	
}

int Ruleta::deleteJugador (Jugador j){

	return (deleteJugador(j.getDNI()));

}

void Ruleta::giraRuleta(){
	srand(time(NULL));
	bola_=rand()%37;
}

void Ruleta::escribeJugadores(){

	list <Jugador>::iterator i;
	
	ofstream f ("jugadores.txt");
	
	for (i=jugadores_.begin();i!=jugadores_.end();++i){
		f << (*i).getDNI() << ',';
		f << (*i).getCodigo() << ',';
		f << (*i).getNombre() << ',';
		f << (*i).getApellidos() << ',';
		f << (*i).getDireccion() << ',';
		f << (*i).getLocalidad() << ',';
		f << (*i).getProvincia() << ',';
		f << (*i).getPais() << ',';
		f << (*i).getDinero() << '\n';
	}
	
	f.close();
}

void Ruleta::leeJugadores (){
	
	char aux[100];
	list <Jugador>::iterator i;
	Jugador j("","");
	
	//Eliminamos todos los elementos de la lista
	
	jugadores_.clear();
	
	//Rellenamos la lista con los elementos del fichero
	ifstream f ("jugadores.txt");
	
	while (!f.eof()){
		f.getline(aux,100,',');
		j.setDNI(string(aux));
		
		f.getline(aux,100,',');
		j.setCodigo(string(aux));
		
		f.getline(aux,100,',');
		j.setNombre(string(aux));
		
		f.getline(aux,100,',');
		j.setApellidos(string(aux));
		
		f.getline(aux,100,',');
		j.setDireccion(string(aux));
		
		f.getline(aux,100,',');
		j.setLocalidad(string(aux));
		
		f.getline(aux,100,',');
		j.setProvincia(string(aux));
		
		f.getline(aux,100,',');
		j.setPais(string(aux));
		
		f.getline(aux,100,'\n');
		j.setDinero(atoi(aux));
		
		if  (!f.eof())
			jugadores_.push_back(j);
	}
	
	f.close();
	
}

void Ruleta::getPremios(){

	list <Jugador>::iterator i;
	list <Apuesta>::iterator j;
	int tipo,cantidad;
	string valor;
	int dinero;
	list <Apuesta> l;
	
	for (i=jugadores_.begin();i!=jugadores_.end();++i){
		(*i).setApuestas();
		l=(*i).getApuestas();
		
		for (j=l.begin();j!=l.end();++j){
			dinero=(*i).getDinero(); //Actualizo el dinero después de comprobar cada apuesta
			tipo=(*j).tipo;
			valor=(*j).valor;
			cantidad=(*j).cantidad;
			switch(tipo){
				case 1:
				if (atoi(valor.c_str())==bola_){ //Si hay acierto
					(*i).setDinero(dinero+35*cantidad);
					banca_=banca_-35*cantidad;
				}else{  //Si no hay acierto
					(*i).setDinero(dinero-cantidad);
					banca_=banca_+cantidad;
				} break;
				
				case 2:
				if (bola_==0){ //Si la bola vale 0, se pierde
					(*i).setDinero(dinero-cantidad);
					banca_=banca_+cantidad;
				}else if (getColor(bola_)){ //Si la bola es negra
					if (valor=="negro"){ //Si el valor también es negro, hay acierto
						(*i).setDinero(dinero+cantidad);
						banca_=banca_-cantidad;
					}else{ //Si el valor es rojo, no hay acierto
						(*i).setDinero(dinero-cantidad);
						banca_=banca_+cantidad;
					}
				}else{ //Si el resultado es rojo
					if (valor=="rojo"){ //Si el valor también es rojo, hay acierto
						(*i).setDinero(dinero+cantidad);
						banca_=banca_-cantidad;
					}else{ //Si el valor es negro, no hay acierto
						(*i).setDinero(dinero-cantidad);
						banca_=banca_+cantidad;
					}
				} break;
				
				case 3:
				if (bola_==0){ //Si la bola vale 0, se pierde
					(*i).setDinero(dinero-cantidad);
					banca_=banca_+cantidad;
				}else if (bola_%2==0){ //Si el resultado es par
					if (valor=="par"){ //Si el valor también es par, hay acierto
						(*i).setDinero(dinero+cantidad);
						banca_=banca_-cantidad;
					}else{ //Si el valor es impar, no hay acierto
						(*i).setDinero(dinero-cantidad);
						banca_=banca_+cantidad;
					}
				}else{ //Si el resultado es impar
					if (valor=="impar"){ //Si el valor también es impar, hay acierto
						(*i).setDinero(dinero+cantidad);
						banca_=banca_-cantidad;
					}else{ //Si el valor es par, no hay acierto
						(*i).setDinero(dinero-cantidad);
						banca_=banca_+cantidad;
					}
				} break;
				
				case 4:
				if (bola_==0){ //Si la bola vale 0, se pierde
					(*i).setDinero(dinero-cantidad);
					banca_=banca_+cantidad;
				}else if (bola_>=1 && bola_<=18){ //Si el resultado es bajo
					if (valor=="bajo"){ //Si el valor también es bajo, hay acierto
						(*i).setDinero(dinero+cantidad);
						banca_=banca_-cantidad;
					}else{ //Si el valor es alto, no hay acierto
						(*i).setDinero(dinero-cantidad);
						banca_=banca_+cantidad;
					}
				}else{ //Si el resultado es alto
					if (valor=="alto"){ //Si el valor también es alto, hay acierto
						(*i).setDinero(dinero+cantidad);
						banca_=banca_-cantidad;
					}else{ //Si el valor también es bajo, no hay acierto
						(*i).setDinero(dinero-cantidad);
						banca_=banca_+cantidad;
					}
				} break;
				
			}
		}
	}
}

//Esta función nos dice el color de un número de la ruleta. Si devuelve true, el número es negro, y viceversa.
bool Ruleta::getColor (int num){

	int resto;
	int coc;
	
	if (num==10)
		return true;
	if (num==19)
		return false;
	
	do{
		resto=num%10;
		coc=(num-resto)/10;
		num=resto+coc;
	}while (num>10);
	
	if (num%2==0)
		return true;
	else
		return false;

}
