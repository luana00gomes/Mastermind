#include <string>
#include <iostream>
#include "header.h"

using namespace std;


Partida::Partida(const int &numCores, const int &tamCodigo, const int &maxPalpites, const bool &coresRepitidas, const int &numJogadores, const int &level): numCores(numCores), tamCodigo(tamCodigo), maxPalpites(maxPalpites), coresRepitidas(coresRepitidas), numJogadores(numJogadores), level(level){
}

Partida::Partida(){}

void Partida::inicia(){
	cout<<"Bem Vindo ao MASTERMIND!\n\nVocê está prestes a ter uma experiência desafiadora."<<endl;
	cout<<"Digite 1 se estiver sozinho ou 2 se for jogar com mais alguém"<<endl;

	cin>>numJogadores;
	
	cout<<"Digite\n\t0 se quer personalizar seu jogo,\n\t1 para nível fácil,\n\t2 para nível intermediário, \n\t3 para nível difícil,\n\te somente se tiver coragem, digite 4."<<endl;

	cin>>level;

	if(!(this->level)){
		int repete=-1;
		
		while(getNumCores()>10||getNumCores()<4){
			cout<<"De 4 a 10, escolha a quantidade máxima de cores"<<endl;
			cin>>numCores;
		}
		
		while(getTamCodigo()<4||getTamCodigo()>6){
			cout<<"De 4 a 6, escolha o tamanho do seu código"<<endl;
			cin>>tamCodigo;
		}
		
		while(this->getMaxPalpites()<4||getMaxPalpites()>10){
			cout<<"De 4 a 10, escolha a quantidade máxima de palpites"<<endl;
			cin>>maxPalpites;
		}	
		if(tamCodigo>numCores){
			setCoresRepitidas(true);
		}else{
			while(repete!=0&&repete!=1){
				cout<<"Digite 0 se seu código não aceitar cores repetidas e 1 caso aceitar"<<endl;
				cin>>repete;
				(repete==0)?setCoresRepitidas(false):setCoresRepitidas(true);
			}
		}
		
	}
	else{

		if(level==1){
			numCores=4;
			tamCodigo=4;
			maxPalpites=10;
			coresRepitidas=false;
		} 
		else{
			if(level==2){
				numCores=7;
				tamCodigo=5;
				maxPalpites=8;
				coresRepitidas=false;
			}
			else{
				if(level==3){
					numCores=10;
					tamCodigo=6;
					maxPalpites=8;
					coresRepitidas=true;
				}
				else{
					if(level==4){
						numCores=10;
						tamCodigo=6;
						maxPalpites=8;
						coresRepitidas=true;
					}
				}		
			}
		}
	}
} 

void Partida::setNumCores(const int &num_Cores){
	numCores=num_Cores;
}
void Partida::setTamCodigo(const int &tam_Codigo){
	tamCodigo=tam_Codigo;
}
void Partida::setMaxPalpites(const int &max_Palpites){
	maxPalpites=max_Palpites;
}
void Partida::setCoresRepitidas(const bool &cores_Repitidas){
	coresRepitidas=cores_Repitidas;
}
void Partida::setNumJogadores(const int &num_Jogadores){
	numJogadores=num_Jogadores;
}
void Partida::setLevel(const int &m_level){
	level=m_level;
}
	
int Partida::getNumCores(){
	return numCores;
}
int Partida::getTamCodigo(){
	return tamCodigo;
}
int Partida::getMaxPalpites(){
	return maxPalpites;
}
bool Partida::getCoresRepitidas(){
	return coresRepitidas;
}
int Partida::getNumJogadores(){
	return numJogadores;
}
int Partida::getLevel(){
	return level;
}


