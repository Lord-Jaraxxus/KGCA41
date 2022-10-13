#pragma once
#include "k_Vector.h"

struct float4 
{
	union 
	{
		struct
		{
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float matrix[4][4];
	};
};

class K_Matrix : public float4
{
public:
	K_Matrix(); // 뭐 생성자
	void Identity(); // 스스로를 단위행렬로 바꾸는 함수
	K_Matrix Transpose() ; // 스스로의 전치행렬을 반환하는 함수
	K_Matrix RotationX(float fRadian) ;
	K_Matrix RotationY(float fRadian) ;
	K_Matrix RotationZ(float fRadian) ; // 단위행렬을 각각 X, Y, Z축에 대해 fRadian만큼 회전시킨 행렬을 반환하는 함수
	K_Matrix Scale(float x, float y, float z); // 단위행렬을 확대/축소한 행렬을 반환하는 함수. xyz 각각 따로 배율 지정가능 
	K_Matrix Translation(float x, float y, float z); // 이동. 얘도 xyz 각각 따로 얼만큼 움직일지 세팅가능

public:
	K_Matrix operator * (K_Matrix &back_matrix); // 곱셈 연산자 재정의
};

