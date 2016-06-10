#include "soldado.h"
#include "arquero.h"
#include "knight.h"
#include "asesino.h"
#include "escuadron.h"
#include<vector>
#include<string>
#include<sstream>
#include<iostream>

using std::string;
using std::vector;
using std::stringstream;

escuadron::escuadron(string name, vector<soldado*> soldiers):name(name),soldiers(soldiers){
}

escuadron::~escuadron(){
	std::cout<<"Eliminando escuadron "<<name<<"..."<<std::endl;	
	for(int i=0;i<soldiers.size();i++){
		delete soldiers.at(i);
	}
}

double escuadron::defensa()const{
	double def=0;
	for(int i=0;i<this->soldiers.size();i++){
		def+=soldiers.at(i)->defensa();
	}
	return def;
}

double escuadron::ataque()const{
	double atk=0;
	for(int i=0;i<this->soldiers.size();i++){
		atk+=this->soldiers.at(i)->ataque();
	}
	return atk;
}

void escuadron::addSoldier(int tipo,string name,string city, int age, double atr1, double atr2){
        if(tipo==1){
                soldiers.push_back(new arquero(name,city,age,atr1,atr2));
        }else if(tipo==2){
                soldiers.push_back(new knight(name,city,age,atr1,atr2));
        }else{
                soldiers.push_back(new asesino(name,city,age,atr1,atr2));
        }
}

string escuadron::toString()const{
	stringstream ss;
	ss<<"Escuadron "<<name<<":\n";
	for(int i=0;i<soldiers.size();i++){
		ss<<"\t"<<soldiers.at(i)->toString()<<"\n";
	}
	return ss.str();
}
