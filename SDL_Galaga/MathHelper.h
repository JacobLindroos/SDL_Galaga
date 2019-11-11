#pragma once

#include <math.h>

#define PI 3.14159265
#define DEG_TO_RAD PI/180.0f


struct Vector2
{
	float x;
	float y;

	Vector2(float _x = 0.0f, float _y = 0.0f) : x(_x), y(_y) {}

	//return the square of a vector magnitude, so the magnitude of the vector but in square value
	float MagnitudeSqr()
	{
		return x * x + y * y;
	}

	//calculates the acctual magnitude of a vector
	float Magnitude()
	{
		//returning the squareRoot value of that vector, which is the magnitude of the vector
		return (float)sqrt(x * x + y * y);
	}

	//directional vector of the vector
	Vector2 Normalized()
	{
		float mag = Magnitude();

		return Vector2(x / mag, y / mag);
	}
};


//operator overloading, so we can add/subtract to vectors with each other
inline Vector2 operator +(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline Vector2 operator -(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

//takes a vector and rotates it to a new angle
inline Vector2 RotateVector(Vector2& vec, float angle)
{
	//calculates the rad of an angle, we need this because all the sin/cos-functions in math.h uses..
	//..radians instead of degrees
	float radAngle = (float)(angle * DEG_TO_RAD);

	//returns a vector rotated in a specific direction to a new angle
	return Vector2((float)(vec.x * cos(radAngle) - vec.y * sin(radAngle)), (float)(vec.x * sin(radAngle) + vec.y * cos(radAngle)));
}