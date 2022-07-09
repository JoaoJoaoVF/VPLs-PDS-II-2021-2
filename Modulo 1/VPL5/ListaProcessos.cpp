
#include "Processo.hpp"
#include "ListaProcessos.hpp"

#include <iostream>
#include <cmath>

void ListaProcessos::adicionar_processo(Processo *proc)
{
    //Processo *a = primeiro2;

    proc->proximo = nullptr;
    /*
    if (primeiro2 == nullptr)
    {
        primeiro2 = proc;
        ultimo2 = proc;
        //   cout << "primeiro " << primeiro2->nome << " ultimo " << ultimo2->nome << endl;
    }
    else
    {
        ultimo2->proximo = proc;
        ultimo2 = proc;
    }
    */
    if (primeiro == nullptr)
    {
        primeiro = proc;
        //ultimo2 = proc;
        cout << "primeiro " << primeiro->nome << endl; //<< " ultimo " << ultimo->nome << endl;
    }
    else
    {
        Processo *p = primeiro;
        Processo *a = nullptr;
        while (p != nullptr)
        {
            a = p;
            if (p->proximo == nullptr)
            {
                cout << " aqui 1 " << endl;
                p->proximo = proc;
                proc->proximo = nullptr;
            }
            else
            {
                if (p->prioridade >= proc->prioridade)
                {
                    cout << " aqui 2 " << endl;
                    a->proximo = p;
                    p->proximo = proc;
                    //a->proximo = proc;
                }
                else
                {
                    cout << " aqui 3" << endl;
                    a->proximo = proc;
                    proc->proximo = p;
                    //p->proximo = nullptr;
                }
            }
            p = p->proximo;
            /*
            if (p != nullptr && p->prioridade < proc->prioridade) // p < proc

                else
                {
                    if (p == nullptr)
                    {
                        cout << " aqui 2" << endl;
                        proc->proximo = p;
                        a->proximo = proc;
                    }
                    else // p >= proc, p entra antes do proc
                }

            
            if (p == nullptr)
                cout << "fim de lista ";
            else
            {
                cout << " p nome " << p->nome;
            }
            cout << " a nome " << a->nome << endl;*/
        }
        cout << " " << endl;
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

    Processo p;
    Processo *aux = primeiro;
    int i = 0;
    while (aux != nullptr)
    {
        cout << aux->id << " " << aux->nome << " " << aux->prioridade << endl;
        //*aux.imprimir_dados();
        aux = aux->proximo;

        //aux = nullptr;
        i++;
    }
}
