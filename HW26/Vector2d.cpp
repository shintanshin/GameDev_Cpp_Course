#include "Vector2d.h"
#include <cmath>
#include <iostream>
#include <cmath>

int Vector2d::instanceCount = 0;

Vector2d::Vector2d()
    :x(0.0f), y(0.0f)
{
    ++instanceCount;
}

Vector2d& Vector2d::operator=(const Vector2d& other)
{
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Vector2d::Vector2d(float xVal, float yVal)
    : x(xVal), y(yVal)
{
    ++instanceCount;
}

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
    return Vector2d(x + secondVector.x, y + secondVector.y);
}

Vector2d Vector2d::operator-(const Vector2d& secondVector)
{
    return Vector2d(x - secondVector.x, y - secondVector.y);
}

float Vector2d::operator()()const 
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

std::ostream& operator<<(std::ostream& out, const Vector2d& vec)
{
    out << "{" << vec.getX() << "; " << vec.getY() << "}";
    return out;
}

void operator>>(std::istream& cin, Vector2d& vec) {
    cin >> vec.x >> vec.y;
}

float Vector2d::dotProduct(const Vector2d& other) const
{
    return (x * other.x) + (y * other.y);
}

VectorRelativeState Vector2d::getRelativeState(const Vector2d& other) const
{
    float dot = dotProduct(other);
    float magnitudeProduct = (*this)() * other();

    if (magnitudeProduct == 0) {
        return VectorRelativeState::RightAngle;
    }

    float cosTheta = dot / magnitudeProduct;

    float angle = std::acos(cosTheta);
    const float pi = std::acos(-1);

    float angleDegrees = angle * 180.0 / pi;


    if (angleDegrees == 0) {
        return VectorRelativeState::Identical;
    }
    else if (angleDegrees > 0 && angleDegrees < 90) {
        return VectorRelativeState::AcuteAngle;
    }
    else if (angleDegrees == 90) {
        return VectorRelativeState::RightAngle;
    }
    else if (angleDegrees > 90) {
        return VectorRelativeState::ObtuseAngle;
    }
    else {
        if (dot > 0) {
            return VectorRelativeState::CoDirected;
        }
        else {
            return VectorRelativeState::OppositeDirected;
        }
    }
}

void Vector2d::scale(float factorX, float factorY)
{
    x *= factorX;
    y *= factorY;
}

