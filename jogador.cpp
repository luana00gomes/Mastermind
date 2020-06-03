#include <string>
#include <iostream>
#include "header.h"

void Um_Jogador::setSenha(){
	senha = new int[getTamCodigo()];
	int i=0;
	bool indice[getNumCores()];
	
	for (i=0; i<getNumCores(); i++){
		indice[i]=false;
	}
	for(i=0; i<getTamCodigo(); i++){
		if (getCoresRepitidas()){
			senha[i]=rand()%getNumCores();
		}
		else{
			senha[i]=rand()%getNumCores();
			if(indice[(senha[i])]) i--;
			else indice[(senha[i])] = true;
		}
	
	}
	cout<<"O mastermind já tem a senha. "<<endl;
	cout<<"\n";
}

void Um_Jogador::interage(){
	setPalpite();
	corriguePalpite();
}

void Um_Jogador::corriguePalpite(){
	int i;
	numPretas=0;
	numBrancas=0;
	for(i=0; i<getTamCodigo(); i++){
		if(palpite[i]==senha[i])numPretas++;
		else{
			for (int j=i+1; j<getTamCodigo(); j++){
				if (palpite[i]==senha[i]) numBrancas++;
			}
		}
	}
	cout<<"Correcao:\t"<<numPretas<<"Pretas"<<endl;
	cout<<"Correcao:\t"<<numBrancas<<"Brancas"<<endl;
}

void Dois_Jogadores::setSenha(){
	senha = new int[getTamCodigo()];
	int i=0, j=0;
	bool indice[getNumCores()];
	
	for (i=0; i<getNumCores(); i++){
		indice[i]=false;
	}
	
	cout<<"\n\n*************************************************************"<<endl;
	cout<<"Mastermind, defina sua senha!"<<endl;
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
			cin>>senha[i];
			if(senha[i]<0||senha[i]>getNumCores()) cout<<"Favor, digite um numero dentro do escopo."<<endl;
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
			cin>>senha[i];
			if(senha[i]<0||senha[i]>getNumCores()||indice[(senha[i])]){
				cout<<"Favor, digite um numero válido."<<endl;
			}
			else{
				indice[senha[i]] = true;
				i++;
			}
			
		}
	}
	cout<<"senha: \n";
	for (int i=0; i<getTamCodigo(); i++){
		cout<<cores[(senha[i])]<<" ";
	}
	cout<<"\n";
}

void Dois_Jogadores::interage(){
	setPalpite();
	corriguePalpite();
}

void Dois_Jogadores::corriguePalpite(){
	cout<<"Mastermind, entre com a quantidade de peças colocadas corretamente: "<<endl;
	cin>>numPretas;
	cout<<"Entre com a quantidade de peças colocadas de cores corretas, no lugar errado: "<<endl;
	cin>>numBrancas;
	
	cout<<"Correcao: \t"<<numPretas<<" Pretas"<<endl;
	cout<<"Correcao: \t"<<numBrancas<<" Brancas"<<endl;
	

}
