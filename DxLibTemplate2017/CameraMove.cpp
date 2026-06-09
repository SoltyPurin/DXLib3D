#include "CameraMove.h"
#include "Vector2.h"
#include <DxLib.h>
CameraMove::CameraMove() {

}

CameraMove::~CameraMove() {

}

const VECTOR CameraMove::ReturnHorizontalForward() {
    { return VGet(sin(_yaw), 0.0f, cos(_yaw)); }
}

const VECTOR CameraMove::ReturnHorizontalRight() {
    { return VGet(cos(_yaw), 0.0f, -sin(_yaw)); }
}

void CameraMove::CameraMoveInput(VECTOR moveValue, VECTOR mousePos) {
    //ここからカメラの視点移動の計算
    _xDifference = mousePos.x - 960;
    _yDifference = mousePos.y - 540;
    _yaw += _xDifference * _sensitivity;
    _pitch -= _yDifference * _sensitivity;
    const float PITCH_LIMIT = 3.1415926f / 2.0f - 0.1f; // 約84度
    if (_pitch > PITCH_LIMIT) _pitch = PITCH_LIMIT;
    if (_pitch < -PITCH_LIMIT) _pitch = -PITCH_LIMIT;
    _flontX = cos(_pitch) * sin(_yaw);
    _flontY = sin(_pitch);
    _flontZ = cos(_pitch) * cos(_yaw);
    _cameraPos.x += moveValue.x;
    _cameraPos.z += moveValue.z;

    float lookX = _cameraPos.x + _flontX;
    float lookY = _cameraPos.y + _flontY;
    float lookZ = _cameraPos.z + _flontZ;

	SetCameraPositionAndTarget_UpVecY(_cameraPos, VGet(lookX, lookY, lookZ));
}