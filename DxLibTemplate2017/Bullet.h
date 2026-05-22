#pragma once
#include <DxLib.h>
class Bullet
{
public:
	Bullet(VECTOR spawnPos,VECTOR plLookDir);
	~Bullet();
	void Update();
	void Draw();
	void Gravity();
private:
	VECTOR _currentPos;
	VECTOR _moveDirection;
	float _gravityPower = 5.5f;
	float _bulletSpeed = 100;
	float _blSize = 100;
};

