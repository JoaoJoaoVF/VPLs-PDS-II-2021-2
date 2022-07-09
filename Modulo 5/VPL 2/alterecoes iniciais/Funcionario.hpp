#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <iostream>
#include <iomanip>

//removi o namespace
//using namespace std;

class Funcionario
{
public:
    double salariobase_funcionario; // valor m�nimo recebido pelo funcion�rio
    std::string idade_funcionario;  //mudei o nome da variavel
    std::string nome_funcionario;   //mudei o nome da variavel
    int rg_funcionario;             //mudei o nome da variavel

    void print()
    {
        std::cout << "[Funcionario]" << std::endl
                  << "  Idade: " << idade_funcionario << std::endl
                  << "  RGFunc: " << rg_funcionario << std::endl;
    }
    //REMOVI DA FUNÇÃO FUNCIONAIRO UMA IMPRESSAO DESNCECESSARIA
    // void print_oi(){
    //     cout << "Tchau" << endl;
    // }
};

#endif
