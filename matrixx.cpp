#include "StdAfx.h"
#include "matrixx.h"
#include <cmath>
#include <assert.h>

float matrixx::getValue(int indexRow, int indexCol)
{
	//check the input's value
	assert(indexRow >= 0 && indexCol >= 0);
	assert(indexRow <= 4 && indexCol <= 4);
	return matrix4x4[indexRow][indexCol];
}

void matrixx::setValue(int indexRow, int indexCol, float value)
{
	//set the input's value
	assert(indexRow >= 0 && indexCol >= 0);
	assert(indexRow <= 4 && indexCol <= 4);
	matrix4x4[indexRow][indexCol] = value;
}

void matrixx::setMatrix(void *)
{

}

float* matrixx::getMatrx()
{
	return NULL;
}

void matrixx::setDefault()
{
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matrix4x4[row][col] = (col == row);
		}
	}
}

//operations
matrixx  matrixx::operator- (void) const
{
	matrixx *newMatrix = new matrixx();

	for (int row = 0; row< 4; row++) {
		for (int col = 0; col < 4; col++) {
			newMatrix->matrix4x4[row][col] = -matrix4x4[row][col];
		}
	}

	return *newMatrix;
}

matrixx	matrixx::operator+ (void) const
{
	matrixx *newMatrx = new matrixx();

	for (int row = 0; row< 4; row++) {
		for (int col = 0; col < 4; col++) {
			newMatrx->matrix4x4[row][col] = matrix4x4[row][col];
		}
	}

	return *newMatrx;
}

matrixx	matrixx::operator+ (const matrixx &m) const
{
	matrixx *newMatrx = new matrixx();

	for (int row = 0; row< 4; row++) {
		for (int col = 0; col < 4; col++) {
			newMatrx->matrix4x4[row][col] = matrix4x4[row][col] + m.matrix4x4[row][col];
		}
	}

	return *newMatrx;
}

matrixx	matrixx::operator- (const matrixx &m) const
{
	matrixx *newMatrx = new matrixx();

	for (int row = 0; row< 4; row++) {
		for (int col = 0; col < 4; col++) {
			newMatrx->matrix4x4[row][col] = matrix4x4[row][col] - m.matrix4x4[row][col];
		}
	}

	return *newMatrx;
}


matrixx	matrixx::operator* (const matrixx &m) const
{
	matrixx tmpMatrix;

	for (int row = 0; row< 4; row++) {
		for (int col = 0; col < 4; col++) {
			tmpMatrix.matrix4x4[row][col] = matrix4x4[row][0] * m.matrix4x4[0][col] + matrix4x4[row][1] * m.matrix4x4[1][col] + matrix4x4[row][2] * m.matrix4x4[2][col] + matrix4x4[row][3] * m.matrix4x4[3][col];
		}
	}

	return tmpMatrix;
}

vec3 matrixx::operator* (const vec3 &m) const{
	float tmp[4] = { m.x, m.y, m.z, 1 };
	float result[4];
	vec3 resultv;
	for (int row = 0; row < 4; row++){
		result[row] = matrix4x4[row][0] * tmp[row] + matrix4x4[row][1] * tmp[row] + matrix4x4[row][0] * tmp[row] + matrix4x4[row][0] * tmp[row];
	}
	resultv.x = result[0];
	resultv.y = result[1];
	resultv.z = result[2];
	
	return resultv;
}

matrixx	matrixx::operator/ (float scalar) const
{
	matrixx *newMatrx = new matrixx();

	for (int row = 0; row< 4; row++) {
		for (int col = 0; col < 4; col++) {
			newMatrx->matrix4x4[row][col] = matrix4x4[row][col] / scalar;
		}
	}

	return *newMatrx;
}

matrixx& matrixx::operator= (const matrixx &m)
{
	for (int row = 0; row< 4; row++) {
		for (int col = 0; col < 4; col++) {
			this->matrix4x4[row][col] = m.matrix4x4[row][col];
		}
	}

	return *this;
}

matrixx& matrixx::operator+=(const matrixx &m)
{
	for (int row = 0; row< 4; row++) {
		for (int col = 0; col < 4; col++) {
			this->matrix4x4[row][col] = matrix4x4[row][col] + m.matrix4x4[row][col];
		}
	}

	return *this;
}

matrixx& matrixx::operator-=(const matrixx &m)
{
	for (int row = 0; row< 4; row++) {
		for (int col = 0; col < 4; col++) {
			this->matrix4x4[row][col] = matrix4x4[row][col] - m.matrix4x4[row][col];
		}
	}

	return *this;
}

matrixx& matrixx::operator *= (const matrixx &m)
{
	matrixx *tmpMatrix = new matrixx();

	for (int row = 0; row< 4; row++) {
		for (int col = 0; col < 4; col++) {
			tmpMatrix->matrix4x4[row][col] = matrix4x4[row][0] * m.matrix4x4[0][col] + matrix4x4[row][1] * m.matrix4x4[1][col] + matrix4x4[row][2] * m.matrix4x4[2][col] + matrix4x4[row][3] * m.matrix4x4[3][col];
		}
	}

	*this = *tmpMatrix;

	return *this;
}
