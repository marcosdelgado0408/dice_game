/**
* @file gerenciador.cpp
* @brief metodos da classe Gerenciador
* @author Marcos V A D Junior
* @since 26/04/2019
* @date 07/05/2019
*/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "classes.h"

using namespace std;

vector<Jogador> Gerenciador::getLista_jogadores() { return lista_jogadores; }

void Gerenciador::adicionar_jogador(){
    char op1;
    cout << "Deseja adicionar jogador?(s/n): ";
    cin >> op1;
    cout << endl;

    if (op1 == 'S' or op1 == 's'){
        Jogador jogador;
        string nome_jogador;

        cout << "Digite o nome do jogador: ";
        getline(cin, nome_jogador);
        getline(cin, nome_jogador);
        cout << endl;

        jogador.setPontuacao(0);
        jogador.setNome(nome_jogador);

        this->lista_jogadores.push_back(jogador);
        this->jogadores_atuais.push_back(jogador);
    }
}





void Gerenciador::exibir_jogadores(vector<Jogador> lista_jogadores){
    for (int i = 0; i < lista_jogadores.size(); i++){
        cout << "--------------------------------------" << endl;
        cout << "Jogador " << i + 1 << " : " << lista_jogadores[i].getNome() << endl;
        cout << "Pontuação: " << lista_jogadores[i].getPontuacao() << endl;
        cout << "--------------------------------------" << endl;
    }
}






int Gerenciador::jogar_dado(){
    int dado1, dado2;

    srand(time(0));

    dado1 = (rand() % 6) + 1;

    srand(time(0));

    dado2 = (rand() % 6) + 1;

    cout << "  Dado 1: " << dado1 << " / ";

    cout << "Dado 2: " << dado2 << endl
         << endl;

    return (dado1 + dado2);
}








int Gerenciador::iniciar_rodada(){
    int n;

    cout << "Digite um numero para ser a pontuação limite que cada jogador poderá alcançar para não perder: ";
    cin >> n;
    cout << endl;

    do{

        cout << "--INICIANDO RODADA--" << endl << endl;

        cout << "Jogadores existentes na partida atual: " << jogadores_atuais.size() << " jogador(es):" << endl;

        exibir_jogadores(jogadores_atuais);

        cout << endl << endl;

        if (jogadores_atuais.size() <= 1){
            break;
        }

        for (int i = 0; i < jogadores_atuais.size(); i++){

            char op;

            if (jogadores_atuais.size() <= 1){
                break;
            }

            cout << "Jogador " << jogadores_atuais[i].getNome() << " deseja:" << endl << endl;
            cout << "  (1) jogar dados" << endl << endl;
            cout << "  (2) parar (e não jogar mais na rodada)" << endl << endl;
            cout << "Digite opção: ";
            cin >> op;
            cout << endl;

            while (op != '1' and op != '2'){
                cout << "opção invalida -> Digite novamente opação: ";
                cin >> op;
                cout << endl;
            }

            if (op == '1'){
                int valor_dado;
                int pontuacao;

                valor_dado = jogar_dado();
                cout << " |Pontuação dos dados: " << valor_dado << "|" << endl << endl;
                pontuacao = jogadores_atuais[i].getPontuacao();
                pontuacao += valor_dado;

                /**
                *se o numero tirado no dado for menor que o valor dado n ele remove a pessoa que tirou isso -> pois ela perdeu
                *se não ele adicionará a pontuação
                */
                if (jogadores_atuais[i].getPontuacao() + valor_dado > n){
                    cout << "--> Jogador " << lista_jogadores[i].getNome() << " passou a pontuação limite e por isso será descartado" << endl
                         << endl;
                    jogadores_atuais.erase(jogadores_atuais.begin() + i);
                }
                else{
                    jogadores_atuais[i].setPontuacao(pontuacao);
                    lista_jogadores[i].setPontuacao(pontuacao);
                }
            }

            if (op == '2'){
                cout << "--> Jogador " << lista_jogadores[i].getNome() << " optou por desisistir e será removido da rodada" << endl
                     << endl;
                jogadores_atuais.erase(jogadores_atuais.begin() + i);
            }
        }

    } while (jogadores_atuais.size() > 0);




    cout << "Todos os jogadores da rodada e suas pontuações: " << endl;
    exibir_jogadores(lista_jogadores);
    cout << endl << endl;


    int maior_num = lista_jogadores[0].getPontuacao();
    int indice_maior = 0;

    /**
     * neste for ele vai achar o maior numero para poder imprimir o jogador ganhador e sua posição
     */
    for (int i = 0; i < lista_jogadores.size(); i++){
        if (lista_jogadores[i].getPontuacao() > maior_num){
            maior_num = lista_jogadores[i].getPontuacao();
            indice_maior = i;//indice maior servira para imprimir o nome da pessoa que ganhou da posição i do vetor
        }
    }


    //se for igual imprimir empate
    int contador = 0;
    for (int i = 0; i < lista_jogadores.size(); i++){ // so vai ate -1 porque no ultimo elemnto não é necessario comparar com ninguém
        int elemento = lista_jogadores[i].getPontuacao();
        for (int j = i + 1; j < lista_jogadores.size(); j++){
            if (elemento == lista_jogadores[j].getPontuacao()){
                contador++;//se elemento for igual ao numero da posição j ele adicionará ao contador
            }
        }
    }



    if (contador+1 == lista_jogadores.size()){
        cout << "Empate!!" << endl<< endl;
    }
    else{
        cout << "Jogador ganhador: " << lista_jogadores[indice_maior].getNome() << endl;
        cout << "Com pontuação de " << lista_jogadores[indice_maior].getPontuacao() << " pontos." << endl;
    }






    /**
 * voltando com as alterações de cada jogador para o original e setando a pontuação de cada um com 0 
*/
    for (int i = 0; i < lista_jogadores.size(); i++){
        lista_jogadores[i].setPontuacao(0);
    }

    jogadores_atuais.clear();

    for (int i = 0; i < lista_jogadores.size(); i++){
        Jogador jogador_backup;
        jogador_backup.setNome(lista_jogadores[i].getNome());
        jogador_backup.setPontuacao(lista_jogadores[i].getPontuacao());
        jogadores_atuais.push_back(jogador_backup);
    }


    cout << endl << endl;

}













