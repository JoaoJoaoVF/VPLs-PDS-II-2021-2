#include "pizza.hpp"

std::string Pizza::descricao() const
{
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   * esta saindo 2X Pizza Calabresa, 4 pedacos e borda recheada
   * era p/ sair 2X Pizza Calabresa, 4 pedacos e borda recheada.
   */
  std::string tem_borda_recheada;
  if (this->_borda_recheada == 1)
  {
    tem_borda_recheada = " ";
  }
  else
  {
    tem_borda_recheada = " sem ";
  }
  std::string borda_recheada = tem_borda_recheada;
  std::string a = std::to_string(this->m_qtd) + "X Pizza " + this->_sabor + ", ";
  std::string b = std::to_string(this->_pedacos) + " pedacos e" + borda_recheada + "borda recheada.";
  std::string descricao = a + b;
  std::cout << descricao << std::endl;
  return descricao;
}

Pizza::Pizza(const std::string &sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario)
{
  // TODO: Implemente este metodo.
  this->_sabor = sabor;
  this->_pedacos = pedacos;
  this->_borda_recheada = borda_recheada;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}