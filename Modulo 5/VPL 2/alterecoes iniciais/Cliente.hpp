#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream> //inclui no hpp e tirei no cpp
#include <string>
//removi o namespace
//using namespace std;

class Cliente
{

public:
	std::string nome_cliente;	  //mudei o nome da variavel
	std::string endereco_cliente; //mudei o nome da variavel
	std::string cep_cliente;	  //mudei o nome da variavel
	//Removi a string altura dos pais
	//string AlturaDosPais;

	void print(); // imprime na tela os dados de um cliente cadastrado
};

#endif
