#include "Bullet.h"


Bullet::Bullet(VECTOR spawnPos, VECTOR plLookDir):
_currentPos(spawnPos),
_moveDirection(plLookDir){

}

Bullet::~Bullet() {

}

void Bullet::Update() {
	_currentPos.x += _moveDirection.x;
	_currentPos.y += _moveDirection.y;
	_currentPos.z += _moveDirection.z;
}

void Bullet::Draw() {
	DrawSphere3D(_currentPos, _blSize, 8, GetColor(255, 0, 0), GetColor(0, 0, 0), FALSE);
}

void Bullet::Gravity() {

}