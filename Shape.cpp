#include "Shape.h"
#include <stdexcept>
#include <string>

// Constructor por defecto
Shape::Shape() : color("red") {
}

// Constructor parametrizado
Shape::Shape(std::string color) {
    set_color(color); // Reutilizamos el método set_color para validar
}

// Consultor
std::string Shape::get_color() const {
    return color;
}

// Modificador con validación
void Shape::set_color(std::string c) {
    if (c == "red" || c == "green" || c == "blue") {
        color = c;
    } else {
        throw std::invalid_argument("Color invalido. Solo se permite red, green o blue.");
    }
}
