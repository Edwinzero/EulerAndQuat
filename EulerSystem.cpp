#include "StdAfx.h"
#include "EulerSystem.h"

EulerSystem::EulerSystem(){

}

matrixx EulerSystem::EuRotateX(Euler m_e){
	euler_cx = cosf(m_e.ro_x);
	euler_sx = sinf(m_e.ro_x);

	Rotate_X.setValue(0, 0, 1);		Rotate_X.setValue(0, 1, 0);			Rotate_X.setValue(0, 2, 0);			Rotate_X.setValue(0, 3, 0);
	Rotate_X.setValue(1, 0, 0);			Rotate_X.setValue(1, 1, euler_cx);	Rotate_X.setValue(1, 2, -euler_sx);	Rotate_X.setValue(1, 3, 0);
	Rotate_X.setValue(2, 0, 0);			Rotate_X.setValue(2, 1, euler_sx);	Rotate_X.setValue(2, 2, euler_cx);	Rotate_X.setValue(2, 3, 0);
	Rotate_X.setValue(3, 0, 0);			Rotate_X.setValue(3, 1, 0);			Rotate_X.setValue(3, 2, 0);			Rotate_X.setValue(3, 3, 1);

	return Rotate_X;
}

matrixx EulerSystem::EuRotateY(Euler m_e){
	euler_cy = cosf(m_e.ro_y);
	euler_sy = sinf(m_e.ro_y);

	Rotate_Y.setValue(0, 0, euler_cy);	Rotate_Y.setValue(0, 1, 0);			Rotate_Y.setValue(0, 2, euler_sy);	Rotate_Y.setValue(0, 3, 0);
	Rotate_Y.setValue(1, 0, 0);			Rotate_Y.setValue(1, 1, 1);			Rotate_Y.setValue(1, 2, 0);			Rotate_Y.setValue(1, 3, 0);
	Rotate_Y.setValue(2, 0, -euler_sy);	Rotate_Y.setValue(2, 1, 0);			Rotate_Y.setValue(2, 2, euler_cy);	Rotate_Y.setValue(2, 3, 0);
	Rotate_Y.setValue(3, 0, 0);			Rotate_Y.setValue(3, 1, 0);			Rotate_Y.setValue(3, 2, 0);			Rotate_Y.setValue(3, 3, 1);

	return Rotate_Y;
}

matrixx EulerSystem::EuRotateZ(Euler m_e){
	euler_cz = cosf(m_e.ro_z);
	euler_sz = sinf(m_e.ro_z);

	Rotate_Z.setValue(0, 0, euler_cz);	Rotate_Z.setValue(0, 1, -euler_sz);	Rotate_Z.setValue(0, 2, 0);			Rotate_Z.setValue(0, 3, 0);
	Rotate_Z.setValue(1, 0, euler_sz);	Rotate_Z.setValue(1, 1, euler_cz);	Rotate_Z.setValue(1, 2, 0);			Rotate_Z.setValue(1, 3, 0);
	Rotate_Z.setValue(2, 0, 0);			Rotate_Z.setValue(2, 1, 0);			Rotate_Z.setValue(2, 2, 1);			Rotate_Z.setValue(2, 3, 0);
	Rotate_Z.setValue(3, 0, 0);			Rotate_Z.setValue(3, 1, 0);			Rotate_Z.setValue(3, 2, 0);			Rotate_Z.setValue(3, 3, 1);

	return Rotate_Z;
}
//THIS MAY NEED TO MOVE TO MAIN.CPP
float EulerSystem::E_OneOrient(float* result, matrixx& m_rox, matrixx& m_roy, matrixx& m_roz){
	matrixx temp1, temp2;
	//float result[16];
	temp1.setDefault();
	temp2.setDefault();
	temp1 = m_rox*m_roy;
	temp2 = temp1*m_roz;
		
	result[0] = temp2.getValue(0, 0); result[1] = temp2.getValue(0, 1); result[2] = temp2.getValue(0, 2); result[3] = temp2.getValue(0, 3);
	result[4] = temp2.getValue(1, 0); result[5] = temp2.getValue(1, 1); result[6] = temp2.getValue(1, 2); result[7] = temp2.getValue(1, 3);
	result[8] = temp2.getValue(2, 0); result[9] = temp2.getValue(2, 1); result[10] = temp2.getValue(0, 2); result[11] = temp2.getValue(2, 3);
	result[12] = temp2.getValue(3, 0); result[13] = temp2.getValue(3, 1); result[14] = temp2.getValue(0, 2); result[15] = temp2.getValue(3, 3);
	
	return result[16];
}

EulerSystem::~EulerSystem(){

}
