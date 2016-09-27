#include "flops.h"
#include <cmath>

const float PI = 3.1415927;

// FLT_Epsilon in <cfloat> is an okay threshold.

bool fequals(float lhs, float rhs)
{
	return fabsf(lhs - rhs) <= 0.0000001f;
	//return true; If the delta between the two operands is less than some threshold
}

float deg2rad(float deg)
{
	return deg * PI / 180;
}

float rad2deg(float rad)
{
	return rad * 180 / PI;
}
