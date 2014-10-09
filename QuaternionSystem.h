#pragma once
#ifndef QUATERNION_SZ_H
#define QUATERNION_SZ_H

#include <iostream>
#include <math.h>
#include "vec3.h"
#include "matrixx.h"

using namespace std;

//================================
// Quaternion_sz
//================================
class Quat{
public:
	float w, x, y, z;

public:
	Quat(){};
	Quat(float w, float x, float y, float z){
		this->w = w; this->x = x; this->y = y; this->z = z;
	};

	Quat &set(float w, float x, float y, float z){
		this->x = x;	this->y = y;	this->z = z;
		return *this;
	};

	float magnitude(void) const{
		return sqrtf(w*w + x * x + y * y + z * z);
	};

	Quat operator/(float scalar) const{
		float inv = 1.0f / scalar;
		return Quat(w*inv, x * inv, y * inv, z * inv);
	};

	// From q to calculate -q
	Quat NegativeQuat(Quat Ngat_q, Quat q){
		Ngat_q.set(-q.w, -q.x, -q.y, -q.z);
		return Ngat_q;
	};
};


//================================
// QuaternionSystem_sz
//================================
//class Quat;

class QuaternionSystem
{
public:
	QuaternionSystem();
	
	//float RotateQuat(float* RotateQ, Quat q);
	matrixx RotateQuat(matrixx RotateQ, Quat q);
	Quat QuatMultiple(Quat tempq, Quat& a, Quat& b);
	vec3 QuatVecMultiple(vec3 temp, Quat& q, vec3& v);

	~QuaternionSystem();

public:

private:
	float w, x, y, z;
	vec3 vec;
	Quat quaternion;
	// For A' = -q*A*q
	matrixx mat_q;
	matrixx mat_iq;
	
};

#endif QUATERNION_SZ_H

