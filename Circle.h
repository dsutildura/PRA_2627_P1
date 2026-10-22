#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Shape.h"

class Circle : public Shape {
private:
    Point2D center;
    double radius;

public:
    // Constructores
    Circle();
    Circle(std::string color, Point2D center, double radius);

    // Consultores y modificadores
    Point2D get_center() const;
    void set_center(Point2D p);
    
    double get_radius() const;
    void set_radius(double r);

    // Sobrecarga global del operador <<
    friend std::ostream& operator<<(std::ostream &out, const Circle &c);

    // Métodos abstractos heredados de Shape
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    void print() override;
};

#endif
