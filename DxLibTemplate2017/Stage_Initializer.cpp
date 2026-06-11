#include "Stage.h"
#include <DxLib.h>
Stage::Stage(CameraMove* camera):
_plCamera(camera){
	_stageHandle = MV1LoadModel("Model/IronBridge_inTokyo.mqo");
	MAP_DATA.resize(MAP_Z, std::vector<int>(MAP_X, 0));
	MV1SetPosition(_stageHandle, VGet(5000, 0, 5000));
}

Stage::~Stage() {
	MV1DeleteModel(_stageHandle);
}
