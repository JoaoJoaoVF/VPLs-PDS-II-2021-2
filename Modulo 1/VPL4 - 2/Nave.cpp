#include "Nave.hpp"
#include "Ponto2D.hpp"

#include <iostream>
#include <cmath>

using namespace std;
//#include "Ponto2D.hpp"
Nave::Nave()
{
}

Nave::Nave(Ponto2D(position), double forca) : _position(position._x, position._y)
{
    this->forca = forca;
    this->energia = 100;
}

void Nave::mover(double dx, double dy)
{
    _position._x += dx;
    _position._y += dy;
}

double Nave::calcular_distancia(Nave *nave)
{
    double DX = _position._x - x;
    double DY = _position._y - y;
    return sqrt(DX * DX + DY * DY);
}

Nave *Nave::determinar_nave_mais_proxima(Nave **naves, int n)
{
    Nave *a;
    double dist = 0, dist2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (calcular_distancia(naves[i]) > 0)
        {
            if (calcular_distancia(naves[i]) < dist2)
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
        cout << " Energia baixa!" << endl;
}

void Nave::imprimir_status()
{
    cout << _position.x << " " << _position.y << " " << energia << endl;
}