#include "Vector2d.h"
#include <cmath>
#include <iostream>

int Vector2d::instanceCount = 0;

Vector2d::Vector2d()
    :x(0.0f), y(0.0f)
{    ++instanceCount; }

Vector2d& Vector2d::operator=(const Vector2d& other)
{
    if(this != &other){
        x = other.x;
        y = other.y;
    }
    return *this;
}

Vector2d::Vector2d(float xVal, float yVal)
    : x(xVal), y(yVal)
{  ++instanceCount; }

float Vector2d::getX() const
{
    return x;
}

float Vector2d::getY() const
{
    return y;
}

Vector2d Vector2d::operator+(const Vector2d& secondVector)
{
    return Vector2d(x+secondVector.x, y+secondVector.y);
}

Vector2d Vector2d::operator-(const Vector2d& secondVector)
{
    return Vector2d(x - secondVector.x, y - secondVector.y);
}

float Vector2d::operator()()
{
    return std::sqrt(x * x + y * y);
}

float& Vector2d::operator[](int i)
{
    if (i == 0) {
        return x;
    }
    else if (i == 1) {
        return y;
    }
    else {
        std::cout << "Wrong vector index!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int Vector2d::getInstanceCount()
{
    return instanceCount;
}

 void operator<<(std::ostream& out, const Vector2d& vec) 
 {
      out << "{" << vec.getX() << "; " << vec.getY() << "}";
}

 void operator>>(std::istream& cin, Vector2d& vec) {
        cin >> vec.x >> vec.y;
 }