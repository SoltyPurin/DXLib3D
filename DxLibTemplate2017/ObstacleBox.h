#pragma once
#include <DxLib.h>
#include "CollisionCalc.h"
class ObstacleBox
{
public:
	ObstacleBox(VECTOR pos);
	~ObstacleBox();
	void Update();
	void Draw();
private:
	int _boxSize = 50;
	AABB _boxAABB;
};

