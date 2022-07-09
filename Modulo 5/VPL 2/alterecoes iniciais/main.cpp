#include <iostream>

#include "Cliente.hpp"
#include "Funcionario.hpp"
#include "Especialista.hpp"
#include "Venda.hpp"
#include "Gerente.hpp"
using namespace std;

int main()
{
     Cliente cliente1;
     cliente1.nome_cliente = "J. Jonah Jameson";
     cliente1.endereco_cliente = "Nova York";
     cliente1.cep_cliente = "35690000";
     cliente1.print();

     Cliente cliente2;
     cliente2.nome_cliente = "Norman Osborn";
     cliente2.endereco_cliente = "Hartlford";
     cliente2.cep_cliente = "22061955";
     cliente2.print();

     Cliente cliente3;
     cliente3.nome_cliente = "Otto Octavius";
     cliente3.endereco_cliente = "Schenectady";
     cliente3.cep_cliente = "24051953";
     cliente3.print();

     Cliente cliente4;
     cliente4.nome_cliente = "Bruce Benner";
     cliente4.endereco_cliente = "Dayton";
     cliente4.cep_cliente = "22111967";
     cliente4.print();

     Cliente cliente5;
     cliente5.nome_cliente = "Steve Rogers";
     cliente5.endereco_cliente = "Lower East Side";
     cliente5.cep_cliente = "13061981";
     cliente5.print();

     Especialista e01;
     int numAtendimentos01 = 0;
     double comissao01 = 0;
     e01.nome_funcionario = "Peter Parker";
     e01.idade_funcionario = "46";
     e01.rg_funcionario = 27061975;
     e01.salariobase_funcionario = 3000;
     e01.especialidade = "Fotografia";

     Especialista e02;
     int numAtendimentos02 = 0;
     double comissao02 = 0;
     e02.nome_funcionario = "Tony Stark";
     e02.idade_funcionario = "56";
     e02.rg_funcionario = 4041965;
     e02.salariobase_funcionario = 1000;
     e02.especialidade = "Consertos de equipamentos eletronicos";

     Especialista e03;
     int numAtendimentos03 = 0;
     double comissao03 = 0;
     e03.nome_funcionario = "Wanda Maximoff";
     e03.idade_funcionario = "32";
     e03.rg_funcionario = 16021989;
     e03.salariobase_funcionario = 5000;
     e03.especialidade = "Engenharia e Designeeeeer";

     Gerente g01;
     double bonificacao01 = 0;
     g01.nome_funcionario = "Nick Fury";
     g01.idade_funcionario = "72";
     g01.rg_funcionario = 21121948;
     g01.salariobase_funcionario = 10000;

     Venda v01;
     v01.cliente = "J. Jonah Jameson";
     v01.esp = e01;
     v01.descricao = "Fotos do Homem Aranha";
     v01.valor_venda = 100;
     comissao01 += e01.comissao(v01.valor_venda);
     numAtendimentos01 += 1;

     Venda v02;
     v02.cliente = "Bruce Benner";
     v02.esp = e02;
     v02.descricao = "Troca da tela do telefone";
     v02.valor_venda = 100;
     comissao02 += e02.comissao(v02.valor_venda);
     numAtendimentos02 += 1;

     Venda v03;
     v03.cliente = "Norman Osborn";
     v03.esp = e01;
     v03.descricao = "Fotos do novo planador";
     v03.valor_venda = 150;
     comissao01 += e01.comissao(v03.valor_venda);
     numAtendimentos01 += 1;

     Venda v04;
     v04.cliente = "J. Jonah Jameson";
     v04.esp = e02;
     v04.descricao = "Recarga de cartucho";
     v04.valor_venda = 10;
     comissao02 += e02.comissao(v04.valor_venda);
     numAtendimentos02 += 1;

     Venda v05;
     v05.cliente = "Bruce Benner";
     v05.esp = e03;
     v05.descricao = "Reconstrucao de Predio";
     v05.valor_venda = 10000;
     comissao03 += e03.comissao(v05.valor_venda);
     numAtendimentos03 += 1;

     Venda v06;
     v06.cliente = "Steve Rogers";
     v06.esp = e03;
     v06.descricao = "Decoracao de Apartamento no Brooklyn";
     v06.valor_venda = 3000;
     comissao03 += e03.comissao(v06.valor_venda);
     numAtendimentos03 += 1;

     v06.descricao = "Decoracao de Apartamento no Brooklyn";
     v06.valor_venda = 3000;

     Venda v07;
     v07.cliente = "J. Jonah Jameson";
     v07.esp = e03;
     v07.descricao = "Reforma do Clarim Diario";
     v07.valor_venda = 5000;
     comissao03 += e03.comissao(v07.valor_venda);
     numAtendimentos03 += 1;

     Venda v08;
     v08.cliente = "Otto Octavius";
     v08.esp = e02;
     v08.descricao = "Formatacao do PC";
     v08.valor_venda = 80;
     comissao02 += e02.comissao(v08.valor_venda);
     numAtendimentos02 += 1;

     cout << " \n \n           Relatorio das Vendas \n"
          << endl;

     v01.print();
     cout << " Descricao: " << v01.descricao << endl;

     v02.print();
     cout << " Descricao: " << v02.descricao << endl;

     v03.print();
     cout << " Descricao: " << v03.descricao << endl;

     v04.print();
     cout << " Descricao: " << v04.descricao << endl;

     v05.print();
     cout << " Descricao: " << v05.descricao << endl;

     v06.print();
     cout << " Descricao: " << v06.descricao << endl;

     v06.print();
     cout << " Descricao: " << v06.descricao << endl;

     v07.print();
     cout << " Descricao: " << v07.descricao << endl;

     v08.print();
     cout << " Descricao: " << v08.descricao << endl;

     cout << " \n \n           Relatorio dos Funcionarios \n"
          << endl;
     e01.print();
     cout << "Num Atendimentos: " << numAtendimentos01 << endl;
     cout << "Salario Total: " << e01.salariobase_funcionario + comissao01 << endl;

     e02.print();
     cout << "Num Atendimentos: " << numAtendimentos02 << endl;
     cout << "Salario Total: " << e02.salariobase_funcionario + comissao02 << endl;

     e03.print();
     cout << "Num Atendimentos: " << numAtendimentos03 << endl;
     cout << "Salario Total: " << e03.salariobase_funcionario + comissao03 << endl;

     int NUMTOTALservicos = 0;
     NUMTOTALservicos = numAtendimentos01 + numAtendimentos02 + numAtendimentos03;
     g01.bonificacao_gerente = g01.calcula_BONIFICACAO_GERENTE(NUMTOTALservicos);
     g01.print();
     cout << "Salario Total: " << g01.salariobase_funcionario + g01.bonificacao_gerente << endl;

     return 0;
}
