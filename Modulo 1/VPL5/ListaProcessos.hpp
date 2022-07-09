#ifndef LISTAPROCESSOS_H
#define LISTAPROCESSOS_H

#include <iostream>
#include "Processo.hpp"

using namespace std;
struct ListaProcessos
{
    Processo *id;
    Processo *nome;
    Processo *prioridade;
    // std::string _nome;
    // std::string _id;
    // std::string _prioridade;
    Processo *primeiro = nullptr;
    Processo *proximo = nullptr;
    //Processo *anterior = nullptr;

    Processo *primeiro2 = nullptr;
    Processo *ultimo2 = nullptr;
    int qtde = 0;
    // Processo *proximo = nullptr;

    void adicionar_processo(Processo *proc);

    //   Processo *remover_processo_maior_prioridade();
    //
    //  Processo *remover_processo_menor_prioridade();
    ///
    // Processo *remover_processo_por_id(int id);

    void imprimir_lista();
};

#endif