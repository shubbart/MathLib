#pragma once

struct vec2 { float x, y;};

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