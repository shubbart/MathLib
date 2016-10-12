#include "mat3.h"
#include "flops.h"
#include <cmath>

vec3 mat3::operator[](unsigned idx) const
{
	return c[idx];
}

vec3 & mat3::operator[](unsigned idx)
{
	return c[idx];
}



mat3 mat3Identity()
{
	return mat3{ 1,0,0,  0,1,0,  0,0,1 };
}

bool operator==(const mat3 & A, const mat3 & B)
{
	return A[0] == B[0] && A[1] == B[1] && A[2] == B[2];
}

bool operator!=(const mat3 & A, const mat3 & B)
{
	return	!(A == B);
}

mat3 transpose(const mat3 &A)
{
	mat3 retval;

	for (unsigned i = 0; i < 3; ++i)
		for (unsigned j = 0; j < 3; ++j)
			retval[i][j] = A[j][i];

	return retval;
}

mat3 operator+(const mat3 &A, const mat3 &B)
{
	//return mat3{ A.m[0] + B.m[0], A.m[1] + B.m[1], A.m[2] + B.m[2], A.m[3] + B.m[3], A };

	mat3 retval;
	retval[0] = A[0] + B[0];
	retval[1] = A[1] + B[1];
	retval[2] = A[2] + B[2];

	/*for (int i = 0; i < 3; ++i)
		retval[i] = A[i] + B[i];*/

	return retval;

}

mat3 operator-(const mat3 &A, const mat3 &B)
{
	//return mat3{ A.m[0] - B.m[0], A.m[1] - B.m[1], A.m[2] - B.m[2], A.m[3] - B.m[3] };

	mat3 retval;
	retval[0] = A[0] - B[0];
	retval[1] = A[1] - B[1];
	retval[2] = A[2] - B[2];
	
	return retval;
}

mat3 operator*(const mat3 & A, float s)
{
	//return mat3{ A.m[0] * s, A.m[1] * s, A.m[2] * s, A.m[3] * s };

	mat3 retval;
	retval[0] = A[0] * s;
	retval[1] = A[1] * s;
	retval[2] = A[2] * s;

	/*for (int i = 0; i < 3; ++i)
	retval[i] = A[i] * s;*/

	return retval;
}

mat3 operator*(float s, const mat3 & A)
{
	//return mat3{ s * A.m[0], s * A.m[1], s * A.m[2], s * A.m[3] };

	mat3 retval;
	retval[0] = A[0] * s;
	retval[1] = A[1] * s;
	retval[2] = A[2] * s;

	/*for (int i = 0; i < 3; ++i)
	retval[i] = A[i] * s;*/

	return retval;
}

mat3 operator*(const mat3 & A, const mat3 & B)
{
	mat3 retval;

	/*retval.m[0] = A.m[0] * B.m[0] + A.m[3] * B.m[1] + A.m[6] * B.m[2];
	retval.m[1] = A.m[1] * B.m[0] + A.m[4] * B.m[1] + A.m[7] * B.m[2];
	retval.m[2] = A.m[2] * B.m[0] + A.m[5] * B.m[1] + A.m[8] * B.m[2];

	retval.m[0] = A.m[0] * B.m[3] + A.m[3] * B.m[4] + A.m[6] * B.m[5];
	retval.m[1] = A.m[1] * B.m[3] + A.m[4] * B.m[4] + A.m[7] * B.m[5];
	retval.m[2] = A.m[2] * B.m[3] + A.m[5] * B.m[4] + A.m[8] * B.m[5];

	retval.m[0] = A.m[0] * B.m[6] + A.m[3] * B.m[7] + A.m[6] * B.m[8];
	retval.m[1] = A.m[1] * B.m[6] + A.m[4] * B.m[7] + A.m[7] * B.m[8];
	retval.m[2] = A.m[2] * B.m[6] + A.m[5] * B.m[7] + A.m[8] * B.m[8];*/

	mat3 At = transpose(A);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			retval[i][j] = dotProd(At[j], B[i]);

	return retval;
}

vec3 operator*(const mat3 & A, const vec3 & V)
{
	vec3 retval;
	mat3 retA = transpose(A);

	retval.x = dotProd(A.c[0], V);
	retval.y = dotProd(A.c[1], V);
	retval.z = dotProd(A.c[2], V);

	return retval;
}

mat3 operator-(const mat3 &A)
{
	/*return mat3{ -A.m[0], -A.m[1], -A.m[2],
				-A.m[3], -A.m[4], -A.m[5],
				-A.m[6], -A.m[7], -A.m[8] };*/
	return A*-1;
}

float determinant(const mat3 & A)
{
	return float(A.m[0] * ((A.m[4] * A.m[8]) - (A.m[5] * A.m[7]))) -
				(A.m[1] * ((A.m[3] * A.m[8]) - (A.m[5] * A.m[6]))) +
				(A.m[2] * ((A.m[3] * A.m[7]) - (A.m[4] * A.m[6])));

	//return dotProd(A[0], crossProd(A[1], A[2]));
}

mat3 inverse(const mat3 & A)
{

	/*mat3 value;
	
	value.m[0] = (A.m[4] * A.m[8]) - (A.m[5] * A.m[7]);
	value.m[1] = (A.m[3] * A.m[8]) - (A.m[5] * A.m[6]);
	value.m[2] = (A.m[3] * A.m[7]) - (A.m[4] * A.m[6]);
	value.m[3] = (A.m[1] * A.m[8]) - (A.m[2] * A.m[7]);
	value.m[4] = (A.m[0] * A.m[8]) - (A.m[2] * A.m[6]);
	value.m[5] = (A.m[0] * A.m[7]) - (A.m[1] * A.m[6]);
	value.m[6] = (A.m[1] * A.m[5]) - (A.m[2] * A.m[4]);
	value.m[7] = (A.m[0] * A.m[5]) - (A.m[2] * A.m[3]);
	value.m[8] = (A.m[0] * A.m[4]) - (A.m[1] * A.m[3]);

	value.m[1] = -value.m[1];
	value.m[3] = -value.m[3];
	value.m[5] = -value.m[5];
	value.m[7] = -value.m[7];

	
	//mat3 adjugate = transpose(value);
	float detA = 1 / determinant(A);

	fequals(value.m[0], detA);
	fequals(value.m[1], detA);
	fequals(value.m[2], detA);
	fequals(value.m[3], detA);
	fequals(value.m[4], detA);
	fequals(value.m[5], detA);
	fequals(value.m[6], detA);
	fequals(value.m[7], detA);
	fequals(value.m[8], detA);
	
	return transpose(value) * detA;
	//return adjugate * detA;*/

////////////////////////////////////////////////////////////////////////////////////////	

	mat3 retval;

	retval[0] = crossProd(A[1], A[2]);
	retval[1] = crossProd(A[2], A[0]);
	retval[2] = crossProd(A[0], A[1]);

	return 1 / determinant(A) *
		transpose(retval);
}

mat3 scale(float w, float h)
{
	mat3 retval = mat3Identity();
	retval[0][0] = w;
	retval[1][1] = h;

	return retval;

}

mat3 translate(float x, float y)
{
	mat3 retval = mat3Identity();
	retval[2][0] = x;
	retval[2][1] = y;


	return retval;
}

mat3 rotate(float a)
{
	vec2 d = fromAngle(a);
	mat3 retval = mat3Identity();

	retval[0].xy = d;
	retval[1].xy = -perp(d);

	return retval;
}