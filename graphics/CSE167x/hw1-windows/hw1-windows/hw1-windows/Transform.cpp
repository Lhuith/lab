// Transform.cpp: implementation of the Transform class.

#include "Transform.h"

//Please implement the following functions:

/*
	centre = 0,0,0

*/
#include <iostream>

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis) {
  // YOUR CODE FOR HW1 HERE
	// axis / a 
	//float radians = rad degrees * pi / 180;
	float radians = glm::radians(degrees);

	mat3 i;

	i[0][0] = 1;
	i[1][0] = 0;
	i[2][0] = 0;

	i[0][1] = 0;
	i[1][1] = 1;
	i[2][1] = 0;

	i[0][2] = 0;
	i[1][2] = 0;
	i[2][2] = 1;

	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	mat3 a_at;
	a_at[0][0] = x * x;
	a_at[1][0] = y * x;
	a_at[2][0] = z * x;

	a_at[0][1] = x * y;
	a_at[1][1] = y * y;
	a_at[2][1] = z * y;

	a_at[0][2] = x * z;
	a_at[1][2] = y * z;
	a_at[2][2] = z * z;


	// [c][r]
	mat3 perp;
	perp[0][0] = 0;
	perp[1][0] = -z;
	perp[2][0] = y;
		
	perp[0][1] = z;
	perp[1][1] = 0;
	perp[2][1] = -x;

	perp[0][2] = -y;
	perp[1][2] = x;
	perp[2][2] = 0;

  // You will change this return call
  return cos(radians) * i + (1 - cos(radians)) * a_at + sin(radians) * perp;
}

// Transforms the camera left around the "crystal ball" interface
// right = -left
void Transform::left(float degrees, vec3& eye, vec3& up) {
	eye = rotate(degrees, up) * eye;
}

// Transforms the camera up around the "crystal ball" interface
// down = -up
void Transform::up(float degrees, vec3& eye, vec3& up) {
	vec3 axis = normalize(cross(eye, up));
	eye = rotate(degrees, axis) * eye;
	up = rotate(degrees, axis) * up;
}
// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {	
	vec3 c = vec3(0.0, 0.0, 0.0);
	vec3 b = up;
	
	vec3 w = glm::normalize(eye);
	vec3 u = normalize(cross(b, w));
	vec3 v = cross(w, u);
	
  // You will change this return call
	

	mat4 rot;
	
	// [c][r]
	// first row
	rot[0][0] = u.x;
	rot[1][0] = u.y;
	rot[2][0] = u.z;
	rot[3][0] = -dot(u, eye);

	// second row
	rot[0][1] = v.x;
	rot[1][1] = v.y;
	rot[2][1] = v.z;
	rot[3][1] = -dot(v, eye);


	// third row
	rot[0][2] = w.x;
	rot[1][2] = w.y;
	rot[2][2] = w.z;
	rot[3][2] = -dot(w, eye);

	// fourth row, for sanity sake
	rot[0][3] = 0;
	rot[1][3] = 0;
	rot[2][3] = 0;
	rot[3][3] = 1;

	return rot;
}

Transform::Transform()
{

}

Transform::~Transform()
{

}