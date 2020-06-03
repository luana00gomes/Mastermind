#include <string>
#include <new>
#include <iostream>
#include "header.h"

using namespace std;


int main (){

	
	Chave chave;
	chave.inicia();
	if (chave.getNumJogadores() == 1) {
		Um_Jogador um_jogador;
		Jogo <Um_Jogador>jogo(chave, um_jogador);
		jogo.start();
		
	}else{
		Dois_Jogadores dois_jogadores;
		
		Jogo <Dois_Jogadores>jogo(chave, dois_jogadores);
		jogo.start();
	}
}
