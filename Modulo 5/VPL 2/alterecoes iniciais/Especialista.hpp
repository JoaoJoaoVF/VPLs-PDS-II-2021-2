#ifndef Especialista_HPP
#define Especialista_HPP

#include "Funcionario.hpp"
#include "Cliente.hpp"

//removi o namespace
//using namespace std;

double PORCENTAGEM = 0.1;
//removi porcentagem desncessaria
//double percWanda = 0.1;

class Especialista : public Funcionario
{
    //removi o public duplicado
    //public:
public:
    std::string especialidade; // especialidade do funcionario

    double comissao(double ValorVenda) // valor da comissao a ser recebida pela venda
    {
        //retornei o valor da comissao direto
        //double c = ValorVenda * porcentagem;
        //return c;
        return ValorVenda * PORCENTAGEM;
    }

    void print()
    {

        std::cout << "[Especialista]" << std::endl;
        Funcionario::print();
        //alterei a impresão
        std::cout << "  Nome: " << nome_funcionario << std::endl
                  << "  SalarioBase: R$ " << std::fixed << std::setprecision(2) << salariobase_funcionario << std::endl;
    }
};

#endif
