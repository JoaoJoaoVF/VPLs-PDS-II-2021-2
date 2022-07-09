#include "Ponto2D.hpp"

//Ponto2D::Ponto2D() {}

Ponto2D::Ponto2D()
{
}

Ponto2D::Ponto2D(double x, double y)
{
    this->_x = x;
    this->_y = y;
}

double Ponto2D::calcularDistancia(Ponto2D *p2)
{
    return sqrt(pow(p2->_x - this->_x, 2) + pow(p2->_y - this->_y, 2));
}
