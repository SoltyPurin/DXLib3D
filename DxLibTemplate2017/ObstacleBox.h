#pragma once
#include <DxLib.h>
#include "CollisionCalc.h"
class ObstacleBox
{
public:
	ObstacleBox(VECTOR pos,int size);
	~ObstacleBox();
	void Update();
	virtual void Draw();
	AABB ReturnAABB() { return _boxAABB; }
protected:
	int _boxSize;
	AABB _boxAABB;
};

