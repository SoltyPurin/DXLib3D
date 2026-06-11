#include "ObstacleBox.h"
ObstacleBox::ObstacleBox(VECTOR pos,int size):
	_boxSize(size),
	_boxAABB{ pos,VGet(pos.x + _boxSize, pos.y + _boxSize, pos.z + _boxSize) } {

}

ObstacleBox::~ObstacleBox() {

}

void ObstacleBox::Update() {
}
void ObstacleBox::Draw() {
	DrawCube3D(_boxAABB.min, _boxAABB.max, GetColor(255, 255, 255), GetColor(255, 255, 255),TRUE);
}