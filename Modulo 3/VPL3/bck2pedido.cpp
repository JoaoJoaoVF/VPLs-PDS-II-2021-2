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
    //Produto p;
    float total = -1;
    //Produto p;
    for (Produto *c : m_produtos)
    {
        total += c->getValor();
    }
    //{for (auto it = m_produtos.begin(); it != m_produtos.end(); it++)
    //{
    //m
    //  total += ; //getValor(m_produtos);
    //}
    return total;
}

void Pedido::adicionaProduto(Produto *p)
{
    // TODO: Implemente este metodo.
    m_produtos.push_back(p);
}

std::string Pedido::resumo() const
{
    // TODO: Implemente este metodo.
    /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   * No método Pedido::resumo() você está utilizando ponteiros nulos (h, p e j). 
   * Na verdade, estas variáveis não são necessárias. Você precisa utilizar o objeto cujo iterador it está apontando.
   */
    //Produto *c;
    std::string pedidoH;
    int pedido = 0;
    std::string resumo;
    for (auto it = m_produtos.begin(); it != m_produtos.end(); it++)
    {
        std::cout << "dentro do for" << std::endl;
        //for (int i = 0; i < 2; i++)
        pedido += 1;
        std::string pedido = "Pedido " + pedido;
        //pedidoH = it->descricao();
        //pedidoH = it.descricao();
        //pedidoH = c->descricao();
        std::string endereco = "Endereco: " + this->m_endereco;
        resumo = pedido + "\n" + pedidoH + "\n" + endereco + "\n";
        std::cout << resumo << std::endl;
        return resumo;
        // }
    }
    std::cout << "passou do for" << std::endl;
}