#pragma once
#include <DxLib.h>
#include "ShareClass.h"
class CollisionCalc
{
public:
	bool BoxCalcAABB(const AABB& a, const AABB& b);
	bool SphereCalcAABB(const SphereAABB& a,const SphereAABB& b);
	bool BSCalcAABB(const AABB& a, const SphereAABB& b);
private:

};

