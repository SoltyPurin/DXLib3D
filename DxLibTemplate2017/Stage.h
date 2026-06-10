#pragma once
#include <DxLib.h>
#include <vector>
#include <memory>
#include "ObstacleBox.h"
class Stage
{
public:
	Stage();
	~Stage();
	void LoadModel();
	void Update();
	void Draw();
	void LoadCSV();
	//マップの横幅
	static constexpr int MAP_X = 500;
	//マップの高さ
	static constexpr int MAP_Y = 10;
	//マップの奥行き
	static constexpr int MAP_Z = 500;
	//障害物のサイズ
	static constexpr int OBSTACLE_SIZE = 50;
	//障害物の拡大率
	static constexpr float OBSTACLE_SCALE = 1.5f;

private:
	int _stageHandle;
	int MAP_DATA[MAP_Z][MAP_X];
	std::vector<std::unique_ptr<ObstacleBox>> _boxs;
};



