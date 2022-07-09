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
        delete (*it); //m_pedidos.erase(it);
    }
}

void Venda::adicionaPedido(Pedido *p)
{
    // TODO: Implemente este metodo

    m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const
{
    // TODO: Implemente este metodo
    /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */
    Pedido p;
    for (auto it = m_pedidos.begin(); it != m_pedidos.end(); it++)
    {
        std::cout << p.resumo() << std::endl;
    }
}