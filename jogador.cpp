/**
* @file gerenciador.cpp
* @brief metodos da classe Jogador
* @author Marcos V A D Junior
* @since 26/04/2019
* @date 07/05/2019
*/

#include <iostream>
#include <string>
#include "classes.h"

using namespace std;

string Jogador::getNome() { return nome; }
void Jogador::setNome(string nome) { this->nome = nome; }

int Jogador::getPontuacao() { return pontuacao; }
void Jogador::setPontuacao(int pontuacao) { this->pontuacao = pontuacao; }
