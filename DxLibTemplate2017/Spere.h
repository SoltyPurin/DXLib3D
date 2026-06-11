#pragma once
#include "DxLib.h"
class SphereAABB
{
public:
	SphereAABB();
	~SphereAABB();
	void Update();
	void Draw();
private:
	VECTOR _centerPos = VGet(960, 540, 0);
	float radius = 40;
	int _divNum = 8;
};

