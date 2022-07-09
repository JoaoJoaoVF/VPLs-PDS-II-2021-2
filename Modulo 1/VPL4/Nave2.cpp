#include "Nave.hpp"
#include "Ponto2D.hpp"

#include <iostream>
#include <cmath>

using namespace std;
//#include "Ponto2D.hpp"
Nave::Nave()
{
}

Nave::Nave(Ponto2D(p), double forca)
{
    // Ponto2D *p;
    //cout << "x antes " << p->_x << " y antes " << p->_y << endl;
    // x = Ponto2D.x;
    //y = 300;
    //cout << forcaa << endl;
    x = p._x;
    y = p._y;
    forca = forca;
    //x=x;
    //y;
    //cout << "x depois " << x << "y depois " << y << endl;
    //cout << "força" << forca << endl;
    if (forca == 0)
        forca = 1;
    //cout << "depois " << forca << endl;
}

void Nave::mover(double dx, double dy)
{
    //cout << "x" << x << endl;
    //cout << "y" << y << endl;
    //Nave *nave;
    x += dx;
    y += dy;
    //cout << "x" << nave->x << endl;
    //cout << "y" << nave->y << endl;
}

double Nave::calcular_distancia(Nave *nave)
{
    Ponto2D ponto;
    //double b = nave->x;
    //double a = ponto.calcularDistancia(&b);
    //return a;
    //cout << "x" << nave->x << endl;
    //cout << "y" << nave->y << endl;
    //double a = sqrt(nave->x * nave->x + nave->y * nave->y);
    // ponto.calcularDistancia(*nave);

    double DX = nave->x - x;
    double DY = nave->y - y;
    return sqrt(DX * DX + DY * DY);
    //cout << a << endl;
    //return a;
}

Nave *Nave::determinar_nave_mais_proxima(Nave **naves, int n)
{
    Nave a;
    //for (int i = 0; i < n; i++)
    // {
    //    double DX = naves[i]->x - x;
    //   double DY = naves[i]->y - y;
    //   double a = sqrt(DX * DX + DY * DY);
    //}
    double dist = 0, dist2 = -99;
    int num_nave = 0;
    for (int i = 0; i <= n; i++)
    {
        dist = a.calcular_distancia(naves[i]);
        if (dist2 == -99)
        {
            dist2 = dist;
        }
        if (dist < dist2)
        {
            dist2 = dist;
            num_nave = i;
        }
    }
    //cout << "distancia euclidiana " << dist << endl;
    //}
    int i = num_nave;
    // cout << "numero da nave retornada nessa funcao"<<i<<endl;
    return naves[i];
    //return naves[0];
}

void Nave::atacar(Nave **naves, int n)
{
    Nave g;
    //double
    // double a=0,b=99;
    //int num=0;
    //double dano;
    int i = 0;
    int d = 0;
    int j = 0;

    j = g.calcular_distancia(naves[n]);

    double dano = (100 / d) * (naves[j]->forca);
    if (dano > 30)
    {
        dano = 30;
    }
    if (naves[j]->energia <= 50)
    {
        cout << " Energia baixa !" << endl;
    }

    naves[j]->energia -= dano;
}

void Nave::imprimir_status()
{
    //Nave *a;
    ///cout << "x nave " << x << " "
    //    << "y nave " << y << " "
    //   << "energia nave " << energia << endl;
    cout << x << " " << y << " " << energia << endl;
}