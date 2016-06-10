#pragma once
#include "soldado.h"
#include<string>

using std::string;

class asesino: public soldado{
  protected:
	double asesinatos, sigilo;
  public:
	asesino(string,string,int,double,double);
	double ataque()const;
	double defensa()const;
	string toString()const;
};
