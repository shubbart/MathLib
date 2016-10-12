#pragma once
#include "vec3.h"

// [ column 1 ] [ column 2 ] [ column 3 ] Layout
// [ 0][ 1][ 2] [ 3][ 4][ 5] [ 6][ 7][ 8] array
// [00][01][02] [10][11][12] [20][21][22] 3D array
// [ 0 {x,y,z}] [ 1 {x,y,z}] [ 2 {x,y,z}] vectors

union mat3
{
	float m[9];      // single dimensional array
	float mm[3][3];  // multidimensional array
	vec3  c[3];      // column vectors

	vec3 operator[](unsigned idx) const;
	vec3 &operator[](unsigned idx);
};

mat3 mat3Identity();

bool operator==(const mat3 &A, const mat3 &B);
bool operator!=(const mat3 &A, const mat3 &B);

mat3 transpose(const mat3 &A);

mat3 operator+(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A, const mat3 &B);

mat3 operator*(const mat3 &A, float s);
mat3 operator*(float s, const mat3 &A);
mat3 operator*(const mat3 &A, const mat3 &B);
vec3 operator*(const mat3 &A, const vec3 &V);

mat3 operator-(const mat3 &A);

float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);

mat3 scale(float w, float h);
mat3 translate(float x, float y);
mat3 rotate(float a);