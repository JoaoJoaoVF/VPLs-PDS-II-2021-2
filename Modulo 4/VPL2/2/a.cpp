#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string &mercadoria, unsigned int qtd)
{
    // TODO
    m_produtos.insert(std::pair<std::string, unsigned int>(mercadoria, qtd));
}

void Estoque::sub_mercadoria(const std::string &mercadoria, unsigned int qtd)
{
    // TODO
    for (auto &it : m_produtos)
    {
        std::cout << "sub_mercadoria" << std::endl;
        if (it.first == mercadoria)
        {
            std::cout << it.first << " " << it.second << " " << qtd << std::endl;
            if (it.second > qtd)
            {
                it.second = qtd;
            }
            else
            {
                std::cout << it.first << " insuficiente" << std::endl;
            }
        }
        if (it.first != mercadoria)
        {
            std::cout << it.first << " inexistente" << std::endl;
        }
    }
}

unsigned int Estoque::get_qtd(const std::string &mercadoria) const
{
    // TODO
    std::cout << "get_qtd" << std::endl;
    int quantidade;
    for (auto it : m_produtos)
    {
        if (it.first == mercadoria)
        {

            quantidade = it.second;
        }
        else
        {
            quantidade = 0;
        }
    }
    return quantidade;
}

void Estoque::imprime_estoque() const
{
    std::cout << "imprime_estoque" << std::endl;
    for (auto it : m_produtos)
    {
        std::cout << it.first << ": " << it.second << std::endl;
    }
}

Estoque &Estoque::operator+=(const Estoque &rhs)
{
    // TODO
    std::cout << "operator+" << std::endl;
    int soma, teste = 0;
    std::map<std::string, unsigned int> lhs;
    lhs = m_produtos;
    for (const auto &[mercadoria_1, qtd_1] : lhs)
    {
        for (const auto &[mercadoria_2, qtd_2] : rhs.m_produtos)
        {

            if (mercadoria_1 == mercadoria_2)
            {
                soma = qtd_1 + qtd_2;
                teste++;
                m_produtos[mercadoria_1] = soma;
                std::cout << "mercadoria_1 " << mercadoria_1 << " qtd_1 " << qtd_1 << " mercadoria_2 " << mercadoria_2 << " qtd_2 " << qtd_2 << " teste " << teste << std::endl;
            }
            if (m_produtos.find(mercadoria_2) == m_produtos.end())
            {
                add_mercadoria(mercadoria_2, qtd_2);
            }
        }
    }
    return *this;
}

Estoque &Estoque::operator-=(const Estoque &rhs)
{
    // TODO
    std::cout << "operator-" << std::endl;
    int soma;
    int teste = 0, estq1 = 0, estq2 = 0;
    std::map<std::string, unsigned int> lhs;
    lhs = m_produtos;
    for (const auto &[mercadoria_1, qtd_1] : lhs)
    {
        if (estq1 == 0)
        {
            for (const auto e : m_produtos)
            {
                std::cout << e.first << " - " << e.second << std::endl;
            }
            estq1++;
        }
        for (const auto &[mercadoria_2, qtd_2] : rhs.m_produtos)
        {
            if (estq2 == 0)
            {
                for (const auto e : rhs.m_produtos)
                {
                    std::cout << e.first << " - " << e.second << std::endl;
                }
                estq2++;
            }
            if (mercadoria_2 == mercadoria_1)
            {
                soma = qtd_1 - qtd_2;
                teste++;
                m_produtos[mercadoria_1] = soma;
                std::cout << "mercadoria_1 " << mercadoria_1 << " qtd_1 " << qtd_1 << " mercadoria_2 " << mercadoria_2 << " qtd_2 " << qtd_2 << " teste " << teste << std::endl;
            }
            if (m_produtos.find(mercadoria_2) == m_produtos.end())
            {
                add_mercadoria(mercadoria_2, qtd_2);
            }
        }
    }
    return *this;
}

bool operator<(Estoque &lhs, Estoque &rhs)
{
    // TODO
    std::cout << "operator<" << std::endl;
    for (const auto &[mercadoria_1, qtd_1] : rhs.m_produtos)
    {
        for (const auto &[mercadoria_2, qtd_2] : lhs.m_produtos)
        {
            // if (lhs.m_produtos != rhs.m_produtos)
            // {
            //     std::cout << "diferentes  " << std::endl;
            //     return false;
            // }
            // if (mercadoria_1 == mercadoria_2)
            // {
            //     std::cout << "mer iguais " << std::endl;
            //     std::cout << "qtd_1 " << qtd_1 << " < "
            //               << "qtd_2 " << qtd_2 << std::endl;
            //     // std::cout << "lhs.m_produtos.size()" << lhs.m_produtos.size() << " < "
            //     //           << "rhs.m_produtos.size" << rhs.m_produtos.size << std::endl;
            //
            //     if (qtd_1 < qtd_2)
            //     {
            //         std::cout << "mer iguais  " << std::endl;
            //         return true;
            //     }
            //     if (rhs.m_produtos.size() < lhs.m_produtos.size())
            //     {
            //         std::cout << "tam1 < tam2 " << std::endl;
            //         return true;
            //     }
            //     else
            //     {
            //         std::cout << "contrario " << std::endl;
            //         return false;
            //     }
            // }
            if (lhs.m_produtos.find(mercadoria_2) != lhs.m_produtos.end())
            {
                if (qtd_1 < qtd_2)
                {
                    return true;
                }
                else if (qtd_1 > qtd_2)
                {
                    return false;
                }
            }
            else if (lhs.m_produtos.find(mercadoria_2) == lhs.m_produtos.end())
            {
                return false;
            }
        }
    }
}

bool operator>(Estoque &lhs, Estoque &rhs)
{
    // TODO
    std::cout << "operator>" << std::endl;

    for (const auto &[mercadoria_1, qtd_1] : lhs.m_produtos)
    {
        for (const auto &[mercadoria_2, qtd_2] : rhs.m_produtos)
        {
            //if (lhs.m_produtos != rhs.m_produtos)
            //{
            //    std::cout << "diferentes  " << std::endl;
            //    if (lhs.m_produtos.size() > rhs.m_produtos.size())
            //    {
            //        std::cout << "diferentes lhs>rhs " << std::endl;
            //        return true;
            //    }
            //    else
            //    {
            //        return false;
            //    }
            //}
            //if (mercadoria_1 == mercadoria_2)
            //{
            //    std::cout << "qtd_1 " << qtd_1 << " > "
            //              << "qtd_2 " << qtd_2 << std::endl;
            //    // std::cout << "lhs.m_produtos.size()" << lhs.m_produtos.size() << " > "
            //    //           << "rhs.m_produtos.size" << rhs.m_produtos.size << std::endl;
            //    if (qtd_1 > qtd_2)
            //    {
            //        std::cout << "mer iguais  " << std::endl;
            //        return true;
            //    }
            //    if (rhs.m_produtos.size() > lhs.m_produtos.size())
            //    {
            //        std::cout << "tam1 > tam2 " << std::endl;
            //        return true;
            //    }
            //    else
            //    {
            //        std::cout << "contrario " << std::endl;
            //        return false;
            //    }
            //}
            if (lhs.m_produtos.find(mercadoria_2) != lhs.m_produtos.end())
            {
                if (qtd_1 > qtd_2)
                {
                    return true;
                }
                else if (qtd_1 < qtd_2)
                {
                    return false;
                }
            }
            else if (lhs.m_produtos.find(mercadoria_2) == lhs.m_produtos.end())
            {
                return false;
            }
        }
    }
}