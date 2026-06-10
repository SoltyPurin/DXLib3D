#pragma once
#include <DxLib.h>
struct Sphere {
	VECTOR center;
	float radius;
};

struct AABB {
	// ç∂â∫
	VECTOR min;  
	// âEè„
	VECTOR max;  
};
class CollisionCalc
{
public:
	bool BoxCalcAABB(AABB a, AABB b);
	bool SphereCalcAABB(Sphere a,Sphere b);
private:

};

