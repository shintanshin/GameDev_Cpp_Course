#pragma once

class Rectangle {

private:
	float Length;
	float Height;

public:
	Rectangle();
	Rectangle(float l, float h);

	float getArea() const;
	float getPerimeter() const;
};