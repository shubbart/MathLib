#pragma once

int doNothing(int x);

// Problem a:
float test_quad(float x);

//Problem b:

// Note: Create structures whenever you feel they'll help!
struct quad_results
{
	float sub_root, add_root;
	int roots; //0, 1, 2
};

quad_results quad(float a, float b, float c);


// problem c.
float lerp(float start, float end, float t);

// problem d.
struct Point { float x, y; };
float distance(const Point &P1, const Point &P2);


// problem e.
struct Point3D { float x, y, z; };
float inner(const Point3D &P1, const Point3D &P2);


// problem f.
// Point-Plane Distance....
struct Plane { Point3D abc; float d; };
float point_plane_distance(const Plane &pl, const Point3D &pt);

// problem g.
// Bezier Curve....*/
Point3D bezier(float t, const Point3D &p1, const Point3D &p2,
	const Point3D &p3, const Point3D &p4);
