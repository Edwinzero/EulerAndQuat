#ifndef __SZ__Matrix__
#define __SZ__Matrix__

//================================
// matrixx
//================================

#include <iostream>
#include "vec3.h"


class matrixx {

public:
	float matrix4x4[4][4];

	matrixx(){
		this->setDefault();
	}


	matrixx(matrixx &matrix){
		for (int row = 0; row<4; row++) {
			for (int col = 0; col < 4; col++) {
				matrix4x4[row][col] = matrix.matrix4x4[row][col];
			}
		}
	}

	matrixx(matrixx *matrix){
		for (int row = 0; row<4; row++) {
			for (int col = 0; col < 4; col++) {
				matrix4x4[row][col] = matrix->matrix4x4[row][col];
			}
		}
	}

	virtual ~matrixx(){};

	//getter and setter
	float getValue(int indexRow, int indexCol);
	void setValue(int indexRow, int indexCol, float value);
	void setMatrix(void *);
	float *getMatrx();

	//zero operation
	void setDefault();

	//operations
	matrixx		operator- (void) const;
	matrixx		operator+ (void) const;

	matrixx		operator+ (const matrixx &m) const;
	matrixx		operator- (const matrixx &m) const;
	matrixx		operator* (const matrixx &m) const;
	vec3		operator* (const vec3 &m) const;
	matrixx		operator/ (float scalar) const;
	//Matrix	operator* ( float factor ) const;

	matrixx &	operator= (const matrixx &m);
	matrixx &	operator+=(const matrixx &m);
	matrixx &	operator-=(const matrixx &m);
	matrixx &	operator*=(const matrixx &m);
	//Matrix &	operator/=( const Matrix &m );    

};



#endif __SZ__Matrix__
