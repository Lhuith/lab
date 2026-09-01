#include "quaternion.h"

#include <cmath>

//Building a quaternion from axis-angle rotation

Quaternion::Quaternion(const Vector& n, float a)
{
	//a will be theta
	//We must convert dagrees to radians.
	//360 dagrees == 2pi radians
	a = a / 360 * (float)M_PI * 2;

	w = cos(a / 2);

	x = n.x*sin(a / 2);
	y = n.y*sin(a / 2);
	z = n.z*sin(a / 2);

}