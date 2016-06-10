#pragma once
#include "soldado.h"
#include<vector>
#include<string>

using std::vector;
using std::string;

class escuadron{
  protected:
	string name;
	vector<soldado*> soldiers;
  public:
	escuadron(string,vector<soldado*>);
	~escuadron();
	double defensa()const;
	double ataque()const;
	void addSoldier(int,string,string,int,double,double);
	string toString()const;
};
