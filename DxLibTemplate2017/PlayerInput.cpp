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
	GetHitKeyStateAll(_keys);
	_input = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	VECTOR pos = GetCameraPosition();
	VECTOR moveVec = VGet(0, 0, 0);

	VECTOR forward = _camera->ReturnHorizontalForward();
	VECTOR right = _camera->ReturnHorizontalRight();

	if ((_input & PAD_INPUT_LEFT) != 0 || _keys[KEY_INPUT_A]) {
		moveVec.x -= right.x;
		moveVec.z -= right.z;

	}
	else if ((_input & PAD_INPUT_RIGHT) != 0 || _keys[KEY_INPUT_D]) {
		moveVec.x += right.x;
		moveVec.z += right.z;

	}
	if ((_input & PAD_INPUT_UP) != 0|| _keys[KEY_INPUT_W]) {
		moveVec.x += forward.x;
		moveVec.z += forward.z;

	}
	else if ((_input & PAD_INPUT_DOWN) != 0 || _keys[KEY_INPUT_S]) {
		moveVec.x -= forward.x;
		moveVec.z -= forward.z;

	}
	if (VSize(moveVec) > 0.0f) {
		moveVec = VNorm(moveVec);

		moveVec = VScale(moveVec, _playerSpeed);
	}
	GetMousePoint(&_currentMousePosX, &_currentMousePosY);
	VECTOR target = GetCameraTarget();
	_camera->CameraMoveInput(moveVec, VGet(_currentMousePosX, _currentMousePosY, 0));

	VECTOR dir = _camera->GetDirection();;
	if (GetMouseInput() & MOUSE_INPUT_LEFT) {
		_bulletManager->ActiveBullet(pos, dir);
	}
}
