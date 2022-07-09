#pragma once

#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>

// Define um vetor de qualquer Tipo cujos índices variam em
// qualquer intervalo, inclusive negativos.
template <class Tipo>
class Vetor
{
public:
  // Cria um vetor cujos índices variam de 'inicio' até 'fim'.
  // PRECONDIÇÃO: fim >= inicio.
  Vetor(int inicio, int fim);

  // Altera o valor do índice i.
  // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
  void atribuir(int i, Tipo valor);

  // Retorna o valor do índice i.
  // PRECONDIÇÕES:
  // (1) i está dentro do intervalo de índices do vetor.
  // (2) i foi inicializando anteriormente.
  Tipo valor(int i) const;

private:
  int inicio_;                              // Primeiro índice válido do vetor.
  int fim_;                                 // Último índice válido do vetor.
  std::vector<Tipo> elementos_;             // Elementos do vetor.
  std::vector<Tipo> elementos_incializados; // Elementos incializados do vetor.
};

// DEFINIÇÃO DAS CLASSES DE EXCEÇÃO.

// Lançada quando o intervalo [inicio, fim] não contém nenhum índice.
struct ExcecaoIntervaloVazio
{
  int inicio; // Índice de início do arranjo que lançou a excecao.
  int fim;    // Índice de fim do arranjo que lançou a excecao.
};

// Lançada quando 'indice' não pertence a [inicio, fim].
struct ExcecaoIndiceInvalido
{
  int inicio; // Índice de início do arranjo que lançou a excecao.
  int fim;    // Índice de fim do arranjo que lançou a excecao.
  int indice; // Índice inválido.
};

// Lançada quando o valor de 'indice' é solicitado e o mesmo não foi previamente
// inicializado.
struct ExcecaoIndiceNaoInicializado
{
  int indice; // Índice do arranjo que não foi inicializado.
};

// IMPLEMENTAÇÃO DOS MÉTODOS DA CLASSE.

template <class Tipo>
Vetor<Tipo>::Vetor(int inicio, int fim) : inicio_(inicio),
                                          fim_(fim)
{
  if (fim < inicio)
  {
    ExcecaoIntervaloVazio e;
    e.inicio = inicio;
    e.fim = fim;
    throw e;
  }
  elementos_.resize(fim - inicio + 1);
}

template <class Tipo>
void Vetor<Tipo>::atribuir(int i, Tipo valor)
{
  if (i > fim_ || i < inicio_)
  {
    ExcecaoIndiceInvalido e;
    e.inicio = inicio_;
    e.fim = fim_;
    e.indice = i;
    throw e;
  }
  int j = i - inicio_;
  elementos_[j] = valor;
  elementos_incializados.emplace_back(i);
}

template <class Tipo>
Tipo Vetor<Tipo>::valor(int i) const
{
  int j = i - inicio_;
  if (i > fim_ || i < inicio_)
  {
    ExcecaoIndiceInvalido e;
    e.inicio = inicio_;
    e.fim = fim_;
    e.indice = i;
    throw e;
  }

  if (std::find(elementos_incializados.begin(), elementos_incializados.end(), i) != elementos_incializados.end())
  {
    return elementos_[j];
  }
  else
  {
    std::cout << "item procurado " << i << std::endl;
    ExcecaoIndiceNaoInicializado e;
    e.indice = i;
    throw e;
  }

  return elementos_[j];
}