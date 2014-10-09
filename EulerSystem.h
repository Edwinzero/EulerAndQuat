#pragma once
#ifndef EULER_SZ_H
#define EULER_SZ_H
#include <math.h>
#include "matrixx.h"
#include "vec3.h"

using namespace std;

//================================
// Euler_sz
//================================
class Euler{
public:
	float ro_x, ro_y, ro_z;

public:
	Euler(){};
	Euler(float x, float y, float z){
		this->ro_x = x; this->ro_y = y; this->ro_z = z;
	};
	Euler &set(float x, float y, float z){
		this->ro_x = x; this->ro_y = y; this->ro_z = z;	return *this;
	};
	~Euler(){};
};



//================================
// EulerSystem_sz
//================================
class vec3;

class EulerSystem
{
public:
	EulerSystem();
	
	matrixx EuRotateX(Euler m_e);
	matrixx EuRotateY(Euler m_e);
	matrixx EuRotateZ(Euler m_e);
	//THIS MAY NEED TO MOVE TO MAIN.CPP
	float E_OneOrient(float* , matrixx& m_rox, matrixx& m_roy, matrixx& m_roz);

	~EulerSystem();

public:
	//Rotation matrix
	matrixx Rotate_X;
	matrixx Rotate_Y;
	matrixx Rotate_Z;

private:
	float euler_cx, euler_cy, euler_cz;
	float euler_sx, euler_sy, euler_sz;
	

};

#endif EULER_SZ_H
