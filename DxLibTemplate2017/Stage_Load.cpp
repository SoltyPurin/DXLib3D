#include "Stage.h"
#include <fstream>
#include <sstream>

void Stage::LoadCSV() {
	std::ifstream file("CSV/MAPData.csv");
	std::string line;

	int z = 0;
	while (std::getline(file, line) && z < MAP_Z) {
		std::istringstream stream(line);
		std::string field;

		// 「,」区切りごとにデータを読み込む
		int x = 0;
		while (getline(stream, field, ',') && x < MAP_X)
		{

			// 文字列をint型に変換してm_chipDataに追加する
			MAP_DATA[z][x] = std::stoi(field);

			if (MAP_DATA[z][x] == 1) { // 1番を障害物とする
				_boxs.push_back(std::make_unique<ObstacleBox>(VGet(x * OBSTACLE_SIZE * OBSTACLE_SCALE, 1 * OBSTACLE_SIZE * OBSTACLE_SCALE, z * OBSTACLE_SIZE * OBSTACLE_SCALE)));
				MAP_DATA[z][x] = 0;
			}

			x++;
		}
		z++;
	}

}