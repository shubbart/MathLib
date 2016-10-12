#pragma once
#include "vec2.h"

union vec3 
{
	float v[3];
	struct { float x, y, z; };
	vec2 xy;

	float operator[](unsigned idx) const;
	float &operator[](unsigned idx);
};

vec3 operator+(const vec3 &lhs, const vec3 &rhs);
vec3 operator-(const vec3 &lhs, const vec3 &rhs);

vec3 operator*(const vec3 &lhs, float rhs);
vec3 operator*(float rhs, const vec3 &lhs);

vec3 operator/(const vec3 &lhs, float rhs);
vec3 operator/(float rhs, const vec3 &lhs);

vec3 operator-(const vec3 &v);

vec3 &operator+=(vec3 &lhs, const vec3 &rhs);
vec3 &operator-=(vec3 &lhs, const vec3 &rhs);
vec3 &operator/=(vec3 &lhs, float rhs);
vec3 &operator*=(vec3 &lhs, float rhs);

bool operator==(const vec3 &lhs, const vec3 &rhs);
bool operator!=(const vec3 &lhs, const vec3 &rhs);

float magnitude(const vec3 &v);

vec3 normal(const vec3 &v);

float dotProd(const vec3 &lhs, const vec3 &rhs);

float angleBetween(const vec3 &lhs, const vec3 &rhs);

vec3 crossProd(const vec3 &lhs, const vec3 &rhs);