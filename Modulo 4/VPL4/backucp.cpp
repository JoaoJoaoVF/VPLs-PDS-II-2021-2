/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include "polygon.h"

std::ostream &operator<<(std::ostream &out, const Polygon &poly)
{
  for (const Point &p : poly.limits)
  {
    out << " " << p;
  }
  return out;
}

bool operator==(const Polygon &lhs, const Polygon &rhs)
{
  // TODO: implement this method.
  for (const Point &p0 : (const std::vector<Point> &)rhs)
  {
    for (const Point &p1 : (const std::vector<Point> &)lhs)
    {
      return p0.contains(p1);
    }
  }
  // for (const Point &p0 : (const std::vector<Point> &)rhs)
  // {
  //   if (!(lhs.contains(p0)))
  //   {
  //     return false;
  //   }
  // }
  // for (const Point &p1 : (const std::vector<Point> &)lhs)
  // {
  //   if (!(rhs.contains(p1)))
  //   {
  //     return false;
  //   }
  // }
  // return true;
}

bool Point::contains(const Point &p) const
{
  return p.x == this->x && p.y == this->y;
}

std::ostream &operator<<(std::ostream &out, const Point &p)
{
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point &p) const
{
  // TODO: implement this method.
  //analisar os ponstos em right rectangle
  //analisar como limits[i]
  //for (auto it : this->limits)
  //{
  //  if (p.x <= it.x && p.y <= it.y)
  //  {
  //    return true;
  //  }
  //  //return p.contains(it);
  //}
  //return false;

  //return ((limits[0].x >= p.x) && (limits[0].y >= p.y) && (limits[1].x <= p.x) && (limits[1].y <= p.y));
  //for (auto point : limits)
  //{
  //  //std::cout << point.x << " " << point.y << std::endl;
  //  if (((p.x >= limits[0].x) && (p.y >= limits[0].y) && (p.x <= limits[1].x) && (p.y <= limits[1].y)))
  //  {
  //    std::cout << " limits[0].x " << limits[0].x << " limits[0].y  " << limits[0].y << " limits[1].x " << limits[1].x << " limits[1].y " << limits[1].y << std::endl;
  //    std::cout << " p.x " << p.x << " p.y  " << p.y << std::endl;
  //
  //    return true;
  //  }
  //}
  //return false;
  return ((p.x >= limits[0].x) && (p.y >= limits[0].y) && (p.x <= limits[1].x) && (p.y <= limits[1].y));
}

Point::Point(int xx, int yy) : x(xx), y(yy)
{
  // TODO: implement this method.

  // std::cout << "xx " << xx << " yy " << yy << std::endl;
  this->limits.push_back(*this);
  for (auto point : limits)
  {
    // std::cout << point.x << " " << point.y << std::endl;
  }
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1)
{
  // TODO: implement this method.
  //colocar os pontos em posicoes definidas
  //testar se x0 eh menor que x1 e a mesma coisa com y

  // std::cout << "3" << std::endl;

  if (x0 < x1 && y0 < y1)
  {
    this->limits.push_back(Point(x0, y0));
    this->limits.push_back(Point(x1, y1));
  }
  else if (x0 > x1 && y0 > y1)
  {
    this->limits.push_back(Point(x1, y1));
    this->limits.push_back(Point(x0, y0));
  }
  else if (x0 < x1 && y0 > y1)
  {
    this->limits.push_back(Point(x0, y1));
    this->limits.push_back(Point(x1, y0));
  }
  else if (x0 > x1 && y0 < y1)
  {
    this->limits.push_back(Point(x1, y0));
    this->limits.push_back(Point(x0, y1));
  }
}