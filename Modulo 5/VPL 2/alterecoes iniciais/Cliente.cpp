//#include <iostream> //tirei no cpp e coloque no hpp
//#include <string> //biblioteca ja no arquivo hpp
#include "Cliente.hpp"

void Cliente::print()
{

	std::cout << "[Cliente]" << std::endl
			  << "Nome: " << nome_cliente << ",  Endereco: " << endereco_cliente << ",  CEP: " << cep_cliente << std::endl;
}
