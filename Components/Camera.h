#pragma once
#include "Transform.h"

class Camera
{
public:
	mat3 camera(Transform playerTrans);
};
