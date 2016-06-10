#pragma once
#include "soldado.h"
#include<string>

using std::string;

class knight: public soldado{
  protected:
	double dureza, lanzas;
  public:
	knight(string,string,int,double,double);
	double ataque()const;
	double defensa()const;
	string toString()const;
};
