#pragma once
#include "DXLib.h"
class CameraMove;
class BulletManager;
class PlayerInput
{
public:
	PlayerInput(CameraMove* camera,BulletManager* bulletManager);
	~PlayerInput();
	void Update();
private:
	int _currentMousePosX, _currentMousePosY;
	int _prevMousePosX, _prevMousePosY;
	CameraMove* _camera;
	BulletManager* _bulletManager;
	float _mouseSensitivity = 0.005f;
	float _yaw, _pitch;
};

