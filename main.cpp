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

void listarEscuadrones(const vector<escuadron*>&);

void listarEscuadrones(const vector<escuadron*>&,vector<int>);
int main(int argc,char* argv[]){
	bool continuar=true;
	vector<escuadron*> escuadrones;
	while(continuar){
		int op;
		cout<<"1. Agregar escuadron\n2. Agregar soldados a un escuadron\n3. Simulacion\n4. Salir"<<endl;
		cin>>op;
		if(op==1){
			string nombre;
			vector<soldado*> n;
			cout<<"Nombre el nuevo escuadron"<<endl;
			cin.ignore();
			getline(cin,nombre);
			escuadrones.push_back(new escuadron(nombre,n));
		}else if(op==2){
			if(escuadrones.size()>0){
				bool agregar=true;
				int index;
				listarEscuadrones(escuadrones);
				cout<<endl<<"Ingrese posicion del escuadron"<<endl;
				cin>>index;
				while(agregar){
					string name,city;
					double atr1,atr2;
					int decision, age;
					cout<<"1. Arquero\n2. Coraza dura\n3. Asesino\n4. terminar"<<endl;
					cin>>decision;
					if(decision!=4){
						cout<<"Nombre: ";
						cin.ignore();
						getline(cin,name);
						cout<<"Ciudad: ";
						getline(cin,city);
						cout<<"Edad: ";
						cin>>age;
						if(decision==1){
							cout<<"Flechas: ";
							cin>>atr1;
							cout<<"Precision: ";
							cin>>atr2;	
						}else if(decision==2){
							cout<<"Dureza: ";
							cin>>atr1;
							cout<<"Lanzas: ";
							cin>>atr2;	
						}else if(decision==3){
							cout<<"Asesinatos: ";
							cin>>atr1;
							cout<<"Sigilo: ";
							cin>>atr2;	
						}
						escuadrones.at(index)->addSoldier(decision,name,city,age,atr1,atr2);
					}else{
						agregar=false;
					}
				}
				listarEscuadrones(escuadrones);
			}else{
				cout<<"No hay escuadrones"<<endl;
			}
		}else if(op==3){
			if(escuadrones.size()<8){
				cout<<"Fuera de aqui, se necesitan al menos 8 "<<endl;
			}else{
				vector<escuadron*> jugador1, jugador2;
				int ind;
				vector<int> indices;
				cout<<"JUGADOR 1 ELIJA SUS ESCUADRONES!!!"<<endl;
				for(int i=0;i<4;i++){
					listarEscuadrones(escuadrones);
					cout<<"Seleccione indice: "<<endl;
					cin>>ind;
					jugador1.push_back(escuadrones.at(ind));
					indices.push_back(ind);
					escuadrones.erase(escuadrones.begin()+ind);
				}
				cout<<"JUGADOR 2 ELIJA SUS ESCUADRONES!!!"<<endl;
				for(int i=0;i<4;i++){
					listarEscuadrones(escuadrones);
					cout<<"Seleccione indice: "<<endl;
					cin>>ind;
					jugador2.push_back(escuadrones.at(ind));
					indices.push_back(ind);
					escuadrones.erase(escuadrones.begin()+ind);
				}
				bool jugar=true; int turno=1,index1,index2;
				while(jugar){
					if(jugador1.size()>0&&jugador2.size()>0){
						if(turno==1){
							cout<<endl<<"ESCUADRONES DEL JUGADOR 1"<<endl<<"-----------------------------"<<endl;
							listarEscuadrones(jugador1);
							cout<<"Jugador1: Elija cual escuadron va a atacar:"<<endl;
							cin>>index1;
							listarEscuadrones(jugador2);
							cout<<"Jugador 2: Elija cual escuadron va a defender:"<<endl;
							cin>>index2;
							if(jugador1.at(index1)->ataque()>jugador2.at(index2)->defensa()){
								cout<<"El escuadron del jugador 1 vencio al del jugador 2!"<<endl;
							//	delete jugador2[index2];
								jugador2.erase(jugador2.begin()+index2);
							}else{
								cout<<"El jugador 2 se defendio del ataque del jugador 1!"<<endl;
							}
							turno=2;
						}else if(turno==2){
							cout<<endl<<"ESCUADRONES DEL JUGADOR 2"<<endl<<"-----------------------------"<<endl;
							listarEscuadrones(jugador2);
							cout<<"Jugador2: Elija cual escuadron va a atacar:"<<endl;
							cin>>index2;
							listarEscuadrones(jugador1);
							cout<<"Jugador 1: Elija cual escuadron va a defender: "<<endl;
							cin>>index1;
							if(jugador2.at(index2)->ataque()>jugador1.at(index1)->defensa()){
								cout<<"El escuadron del jugador 2 vencio al del jugador 1!"<<endl;
								//delete jugador1[index1];
								jugador1.erase(jugador1.begin()+index1);
							}
							turno=1;
						}
					}else{
						if(jugador1.size()==0){
							cout<<"FELICIDADES JUGADOR 2, HAS MASACRADO A MUCHAS PERSONAS Y ERES VICTORIOSO!";
						}else{
							cout<<"FELICIDADES JUGADOR 1, HAS MASACRADO A MUCHAS PERSONAS Y ERES VICTORIOSO!";
						}
						jugador1.clear();
						jugador2.clear();
						jugar=false;
					}
				}
			}
		}else if(op==4){
			continuar=false;
		}				
	}
	for(int i=0;i<escuadrones.size();i++){
		delete escuadrones.at(i);
	}
	return 0;	
}

void listarEscuadrones(const vector<escuadron*>& escuadrones){
	for(int i=0;i<escuadrones.size();i++){
		cout<<i<<" - "<<escuadrones.at(i)->toString()<<endl;
	}	
}

void listarEscuadrones(const vector<escuadron*>& escuadrones,vector<int> posiciones){
	for(int i=0;i<escuadrones.size();i++){
		bool print=true;
		for(int j=0;j<posiciones.size();j++){
			if(i==posiciones.at(j)){
				print=false;
			}	
		}
		if(print)
			cout<<i<<" - "<<escuadrones.at(i)->toString()<<endl;
	}	
}
