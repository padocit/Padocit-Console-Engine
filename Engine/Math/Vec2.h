#pragma once

#include "Core.h"

class ENGINE_API Vec2
{
public:
	Vec2(int x, int y);
	~Vec2() = default;

	// operator overloading
	bool operator==(const Vec2& other);
	bool operator!=(const Vec2& other);

	Vec2 operator+(const Vec2& other);
	Vec2 operator-(const Vec2& other);
	Vec2 operator*(const Vec2& other);
	Vec2 operator/(const Vec2& other);

	Vec2& operator+=(const Vec2& other);
	Vec2& operator-=(const Vec2& other);
	Vec2& operator*=(const Vec2& other);
	Vec2& operator/=(const Vec2& other);

public:
	int x = 0;
	int y = 0;
};