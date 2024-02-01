// #include "stdafx.h"
#include "core.h"

float dot(const vec2 &v, const vec2 &v2)
{
	vec2 vn = v.normalized();
	vec2 vn2 = v2.normalized();
	return (vn.x * vn2.x) + (vn.y * vn2.y);
}

float clamp(const float &min, const float &max, const float &i)
{
	if (i > max)
		return max;
	else if (i < min)
		return min;
	else
		return i;
}

float clamp01(const float &i)
{
	return clamp(0, 1, i);
}
