#pragma once
#include <DxLib.h>

class Stage
{
public:
	Stage();
	~Stage();
	void LoadModel();
	void Update();
	void Draw();

private:
	int _stageHandle;
};


