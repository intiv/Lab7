#pragma once
#include<string>

using std::string;

class soldado{
  protected:
	string name, city;
	int age;
  public:
	soldado(string,string,int=18);
	virtual double ataque()const=0;
	virtual double defensa()const=0;
	string toString()const=0;
};
