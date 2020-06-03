#include <string>
#include <iostream>

using namespace std;

class Chave;

class Partida{
	protected:
	int numCores;
	int tamCodigo;
	bool coresRepitidas;
	int numJogadores;
	int maxPalpites;
	int level;
	int *senha;
	
	public:
	Partida(const int &numCores, const int &tamCodigo, const int &maxPalpites, const bool &coresRepitidas, const int &numJogadores, const int &level);
	Partida(); 
	void inicia();
		
	void setNumCores(const int &numCores);
	void setTamCodigo(const int &tamCodigo);
	void setMaxPalpites(const int &maxPalpites);
	void setCoresRepitidas(const bool &coresRepitidas);
	void setNumJogadores(const int &numJogadores);
	void setLevel(const int &level);
	
	int getNumCores();
	int getTamCodigo();
	int getMaxPalpites();
	bool getCoresRepitidas();
	int getNumJogadores();
	int getLevel();
	
	void freeSenha();
	virtual void setSenha()=0;
};

class Chave: public Partida{
	protected:
	string *cores;
	int *palpite;
	int numPalpites=0;
	int numPretas=0;
	int numBrancas=0;
	
	public:
	Chave();
	void setCores();
	void setSenha(); 
	void setPalpite();
	
	int* getPalpite();
	int* getSenha();
	int getNumPretas();
	int getNumBrancas();
	
	void freeAtributos();
	
	template <typename T>
	T getT_jogador();
};

template <typename T>
class Jogo{
	Chave chave;
	T t_jogador;
	
	public:
	Jogo(Chave chave, T t_jogador);
	void start();
	void iniciaT();
};

class Um_Jogador: public Chave{
	public:
	void setSenha();
	void interage();
	void corriguePalpite();
};


class Dois_Jogadores: public Chave{
	public:
	void interage();
	void setSenha();
	void corriguePalpite();
};

template <typename T>
T Chave::getT_jogador(){
	if (numJogadores == 1){
		Um_Jogador um_jogador;
		return um_jogador;
	}else{
		Dois_Jogadores dois_jogadores;
		return dois_jogadores;
	
	}
}

template <typename T>	
Jogo<T>::Jogo(Chave chave, T t_jogador): chave(chave), t_jogador(t_jogador){}

template <typename T>	
void Jogo<T>::start(){
	iniciaT();
	t_jogador.setCores();
	t_jogador.setSenha();
	int i;
	for(i=0; (i < chave.getMaxPalpites() && t_jogador.getNumPretas()!=t_jogador.getTamCodigo()); i++){
		cout<<"Restam "<<chave.getMaxPalpites()-i<<"tentativas."<<endl;
		t_jogador.interage();
	}
	if(t_jogador.getNumPretas()==t_jogador.getTamCodigo()){
		cout<<"Hacker venceu!"<<endl;
	}else{
		cout<<"Mastermind venceu!"<<endl;
	}
	t_jogador.freeAtributos();
}


template <typename T>	
void Jogo<T>::iniciaT(){
	t_jogador.setNumJogadores (chave.getNumJogadores());
	t_jogador.setTamCodigo (chave.getTamCodigo());
	t_jogador.setLevel (chave.getLevel());
	t_jogador.setCoresRepitidas (chave.getCoresRepitidas());
	t_jogador.setMaxPalpites (chave.getMaxPalpites());
	t_jogador.setNumCores (chave.getNumCores());
}
