#include "Stage.h"
#include <DxLib.h>
Stage::Stage() {
	_stageHandle = MV1LoadModel("Model/IronBridge_inTokyo.mqo");
	MV1SetPosition(_stageHandle, VGet(0, 0, 0));
}

Stage::~Stage() {
	MV1DeleteModel(_stageHandle);
}
