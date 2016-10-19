#include "Camera.h"
#include "sfwdraw.h"

mat3 Camera::camera(Transform playerTrans)
{

	Transform cameraTransform;

	cameraTransform.m_position
		= lerp(cameraTransform.m_position,
			playerTrans.getGlobalPosition(),
			sfw::getDeltaTime() * 10);

	// translation is the position of the camera ON THE SCREEN
	// the scale describes the zoom
	mat3 proj = translate(1920 / 2, 1080 / 2) * scale(2, 2);
	mat3 view = inverse(cameraTransform.getGlobalTransform());

	return proj * view;
}
