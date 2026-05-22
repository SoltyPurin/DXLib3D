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
	CameraMove* _camera;
	BulletManager* _bulletManager;
};

