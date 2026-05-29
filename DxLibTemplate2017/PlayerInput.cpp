#include "PlayerInput.h"
#include "CameraMove.h"
#include "BulletManager.h"
PlayerInput::PlayerInput(CameraMove* camera,BulletManager* bulletManager):
_camera(camera),
_bulletManager(bulletManager){

}

PlayerInput::~PlayerInput() {

}
void PlayerInput::Update() {
	GetMousePoint(&_currentMousePosX, &_currentMousePosY);
	VECTOR pos = GetCameraPosition();
	VECTOR target = GetCameraTarget();
	_camera->CameraMoveInput(pos, VGet(_currentMousePosX, _currentMousePosY, 0));

	VECTOR dir = _camera->GetDirection();;
	if (GetMouseInput() & MOUSE_INPUT_LEFT) {
		_bulletManager->ActiveBullet(pos, dir);
	}
}
