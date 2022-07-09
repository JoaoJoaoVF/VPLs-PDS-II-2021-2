#include <vector>
#include <iostream>
#include <set>

#include "Algoritmos.hpp"

template <class T>
void read_input(std::vector<T> &vec)
{
  T val;
  while (std::cin >> val)
  {
    vec.push_back(val);
  }
}

template <class T>
void print_input(std::vector<T> &vec)
{
  // TODO
  for (T elem : vec)
  {
    std::cout << elem << ", ";
  }
  std::cout << std::endl;
}

template <class T>
T get_max(std::vector<T> &vec)
{
  if (vec.empty())
  {
    std::cout << "Erro: vetor vazio.\n";
  }
  // TODO
  T maior_elemento = 0;
  for (T elem1 : vec)
  {
    for (T elem2 : vec)
    {
      if (maior_elemento == 0)
      {
        maior_elemento = elem1;
      }
      if (maior_elemento < elem2)
      {
        maior_elemento = elem2;
      }
    }
  }
  return maior_elemento;
}

//case 4 e 5
template <class T>
unsigned int count_duplicates(std::vector<T> &vec)
{
  int repetidos = 0;
  int a = vec.size();
  for (int i = 0; i < a; i++)
  {
    for (int j = i + 1; j < a; j++)
    {
      if (vec[i] == vec[j])
      {
        std::cout << vec[j] << " " << vec[i] << ", " << j << " - " << i << std::endl;
        repetidos++;
        std::cout << "repetidos " << repetidos << ", " << a << std::endl;
      }
      if (i == 0 && repetidos >= a - 1)
      {
        //break;
        return repetidos;
      }
    }
  }
  return repetidos;
}

template <class T>
void test_print_input()
{
  std::vector<T> vec;
  read_input(vec);
  print_input(vec);
}

template <class T>
void test_get_max()
{
  std::vector<T> vec;
  read_input(vec);
  std::cout << get_max(vec) << std::endl;
}

template <class T>
void test_count_dups()
{
  std::vector<T> vec;
  read_input(vec);
  std::cout << count_duplicates(vec) << std::endl;
}

int main()
{
  int tipo_teste;
  std::cin >> tipo_teste;
  switch (tipo_teste)
  {
  case 0:
    test_print_input<std::string>();
    break;
  case 1:
    test_print_input<int>();
    break;
  case 2:
    test_get_max<double>();
    break;
  case 3:
    test_get_max<char>();
    break;
  case 4:
    test_count_dups<int>();
    break;
  case 5:
    test_count_dups<std::string>();
    break;
  default:
    std::cout << "Erro: teste invalido: " << tipo_teste << std::endl;
  }
  return 0;
}