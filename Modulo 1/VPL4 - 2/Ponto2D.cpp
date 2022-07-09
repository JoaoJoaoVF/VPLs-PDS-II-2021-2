#include "Ponto2D.hpp"

Ponto2D::Ponto2D()
{
}

Ponto2D::Ponto2D(double x, double y)
{
    this->_x = x;
    this->_y = y;
    //this->_p = ;
}

double Ponto2D::calcularDistancia(Ponto2D *p2)
{
    double dx = p2->_x - this->_x;
    double dy = p2->_y - this->_y;
    return sqrt(dx * dx + dy * dy);
}