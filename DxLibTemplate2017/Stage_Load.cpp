#include "Stage.h"
#include <fstream>
#include <sstream>

void Stage::LoadCSV() {
	std::ifstream file("CSV/MAPData.csv");
	std::string line;

	// ファイルがそもそも開けなかった場合のガード処理
	if (!file.is_open()) {
		printfDx("CSVファイルが開けませんでした\n");
		return;
	}

	int z = 0;
	// CSVから1行ずつ読み込む（実際の行数分だけ回る。最大MAP_Zまで）
	while (std::getline(file, line) && z < MAP_Z) {
		std::istringstream stream(line);
		std::string field;

		int x = 0;
		// その行にあるカンマ区切りのデータを1つずつ読み込む（実際の列数分だけ回る。最大MAP_Xまで）
		while (std::getline(stream, field, ',') && x < MAP_X)
		{
			// 空白文字（スペースや改行コードの残骸）を取り除く
			if (field.empty() || field == "\r" || field == "\n") {
				x++;
				continue;
			}

			try {
				// 文字列をint型に変換して代入
				MAP_DATA[z][x] = std::stoi(field);

				if (MAP_DATA[z][x] == 1) { // 1番を障害物とする
					_boxs.push_back(std::make_unique<ObstacleBox>(VGet(
						x * OBSTACLE_SIZE * OBSTACLE_SCALE,
						-1 * OBSTACLE_SIZE * OBSTACLE_SCALE,
						z * OBSTACLE_SIZE * OBSTACLE_SCALE
					), OBSTACLE_SIZE));
					MAP_DATA[z][x] = 0;
				}
			}
			catch (const std::exception& e) {
				// もし数字じゃないゴミ文字が入っていても、クラッシュさせずにスルーする
				MAP_DATA[z][x] = 0;
			}

			x++;
		}
		z++;
	}
	printfDx("ステージのロードが完了しました（読み込み行数: %d）\n", z);
}