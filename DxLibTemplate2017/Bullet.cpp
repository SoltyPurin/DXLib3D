#include "Bullet.h"
#include "BulletManager.h"

Bullet::Bullet(VECTOR spawnPos, VECTOR plLookDir, BulletManager& blManager,int number):
_currentPos(spawnPos),
_moveDirection(plLookDir),
_bulletManager(blManager),
_sphereAABB{spawnPos,_bulletSize},
_isDead(false){

}

Bullet::~Bullet() {

}

void Bullet::Update() {
	_currentPos.x += _moveDirection.x * _bulletSpeed;
	_currentPos.y += _moveDirection.y * _bulletSpeed;
	_currentPos.z += _moveDirection.z * _bulletSpeed;
	_currentLifeTime += ShareClass::ConstValue;
	_sphereAABB.center = _currentPos;
	if (_currentLifeTime >= _bulletLifeTime) {
		_isDead = true;
	}
}

void Bullet::Draw() {
	DrawSphere3D(_currentPos, _bulletSize, 8, GetColor(255, 0, 0), GetColor(0, 0, 0), FALSE);
}

void Bullet::Gravity() {

}