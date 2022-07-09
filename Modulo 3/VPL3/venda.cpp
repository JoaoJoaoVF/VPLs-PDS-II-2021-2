#include "venda.hpp"

#include <iomanip>

Venda::~Venda()
{
  // TODO: Implemente este metodo
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */
  for (auto it = m_pedidos.begin(); it != m_pedidos.end(); it++)
  {
    delete (*it);
  }
}

void Venda::adicionaPedido(Pedido *p)
{
  // TODO: Implemente este metodo
  m_pedidos.emplace_back(p);
}

void Venda::imprimeRelatorio() const
{
  // TODO: Implemente este metodo
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   * No método Venda::imprimeRelatorio() você comete o mesmo tipo de erro acima. 
   * Entretanto, você utiliza uma instância de Pedido sem nenhuma informação.
  */
  std::string relatorio;
  std::cout << std::fixed << std::setprecision(2);
  int num_pedido = 0;
  float total = 0;
  int entradas;
  for (auto it = m_pedidos.begin(); it != m_pedidos.end(); it++)
  {
    num_pedido += 1;
    std::cout << "Pedido " << num_pedido << std::endl;
    std::cout << (*it)->resumo() << std::endl;
    total += (*it)->calculaTotal();
  }
  if (m_pedidos.size() == num_pedido)
  {
    std::cout << "Relatorio de Vendas" << std::endl;
    std::cout << "Total de vendas: R$ " << total << std::endl;
    std::cout << "Total de pedidos: " << num_pedido << std::endl;
  }
}