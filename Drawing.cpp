#include "Drawing.h"
#include "ListArray.h"
#include "ListLinked.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>

// Constructor: decidimos usar la implementación de nodos enlazados
Drawing::Drawing() {
    shapes = new ListLinked<Shape*>();
}

// Destructor: libera la memoria de la lista
Drawing::~Drawing() {
    delete shapes;
}

// Añade una figura al principio de la lista
void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

// Añade una figura al final de la lista
void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

// Imprime todas las figuras delegando en el método print() de cada una
void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); i++) {
        shapes->get(i)->print();
    }
}

// Suma el área exclusiva de los círculos
double Drawing::get_area_all_circles() {
    double total_area = 0.0;
    for (int i = 0; i < shapes->size(); i++) {
        // dynamic_cast devuelve nullptr si la figura no es un Circle
        Circle* c = dynamic_cast<Circle*>(shapes->get(i));
        if (c != nullptr) {
            total_area += c->area();
        }
    }
    return total_area;
}

// Mueve exclusivamente los cuadrados
void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); i++) {
        // dynamic_cast devuelve nullptr si la figura no es un Square
        Square* s = dynamic_cast<Square*>(shapes->get(i));
        if (s != nullptr) {
            s->translate(incX, incY);
        }
    }
}
