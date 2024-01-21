#pragma once
#include <iostream>

class Vector2d {
private:
	float x;
	float y;
	static int instanceCount;

public:
	Vector2d();
	Vector2d(float xVal, float yVal);

	float getX() const;
	float getY() const;

	Vector2d& operator=(const Vector2d& other);

	Vector2d operator+(const Vector2d& secondVector);
	Vector2d operator-(const Vector2d& secondVector);

	friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
	friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);

	float operator()();

	float& operator[](int i);

	friend void operator<<(std::ostream& out, const Vector2d& vec);

	friend void operator>>(std::istream& cin, Vector2d& vec);

	static int getInstanceCount();
};
