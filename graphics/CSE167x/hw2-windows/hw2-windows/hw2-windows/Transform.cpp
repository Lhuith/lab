// Transform.cpp: implementation of the Transform class.

// Note: when you construct a matrix using mat4() or mat3(), it will be COLUMN-MAJOR
// Keep this in mind in readfile.cpp and display.cpp
// See FAQ for more details or if you're having problems.

#include "Transform.h"

// Helper rotation function.  Please implement this.  
mat3 Transform::rotate(const float degrees, const vec3& axis) 
{
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

	mat3 rot = cos(radians) * i + (1 - cos(radians)) * a_at + sin(radians) * perp;
    return rot;
}

void Transform::left(float degrees, vec3& eye, vec3& up) 
{
    // YOUR CODE FOR HW2 HERE
	eye = rotate(degrees, up) * eye;
}

void Transform::up(float degrees, vec3& eye, vec3& up) 
{
	vec3 axis = normalize(cross(eye, up));
	eye = rotate(degrees, axis) * eye;
	up = rotate(degrees, axis) * up;
}

mat4 Transform::lookAt(const vec3 &eye, const vec3 &center, const vec3 &up) 
{
    mat4 rot;
    
	vec3 c = vec3(0.0, 0.0, 0.0);
	vec3 b = up;

	vec3 w = glm::normalize(eye);
	vec3 u = normalize(cross(b, w));
	vec3 v = cross(w, u);

	// [c][r]
	rot[0][0] = u.x;	rot[1][0] = u.y;	rot[2][0] = u.z;	rot[3][0] = -dot(u, eye);
	rot[0][1] = v.x;	rot[1][1] = v.y;	rot[2][1] = v.z;	rot[3][1] = -dot(v, eye);
	rot[0][2] = w.x;	rot[1][2] = w.y;	rot[2][2] = w.z;	rot[3][2] = -dot(w, eye);
	rot[0][3] = 0;		rot[1][3] = 0;		rot[2][3] = 0;		rot[3][3] = 1;

	return rot;
}

mat4 Transform::perspective(float fovy, float aspect, float zNear, float zFar)
{
    mat4 rot;
	
	float angle = (fovy / 2);
	// cot(x) = cos(x)/sin(x)
	float d = cos(angle)/sin(angle);
	float A = (zFar + zNear) / (zFar - zNear);
	float B = (2 * (zFar * zNear)) / (zFar - zNear);
	rot[0][0] = d / aspect;	rot[1][0] = 0;	rot[2][0] = 0;	rot[3][0] = 0;
	rot[0][1] = 0;			rot[1][1] = d;	rot[2][1] = 0;	rot[3][1] = 0;
	rot[0][2] = 0;			rot[1][2] = 0;	rot[2][2] = -A;	rot[3][2] = -B;
	rot[0][3] = 0;			rot[1][3] = 0;	rot[2][3] = -1;	rot[3][3] = 0;
    return rot;
}

mat4 Transform::scale(const float &sx, const float &sy, const float &sz) 
{
    mat4 rot;
	rot[0][0] = sx;	rot[1][0] = 0;	rot[2][0] = 0;	rot[3][0] = 0;
	rot[0][1] = 0;	rot[1][1] = sy;	rot[2][1] = 0;	rot[3][1] = 0;
	rot[0][2] = 0;	rot[1][2] = 0;	rot[2][2] = sz;	rot[3][2] = 0;
	rot[0][3] = 0;	rot[1][3] = 0;	rot[2][3] = 0;	rot[3][3] = 1;
    return rot;
}

mat4 Transform::translate(const float &tx, const float &ty, const float &tz) 
{
    mat4 rot;
	rot[0][0] = 1;	rot[1][0] = 0;	rot[2][0] = 0;	rot[3][0] = tx;
	rot[0][1] = 0;	rot[1][1] = 1;	rot[2][1] = 0;	rot[3][1] = ty;
	rot[0][2] = 0;	rot[1][2] = 0;	rot[2][2] = 1;	rot[3][2] = tz;
	rot[0][3] = 0;	rot[1][3] = 0;	rot[2][3] = 0;	rot[3][3] = 1;
    return rot;
}

// To normalize the up direction and construct a coordinate frame.  
// As discussed in the lecture.  May be relevant to create a properly 
// orthogonal and normalized up. 
// This function is provided as a helper, in case you want to use it. 
// Using this function (in readfile.cpp or display.cpp) is optional.  

vec3 Transform::upvector(const vec3 &up, const vec3 & zvec) 
{
    vec3 x = glm::cross(up,zvec); 
    vec3 y = glm::cross(zvec,x); 
    vec3 ret = glm::normalize(y); 
    return ret; 
}


Transform::Transform()
{

}

Transform::~Transform()
{

}
