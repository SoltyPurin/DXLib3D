#include "ObstacleBox.h"
ObstacleBox::ObstacleBox(VECTOR pos):
	_boxAABB{ pos,VGet(pos.x + _boxSize, pos.y + _boxSize, pos.z + _boxSize) } {

}

ObstacleBox::~ObstacleBox() {

}

void ObstacleBox::Update() {
	Draw();
}
void ObstacleBox::Draw() {
	DrawCube3D(_boxAABB.min, _boxAABB.max, GetColor(0, 0, 0), GetColor(0, 0, 0),TRUE);
}