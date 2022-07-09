#include "hamburguer.hpp"

std::string Hamburguer::descricao() const
{
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
   *
   * Exemplos:
   * 1X Hamburguer X-tudo artesanal.
   * 1X Hamburguer X-tudo simples.
   * 2X Hamburguer X-tudo artesanal.
   * 2X Hamburguer X-tudo artesanal.
  */
  std::string eh_artesanal;
  if (this->_artesanal == 1)
  {
    eh_artesanal = " artesanal.";
  }
  else
  {
    eh_artesanal = " simples.";
  }
  std::string artesanal = eh_artesanal;
  std::string descricao = std::to_string(this->m_qtd) + "X Hamburguer " + this->_tipo + artesanal;
  std::cout << descricao << std::endl;
  return descricao;
}

Hamburguer::Hamburguer(const std::string &tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario)
{
  // TODO: Implemente este metodo.
  this->_tipo = tipo;
  this->_artesanal = artesanal;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}