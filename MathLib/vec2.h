#pragma once

union vec2 
{
	float v[2];
	struct       // untagged
	{
		float x, y;
	};

	float operator[](unsigned idx) const;
	float &operator[](unsigned idx);
 };


vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);

vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator*(float rhs, const vec2 &lhs);

vec2 operator/(const vec2 &lhs, float rhs);
vec2 operator/(float rhs, const vec2 &lhs);

vec2 operator-(const vec2 &v);

vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 &lhs, const vec2 &rhs);
vec2 &operator/=(vec2 &lhs, float rhs);
vec2 &operator*=(vec2 &lhs, float rhs);

bool operator==(const vec2 &lhs, const vec2 &rhs);
bool operator!=(const vec2 &lhs, const vec2 &rhs);

float magnitude(const vec2 &v);

vec2 normal(const vec2 &v);

float dotProd(const vec2 &lhs, const vec2 &rhs);

float angleBetween(const vec2 &lhs, const vec2 &rhs);

// right-handed.
vec2 perp(const vec2 &v);

//arctangent
float angle(const vec2 &v);

// vec2{cos(a), sin(a)};
vec2 fromAngle(float a);

vec2 lerp(const vec2 &start, const vec2 &end, float alpha);
vec2 quadBezier(const vec2 &start, const vec2 &mid, const vec2 &end, float alpha);
vec2 cubicBezier(vec2 &start, vec2 &mid1, vec2 &mid2, vec2 &end, float alpha);
vec2 HermiteSpline(const vec2 &start, const vec2 &s_tan, const vec2 &end, const vec2 &e_tan, float alpha);
vec2 cardinalSpline(const vec2 &start, const vec2 &mid, const vec2 &end, float tightness, float alpha);
vec2 catRomSpline(const vec2 &start, const vec2 &mid, const vec2 &end, float alpha);