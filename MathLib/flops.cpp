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

float linearHalf(float x)
{
	return .5f * x;
}

float quad(float x)
{
	return x * x;
}

float sqroot(float x)
{
	return sqrt(x);
}

float rAbsolute(float x)
{
	return -abs(2 * x - 1) + 1;
}

float bounce(float x)
{
	return abs(cos(x * 10)*(quad(1 - x)));
}

float rBounce(float x)
{
	return 1 - bounce(x);
}

float rQuad(float x)
{
	return -quad(2*x - 1) + 1;
}

// Interpolation/ Extrapolation / Mixing

// if alpha is 0, we want to return the start
// if alpha is 1, we want to return the end
float lerp(float start, float end, float alpha)
{
		return (1-alpha)*start + (alpha)*end; // avoids some issues with floating point error

	// return alpha*(end - start) + start; //linear form, where alpha is x
}

float quadBezier(float start, float mid, float end, float alpha)
{
	return lerp(lerp(start, mid, alpha), lerp(mid, end, alpha), alpha);
}

float cubicBezier(float start, float mid1, float mid2, float end, float alpha)
{
	return (1-alpha)*(1 - alpha)*(1 - alpha)*start + 3*(1-alpha)*(1 - alpha)*alpha*mid1 +
			3*(1-alpha)*alpha*alpha*mid2 + alpha*alpha*alpha*end;
}

float HermiteSpline(float start, float s_tan, float end, float e_tan, float alpha)
{
	float alphaSq = alpha*alpha;
	float alphaCub = alphaSq*alpha;

	float h00 = 2 * alphaCub - 3 * alphaSq + 1;
	float h01 = -2 * alphaCub + 3 * alphaSq;
	float h10 = alphaCub - 2 * alphaSq + alpha;
	float h11 = alphaCub - alphaSq;

	return h00 * start + h10 *s_tan + h01*end + h11*e_tan;
}

float cardinalSpline(float start, float mid, float end, float tightness, float alpha)
{
	float s_tan = (mid - start) * tightness;
	float e_tan = (end - start) * tightness;

	return HermiteSpline(start, s_tan, end, e_tan, alpha);
}

float catRomSpline(float start, float mid, float end, float alpha)
{
	return cardinalSpline(start, mid, end, 0.5f, alpha);
}
