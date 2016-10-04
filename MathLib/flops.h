#pragma once

/////////////
// 0.00000001
bool fequals(float lhs, float rhs);

//Basic Curving Functions
float deg2rad(float deg);
float rad2deg(float rad);
float linearHalf(float x);
float quad(float x);
float sqroot(float x);
float rAbsolute(float x);
float bounce(float x);
float rBounce(float x);
float rQuad(float x);

// Curving Functions
float lerp(float start, float end, float alpha);
float quadBezier(float start, float mid, float end, float alpha);
float cubicBezier(float start, float mid1, float mid2, float end, float alpha);
float HermiteSpline(float start, float s_tan, float end, float e_tan, float alpha);
float cardinalSpline(float start, float mid, float end, float tightness, float alpha);
float catRomSpline(float start, float mid, float end, float alpha);