#pragma once
#include "ObstacleBox.h"
class Target : public ObstacleBox
{
public:
	Target(VECTOR pos, int size);
	virtual void Draw()override;
};

