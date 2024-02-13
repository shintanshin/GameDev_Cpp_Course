#pragma once
#include <iostream>

enum class VectorRelativeState {
	Identical,
	CoDirected,
	OppositeDirected,
	AcuteAngle,
	ObtuseAngle,
	RightAngle
};

class Vector2d {
private:
	float x;
	float y;
	static int instanceCount;

public:
	Vector2d(float x0, float y0, float x1, float y1)
		: x(x1 - x0), y(y1 - y0) {}

	Vector2d();
	Vector2d(float xVal, float yVal);

	float getX() const;
	float getY() const;

	Vector2d& operator=(const Vector2d& other);

	Vector2d operator+(const Vector2d& secondVector);
	Vector2d operator-(const Vector2d& secondVector);

	friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
	friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);
	float operator()() const;
	float& operator[](int i);
	friend std::ostream& operator<<(std::ostream& out, const Vector2d& vec);
	friend void operator>>(std::istream& cin, Vector2d& vec);

	static int getInstanceCount();

	float dotProduct(const Vector2d& other) const;

	Vector2d negate() const {return Vector2d(-x, -y);}

	VectorRelativeState getRelativeState( const Vector2d& other) const;

	void scale(float factorX, float factorY);
};