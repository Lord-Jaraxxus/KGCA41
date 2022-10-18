#include "K_Shape.h"

void K_ShapeBox::CreateVertexData()
{
	// »ó´Ü
  // 5    6
  // 1    2
  // ÇÏ´Ü
  // 4    7
  // 0    3  
  // ¾Õ¸é
	m_VertexList.resize(24);
	m_VertexList[0] = SimpleVertex(k_Vector(-1.0f, 1.0f, -1.0f), k_Vector4D(1.0f, 0.0f, 0.0f, 1.0f), k_Vector2D(0.0f, 0.0f));
	m_VertexList[1] = SimpleVertex(k_Vector(1.0f, 1.0f, -1.0f), k_Vector4D(1.0f, 0.0f, 0.0f, 1.0f), k_Vector2D(1.0f, 0.0f));
	m_VertexList[2] = SimpleVertex(k_Vector(1.0f, -1.0f, -1.0f), k_Vector4D(1.0f, 0.0f, 0.0f, 1.0f), k_Vector2D(1.0f, 1.0f));
	m_VertexList[3] = SimpleVertex(k_Vector(-1.0f, -1.0f, -1.0f), k_Vector4D(1.0f, 0.0f, 0.0f, 1.0f), k_Vector2D(0.0f, 1.0f));
	// µÞ¸é
	m_VertexList[4] = SimpleVertex(k_Vector(1.0f, 1.0f, 1.0f), k_Vector4D(0.0f, 0.0f, 0.0f, 1.0f), k_Vector2D(0.0f, 0.0f));
	m_VertexList[5] = SimpleVertex(k_Vector(-1.0f, 1.0f, 1.0f), k_Vector4D(0.0f, 1.0f, 0.0f, 1.0f), k_Vector2D(1.0f, 0.0f));
	m_VertexList[6] = SimpleVertex(k_Vector(-1.0f, -1.0f, 1.0f), k_Vector4D(0.0f, 1.0f, 0.0f, 1.0f), k_Vector2D(1.0f, 1.0f));
	m_VertexList[7] = SimpleVertex(k_Vector(1.0f, -1.0f, 1.0f), k_Vector4D(0.0f, 1.0f, 0.0f, 1.0f), k_Vector2D(0.0f, 1.0f));

	// ¿À¸¥ÂÊ
	m_VertexList[8] = SimpleVertex(k_Vector(1.0f, 1.0f, -1.0f), k_Vector4D(0.0f, 0.0f, 1.0f, 1.0f), k_Vector2D(0.0f, 0.0f));
	m_VertexList[9] = SimpleVertex(k_Vector(1.0f, 1.0f, 1.0f), k_Vector4D(0.0f, 0.0f, 1.0f, 1.0f), k_Vector2D(1.0f, 0.0f));
	m_VertexList[10] = SimpleVertex(k_Vector(1.0f, -1.0f, 1.0f), k_Vector4D(0.0f, 0.0f, 1.0f, 1.0f), k_Vector2D(1.0f, 1.0f));
	m_VertexList[11] = SimpleVertex(k_Vector(1.0f, -1.0f, -1.0f), k_Vector4D(0.0f, 0.0f, 1.0f, 1.0f), k_Vector2D(0.0f, 1.0f));

	// ¿ÞÂÊ
	m_VertexList[12] = SimpleVertex(k_Vector(-1.0f, 1.0f, 1.0f), k_Vector4D(1.0f, 1.0f, 0.0f, 1.0f), k_Vector2D(0.0f, 0.0f));
	m_VertexList[13] = SimpleVertex(k_Vector(-1.0f, 1.0f, -1.0f), k_Vector4D(1.0f, 1.0f, 0.0f, 1.0f), k_Vector2D(1.0f, 0.0f));
	m_VertexList[14] = SimpleVertex(k_Vector(-1.0f, -1.0f, -1.0f), k_Vector4D(1.0f, 1.0f, 0.0f, 1.0f), k_Vector2D(1.0f, 1.0f));
	m_VertexList[15] = SimpleVertex(k_Vector(-1.0f, -1.0f, 1.0f), k_Vector4D(1.0f, 1.0f, 0.0f, 1.0f), k_Vector2D(0.0f, 1.0f));

	// À­¸é
	m_VertexList[16] = SimpleVertex(k_Vector(-1.0f, 1.0f, 1.0f), k_Vector4D(1.0f, 0.5f, 1.0f, 1.0f), k_Vector2D(0.0f, 0.0f));
	m_VertexList[17] = SimpleVertex(k_Vector(1.0f, 1.0f, 1.0f), k_Vector4D(1.0f, 0.5f, 1.0f, 1.0f), k_Vector2D(1.0f, 0.0f));
	m_VertexList[18] = SimpleVertex(k_Vector(1.0f, 1.0f, -1.0f), k_Vector4D(1.0f, 0.5f, 1.0f, 1.0f), k_Vector2D(1.0f, 1.0f));
	m_VertexList[19] = SimpleVertex(k_Vector(-1.0f, 1.0f, -1.0f), k_Vector4D(1.0f, 0.5f, 1.0f, 1.0f), k_Vector2D(0.0f, 1.0f));

	// ¾Æ·§¸é
	m_VertexList[20] = SimpleVertex(k_Vector(-1.0f, -1.0f, -1.0f), k_Vector4D(0.0f, 1.0f, 1.0f, 1.0f), k_Vector2D(0.0f, 0.0f));
	m_VertexList[21] = SimpleVertex(k_Vector(1.0f, -1.0f, -1.0f), k_Vector4D(0.0f, 1.0f, 1.0f, 1.0f), k_Vector2D(1.0f, 0.0f));
	m_VertexList[22] = SimpleVertex(k_Vector(1.0f, -1.0f, 1.0f), k_Vector4D(0.0f, 1.0f, 1.0f, 1.0f), k_Vector2D(1.0f, 1.0f));
	m_VertexList[23] = SimpleVertex(k_Vector(-1.0f, -1.0f, 1.0f), k_Vector4D(0.0f, 1.0f, 1.0f, 1.0f), k_Vector2D(0.0f, 1.0f));


	m_InitVertexList = m_VertexList;
}

void K_ShapeBox::CreateIndexData()
{
	m_IndexList.resize(36);
	int iIndex = 0;
	m_IndexList[iIndex++] = 0; 	m_IndexList[iIndex++] = 1; 	m_IndexList[iIndex++] = 2; 	m_IndexList[iIndex++] = 0;	m_IndexList[iIndex++] = 2; 	m_IndexList[iIndex++] = 3;
	m_IndexList[iIndex++] = 4; 	m_IndexList[iIndex++] = 5; 	m_IndexList[iIndex++] = 6; 	m_IndexList[iIndex++] = 4;	m_IndexList[iIndex++] = 6; 	m_IndexList[iIndex++] = 7;
	m_IndexList[iIndex++] = 8; 	m_IndexList[iIndex++] = 9; 	m_IndexList[iIndex++] = 10; m_IndexList[iIndex++] = 8;	m_IndexList[iIndex++] = 10; m_IndexList[iIndex++] = 11;
	m_IndexList[iIndex++] = 12; m_IndexList[iIndex++] = 13; m_IndexList[iIndex++] = 14; m_IndexList[iIndex++] = 12;	m_IndexList[iIndex++] = 14; m_IndexList[iIndex++] = 15;
	m_IndexList[iIndex++] = 16; m_IndexList[iIndex++] = 17; m_IndexList[iIndex++] = 18; m_IndexList[iIndex++] = 16;	m_IndexList[iIndex++] = 18; m_IndexList[iIndex++] = 19;
	m_IndexList[iIndex++] = 20; m_IndexList[iIndex++] = 21; m_IndexList[iIndex++] = 22; m_IndexList[iIndex++] = 20;	m_IndexList[iIndex++] = 22; m_IndexList[iIndex++] = 23;
}

bool K_ShapeBox::Frame()
{
	return true;
}

bool K_ShapeBox::Render()
{
	PreRender();
	PostRender();
	return true;
}
