// NÃO ALTERE ESSA LINHA
//#include "avaliacao_basica_escalonador.hpp"

#include <iostream>
#include <iomanip>

#include "ListaProcessos.hpp"
#include "Processo.hpp"

int main()
{
    //int qtde = 0;
    Processo *p;
    ListaProcessos lp;

    char codigo;
    int id = 0, prioridade = 0;
    std::string nome;
    while (cin >> codigo)
    {
        switch (codigo)
        {

        //comando para adicionar um novo processo na lista de acordo com os parâmetros passados.
        case 'a':
        {

            cin >> id >> nome >> prioridade;
            //cout << "x, y e forca " << x << " " << y << " " << forca << endl;
            p = new Processo(id, nome, prioridade);
            lp.adicionar_processo(p);
            //cout << "naves[i] " << i << " " << naves[i]->x << " " << naves[i]->y << " " << naves[i]->forca << endl;
            // qtde += 1;
            break;
        }
        // comando para remover o processo de MAIOR prioridade da lista.
        //case 'm':
        // break;

        //comando para remover o processo de MENOR prioridade da lista
        //case 'n':
        //break;

        //comando para remover um processo da lista de acordo com o ID informado
        //case 'r id':
        //break;

        //comando para imprimir a lista
        case 'p':
        {
            //int x = *qtde;
            lp.imprimir_lista();
            break;
        }

            //chamar a função 'avaliacao_basica()
            // case 'b':
            //avaliacao_basica();
            //break;
        }
    }
    return 0;
}