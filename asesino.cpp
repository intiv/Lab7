#include "soldado.h"
#include "asesino.h"
#include<string>

using std::string;

asesino::asesino(string name,string city,int age,double asesinatos,double sigilo):soldado(name,city,age),asesinatos(asesinatos){
	if(sigilo>1&&sigilo>10){
		this->sigilo=sigilo;
	}else{
		this->sigilo=5.0;
	}
}

double asesino::ataque()const{
	return this->asesinatos;
}

double asesino::defensa()const{
	return this->sigilo;
}
