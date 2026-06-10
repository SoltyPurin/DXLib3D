#include <DxLib.h>
#include "Vector2.h"
#include "PlayerInput.h"
#include "CameraMove.h"
#include "BulletManager.h"
#include "Stage.h"
#include "ObstacleBox.h"
// -------------------- Main --------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    SetOutApplicationLogValidFlag(TRUE);

    // 【修正】FALSEは全画面です。非全画面（ウィンドウ）なら TRUE にします
    ChangeWindowMode(TRUE);

    SetGraphMode(1920, 1080, 32);
    SetBackgroundColor(0, 0, 0, 1);


    // 【修正】DxLib_Initのエラーは -1 が返ってきます
    if (DxLib_Init() == -1) { return -1; }
    SetWaitVSyncFlag(TRUE);
    SetMouseDispFlag(FALSE);
    VECTOR _cameraPos = VGet(0.0f, 0.0f, 0.0f);


    //Stage _stage;
    //_stage.LoadCSV();
    CameraMove _camera;
    BulletManager _bulletManager;
    PlayerInput _input = PlayerInput(&_camera, &_bulletManager);

    ObstacleBox box = ObstacleBox(VGet(0,0,0));

    // 【修正】裏画面設定はループの前に1回だけ行う
    SetDrawScreen(DX_SCREEN_BACK);
    while (ProcessMessage() == 0 && ClearDrawScreen() == 0) {
        DrawString(0, 20, "Gキーでゲーム画面、Mキーでメニュー画面,Tキーでクリア画面", GetColor(255, 255, 255));

        _input.Update();
        _bulletManager.Update();
        //_stage.Update();
        box.Update();
        // 画面のど真ん中に緑色の照準（クロスヘア）を描画する
        DrawLine(960 - 15, 540, 960 + 15, 540, GetColor(0, 255, 0)); // 横線
        DrawLine(960, 540 - 15, 960, 540 + 15, GetColor(0, 255, 0)); // 縦線
        SetMousePoint(960, 540);
        ScreenFlip();
        ClearDrawScreen();
    }

    DxLib_End();
    return 0;
}
