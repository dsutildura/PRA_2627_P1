#include "Square.h"
#include <stdexcept>

// Comprueba si los vértices forman un cuadrado válido (4 lados iguales)
bool Square::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);
    
    return (d01 == d12) && (d12 == d23) && (d23 == d30);
}

// Constructor por defecto
Square::Square() {
    // El constructor base Rectangle() ya inicializa el color y reserva memoria para 'vs'
    // Solo necesitamos sobrescribir las coordenadas a las de un cuadrado por defecto
    vs[0] = Point2D(-1, 1);
    vs[1] = Point2D(1, 1);
    vs[2] = Point2D(1, -1);
    vs[3] = Point2D(-1, -1);
}

// Constructor con parámetros
Square::Square(std::string color, Point2D* vertices) {
    set_color(color);         // Valida y asigna el color
    set_vertices(vertices);  // Valida y asigna los vértices
}

// Modificador de vértices sobrescrito para cuadrados
void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un cuadrado válido.");
    }
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

// Imprimir por pantalla
void Square::print() {
    std::cout << *this << std::endl;
}

// Sobrecarga global del operador de inserción (<<)
std::ostream& operator<<(std::ostream &out, const Square &square) {
    out << "[Square: color = " << square.color 
        << "; v0 = " << square.vs[0] << "; v1 = " << square.vs[1] 
        << "; v2 = " << square.vs[2] << "; v3 = " << square.vs[3] << "]";
    return out;
}
