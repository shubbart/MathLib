#include "PlanetaryMotor.h"

void PlanetaryMotor::update(Rigidbody & planetaryRbody)
{
	planetaryRbody.addTorque(m_rotationSpeed);
}
