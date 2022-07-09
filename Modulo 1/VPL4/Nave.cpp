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
    x = p._x;
    y = p._y;
    forca = forca;
    if (forca == 0)
        forca = 1;
}

void Nave::mover(double dx, double dy)
{
    x += dx;
    y += dy;
}

double Nave::calcular_distancia(Nave *nave)
{
    double DX = nave->x - x;
    double DY = nave->y - y;
    return sqrt(DX * DX + DY * DY);
}

Nave *Nave::determinar_nave_mais_proxima(Nave **naves, int n)
{
    Nave a;
    double dist = 0, dist2 = 999999;
    int num_nave = 0;

    for (int i = 0; i < n; i++)
    {
        dist = a.calcular_distancia(naves[i]);
        if (dist < dist2 && a.x != x && a.y != y)
        {
            dist2 = dist;
            num_nave = i;
        }
    }
    return naves[num_nave];
}

void Nave::atacar(Nave **naves, int n)
{
    Nave h;
    int dano = 0, i = 0, d = 0;

    naves[i] = determinar_nave_mais_proxima(naves, n);

    d = h.calcular_distancia(naves[i]);

    cout << "atacar2 " << d << endl;

    dano = (100 / d) * (h.determinar_nave_mais_proxima(naves, n)->forca);

    if (dano > 30)
    {
        dano = 30;
    }

    cout << "dano " << dano << endl;

    h.determinar_nave_mais_proxima(naves, n)->energia -= dano;

    if (h.determinar_nave_mais_proxima(naves, n)->energia <= 50)
        cout << " Energia baixa !" << endl;
}

void Nave::imprimir_status()
{
    cout << x << " " << y << " " << energia << endl;
}