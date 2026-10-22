#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
protected:
    Point2D* vs;

private:
    static bool check(Point2D* vertices);

public:
    static int const N_VERTICES = 4;

    // Constructores y destructor
    Rectangle();
    Rectangle(std::string color, Point2D* vertices);
    Rectangle(const Rectangle &r); // Constructor de copia
    ~Rectangle();                  // Destructor

    // Consultores y modificadores
    Point2D get_vertex(int ind) const;
    Point2D operator[](int ind) const;
    virtual void set_vertices(Point2D* vertices);

    // Sobrecarga del operador de asignación
    Rectangle& operator=(const Rectangle &r);

    // Sobrecarga global del operador <<
    friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);

    // Métodos abstractos heredados de Shape
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    void print() override;
};

#endif
