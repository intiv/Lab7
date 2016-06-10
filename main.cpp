#include "soldado.h"
#include "asesino.h"
#include "knight.h"
#include "arquero.h"
#include "escuadron.h"
#include<string>
#include<vector>
#include<iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int main(int argc,char* argv[]){
	bool continuar=true;
	vector<escuadron*> escuadrones;
	while(continuar){
		int op;
		cout<<"1. Agregar escuadron\n2. Eliminar escuadron\n3. Simulacion\n4. Salir"<<endl;
		cin>>op;
		if(op==1){
			string nombre;
			vector<soldado*> n;
			cout<<"Nombre el nuevo escuadron"<<endl;
			cin.ignore();
			getline(cin,nombre);
			escuadrones.push_back(new escuadron(nombre,n));
		}else if(op==2){

		}else if(op==3){

		}else if(op==4){
			continuar=false;
		}				
	}
	return 0;	
}

void listarEscuadrones(vector<escuadron*>& escuadrones){
	
}
