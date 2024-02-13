#include "Vector3d.h"


std::ostream& operator<<(std::ostream& out, const Vector3d& vec)
{
	out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
    return out;
}

Vector3d Vector3d::crossProduct(const Vector3d& other) const
{
    float resultX = y * other.z - z * other.y;
    float resultY = z * other.x - x * other.z;
    float resultZ = x * other.y - y * other.x;

    return Vector3d(resultX, resultY, resultZ);
}