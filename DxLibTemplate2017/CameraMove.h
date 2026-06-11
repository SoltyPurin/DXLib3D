#pragma once
#include <DxLib.h>
#include "CollisionCalc.h"
class CameraMove
{
public:
	CameraMove();
	~CameraMove();
	//カメラの移動関数、移動量とマウス座標を渡すことでカメラの座標移動とカメラの視点移動が可能
	void CameraMoveInput(VECTOR moveValue, VECTOR mouse);
	void CheckCollision();
	const VECTOR GetDirection() const { return VNorm(VGet(_flontX, _flontY, _flontZ)); }
	const VECTOR ReturnHorizontalForward();
	const VECTOR ReturnHorizontalRight();
	//AABBに使用する当たり判定を返す
	const AABB ReturnAABB() { return _cameraCollision; }
	//左右又は前後に押し戻す処理
	void PushXZ(float x, float z);
private:
	int _xDifference, _yDifference;
	float _yaw = 0, _pitch = 0;
	float _flontX, _flontY, _flontZ;
	float _sensitivity = 0.005f;
	int _horizontalSize = 50;
	int _verticalSize = 100;
	VECTOR _cameraPos = VGet(5000,0,5000);
	AABB _cameraCollision{ _cameraPos, VGet(_cameraPos.x + _horizontalSize, _cameraPos.y + _verticalSize, _cameraPos.z + _horizontalSize) };
};

