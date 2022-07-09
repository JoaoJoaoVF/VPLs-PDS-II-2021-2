#include "Nave.hpp"
#include "Ponto2D.hpp"

#include <iostream>
#include <cmath>

using namespace std;

Nave::Nave()
{
}

Nave::Nave(Ponto2D(p), double forca)
{
    x = p._x;
    y = p._y;
    this->forca = forca;
    this->energia = 100;
    if (forca == 0)
        forca = 1;
}

void Nave::mover(double dx, double dy)
{
    this->x += dx;
    this->y += dy;
}

double Nave::calcular_distancia(Nave *nave)
{
    double DX = nave->x - x;
    double DY = nave->y - y;
    return sqrt(DX * DX + DY * DY);
}

Nave *Nave::determinar_nave_mais_proxima(Nave **naves, int n)
{
    Nave *a;
    double dist = 0, dist2 = 9999;
    for (int i = 0; i < n; i++)
    {
        dist = calcular_distancia(naves[i]);
        if (dist < dist2)
        {
            if (dist > 0)
            {

                dist2 = dist;
                a = naves[i];
            }
        }
    }
    return a;
}

void Nave::atacar(Nave **naves, int n)
{
    Nave *h;
    int dano = 0, d = 0;

    h = determinar_nave_mais_proxima(naves, n);

    d = calcular_distancia(h);

    dano = (100 / d) * forca;

    if (dano > 30)
    {
        dano = 30;
    }

    h->energia -= dano;

    if (h->energia <= 50)
        cout << " Energia baixa !" << endl;
}

void Nave::imprimir_status()
{
    cout << x << " " << y << " " << energia << endl;
}