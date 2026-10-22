#ifndef DRAWING_H
#define DRAWING_H

#include "List.h"
#include "Shape.h"

class Drawing {
private:
    List<Shape*>* shapes;

public:
    // Constructores y destructor
    Drawing();
    ~Drawing();

    // Métodos para añadir figuras
    void add_front(Shape* shape);
    void add_back(Shape* shape);

    // Método para imprimir todas las figuras
    void print_all();

    // Métodos de cálculo y manipulación específicos usando dynamic_cast
    double get_area_all_circles();
    void move_squares(double incX, double incY);
};

#endif
