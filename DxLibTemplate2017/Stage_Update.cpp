#include "Stage.h"
#include "CameraMove.h"
#include "BulletManager.h"
void Stage::Update() {
	MV1DrawModel(_stageHandle);
	for (auto i = _boxs.begin(); i != _boxs.end(); i++) {
		(*i)->Draw();
	}
	for (auto i = _targets.begin(); i != _targets.end(); i++) {
		(*i)->Draw();
	}
	_bulletManager->Update();
	CheckCollision();
}