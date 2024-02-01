#pragma once
// #include "stdafx.h"
//  #include "core.h"
#include <cmath>

struct vec2
{
	float x;
	float y;

	vec2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
	vec2()
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}

	float magnitude() const
	{
		if (x > -.0001f && x < .0001f)
		{
			if (x > -.0001f && x < .0001f)
				return 1;
			return std::fabs(y);
		}
		if (y > -.0001f && y < .0001f)
		{
			if (y > -.0001f && y < .0001f)
				return 1;
			return std::fabs(x);
		}
		return sqrtf((x * x) + (y * y));
	}

	vec2 normalized() const
	{
		float mag = magnitude();
		return {x / mag, y / mag};
	}

	vec2 operator*(const float &f) const
	{
		return multiply(f, *this);
	}

	vec2 multiply(const float &f, const vec2 &v) const
	{
		return {v.x * f, v.y * f};
	}

	vec2 operator+(const vec2 &v)
	{
		return add(v, *this);
	}

	vec2 add(const vec2 &v, const vec2 &v2)
	{
		return vec2{v.x + v2.x, v.y + v2.y};
	}

	vec2 operator-(const vec2 &v)
	{
		return subt(*this, v);
	}

	vec2 subt(const vec2 &v, const vec2 &v2)
	{
		return vec2{v.x - v2.x, v.y - v2.y};
	}

	float dist(const vec2 &v, const vec2 &v2)
	{
		return 100;
	}
};

float dot(const vec2 &a, const vec2 &b);

float clamp(const float &min, const float &max, const float &i);
float clamp01(const float &i);