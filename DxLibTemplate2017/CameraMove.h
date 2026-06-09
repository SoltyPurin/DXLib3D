#pragma once
#include <DxLib.h>
class CameraMove
{
public:
	CameraMove();
	~CameraMove();
	//カメラの移動関数、移動量とマウス座標を渡すことでカメラの座標移動とカメラの視点移動が可能
	void CameraMoveInput(VECTOR moveValue, VECTOR mouse);
	const VECTOR GetDirection() const { return VNorm(VGet(_flontX, _flontY, _flontZ)); }
	const VECTOR ReturnHorizontalForward();
	const VECTOR ReturnHorizontalRight();
private:
	int _xDifference, _yDifference;
	float _yaw = 0, _pitch = 0;
	float _flontX, _flontY, _flontZ;
	float _sensitivity = 0.005f;
	VECTOR _cameraPos = VGet(0,0,0);
};

