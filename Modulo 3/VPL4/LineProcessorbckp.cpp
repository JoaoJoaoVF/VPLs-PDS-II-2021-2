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
    // std::cout << " " << std::endl;
    // std::cout << str << std::endl;
    // std::cout << " tamanho string " << str.size() << std::endl;
    std::smatch m; // \\w+|-?[[:digit:]]+||-?[[:digit:]]
    std::regex test("[^0123456789\\s*]|[:alpha:]");
    // std::cout << regex_search(str, m, test) << std::endl;
    if (regex_search(str, m, test) == 0)
    {
        return 1;
    }
    //std::cout << "ContadorNumNaturais " << std::endl;
    // std::regex test2("-?[[:digit:]]+");
    //std::regex reg("\\d\\s*\\d\\s*\\d\\s*\\d\\s*\\d\\s*");
    // std::cout << "encontrou certo? " << std::regex_match(str, reg) << std::endl;
    //return std::regex_match(str, reg);

    return 0;
}

void ContadorNumNaturais::processaLinha(const std::string &str)
{
    // TODO: Implemente este metodo:
    //int a = 0;
    //std::cout << "ddfdddfdfd" << std::endl;
    //std::vector<std::string> num = str;
    // int b = 0;
    //a++; //for(int n : v)
    // for (int i = 0; i <= str.size(); i++)
    // {
    // a += std::atol(str);
    //int n = str.length();
    //char char_array[n + 1]; // Declarar Char Array
    //strcpy(char_array, str.c_str());
    //for (int i = 0; i < n; i++)
    //{
    //  std::cout << char_array[i]<< std::endl;
    //}
    //int p = str.size(); // Declarando a Char Array
    //int i = 0;
    //for (i = 0; i < sizeof(p); i++)
    //{
    //  p[&i] = str[i];
    //  std::cout << p[&i] << std::endl;
    //  //  std::cout << std::stoi(str) << std::endl;
    //  //}
    //}
    //std::vector<std::string> num;
    //num.push_back(str);
    //for (auto it = num.begin(); it != num.end(); it++)
    //{
    //  int x = std::stoi(*it);
    //  std::cout << num.size() << std::endl;
    //}
    //std::stringstream ss;
    //for (int i = 0; i < str.size(); i++)
    //{
    //  if (&str[i] == " ")
    //  {
    //    std::cout << str[i] << std::endl;
    //    //int x = std::stoi(str[i]);
    //
    //    // return;
    //
    //    ss << str;
    //    ss >> a;
    //    b += a;
    //    std::cout << "a " << a << std::endl;
    //  }
    //}
    //std::cout << "b " << b << std::endl;
    //std::cout << "\n";
    // std::cout << "string " << str << std::endl;
    // std::cout << str[1] << std::endl;
    // std::cout << "a " << a << std::endl;
    //std::vector<std::string> v;
    //v.emplace_back(str);
    //for (size_t i = 0; i < v.size(); ++i)
    //{
    //  std::cout << v.at(i) << std::endl;
    //}
    ////std::cout ;
    //if (issspace(str))
    //{
    //}
    std::vector<std::string> words{};
    char delimiter = ' ';

    std::istringstream sstream(str);
    std::string word;

    while (std::getline(sstream, word, delimiter))
    {
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
    }
    int dsd = 0;
    for (const auto &text : words)
    {
        dsd += std::stoi(text);
    }
    std::cout << dsd << std::endl;
}
bool LeitorDeFutebol::linhaValida(const std::string &str) const
{
    // TODO: Implemente este metodo
    //return false;
    // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
    // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
    // \\d+ eh qualquer sequencia de um ou mais digitos
    //std::cout << "LeitorDeFutebol " << std::endl;
    std::regex regularExpr("\\w+\\s*\\d+\\s*\\w+\\s*\\d+");
    // std::cout << std::regex_match(str, regularExpr) << std::endl;
    return std::regex_match(str, regularExpr);
}

void LeitorDeFutebol::processaLinha(const std::string &str)
{
    // TODO: Implemente este metodo:
    //std::cout << "Imprime algo aqui!" << std::endl;
    std::vector<std::string> words{};
    char delimiter = ' ';

    std::istringstream sstream(str);
    std::string word;

    while (std::getline(sstream, word, delimiter))
    {
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
    }
    int sad = 0;
    int teste = 0;
    int teste2 = 0;
    int Ponto1 = 0;
    int Ponto2 = 0;
    int mover = 0;
    std::string Time1;
    std::string Time2;
    for (const auto &text : words)
    {
        sad++;
        if (sad % 2 == 0)
        {
            if (teste == 0)
            {
                //Time1 = text;
                Ponto1 = std::stoi(text);
                teste++;
            }
            if (words[mover] == " ")
            {
            }
            else
            {
                //Time2 = text;
                Ponto2 = std::stoi(text);
            }
        }
        else
        {
            if (teste2 == 0)
            {
                Time1 = text;
                teste2++;
            }
            if (words[mover] == " ")
            {
            }
            else
            {
                Time2 = text;
                //std::cout << text << std::endl;
            }
            mover++;
        }
    }
    if (Ponto1 == Ponto2)
    {
        std::cout << "Empate" << std::endl;
    }
    if (Ponto1 > Ponto2)
    {
        std::cout << "Vencedor: " << Time1 << std::endl;
    }
    if (Ponto1 < Ponto2)
    {
        std::cout << "Vencedor: " << Time2 << std::endl;
    }
}

void ContadorDePalavras::processaLinha(const std::string &str)
{
    // TODO: Implemente este metodo:
    //std::cout << "Imprime algo aqui!" << std::endl;
    std::vector<std::string> words{};
    char delimiter = ' ';

    std::istringstream sstream(str);
    std::string word;

    while (std::getline(sstream, word, delimiter))
    {
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
    }
    int num_palavras = 0;
    //for (const auto &text : words)
    //{
    //  std::cout << text << std::endl;
    //}
    for (const auto &text : words)
    {
        if (text != " " && text != "!" && text != "." && text != ",")
        {
            num_palavras++;
        }
    }
    std::cout << num_palavras << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const
{
    // TODO: Implemente este metodo
    // std::cout << " InversorDeFrases" << std::endl;
    std::smatch m; // \\w+|-?[[:digit:]]+||-?[[:digit:]]
    std::regex test("[0123456789]|[-!#$%&'*+,./:;<=>?@_`{|}~]");
    //std::cout << regex_search(str, m, test) << std::endl;
    if (regex_search(str, m, test) == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    //return false;
}

void InversorDeFrases::processaLinha(const std::string &str)
{
    // TODO: Implemente este metodo:
    //std::cout << "Imprime algo aqui!" << std::endl;
    //for (int i = 0; i < str.size(); i++)
    //{
    //  std::cout << str[i];
    //
    //}
    // int a = str.size();
    // std::cout << "a " << a << std::endl;
    // for (int f = a; f >= 0; f--)
    //for (int i = 0; i < a; i++)
    //{
    //  std::cout << str[i];
    //}
    // std::cout << std::endl;
    // for (int i = 0; i < str.length(); i++)
    // {
    //   std::cout << str[i];
    // }
    // std::cout << std::endl;
    //std::vector<std::string> words{};
    //char delimiter = ' ';
    //
    //std::istringstream sstream(str);
    //std::string word;
    //while (std::getline(sstream, word, delimiter))
    //{
    //  word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
    //  words.push_back(word);
    //}
    //int dsd = 0;
    //int i = 0;
    //std::string invertido[10000];
    //std::cout << std::endl;
    //for (const auto &text : words)
    //{
    //  //dsd++;
    //  if (i == 0)
    //  {
    //    std::cout << words[0] << " ";
    //  }
    //  else
    //  {
    //    std::cout << words[i] << " ";
    //    //invertido[i] = text;
    //    i++;
    //  }
    //}
    ////std::cout << dsd << std::endl;
    //
    ////for (int i = 0; i <= dsd; i++)
    //
    ////for (const auto &text : words)
    //// {
    //
    ////  }
    //std::cout << std::endl;
    ////for (int i = dsd; i > 0; --i)
    ////{
    ////  std::cout << invertido[i] << " ";
    ////}
    ////std::cout << std::endl;
    std::vector<std::string> words{};
    char delimiter = ' ';

    std::istringstream sstream(str);
    std::string word;

    while (std::getline(sstream, word, delimiter))
    {
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
    }
    // std::string invertido[10000];
    //int i = 0;
    //int tam = 0;
    //for (const auto &text : words)
    //{

    //  //std::cout << words[i] << std::endl;
    //  //invertido[i] = text;
    //  //i++;
    //  tam++;
    //}
    //std::cout << invertido[tam - 5] << std::endl;
    // int cont = words.size();
    //int beta = word.size();
    //for (int i = -1; i < beta; i++)
    //{
    //  std::cout << words[i] << " ";
    //}
    //std::cout << std::endl;
    //for (tam; tam == 0; tam--)
    // std::cout << "tamaho strring " << words.size() << std::endl;
    for (int cont = words.size() - 1; cont >= 0; cont--)
    {
        // std::cout << cont << std::endl;
        std::cout << words[cont] << " "; //std::endl;
    }
    std::cout << std::endl;
    //int cont = -1;
    //while (1)
    //{
    //  cont++;
    //  std::cout << words[cont] << std::endl;
    //  if (cont == words.size())
    //  {
    //    break;
    //  }
    //}
}

bool EscritorDeDatas::linhaValida(const std::string &str) const
{
    // std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");
    std::regex dateFormat("\\s*\\d\\d?/\\d\\d?/\\d{4}");
    // TODO: Implemente este metodo
    // Note que você pode usar uma expressao regular como:
    // "\\s*\\d\\d?/\\d\\d?/\\d{4}" para saber se a linha eh valida:
    // std::cout << "EscritorDeDatas " << std::endl;
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
    // std::cout << "Imprime algo aqui!" << std::endl;
    std::vector<std::string> words{};
    char delimiter = '/';

    std::istringstream sstream(str);
    std::string word;

    while (std::getline(sstream, word, delimiter))
    {
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
    }
    //int posicao = 1;
    //int adicao = 0;
    //std::cout <<
    verifica_Mes(words[1]); //<< std::endl;
    // for (const auto &text : words)
    {
        // if (posicao == 1)
        // {
        //std::cout << text << std::endl;
        //}
        //adicao = posicao;
        //posicao += 3;
        //if (posicao + adicao == posicao + adicao)
        //{
        //  std::cout << text << std::endl;
        //}
    }
}
