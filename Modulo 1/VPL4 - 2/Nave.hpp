#ifndef NAVE_H
#define NAVE_H

#include "Ponto2D.hpp"

using namespace std;

struct Nave
{
    //Ponto2D p;
    //double x;
    //double y;
    double energia = 100;
    double forca;
    double _position;

    Nave();

    Nave(Ponto2D position, double forca);

    void mover(double dx, double dy);

    double calcular_distancia(Nave *nave);

    Nave *determinar_nave_mais_proxima(Nave **naves, int n);

    void atacar(Nave **naves, int n);

    void imprimir_status();
};

#endif