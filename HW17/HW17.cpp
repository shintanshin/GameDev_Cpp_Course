#include <iostream>
#include "Vector2d.h"

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector) {
	return Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) {
	return Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);
}



int main()
{
	Vector2d v1;
	Vector2d v2(1.0, 2.0);
	Vector2d v3(5.0, 3.0);

	Vector2d v4 = v2;

	std::cout << "v1: (" << v1.getX() << ", " << v1.getY() << ")" << std::endl;
	std::cout << "v2: (" << v2.getX()<< ", " << v2.getY() << ")" << std::endl;
	std::cout << "v3: (" << v4.getX()<< ", " << v4.getY() << ")" << std::endl;

	Vector2d v_sum = v2 + v3;
	Vector2d v_diff = v3 - v2;

	// This outputs show us both (native & friend) realization of operators +, -
	std::cout << "v1 + v2: (" << v_sum.getX() << ", " << v_sum.getY() << ")" << std::endl;
	std::cout << "v1 - v2: (" << v_diff.getX() << ", " << v_diff.getY() << ")" << std::endl;


	std::cout << "Length v3 is: " << v3() << std::endl;

	std::cout << "x = " << v2[0] << std::endl; 
	std::cout << "y = " << v2[1] << std::endl;

	Vector2d testVec(1.2, 5.6);
	std::cout << testVec;	std::cout << std::endl;

	Vector2d vecInput;
	std::cout << "Enter vector coordinates (x y): ";
	std::cin >>vecInput;
	std::cout << "Entered vector: " << vecInput; std::cout << std::endl;

	std::cout << "Count of live instances: " << Vector2d::getInstanceCount() << std::endl;
}
