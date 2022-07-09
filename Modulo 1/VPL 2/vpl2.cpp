#include <iostream>
#include <string>

int main()
{
  std::string texto;
  int v = 0, w = 0, x = 0, y = 0, z = 0;
  std::cin >> texto;
  //std::cout << "O tamanho da string é: " << texto.size() << std::endl;

  for (unsigned i = 0; i < texto.length(); ++i)
  {
    if (texto.at(i) == 'a')
    {
      v = v + 1;
    }
    if (texto.at(i) == 'e')
    {
      w = w + 1;
    }
    if (texto.at(i) == 'i')
    {
      x = x + 1;
    }
    if (texto.at(i) == 'o')
    {
      y = y + 1;
    }
    if (texto.at(i) == 'u')
    {
      z = z + 1;
    }
  }

  if (v > 0)
  {
    std::cout << "a ";
    std::cout << v << std::endl;
  }
  if (w > 0)
  {
    std::cout << "e ";
    std::cout << w << std::endl;
  }
  if (x > 0)
  {
    std::cout << "i ";
    std::cout << x << std::endl;
  }
  if (y > 0)
  {
    std::cout << "o ";
    std::cout << y << std::endl;
  }
  if (z > 0)
  {
    std::cout << "u ";
    std::cout << z << std::endl;
  }

  return 0;
}