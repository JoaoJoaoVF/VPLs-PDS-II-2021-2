#ifndef PONTO2D_H
#define PONTO2D_H

#include <iostream>
#include <cmath>

using namespace std;

struct Ponto2D
{
    double _x;
    double _y;

    //Ponto2D() {}

    Ponto2D();

    Ponto2D(double x, double y);

    double calcularDistancia(Ponto2D *p2);
};

#endif