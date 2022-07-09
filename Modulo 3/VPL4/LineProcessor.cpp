#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str)
{
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const
{
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str)
{
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana / 100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais << std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const
{
  // TODO: Implemente este metodo
  std::smatch m;
  std::regex tem_letra("[^0123456789\\s*]|[:alpha:]");
  if (regex_search(str, m, tem_letra) == 0)
  {
    return 1;
  }
  return 0;
}

void ContadorNumNaturais::processaLinha(const std::string &str)
{
  // TODO: Implemente este metodo:
  std::vector<std::string> words{};
  char delimiter = ' ';
  std::istringstream sstream(str);
  std::string word;

  while (std::getline(sstream, word, delimiter))
  {
    word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
    words.push_back(word);
  }
  int soma_valores = 0;
  for (const auto &text : words)
  {
    soma_valores += std::stoi(text);
  }
  std::cout << soma_valores << std::endl;
}
bool LeitorDeFutebol::linhaValida(const std::string &str) const
{
  // TODO: Implemente este metodo
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\w+\\s*\\d+|\\s*\\w+\\s*\\d+\\s*\\w+\\s*\\d+");
  return std::regex_match(str, regularExpr);
}

void LeitorDeFutebol::processaLinha(const std::string &str)
{
  // TODO: Implemente este metodo:
  //std::vector<std::string> words{};
  //char delimiter = ' ';
  //std::istringstream sstream(str);
  //std::string word;
  //while (std::getline(sstream, word, delimiter))
  //{
  //  word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
  //  words.push_back(word);
  //}
  //int Placar = 0;
  //int mudando_Placar = 0;
  //int mudando_Time = 0;
  //int Placar_time1 = 0;
  //int Placar_time2 = 0;
  ////int mover = 0;
  //std::string Time1;
  //std::string Time2;
  //std::string teste = " ";
  //std::istringstream iss(str);
  //std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
  //                                std::istream_iterator<std::string>{}};
  //for (auto it = tokens.end(); it != tokens.begin(); --it)
  //{
  //  std::cout << (*it) << std::endl;
  //}
  //for (const auto &text : words)
  //{
  //' if (*it == teste)
  //{
  //  std::cout << (*it) << std::endl;
  //  //}
  //  Placar++;
  //  if (Placar % 2 == 0)
  //  {
  //    if (mudando_Placar == 0)
  //    {
  //      // Placar_time1 = std::stoi(text);
  //      Placar_time1 = std::stoi(*it);
  //      mudando_Placar++;
  //    }
  //    // if (words[mover] == " ")
  //    // {
  //    // }
  //    else
  //    {
  //      // Placar_time2 = std::stoi(text);
  //      Placar_time2 = std::stoi(*it);
  //    }
  //  }
  //  else
  //  {
  //    if (mudando_Time == 0)
  //    {
  //      Time1 = (*it);
  //      //Time1 = (text);
  //      mudando_Time++;
  //    }
  //    // if (words[mover] == " ")
  //    // {
  //    // }
  //    else
  //    {
  //      //Time2 = (text);
  //      Time2 = (*it);
  //    }
  //    //   mover++;
  //  }
  //}
  //if (Placar_time1 == Placar_time2)
  //{
  //  std::cout << "Empate" << std::endl;
  //}
  //if (Placar_time1 > Placar_time2)
  //{
  //  std::cout << "Vencedor: " << Time1 << std::endl;
  //}
  //if (Placar_time1 < Placar_time2)
  //{
  //  std::cout << "Vencedor: " << Time2 << std::endl;
  //}
  //std::cout << std::endl;
  std::stringstream ss(str);
  int pontos_1, pontos_2;
  std::string time_1, time_2;

  ss >> time_1 >> pontos_1 >> time_2 >> pontos_2;

  if (pontos_1 > pontos_2)
  {
    std::cout << "Vencedor: " << time_1 << std::endl;
  }
  if (pontos_1 < pontos_2)
  {
    std::cout << "Vencedor: " << time_2 << std::endl;
  }
  if (pontos_1 == pontos_2)
  {
    std::cout << "Empate" << std::endl;
  }
}

void ContadorDePalavras::processaLinha(const std::string &str)
{
  // TODO: Implemente este metodo:
  int num_palavras = 0;
  std::istringstream iss(str);
  std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                                  std::istream_iterator<std::string>{}};
  for (auto it = tokens.end(); it != tokens.begin(); --it)
  {
    num_palavras++;
  }
  std::cout << num_palavras << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const
{
  // TODO: Implemente este metodo
  std::smatch m;
  std::regex eh_Valido("[0123456789]|[-!#$%&'*+,./:;<=>?@_`{|}~]");
  if (regex_search(str, m, eh_Valido) == 1)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

void InversorDeFrases::processaLinha(const std::string &str)
{
  // TODO: Implemente este metodo:
  std::vector<std::string> words{};
  char delimiter = ' ';

  std::istringstream sstream(str);
  std::string word;

  while (std::getline(sstream, word, delimiter))
  {
    word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
    words.push_back(word);
  }
  for (int palavras = words.size() - 1; palavras >= 0; palavras--)
  {
    std::cout << words[palavras] << " ";
    // std::cout << words[palavras] << std::endl;
  }
  std::cout << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const
{
  std::regex dateFormat("\\s*\\d\\d?/\\d\\d?/\\d{4}");
  // TODO: Implemente este metodo
  // Note que você pode usar uma expressao regular como:
  // "\\s*\\d\\d?/\\d\\d?/\\d{4}" para saber se a linha eh valida:
  return std::regex_match(str, dateFormat);
}
void verifica_Mes(std::string mes)
{
  if (mes == "1" || mes == "01")
  {
    std::cout << "Jan" << std::endl;
  }
  if (mes == "2" || mes == "02")
  {
    std::cout << "Fev" << std::endl;
  }
  if (mes == "3" || mes == "03")
  {
    std::cout << "Mar" << std::endl;
  }
  if (mes == "4" || mes == "04")
  {
    std::cout << "Abr" << std::endl;
  }
  if (mes == "5" || mes == "05")
  {
    std::cout << "Mai" << std::endl;
  }
  if (mes == "6" || mes == "06")
  {
    std::cout << "Jun" << std::endl;
  }
  if (mes == "7" || mes == "07")
  {
    std::cout << "Jul" << std::endl;
  }
  if (mes == "8" || mes == "08")
  {
    std::cout << "Ago" << std::endl;
  }
  if (mes == "9" || mes == "09")
  {
    std::cout << "Set" << std::endl;
  }
  if (mes == "10")
  {
    std::cout << "Out" << std::endl;
  }
  if (mes == "11")
  {
    std::cout << "Nov" << std::endl;
  }
  if (mes == "12")
  {
    std::cout << "Dez" << std::endl;
  }
}
void EscritorDeDatas::processaLinha(const std::string &str)

{
  // TODO: Implemente este metodo:
  // Lembre-se que as iniciais dos meses sao:
  // "Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out",
  // "Nov", e "Dez".
  std::vector<std::string> words{};
  char delimiter = '/';

  std::istringstream sstream(str);
  std::string word;

  while (std::getline(sstream, word, delimiter))
  {
    word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
    words.push_back(word);
  }
  verifica_Mes(words[1]);
}
