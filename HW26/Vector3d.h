#pragma once
#include <iostream>

class Vector3d {
private:
    float x;
    float y;
    float z;

public:
   // Vector3d();
    Vector3d(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) {}

    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }

    Vector3d crossProduct(const Vector3d& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Vector3d& vec);
};