#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string &mercadoria, unsigned int qtd)
{
  // TODO
  m_produtos[mercadoria] += qtd;
}

void Estoque::sub_mercadoria(const std::string &mercadoria, unsigned int qtd)
{
  // TODO
  for (auto &it : m_produtos)
  {
    if (m_produtos.find(mercadoria) != m_produtos.end())
    {
      {

        if (mercadoria == it.first)
        {
          //std::cout << "qtd 1 " << it.second << " qtd 2 " << qtd << std::endl;
          it.second -= qtd;
        }
      }
      // if (it.first == mercadoria)
      // {
      //   if (it.second > qtd)
      //   {
      //     it.second = qtd;
      //   }
      //   else
      //   {
      //     std::cout << it.first << " insuficiente" << std::endl;
      //   }
      // }
      // if (it.first != mercadoria)
      // {
      //   std::cout << it.first << " inexistente" << std::endl;
      // }
    }
  }
}
unsigned int Estoque::get_qtd(const std::string &mercadoria) const
{
  // TODO
  for (auto it : m_produtos)
  {
    if (it.first == mercadoria)
    {
      return it.second;
    }
  }
  return 0;
}

void Estoque::imprime_estoque() const
{
  // TODO
  for (auto it : m_produtos)
  {
    std::cout << it.first << ": " << it.second << std::endl;
  }
}

Estoque &Estoque::operator+=(const Estoque &rhs)
{
  // TODO
  for (const auto &[mercadoria, qtd] : rhs.m_produtos)
  {
    add_mercadoria(mercadoria, qtd);
  }
  return *this;
}

Estoque &Estoque::operator-=(const Estoque &rhs)
{
  // TODO
  for (const auto &[mercadoria, qtd] : rhs.m_produtos)
  {
    sub_mercadoria(mercadoria, qtd);
  }
  return *this;
}

bool operator<(Estoque &lhs, Estoque &rhs)
{
  // TODO
  for (const auto &[mercadoria, qtd] : lhs.m_produtos)
  {
    auto const &it = rhs.m_produtos.find(mercadoria);
    if (it == rhs.m_produtos.end())
    {
      return false;
    }
    if (qtd >= it->second)
    {
      return false;
    }
  }
  return true;
}

bool operator>(Estoque &lhs, Estoque &rhs)
{
  // TODO
  for (const auto &[mercadoria, qtd] : lhs.m_produtos)
  {
    auto const &it = rhs.m_produtos.find(mercadoria);
    if (it == rhs.m_produtos.end())
    {
      return false;
    }
    if (qtd <= it->second)
    {
      return false;
    }
  }
  return true;
}