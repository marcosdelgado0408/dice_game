/**
* @file gerenciador.cpp
* @brief declaração das classes Jogador e Gerenciador e declaração da função menu();
* @author Marcos V A D Junior
* @since 26/04/2019
* @date 07/05/2019
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef _classes_
#define _classes_

class Jogador{

  private:
    string nome;
    int pontuacao;

  public:
    string getNome();
    void setNome(string nome);

    int getPontuacao();
    void setPontuacao(int pontuacao);
};

class Gerenciador{
  private:
    vector<Jogador> lista_jogadores;

    vector<Jogador> jogadores_atuais; // essa variavel foi criada podermos alterar-la no metodo iniciar_rodada()
  public:
    vector<Jogador> getLista_jogadores();

    /**
     *@brief Método para adicionar jogador a classe através de pushbacks's nos vector's do tipo Jogador 
     */
    void adicionar_jogador();
    
    /**
    *@brief Método para exibir jogadores da partida 
    *@param lista_jogadores Vector do tipo Jogador com a lista dos jogadores
    */
    void exibir_jogadores(vector<Jogador> lista_jogadores);
    
    /**
    *@brief Método para retornar a soma do numero de 2 dados jogados aleatoriamente 
    *@return Soma do valor dos dois dados
    */
    int jogar_dado();

    /**
    *@brief Método onde ocorrerá todo o gerenciamento de uma rodada do jogo
     */
    int iniciar_rodada();
};

/**
 *@brief Funcão do menu 
 */
int menu();

#endif