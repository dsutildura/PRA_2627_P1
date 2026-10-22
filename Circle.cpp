#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Circle.h"

// Constructor por defecto (llama al constructor base de Shape y asigna valores)
Circle::Circle() : Shape(), center(0, 0), radius(1.0) {
}

// Constructor con parámetros
Circle::Circle(std::string color, Point2D center, double radius) : Shape(color) {
    this->center = center;
    set_radius(radius); // Usamos set_radius para aprovechar su validación
}

// Consultor de centro
Point2D Circle::get_center() const {
    return center;
}

// Modificador de centro
void Circle::set_center(Point2D p) {
    center = p;
}

// Consultor de radio
double Circle::get_radius() const {
    return radius;
}

// Modificador de radio
void Circle::set_radius(double r) {
    if (r < 0) {
        throw std::invalid_argument("El radio no puede ser negativo.");
    }
    radius = r;
}

// Sobrecarga del operador de inserción
std::ostream& operator<<(std::ostream &out, const Circle &c) {
    out << "[Circle: color = " << c.get_color() << ", center = " << c.center << ", radius = " << c.radius << "]";
    return out;
}

// Implementación de las funciones virtuales puras de Shape
double Circle::area() const {
    return 3.141592 * std::pow(radius, 2);
}

double Circle::perimeter() const {
    return 2 * 3.141592 * radius;
}

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

void Circle::print() {
    std::cout << *this << std::endl;
}
