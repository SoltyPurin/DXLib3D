#pragma once
#include "DxLib.h"
class Sphere
{
public:
	Sphere();
	~Sphere();
	void Update();
	void Draw();
private:
	VECTOR _centerPos = VGet(1820, 540, 0);
	float _radius = 40;
	int _divNum = 8;
};

