#include "Spere.h"

SphereAABB::SphereAABB() {

}

SphereAABB::~SphereAABB() {

}

void SphereAABB::Update() {

}

void SphereAABB::Draw() {
	DrawSphere3D(_centerPos, radius, _divNum, GetColor(255, 0, 0), GetColor(0, 0, 0), FALSE);
}
