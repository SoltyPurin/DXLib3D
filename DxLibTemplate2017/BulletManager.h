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
	std::unique_ptr<Bullet> _plBullets[1000];
	const int BULLET_MAX = 1000;
	float _bulletCoolTime = 1.0f;
	float _currentCoolTime = 0.0f;
	bool _isCoolTimeEnd = true;
};

