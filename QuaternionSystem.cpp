#include "StdAfx.h"
#include "QuadernionSystem.h"

QuaternionSystem::QuaternionSystem(){

}


matrixx QuaternionSystem::RotateQuat(matrixx RotateQ, Quat q){
	matrixx Rotate_Q;
	Rotate_Q.setDefault();
	float temp[4][4];
	//ROTATE_Q MATRIX
	temp[0][0] = 1 - 2 * powf(q.y, 2) - 2 * powf(q.z, 2);	temp[0][1] = 2 * (q.x*q.y - q.w*q.z);					temp[0][2] = 2 * (q.x*q.z + q.w*q.y);					temp[0][3] = 0;
	temp[1][0] = 2 * (q.x*q.y + q.w*q.z);					temp[1][1] = 1 - 2 * powf(q.x, 2) - 2 * powf(q.z, 2);	temp[1][2] = 2 * (q.y*q.z - q.w*q.x);					temp[1][3] = 0;
	temp[2][0] = 2 * (q.x*q.z - q.w*q.y);					temp[2][1] = 2 * (q.y*q.z + q.w*q.x);					temp[2][2] = 1 - 2 * powf(q.x, 2) - 2 * powf(q.y, 2);	temp[2][3] = 0;
	temp[3][0] = 0;											temp[3][1] = 0;											temp[3][2] = 0;											temp[3][3] = 1;
	RotateQ = Rotate_Q;
	return RotateQ;
}

Quat QuaternionSystem::QuatMultiple(Quat tempq, Quat& a, Quat& b){
	vec3 vec_a, vec_b, vec_temp;
	vec_a.set(a.x, a.y, a.z);
	vec_b.set(b.x, b.y, b.z);
	vec_temp = a.w*vec_b + b.w*vec_a + vec_a.cross(vec_b);
	tempq.w = a.w*b.w - vec_a.dot(vec_b);
	tempq.x = vec_temp.x; tempq.y = vec_temp.y; tempq.z = vec_temp.z;

	return tempq;
}

vec3 QuaternionSystem::QuatVecMultiple(vec3 temp, Quat& q, vec3& v){
	Quat iq;
	vec3 tpv;
	float s;

	iq.set(q.w, -q.x, -q.y, -q.z);
	tpv.set(q.x, q.y, q.z);
	s = powf(q.w, 2) + tpv.dot(tpv);
	//Calculate InvQ
	iq = iq / s;
	// create Quaternion matrix
	RotateQuat(mat_q, q);
	RotateQuat(mat_iq, iq);
	// Start multiplication
	temp = mat_iq*v;
	temp = mat_q*(temp);

	return temp;
}

QuaternionSystem::~QuaternionSystem(){

}
