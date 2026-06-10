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
	// vectorの現在のサイズがMAX未満なら追加する
	if (_plBullets.size() < BULLET_MAX) {
		_plBullets.push_back(std::make_unique<Bullet>(spawnPos, plLookDir, *this, _plBullets.size()));
		printfDx("射撃中\n");
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

    // イテレータか通常のループで、Deadな弾を消しながら更新する
    for (auto it = _plBullets.begin(); it != _plBullets.end(); ) {
        (*it)->Update();
        (*it)->Draw();

        if ((*it)->IsDead()) {
            it = _plBullets.erase(it); // 死んだ弾をvectorから削除（自動解放）
        }
        else {
            ++it;
        }
    }
}

void BulletManager::DeActiveBullet(int index) {
	if (!_plBullets[index]) {
		return;
	}
	_plBullets[index].reset();
}