#include "celular.hpp"
#include <iostream>

// TODO: Inicialize aqui sua variavel estatica. Caso tenha optado por essa
// solucao.

Celular::Celular(std::string modelo,
                 std::string fabricante,
                 int armazenamento,
                 int memoria,
                 double peso,
                 std::string cor,
                 int qtd,
                 float valor)
{
  // TODO: Implemente este metodo
  codigo_celular++;
  this->_modelo = modelo;
  this->_fabricante = fabricante;
  this->_armazenamento = armazenamento;
  this->_memoria = memoria;
  this->_peso = peso;
  this->_cor = cor;
  this->_qtd = qtd;
  this->_valor = valor;
  this->_cod = codigo_celular;
}

int Celular::codigo_celular = 0;

bool Celular::operator<(const Celular &other)
{
  // TODO: Implemente este metodo.
  // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
  // a fabricante antes do modelo do celular
  if ((this->_fabricante == other._fabricante))
  {
    if (this->_modelo < other._modelo)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  if ((this->_fabricante < other._fabricante))
  {
    return true;
  }

  else
  {
    return false;
  }
  for (auto &c : this->_cor)
    this->_cor[0] = toupper(this->_cor[0]);
}