#include <iostream>
#include <string>

using namespace std;

string descricao(string _tipo, int m_qtd, string _artesanal)
{
    string é_artesanal;
    if (_artesanal == "1")
    {
        é_artesanal = " artesanal.";
    }
    else
    {
        é_artesanal = " simples.";
    }
    std::string artesanal = é_artesanal;
    std::string descricao = std::to_string(m_qtd) + "X Hamburguer " + _tipo + artesanal;
    return descricao;
}

int main()
{
    string _tipo = "X-Burger";
    string _artesanal = "0";
    int m_qtd = 2;
    cout << descricao(_tipo, m_qtd, _artesanal) << endl;
    return 0;
}