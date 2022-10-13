#include "K_Matrix.h"

// ������, ������ķ� �ʱ�ȭ ����
K_Matrix::K_Matrix()
{
	Identity();
}

// �����θ� ������ķ� �ٲٴ� �Լ�
void K_Matrix::Identity()
{
	_12 = _13 = _14 = 0.0f;
	_21 = _23 = _24 = 0.0f;
	_31 = _32 = _34 = 0.0f;
	_41 = _42 = _43 = 0.0f;
	_11 = _22 = _33 = _44 = 1.0f;
}

// �������� ��ġ����� ��ȯ�ϴ� �Լ�
K_Matrix K_Matrix::Transpose()
{
	K_Matrix transposed;

	transposed._11 = _11; transposed._12 = _21; transposed._13 = _31; transposed._14 = _41;
	transposed._21 = _12; transposed._22 = _22; transposed._23 = _32; transposed._24 = _42;
	transposed._31 = _13; transposed._32 = _23; transposed._33 = _33; transposed._34 = _43;
	transposed._41 = _14; transposed._42 = _24; transposed._43 = _34; transposed._44 = _44;

	return transposed;
}

// ��������� X�࿡ ���� fRadian��ŭ ȸ����Ų ����� ��ȯ�ϴ� �Լ�
K_Matrix K_Matrix::RotationX(float fRadian)
{
	float fCosTheta = cos(fRadian);
	float fSinTheta = sin(fRadian);

	K_Matrix result;
	result._22 = fCosTheta;		result._23 = fSinTheta;
	result._32 = -fSinTheta;	result._33 = fCosTheta;

	return result;
}

// ��������� Y�࿡ ���� fRadian��ŭ ȸ����Ų ����� ��ȯ�ϴ� �Լ�
K_Matrix K_Matrix::RotationY(float fRadian)
{
	float fCosTheta = cos(fRadian);
	float fSinTheta = sin(fRadian);

	K_Matrix result;
	result._11 = fCosTheta;		result._13 = -fSinTheta;
	result._31 = fSinTheta;		result._33 = fCosTheta;

	return result;
}

// ��������� Z�࿡ ���� fRadian��ŭ ȸ����Ų ����� ��ȯ�ϴ� �Լ�
K_Matrix K_Matrix::RotationZ(float fRadian)
{
	float fCosTheta = cos(fRadian);
	float fSinTheta = sin(fRadian);

	K_Matrix result;
	result._11 = fCosTheta;		result._12 = fSinTheta;
	result._21 = -fSinTheta;	result._22 = fCosTheta;

	return result;
}

// ��������� �Ű�������ŭ Ȯ��/����� ����� ��ȯ�ϴ� �Լ�. xyz ���� ���� ���� ��������
K_Matrix K_Matrix::Scale(float x, float y, float z)
{
	K_Matrix result;

	result._11 = x;
	result._22 = y;
	result._33 = z;

	return result;
}

// ��������� �Ű�������ŭ �̵��� ����� ��ȯ�ϴ� �Լ�
K_Matrix K_Matrix::Translation(float x, float y, float z)
{
	K_Matrix result;

	result._41 = x;
	result._42 = y;
	result._43 = z;

	return result;
}

// ���� ������ ������, �ڿ� ���� ��İ� �������� �������� ��ȯ
K_Matrix K_Matrix::operator*(K_Matrix& back_matrix)
{
	K_Matrix result;

	for (int iColumn = 0; iColumn < 4; iColumn++)
	{
		for (int iRow = 0; iRow < 4; iRow++)
		{
			result.matrix[iRow][iColumn] =
				matrix[iRow][0] * back_matrix.matrix[0][iColumn] +
				matrix[iRow][1] * back_matrix.matrix[1][iColumn] +
				matrix[iRow][2] * back_matrix.matrix[2][iColumn] +
				matrix[iRow][3] * back_matrix.matrix[3][iColumn];
		}
	}
	return result;
}
