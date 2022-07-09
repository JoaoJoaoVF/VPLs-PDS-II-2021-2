#ifndef PROCESSOS_H
#define PROCESSOS_H

#include <iostream>

using namespace std;

struct Processo
{
    int id;
    int prioridade;
    string nome;
    Processo *proximo = nullptr;
    Processo *primeiro = nullptr;
    Processo *primeiro2 = nullptr;
    Processo *ultimo = nullptr;
    Processo *anterior = nullptr;
    Processo *p = nullptr;
    // Processo *proximo;
    //Processo *inicio = nullptr;
    // Processo *fim = nullptr;

    Processo();
    Processo(int id, std::string nome, int prioridade);
    void imprimir_dados();
    //void imprimir_dados(int id, std::string nome, int prioridade);
};

#endif