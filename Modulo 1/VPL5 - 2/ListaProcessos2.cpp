
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
    aux->p = nullptr;

    if (primeiro == nullptr)
    {
        primeiro = proc;
        ultimo = proc;
        anterior = proc;
    }
    else
    {
        p = primeiro;
        while (p->prioridade < aux->prioridade) // define o primeiro valor
        {
            if (p->prioridade < aux->prioridade)
            {
                cout << "p->prioridade " << p->prioridade << " aux->prioridade " << aux->prioridade << endl;
                //anterior = primeiro;
                //ultimo = primeiro;
                primeiro = proc;
                p = proc;
                //cout << "primeiro->prioridade depois " << primeiro->prioridade << " aux->prioridade depois " << aux->prioridade << endl;
            }
            else if (anterior->prioridade < aux->prioridade)
            {
            }
        }
        /*
        else
        {
            cout << "to aquii" << endl;
            ultimo->proximo = proc;
            ultimo = proc;
        }
        */
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
    cout << "acabei" << endl;
}
