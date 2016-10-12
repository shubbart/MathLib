#include "mat2.h"
#include "flops.h"

vec2 mat2::operator[](unsigned idx) const
{
	return c[idx];
}

vec2 & mat2::operator[](unsigned idx)
{
	return c[idx];
}



mat2 mat2Identity()
{
	return mat2{ 1,0,0,1 };
}

bool operator==(const mat2 & A, const mat2 & B)
{
	return A[0] == B[0] && A[1] == B[1];
}

bool operator!=(const mat2 & A, const mat2 & B)
{
	return	!(A == B);
}

mat2 transpose(const mat2 &A)
{
	mat2 retval = A;

	retval.mm[1][0] = A.mm[0][1];
	retval.mm[0][1] = A.mm[1][0];

	return retval;
}

mat2 operator+(const mat2 &A, const mat2 &B)
{
	return mat2{A.m[0] + B.m [0], A.m[1] + B.m[1], A.m[2] + B.m[2], A.m[3] + B.m[3]};

	/*mat2 retval;
	  retval[0] = A[0] + B[0];
	  retval[1] = A[1] + B[1];
	*/
	
}

mat2 operator-(const mat2 &A, const mat2 &B)
{
	return mat2{ A.m[0] - B.m[0], A.m[1] - B.m[1], A.m[2] - B.m[2], A.m[3] - B.m[3] };

	/*mat2 retval;
	retval[0] = A[0] - B[0];
	retval[1] = A[1] - B[1];
	*/
}

mat2 operator*(const mat2 & A, float s)
{
	return mat2{ A.m[0] * s, A.m[1] * s, A.m[2] * s, A.m[3] * s };

	/*mat2 retval;
	retval[0] = A[0] * s;
	retval[1] = A[1] * s;
	*/
}

mat2 operator*(float s, const mat2 & A)
{
	return mat2{ s * A.m[0], s * A.m[1], s * A.m[2], s * A.m[3]};

	/*mat2 retval;
	retval[0] = A[0] * s;
	retval[1] = A[1] * s;
	*/
}

mat2 operator*(const mat2 & A, const mat2 & B)
{

	mat2 retA = transpose(A);
	mat2 retval;

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			retval[j][i] = dotProd(retA[i], B[j]);

	return retval;
}

vec2 operator*(const mat2 & A, const vec2 &V)
{
	mat2 retA = transpose(A);
	vec2 retval;

	retval.x = dotProd(A.c[0], V);
	retval.y = dotProd(A.c[1], V);

	return retval;
}

mat2 operator-(const mat2 &A)
{
	return mat2{ -A.m[0], -A.m[1], -A.m[2], -A.m[3] };
	//return A*-1;
}

float determinant(const mat2 & A)
{
	return float((A.m[0] * A.m[3]) - (A.m[1] * A.m[2]));
}

mat2 inverse(const mat2 & A)
{

	mat2 value;
	value.m[0] = A.m[3];
	value.m[1] = -A.m[1];
	value.m[2] = -A.m[2];
	value.m[3] = A.m[0];

	float invA = 1 / determinant(A);
	
	fequals(value.m[0], invA);
	fequals(value.m[1], invA);
	fequals(value.m[2], invA);
	fequals(value.m[3], invA);

	return value * invA;
}
