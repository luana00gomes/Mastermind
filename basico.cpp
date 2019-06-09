#include <String>
#include <iostream>
#include "header.h"

using namespace std;


Partida::Partida(const int &numCores, const int &tamCodigo, const int &maxPalpites, const bool &coresRepitidas, const int &numJogadores, const int &level);
Partida::Partida(); //definir inicio padrao
	
void Partida::setNumCores(const int &numCores){

}

void Partida::setTamCodigo(const int &tamCodigo);
void Partida::setMaxPalpites(const int &maxPalpites);
void Partida::setCoresRepitidas(const bool &coresRepitidas);
void Partida::setNumJogadores(const int &numJogadores);
void Partida::setLevel(const int &level);
	
int Partida::getNumCores();
int Partida::getTamCodigo();
int Partida::getMaxPalpites();
bool Partida::getCoresRepitidas();
int Partida::getNumJogadores();
int Partida::getLevel();

