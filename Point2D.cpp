#include <ostream>
#include <cmath>
#include "Point2D.h"

// Implementación del constructor
// (Los valores por defecto x=0.0, y=0.0 solo se ponen en el .h)
Point2D::Point2D(double x, double y) {
    this->x = x;
    this->y = y;
}

// Cálculo de la distancia euclidiana
double Point2D::distance(const Point2D &a, const Point2D &b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

// Operador de igualdad
bool Point2D::operator==(const Point2D &other) {
    return (this->x == other.x) && (this->y == other.y);
}

// Operador de desigualdad
bool Point2D::operator!=(const Point2D &other) {
    return (this->x != other.x) || (this->y != other.y);
}

// Operador de impresión
std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
