#include "CameraMove.h"
#include "Vector2.h"
CameraMove::CameraMove() {

}

CameraMove::~CameraMove() {

}

void CameraMove::CameraMoveInput(VECTOR pos, VECTOR mousePos) {
    _xDifference = mousePos.x - 960;
    _yDifference = mousePos.y - 540;
    _yaw += _xDifference * _sensitivity;
    _pitch -= _yDifference * _sensitivity;
    const float PITCH_LIMIT = 3.1415926f / 2.0f - 0.1f; // –ñ84“x
    if (_pitch > PITCH_LIMIT) _pitch = PITCH_LIMIT;
    if (_pitch < -PITCH_LIMIT) _pitch = -PITCH_LIMIT;
    _flontX = cos(_pitch) * sin(_yaw);
    _flontY = sin(_pitch);
    _flontZ = cos(_pitch) * cos(_yaw);
    float lookX = pos.x + _flontX;
    float lookY = pos.y + _flontY;
    float lookZ = pos.z + _flontZ;

	SetCameraPositionAndTarget_UpVecY(pos, VGet(lookX, lookY, lookZ));
}