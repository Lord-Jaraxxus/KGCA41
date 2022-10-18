#pragma once
#include "K_Texture.h"
#include "K_TextureManager.h"
#include "K_Shader.h"
#include "K_ShaderManager.h"

#include "k_Vector.h"
#include "k_Vector2D.h"
#include "K_Matrix.h"

struct SimpleVertex
{
	k_Vector	p;
	k_Vector4D	c;
	k_Vector2D	t;

	SimpleVertex() {}
	SimpleVertex(k_Vector vp, k_Vector4D vc, k_Vector2D vt)
	{
		p = vp;
		c = vc;
		t = vt;
	}
}; 

struct VS_CONSTANT_BUFFER
{
	K_Matrix  matWorld;
	K_Matrix  matView;
	K_Matrix  matProj;
	float    x;
	float    y;
	float    fTimer;
	float    d;
};



class K_BaseObject
{
public: 
	virtual bool Init();
	virtual bool Frame();
	virtual bool PreRender();
	virtual bool Render();
	virtual bool PostRender();
	virtual bool Release();

	void SetDevice(ID3D11Device* pd3dDevice, ID3D11DeviceContext* pContext); // ����̽��� ���ؽ�Ʈ�� �Ѱ��ִ� �Լ�
	virtual bool Create(ID3D11Device* pd3dDevice, ID3D11DeviceContext* pContext, const wchar_t* textureName = 0, const wchar_t* shaderName = 0);

public:
	virtual void		CreateVertexData();
	virtual void		CreateIndexData();
	virtual void		CreateConstantData();
	HRESULT				CreateVertexBuffer();
	HRESULT				CreateIndexBuffer();
	virtual HRESULT		CreateConstantBuffer();
	bool				CreateShader(std::wstring filename);
	HRESULT				CreateVertexLayout();
	virtual void		UpdateVertexBuffer();
	virtual void		UpdateConstantBuffer();
	virtual void		SetMatrix(K_Matrix* matWorld, K_Matrix* matView, K_Matrix* matProj);

	bool				LoadTexture(std::wstring filename);

public:
	ID3D11Device* m_pd3dDevice = nullptr; // ����̽� ��ü
	ID3D11DeviceContext* m_pImmediateContext = nullptr; // ���ؽ�Ʈ, ������ �� ��Ʈ���ϴ� �뵵

public:
	std::vector<SimpleVertex>	m_VertexList; 
	std::vector<SimpleVertex>	m_InitVertexList;
	std::vector<DWORD>			m_IndexList;
	ID3D11Buffer* m_pVertexBuffer;
	ID3D11Buffer* m_pIndexBuffer;
	VS_CONSTANT_BUFFER  m_cbData;
	ID3D11Buffer* m_pConstantBuffer;
	ID3D11InputLayout* m_pVertexLayout;


public:
	K_Shader*	m_pShader;
	K_Texture*	m_pTexture;

	K_Matrix	m_matWorld;
	K_Matrix	m_matView;
	K_Matrix	m_matProj;


};

