#include "vec2.h"
#include <cmath>
#include "flops.h"

vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x + rhs.x, lhs.y + rhs.y };
}

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x - rhs.x, lhs.y - rhs.y };
}

vec2 operator*(const vec2 & lhs, float rhs)
{
	return vec2{ lhs.x  *rhs, lhs.y *rhs };
}
vec2 operator*(float rhs, const vec2 & lhs)
{
	return vec2{ rhs * lhs.x, rhs * lhs.y };
}

vec2 operator/(const vec2 & lhs, float rhs)
{
	return vec2{ lhs.x  /rhs, lhs.y /rhs };
}

vec2 operator/(float rhs, const vec2 & lhs)
{
	return vec2{ rhs / lhs.x, rhs / lhs.y };
}

vec2 operator-(const vec2 & v)
{
	return vec2{ -v.x, -v.y};
}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs + rhs;
}

vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs - rhs;
}

vec2 & operator/=(vec2 & lhs, float rhs)
{
	return lhs = lhs / rhs;
}

vec2 & operator*=(vec2 & lhs, float rhs)
{
	return lhs = lhs * rhs;
}

bool operator==(const vec2 & lhs, const vec2 &rhs)
{
	return fequals(lhs.x, rhs.x)
		&& fequals(lhs.y, rhs.y);
	//return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	return lhs.x != rhs.x && lhs.y != rhs.y;
}

float magnitude(const vec2 & v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

vec2 normal(const vec2 & v)
{
	vec2 retval;

	retval.x = v.x / sqrt(v.x * v.x + v.y * v.y);
	retval.y = v.y / sqrt(v.x * v.x + v.y * v.y);

	return retval;
}

float dotProd(const vec2 & lhs, const vec2 & rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y;
}


float angleBetween(const vec2 & lhs, const vec2 & rhs)
{
	return acos(dotProd(normal(lhs), normal(rhs)));
}

vec2 perp(const vec2 & v)
{
	return { v.y, -v.x };
}

float angle(const vec2 & v)
{
	return atan2f(v.y, v.x);
}

vec2 fromAngle(float a)
{
	return vec2{ cos(a), sin(a) };
}

vec2 lerp(const vec2 &start, const vec2 &end, float alpha)
{
	vec2 retval;
	retval.x = lerp(start.x, end.x, alpha);
	retval.y = lerp(start.y, end.y, alpha);
	return retval; 
}

vec2 quadBezier(const vec2 &start, const vec2 &mid, const vec2 &end, float alpha)
{
	vec2 retval;
	retval.x = quadBezier(start.x, mid.x, end.x, alpha);
	retval.y = quadBezier(start.y, mid.y, end.y, alpha);
	return retval;
}

vec2 cubicBezier(vec2 &start, vec2 &mid1, vec2 &mid2, vec2 &end, float alpha)
{
	vec2 retval;
	retval.x = cubicBezier(start.x, mid1.x, mid2.x, end.x, alpha);
	retval.y = cubicBezier(start.y, mid1.y, mid2.y, end.y, alpha);
	return retval;
}

vec2 HermiteSpline(const vec2 &start, const vec2 &s_tan, const vec2 &end, const vec2 &e_tan, float alpha)
{
	vec2 retval;
	retval.x = HermiteSpline(start.x, s_tan.x, end.x, e_tan.x, alpha);
	retval.y = HermiteSpline(start.y, s_tan.y, end.y, e_tan.y, alpha);
	return retval;
}

vec2 cardinalSpline(const vec2 &start, const vec2 &mid, const vec2 &end, float tightness, float alpha)
{
	vec2 retval;
	retval.x = cardinalSpline(start.x, mid.x, end.x, tightness, alpha);
	retval.y = cardinalSpline(start.y, mid.y, end.y, tightness, alpha);
	return retval;
}

vec2 catRomSpline(const vec2 &start, const vec2 &mid, const vec2 &end, float alpha)
{
	vec2 retval;
	retval.x = cardinalSpline(start.x, mid.x, end.x, .5f, alpha);
	retval.y = cardinalSpline(start.y, mid.y, end.y, .5f, alpha);
	return retval;
}

float vec2::operator[](unsigned idx) const
{
	return v[idx];
}

float & vec2::operator[](unsigned idx)
{
	return v[idx];
}
