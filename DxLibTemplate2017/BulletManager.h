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
	//e’e‚Ì—LŒø‰»
	void ActiveBullet(VECTOR spawnPos, VECTOR plLookDir);
	//ƒAƒNƒeƒBƒu‚Èe’e‚Ì–³Œø‰»
	void DeActiveBullet(int index);
	//e’e‚Ìƒv[ƒ‹‚ğ•Ô‚·
	const std::vector<std::unique_ptr<Bullet>>& GetBullets() const { return _plBullets; }

private:
	std::vector<std::unique_ptr<Bullet>> _plBullets;
	const int BULLET_MAX = 1000;
	float _bulletCoolTime = 1.0f;
	float _currentCoolTime = 0.0f;
	bool _isCoolTimeEnd = true;
};

