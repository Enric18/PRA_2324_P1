#include "Shape.h"
#include <iostream>
using namespace std;

Shape::Shape(){
  color = "red";
}


Shape::Shape(string color) {
    if (color == "red" || color == "green" || color == "blue") {
        this->color = color;
    } 
    else {
        throw invalid_argument("Color inválido.");
    }
}

string Shape::get_color() const {
    return color;
}

void Shape::set_color(string c) {
    if (c == "red" || c == "green" || c == "blue") {
        color = c;
    }
    else {
        throw invalid_argument("Color inválido.");
    }
}
