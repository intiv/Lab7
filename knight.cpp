#include "soldado.h"

#include "knight.h"
#include<string>

using std::string;

knight::knight(string name,string city, int age,double dureza,double lanzas):soldado(name,city,age),lanzas(lanzas){
	if(dureza>1&&dureza<10){
		this->dureza=dureza;
	}else{
		this->dureza=5.0;
	}
}

double knight::ataque()const{
	return this->lanzas;
}

double knight::defensa()const{
	return this->dureza;
}

string knight::toString()const{
	stringstream ss;
	
}
