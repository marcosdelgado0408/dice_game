/**
* @file gerenciador.cpp
* @brief Implementação da função menu()
* @author Marcos V A D Junior
* @since 26/04/2019
* @date 07/05/2019
*/
#include <iostream>
#include <string>
#include <vector>
#include "classes.h"

int menu(){

    Gerenciador gerenciador_jogo;
    char op1;

    while (op1 != '0'){

        cout << "|                       MENU DO JOGO                   |" << endl << endl << endl;
        cout << "|  (1) Quantidade de jogadores atual                   |" << endl;
        cout << "|  (2) Adicionar um jogador a partida atual            |" << endl;
        cout << "|  (3) Exibir dados dos jogadores                      |" << endl;
        cout << "|  (4) Iniciar partida                                 |" << endl;
        cout << "|  (0) sair                                            |" << endl << endl << endl;
        cout << endl << endl;

        cout << "Digite opção: ";
        cin >> op1;
        cout << endl;

        switch (op1){
        case '1':
            cout << "Quantidade de jogadores atual: " << gerenciador_jogo.getLista_jogadores().size() << endl << endl;
            break;
        case '2':
            gerenciador_jogo.adicionar_jogador();
            cout << endl;
            break;

        case '3':
            gerenciador_jogo.exibir_jogadores(gerenciador_jogo.getLista_jogadores());
            break;

        case '4':
            gerenciador_jogo.iniciar_rodada();
            break;

        case '0':
            return 0;

        default:
            break;
        }
    }
}