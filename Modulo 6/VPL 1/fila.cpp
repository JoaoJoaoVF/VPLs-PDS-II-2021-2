#include "fila.h"

struct No
{
  int chave;
  No *proximo;
};

Fila::Fila()
{
  // TODO
}

void Fila::Inserir(int k)
{
  // TODO
  No *insercao = new No;

  insercao->chave = k;
  insercao->proximo = nullptr;

  if (primeiro_ == nullptr)
  {
    primeiro_ = insercao;
    ultimo_ = insercao;
  }
  else
  {
    ultimo_->proximo = insercao;
    ultimo_ = insercao;
  }
}
void Fila::RemoverPrimeiro()
{
  // TODO
  if (this->primeiro_ == nullptr || this->ultimo_ == nullptr)
  {
    ExcecaoFilaVazia excecao_encontrada;
    throw excecao_encontrada;
  }

  No *atual = primeiro_;
  No *anterior = nullptr;

  while (atual != nullptr)
  {
    if (atual == primeiro_)
    {
      if (anterior == nullptr)
      {
        primeiro_ = atual->proximo;
      }
      else if (atual->proximo == nullptr)
      { //TAIL
        anterior->proximo = nullptr;
        ultimo_ = anterior;
      }
      else
      {
        anterior->proximo = atual->proximo;
      }
    }
    delete atual;
    return;
  }
  anterior = atual;
  atual = atual->proximo;
}

int Fila::primeiro() const
{
  // TODO
  if (this->primeiro_ == nullptr || this->ultimo_ == nullptr)
  {
    ExcecaoFilaVazia excecao_encontrada;
    throw excecao_encontrada;
  }
  int primeiro_elemento = this->primeiro_->chave;
  return primeiro_elemento;
}

int Fila::ultimo() const
{
  // TODO
  if (this->primeiro_ == nullptr || this->ultimo_ == nullptr)
  {
    ExcecaoFilaVazia excecao_encontrada;
    throw excecao_encontrada;
  }
  int ultimo_elemento = this->ultimo_->chave;
  return ultimo_elemento;
}

int Fila::tamanho() const
{
  // TODO
  int tamanho = 0;
  No *current = primeiro_;
  No *previous = nullptr;

  while (current != nullptr)
  {
    tamanho++;
    current = current->proximo;
  }
  return tamanho;
}