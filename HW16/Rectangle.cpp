#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle()
    : Length(0.0), Height(0.0){}

Rectangle::Rectangle(float l, float h)
    : Length(l), Height(h) {}

float Rectangle::getArea() const {
    return Length * Height;
}

float Rectangle::getPerimeter() const {
    return 2 * (Length + Height);
}