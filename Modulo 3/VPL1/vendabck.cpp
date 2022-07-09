#include "venda.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>

//using namespace std;

void Venda::adicionaCelular(const Celular &celular)
{
    // TODO: Implemente este metodo
    m_celulares.push_back(celular);
}

void Venda::ordena()
{
    // TODO: Implemente este metodo
    // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
    // a fabricante antes do modelo do celular
    for (auto it = m_celulares.begin(); it != m_celulares.end(); it++)
    {
        m_celulares.sort();
    }
}

void Venda::recarregaEstoque(int cod, int qtd)
{
    // TODO: Implemente este metodo
    Celular cel;
    for (auto it = m_celulares.begin(); it != m_celulares.end(); it++)
    {
        if (cel._cod == cod)
        {
            cel._qtd += qtd;
        }
    }
}

void Venda::efetuaVenda(int cod, int qtd)
{
    // TODO: Implemente este metodo
    /**
   * Observe na descricao do enunciado que nao e permita a venda de um modelo
   * cuja quantidade seja maior que a quantidade atual em estoque.
   * Ex: Se existirem apenas 5 celulares Motorola Moto G50 em estoque, vendas a
   * partir de 6 unidades devem ser ignoradas.
   */
    //std::cout << "ven" << std::endl;
    Celular cel;
    for (auto it = m_celulares.begin(); it != m_celulares.end(); it++)
    {
        if (cel._qtd > qtd)
        {
            qtd = cel._qtd;
        }
        if (cel._cod == cod)
        {
            cel._qtd -= qtd;
        }
    }
}

void Venda::aplicaDesconto(const std::string &fabricante, float desconto)
{
    // TODO: Implemente este metodo
    Celular cel;
    for (auto it = m_celulares.begin(); it != m_celulares.end(); it++)
    {
        if (cel._fabricante == fabricante)
        {
            cel._valor -= (cel._valor * (desconto / 100));
        }
    }
}

void Venda::removeModelo(int cod)
{
    // TODO: Implemente este metodo
    Celular cel;
    for (auto it = m_celulares.begin(); it != m_celulares.end(); it++)
    {
        if (cel._cod == cod)
        {
            m_celulares.remove(cel);
            break;
        }
    }
}

void Venda::imprimeEstoque() const
{
    // TODO: Implemente este metodo.
    /**
   * Aqui voce tera que imprimir a lista de celulares em estoque com as
   * restricoes descritas no enunciado do problema. Notem no exemplo que a
   * primeira letra da cor do celular fica maiuscula. Outra coisa, se houver
   * apenas um item em estoque de determinado modelo de celular, voce tera que
   * imprimir '1 restante' e nao '1 restantes'. Por ultimo, apenas modelos de
   * celulares com pelo menos um item em estoque deverao ser exibidos.
   */
    for (Celular c : m_celulares)
    {
        std::cout << std::fixed << std::setprecision(0);
        if (c._qtd > 1)
        {
            std::cout << c._fabricante << " "
                      << c._modelo << ", "
                      << c._armazenamento << "GB, "
                      << c._memoria << "GB RAM, "
                      << c._peso * 1000 << " gramas, "
                      << c._cor << ", "
                      << c._qtd << " restantes, ";
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "R$ " << c._valor
                      << std::endl;
        }
        std::cout << std::fixed << std::setprecision(0);
        if (c._qtd == 1)
        {
            std::cout << c._fabricante << " "
                      << c._modelo << ", "
                      << c._armazenamento << "GB, "
                      << c._memoria << "GB RAM, "
                      << c._peso * 1000 << " gramas, "
                      << c._cor << ", "
                      << c._qtd << " restante, ";
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "R$ " << c._valor
                      << std::endl;
        }
        if (c._qtd <= 0)
        {
        }
    }
}