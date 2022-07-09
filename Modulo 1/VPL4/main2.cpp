#include <iostream>
#include <iomanip>

#include "Nave.hpp"
#include "Ponto2D.hpp"

using namespace std;

int main()
{

    // Lendo quantidade de naves na batalha
    int num_naves;
    cin >> num_naves;

    // Criando o vetor de ponteiros
    Nave *naves[num_naves];

    // Preenchendo o vetor com os dados de entrada
    double x, y, forca;
    for (int i = 0; i < num_naves; i++)
    {
        cin >> x >> y >> forca;
        //cout << x << " " << y << " " << forca << endl;
        naves[i] = new Nave(Ponto2D(x, y), forca);
    }
}