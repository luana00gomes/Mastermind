#include <String>
#include <iostream>

using namespace std;

//A partir dos dados coletados com o usuário, cria-se o obj partida que é passado no construtor do obj jogo
Class Partida{
	int numCores;
	int tamCodigo;
	int maxPalpites;
	bool coresRepitidas;
	int numJogadores;
	int level;

	public:
	Partida(const int &numCores, const int &tamCodigo, const int &maxPalpites, const bool &coresRepitidas, const int &numJogadores, const int &level);
	Partida(); //definir inicio padrao
	
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
};

Class Jogo: public Partida{
	Partida partida;
	int *cores;
	
	void setCores(Partida partida);
	
};
