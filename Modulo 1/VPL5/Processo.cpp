#include "Processo.hpp"
#include "ListaProcessos.hpp"

#include <iostream>
#include <cmath>

Processo::Processo()
{
}

Processo::Processo(int id, std::string nome, int prioridade)
{
    this->id = id;
    this->nome = nome;
    this->prioridade = prioridade;
    this->qtde = 0;
}
void Processo::imprimir_dados()
{
    Processo *proc;
    cout << proc->id << " " << proc->nome << " " << proc->prioridade << endl;
}
