#include "Stage.h"
#include "CollisionCalc.h"
#include "CameraMove.h"
#include "BulletManager.h"
#include "Bullet.h"
void Stage::CheckCollision() {
	for (auto i = _boxs.begin(); i != _boxs.end(); i++) {
		if (_calc.BoxCalcAABB(_plCamera->ReturnAABB(), (*i)->ReturnAABB())) {
			printfDx("プレイヤーと箱が接触\n");
			//左へ押す量
			float overLapL = _plCamera->ReturnAABB().max.x - (*i)->ReturnAABB().min.x;
			//右へ押す量
			float overLapR = (*i)->ReturnAABB().max.x - _plCamera->ReturnAABB().min.x;

			//前へ押す量
			float overLapF = _plCamera->ReturnAABB().max.z - (*i)->ReturnAABB().min.z;
			//後ろへ押す量
			float overLapB = (*i)->ReturnAABB().max.z - _plCamera->ReturnAABB().min.z;

			// X/Zそれぞれ最小の押し戻し量
			float pushX = (overLapL < overLapR) ? overLapL : overLapR;
			float pushZ = (overLapF < overLapB) ? overLapF : overLapB;

			//中心でどちら側にいるか判定
			float rcx = _plCamera->ReturnAABB().min.x + _plCamera->ReturnAABB().max.x * 0.5f;
			float ccx = (*i)->ReturnAABB().min.x + (*i)->ReturnAABB().max.x * 0.5f;
			float rcz = _plCamera->ReturnAABB().min.z + _plCamera->ReturnAABB().max.z * 0.5f;
			float ccz = (*i)->ReturnAABB().min.z + (*i)->ReturnAABB().max.z * 0.5f;

			if (pushX < pushZ) {
				// 横解決
				if (rcx < ccx) {
					_plCamera->PushXZ(-pushX, 0);
				}
				else {
					_plCamera->PushXZ(pushX, 0);
				}
			}
			else {
				//奥行解決
				if (rcz < ccz) {
					_plCamera->PushXZ(0, -pushZ);
				}
				else {
					_plCamera->PushXZ(0, pushZ);
				}
			}
		}
	}
	const auto& bullets = _bulletManager->GetBullets();
	for (auto i = _targets.begin(); i != _targets.end();) {
		bool isHit = false; // 弾に当たったかどうかのフラグ

		for (const auto& bullet : bullets) {
			if (_calc.BSCalcAABB((*i)->ReturnAABB(), bullet->ReturnBulletAABB()))
			{
				// ターゲットを削除し、次の要素を指すイテレータを受け取る
				i = _targets.erase(i);
				bullet->ColDead();

				printfDx("弾がターゲットに接触\n");

				isHit = true; // 当たったフラグを立てる
				break;        // このターゲットは消えたので、残りの弾のループはスキップする
			}
		}

		if (!isHit) {
			i++;
		}
	}
}
