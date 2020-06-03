#include <string>
#include <iostream>
#include <new>
#include <stdlib.h>
#include "header.h"

using namespace std;
Chave::Chave(){}

int Chave::getNumPretas(){return numPretas;}
int Chave::getNumBrancas(){return numBrancas;}
	
void Chave::setCores(){

	cores = new string[getNumCores()];
	cores[0]="Verde";
	cores[1]="Preto";
	cores[2]="Branco";
	cores[3]="Rosa";
	int i=3;
	
	while(i<getNumCores()){

		if(i==4){ cores[4]="Azul";}
		else{
			if(i==5){ cores[5]="Vermelho";}
			else{
				if(i==6){cores[6]="Roxo";}
				else{
					if(i==7){cores[7]="Amarelo";}
					else{
						if(i==8){cores[8]="Laranja";}
						else{
							if(i==9)cores[9]="Marrom";
						}
					}
				}
			}
		}
		i=i+1;
	}
	
	return;
}

void Chave::freeAtributos(){
	delete []cores;
	delete []senha;
	delete []palpite;
}
void Chave::setSenha(){
}

void Chave::setPalpite(){
	numPalpites++;
	
	palpite = new int[getTamCodigo()];
	int i=0, j=0;
	bool indice[getNumCores()];
	
	for (i=0; i<getNumCores(); i++){
		indice[i]=false;
	}
	
	cout<<"\n\n*************************************************************"<<endl;
	cout<<"Hacker, faça seu chute."<<endl;
	if(getCoresRepitidas()){
		cout<<"Cores:"<<endl;
		i=0;
		while(i<getNumCores()){
			cout<<"\t("<<i<<") "<<cores[i]<<endl;
			i++;
		}
		i=0;
		while(i<getTamCodigo()){
			cout<<"Escolha a cor da posicao "<<i<<"."<<endl;
			cin>>palpite[i];
			if(palpite[i]<0||palpite[i]>getNumCores()) cout<<"Favor, digite um numero dentro do escopo."<<endl;
			else{i++;}
		}
	}
	else{
		
		i=0;
		
		while (i<getTamCodigo()){
			cout<<"Cores:"<<endl;
			j=0;
			while(j<getNumCores()){
				if(indice[j])cout<<"USADO  ";
				cout<<"\t("<<j<<") "<<cores[j]<<endl;
				j++;
			}
			cout<<"Escolha a cor da posicao "<<i<<"."<<endl;
			cin>>palpite[i];
			if(palpite[i]<0||palpite[i]>getNumCores()||indice[(palpite[i])]){
				cout<<"Favor, digite um numero válido."<<endl;
			}
			else{
				indice[palpite[i]] = true;
				i++;
			}
			
		}
	}
	cout<<"Palpite: \n";
	for (int i=0; i<getTamCodigo(); i++){
		cout<<cores[(palpite[i])]<<" ";
	}
	cout<<"\n";
}

int* Chave::getPalpite(){
	return palpite;
}

int* Chave::getSenha(){
	return senha;
}
