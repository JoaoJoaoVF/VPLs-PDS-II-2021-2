
#include "Processo.hpp"
#include "ListaProcessos.hpp"

#include <iostream>
#include <cmath>

void ListaProcessos::adicionar_processo(Processo *proc)
{
    Processo *aux = new Processo;
    aux->id = proc->id;
    aux->nome = proc->nome;
    aux->prioridade = proc->prioridade;
    aux->primeiro = nullptr;
    aux->ultimo = nullptr;
    aux->anterior = nullptr;

    if (primeiro == nullptr)
    {
        primeiro = aux;
        ultimo = aux;
        //anterior = aux;
    }
    else
    {
        if (aux->prioridade > primeiro->prioridade)
        {
            //primeiro->proximo = primeiro;
            //ultimo->proximo = primeiro;
            ultimo = primeiro;
            anterior = primeiro;
            primeiro = aux;

            cout << "aqui" << endl;
        }
        else
        {
            ultimo->proximo = aux;
            ultimo = aux;
            cout << "la " << endl;
        }
    }
}

//Processo ListaProcessos::*remover_processo_maior_prioridade()
///{
//}
//Processo ListaProcessos::*remover_processo_menor_prioridade()
//{
//}

//Processo ListaProcessos::*remover_processo_por_id(int id)
//{
//}
void ListaProcessos::imprimir_lista()
{

    //Processo p;
    Processo *aux = primeiro;
    //int i = 0;
    while (aux != nullptr)
    {
        cout << aux->id << " " << aux->nome << " " << aux->prioridade << endl;
        //*aux.imprimir_dados();
        aux = aux->proximo;

        //aux = nullptr;
        //i++;
    }
}
