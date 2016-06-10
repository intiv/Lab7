#pragma once
#include "soldado.h"
#include<string>

using std::string;

class arquero: public soldado{
  protected:
	double flechas,precision;
  public:
	arquero(string,string,int,double,double);
	double ataque()const;
	double defensa()const;
	string toString()const;
};
