#include "BulletManager.h"
#include "Bullet.h"

BulletManager::BulletManager() {

}
BulletManager::~BulletManager() {

}
void BulletManager::ActiveBullet(VECTOR spawnPos, VECTOR plLookDir) {
	for (int i = 0; i < BULLET_MAX; i++) {
		if (_plBullets[i] == nullptr) {
			_plBullets[i] = std::make_unique<Bullet>(spawnPos, plLookDir);
		}
	}
}

void BulletManager::Update() {
	for (int i = 0; i < BULLET_MAX; i++) {
		if (!_plBullets[i]) {
			return;
		}
		_plBullets[i]->Update();
		_plBullets[i]->Draw();
	}
}

void BulletManager::DeActiveBullet(int index) {
	if (!_plBullets[index]) {
		return;
	}
	_plBullets[index].reset();
}