#pragma once
#include <DxLib.h>
class CameraMove
{
public:
	CameraMove();
	~CameraMove();
	//カメラの移動関数、座標とマウス座標を渡すことで移動とカメラ移動が可能
	void CameraMoveInput(VECTOR pos, VECTOR mouse);
	const VECTOR GetDirection() const { return VNorm(VGet(_flontX, _flontY, _flontZ)); }
private:
	int _xDifference, _yDifference;
	float _yaw = 0, _pitch = 0;
	float _flontX, _flontY, _flontZ;
	float _sensitivity = 0.005f;
};

