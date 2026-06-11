#pragma once
#include <DxLib.h>
struct SphereAABB {
	VECTOR center;
	float radius;
};

struct AABB {
	// ç∂â∫
	VECTOR min;
	// âEè„
	VECTOR max;
};
class ShareClass
{
public:
	ShareClass();
	~ShareClass();
	static float ConstValue;
};

