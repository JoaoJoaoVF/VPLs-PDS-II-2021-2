#ifndef GERENTE_HPP
#define GERENTE_HPP

#include <iostream>
#include <iomanip>

//using namespace std;
//removi o namespace

double VALOR_BONIFICACAO = 15.0;

class Gerente : public Funcionario
{
public:
    // double salariobase_gerente; // valor m�nimo recebido pelo gerente
    // string idade_gerente;       //mudei o nome da variavel
    // string nome_gerente;        //mudei o nome da variavel
    // int rg_gerente;             //mudei o nome da variavel
    double bonificacao_gerente; //mudei o nome da variavel

    void print() // imprime na tela os dados do gerente
    {
        std::cout << "[Funcionario]" << std::endl
                  << "[Gerente]" << std::endl;
        Funcionario::print();
        //alterei a impresão
        // << "  Nome: " << nome_funcionario << endl
        // << "  Idade: " << idade_funcionario << endl
        // << "  RGFunc: " << rg_funcionario << endl
        std::cout << "  SalarioBase: R$ " << std::fixed << std::setprecision(2) << salariobase_funcionario << std::endl;
    }

    double
    calcula_BONIFICACAO_GERENTE(int numTOTALVendas)
    {
        // double x; //removi o x uma varivel desncessaria
        return numTOTALVendas * VALOR_BONIFICACAO;
    }
};

#endif
