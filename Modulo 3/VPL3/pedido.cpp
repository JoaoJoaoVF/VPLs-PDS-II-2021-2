#include "pedido.hpp"

Pedido::~Pedido()
{
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */
  for (auto it = m_produtos.begin(); it != m_produtos.end(); it++)
  {
    delete (*it); //&m_produtos;
  }
}

void Pedido::setEndereco(const std::string &endereco)
{
  // TODO: Implemente este metodo.
  this->m_endereco = endereco;
}

float Pedido::calculaTotal() const
{
  // TODO: Implemente este metodo.
  float total = 0;
  for (auto it = m_produtos.begin(); it != m_produtos.end(); it++)
  {
    total += ((*it)->getValor() * (*it)->getQtd());
  }
  return total;
}

void Pedido::adicionaProduto(Produto *p)
{
  // TODO: Implemente este metodo.
  m_produtos.emplace_back(p);
}

std::string Pedido::resumo() const
{
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
    */
  std::string res;
  int entradas = 0;
  for (auto it = m_produtos.begin(); it != m_produtos.end(); ++it)
  {
    while (res == (*it)->descricao())
    {
      res = (*it)->descricao();
    }
    if (entradas == m_produtos.size())
    {
      break;
    }
  }
  return res + "Endereco: " + this->m_endereco;
}