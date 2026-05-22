#pragma once
#include <DxLib.h>
#include <vector>
#include <memory>
class Bullet;
class BulletManager
{
public:
	BulletManager();
	~BulletManager();
	void Update();
	//銃弾の有効化
	void ActiveBullet(VECTOR spawnPos, VECTOR plLookDir);
	//アクティブな銃弾の無効化
	void DeActiveBullet(int index);
private:
	std::unique_ptr<Bullet> _plBullets[100];
	const int BULLET_MAX = 100;
};

