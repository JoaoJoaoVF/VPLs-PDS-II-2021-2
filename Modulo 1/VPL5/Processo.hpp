#ifndef PROCESSOS_H
#define PROCESSOS_H

#include <iostream>

using namespace std;

struct Processo
{
    int id;
    int prioridade;
    string nome;

    Processo *primeiro = nullptr;
    Processo *proximo = nullptr;
    Processo *anterior = nullptr;

    Processo *primeiro2 = nullptr;
    Processo *ultimo2 = nullptr;
    // Processo *proximo;
    //Processo *inicio = nullptr;
    // Processo *fim = nullptr;
    int qtde = 0;

    Processo();
    Processo(int id, std::string nome, int prioridade);
    void imprimir_dados();
    //void imprimir_dados(int id, std::string nome, int prioridade);
};

#endif