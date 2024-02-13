#include <iostream>
#include "Vector2d.h"
#include "Vector3d.h"

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector) {
	return Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) {
	return Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);
}
int main()
{
    Vector2d v1(6.0, 0.5, 4.5, 4.0);
	Vector2d v2(1.0, 2.0, 5.0, 3.0);
    Vector2d v3(0.5, 0.2, 5.0, 3.0);

	std::cout << "Vector v2: " << v2 << std::endl;
	v2.scale(2.0, 1.5);
	std::cout << "Scaled v2: " << v2 << std::endl;

	Vector2d negatedV2 = v2.negate();
	std::cout << "Negated v2: " << negatedV2 << std::endl;

	std::cout << "Dot product of v2 and v3: " << v2.dotProduct(v3) << std::endl;

    VectorRelativeState relativeState = v2.getRelativeState(v1);
    std::cout << "Relative state between v2 and v3: ";
    switch (relativeState) {
    case VectorRelativeState::Identical:
        std::cout << "Identical";
        break;
    case VectorRelativeState::CoDirected:
        std::cout << "CoDirected";
        break;
    case VectorRelativeState::OppositeDirected:
        std::cout << "OppositeDirected";
        break;
    case VectorRelativeState::AcuteAngle:
        std::cout << "AcuteAngle";
        break;
    case VectorRelativeState::ObtuseAngle:
        std::cout << "ObtuseAngle";
        break;
    case VectorRelativeState::RightAngle:
        std::cout << "RightAngle";
        break;
    }
    std::cout << std::endl;

    Vector3d vA(1.0, 2.0, 3.0);
    Vector3d vB(4.0, 5.0, 6.0);

    Vector3d result = vA.crossProduct(vB);

    std::cout << "Cross Product: " << result << std::endl;
}