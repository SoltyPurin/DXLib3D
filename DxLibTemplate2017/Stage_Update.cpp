#include "Stage.h"
#include "CameraMove.h"
void Stage::Update() {
	MV1DrawModel(_stageHandle);
	for (auto i = _boxs.begin(); i != _boxs.end(); i++) {
		(*i)->Draw();
	}
	CheckCollision();
}