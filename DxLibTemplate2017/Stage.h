#pragma once
#include <DxLib.h>
#include <vector>
#include <memory>
#include "ObstacleBox.h"
class CameraMove;
class CollisionCalc;
class CameraMove;
class Stage
{
public:
	Stage(CameraMove* camera);
	~Stage();
	void LoadModel();
	void Update();
	void Draw();
	void LoadCSV();
	//当たり判定のチェック
	void CheckCollision();
	//マップの横幅
	static constexpr int MAP_X = 500;
	//マップの高さ
	static constexpr int MAP_Y = 10;
	//マップの奥行き
	static constexpr int MAP_Z = 500;
	//障害物のサイズ
	static constexpr int OBSTACLE_SIZE = 500;
	//障害物のすきま
	static constexpr float OBSTACLE_SCALE = 1.0f;

private:
	int _stageHandle;
	std::vector<std::vector<int>> MAP_DATA;
	std::vector<std::unique_ptr<ObstacleBox>> _boxs;
	CameraMove* _plCamera;
	CollisionCalc _calc;
};


