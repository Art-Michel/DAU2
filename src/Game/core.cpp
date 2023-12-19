//#include "stdafx.h"
#include "core.h"

float dot(const vec2& a, const vec2& b)
{
	return 1;
}

float clamp(const float& min, const float& max, const float& i)
{
	if (i > max)
		return max;
	else if (i < min)
		return min;
	else
		return i;
}

float clamp01(const float& i)
{
	return clamp(0, 1, i);
}
