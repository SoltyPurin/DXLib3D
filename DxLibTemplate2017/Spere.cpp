#include "Spere.h"

Sphere::Sphere() {

}

Sphere::~Sphere() {

}

void Sphere::Update() {

}

void Sphere::Draw() {
	DrawSphere3D(_centerPos, _radius, _divNum, GetColor(255, 0, 0), GetColor(0, 0, 0), FALSE);
}
