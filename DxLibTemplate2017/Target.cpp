#include "Target.h"
Target::Target(VECTOR pos, int size) : ObstacleBox(pos, size)
{
}
void Target::Draw() {
	DrawCube3D(_boxAABB.min, _boxAABB.max, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);
}