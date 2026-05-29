#include "BulletManager.h"
#include "Bullet.h"
#include "ShareClass.h"

BulletManager::BulletManager() {

}
BulletManager::~BulletManager() {

}
void BulletManager::ActiveBullet(VECTOR spawnPos, VECTOR plLookDir) {
	if (!_isCoolTimeEnd) {
		return;
	}
	for (int i = 0; i < BULLET_MAX; i++) {
		if (!_plBullets[i]) {
			_plBullets[i] = std::make_unique<Bullet>(spawnPos, plLookDir,*this,i);
			printfDx("ŽËŒ‚’†\n");
			break;
		}
	}
	_isCoolTimeEnd = false;
}

void BulletManager::Update() {
	if (!_isCoolTimeEnd) {
		_currentCoolTime += ShareClass::ConstValue;
	}

	if (_currentCoolTime >= _bulletCoolTime) {
		_isCoolTimeEnd = true;
		_currentCoolTime = 0;
	}
	for (int i = 0; i < BULLET_MAX; i++) {
		if (!_plBullets[i]) {
			continue;
		}
		_plBullets[i]->Update();
		_plBullets[i]->Draw();
		if (_plBullets[i]->IsDead()) {
			DeActiveBullet(i);
		}
	}
}

void BulletManager::DeActiveBullet(int index) {
	if (!_plBullets[index]) {
		return;
	}
	_plBullets[index].reset();
}