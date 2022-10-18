#pragma once
#include "K_BaseObject.h"
class K_Object3D : public K_BaseObject
{
public:
	K_Object3D() {};
	virtual ~K_Object3D() {};
};
class K_Shape : public K_Object3D
{
public:
	K_Shape() {};
	virtual ~K_Shape() {};
};
class K_ShapeBox : public K_Object3D
{
public:
	virtual void		CreateVertexData() override;
	virtual void		CreateIndexData() override;
	virtual bool		Frame() override;
	virtual bool		Render() override;
public:
	K_ShapeBox() {};
	virtual ~K_ShapeBox() {};
};