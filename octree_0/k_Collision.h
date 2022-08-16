#include "k_QuadTree.h"
#include "k_Octree.h"
#include <queue>

enum k_CollisionType
{
	RECT_OUT = 0,
	RECT_IN,
	RECT_OVERLAP,
};

class k_Collision
{
public:
	k_QuadTree QT;


public:
	static bool	RectToInRect(k_Rect& a, k_Rect& b); // a가 b를 완전히 포함하는지
	static k_CollisionType RectToRect(k_Rect& a, k_Rect& b); // 한 사각형이 다른 사각형과 겹치는지
	static bool CircleToCircle(k_Circle &a, k_Circle &b);

	k_Node2D* FindNodeToGo(k_Node2D* pNode, k_Object2D* pObj);
	void AddStaticObject(k_Object2D* pObj);
	void AddDynamicObject(k_Object2D* pObj);
	void DynamicObjectReset(k_Node2D* pNode);

	std::vector<k_Object2D*> COL(k_Object2D* pObj); // Collided Object List
	void GCO(k_Node2D* pNode, k_Object2D* pObj, std::vector<k_Object2D*> &list); //Get Collided Object
};


