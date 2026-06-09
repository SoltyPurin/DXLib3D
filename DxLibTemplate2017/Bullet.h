#pragma once
#include <DxLib.h>
#include "ShareClass.h"
class BulletManager;
class Bullet
{
public:
	Bullet(VECTOR spawnPos,VECTOR plLookDir,BulletManager& blManager,int number);
	~Bullet();
	void Update();
	void Draw();
	void Gravity();
	bool IsDead() { return _isDead; }
private:
	VECTOR _currentPos;
	VECTOR _moveDirection;
	BulletManager& _bulletManager;
	float _gravityPower = 5.5f;
	float _bulletSpeed = 10;
	float _bulletSize = 5;
	float _bulletLifeTime = 5;
	float _currentLifeTime = 0;
	bool _isDead = false;
};

