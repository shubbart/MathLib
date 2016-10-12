#include "vec3.h"
#include <cmath>
#include "flops.h"

float vec3::operator[](unsigned idx) const
{
	return v[idx];
}

float & vec3::operator[](unsigned idx)
{
	return v[idx];
}


vec3 operator+(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}

vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
}

vec3 operator*(const vec3 & lhs, float rhs)
{
	return vec3{ lhs.x  *rhs, lhs.y *rhs, lhs.z *rhs };
}
vec3 operator*(float rhs, const vec3 & lhs)
{
	return vec3{ rhs * lhs.x, rhs * lhs.y, rhs * lhs.z };
}

vec3 operator/(const vec3 & lhs, float rhs)
{
	return vec3{ lhs.x / rhs, lhs.y / rhs, lhs.z / rhs };
}

vec3 operator/(float rhs, const vec3 & lhs)
{
	return vec3{ rhs / lhs.x, rhs / lhs.y, rhs / lhs.z };
}

vec3 operator-(const vec3 & v)
{
	return vec3{-v.x, -v.y, -v.z};
}

vec3 & operator+=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs + rhs;
}

vec3 & operator-=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs - rhs;
}

vec3 & operator/=(vec3 & lhs, float rhs)
{
	return lhs = lhs / rhs;
}

vec3 & operator*=(vec3 & lhs, float rhs)
{
	return lhs = lhs * rhs;
}

bool operator==(const vec3 & lhs, const vec3 &rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	return lhs.x != rhs.x && lhs.y != rhs.y && lhs.z != rhs.z;
}

float magnitude(const vec3 & v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

vec3 normal(const vec3 & v)
{
	vec3 retval;

	retval.x = v.x / sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	retval.y = v.y / sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	retval.z = v.z / sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

	return retval;
}

float dotProd(const vec3 & lhs, const vec3 & rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

float angleBetween(const vec3 & lhs, const vec3 & rhs)
{
	return acos(dotProd(normal(lhs), normal(rhs)));
}

vec3 crossProd(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{lhs.y*rhs.z - lhs.z*rhs.y,
				lhs.z*rhs.x - lhs.x*rhs.z,
				lhs.x*rhs.y - lhs.y*rhs.x};
}
