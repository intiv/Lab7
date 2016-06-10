#include "soldado.h"
#include "arquero.h"
#include<string>

using std::string;

arquero::arquero(string name,string city,int age,double flechas,double precision):soldado(name,city,age),flechas(flechas),precision(precision){
}

double arquero::ataque()const{
	return (flechas*precision)/1000;
}

double arquero::defensa()const{
	return 0.0;
}

string arquero::toString()const{
	stringstream ss;
	ss<<name<<"- Arquero(a): Precision "<<precision<<", Flechas "<<flechas;
	return ss.str();
}
