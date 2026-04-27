#include <DxLib.h>
#include "Spere.h"
// -------------------- Main --------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    SetOutApplicationLogValidFlag(FALSE);

    // 【修正】FALSEは全画面です。非全画面（ウィンドウ）なら TRUE にします
    ChangeWindowMode(TRUE);

    SetGraphMode(1920, 1080, 32);
    SetBackgroundColor(0, 0, 0, 1);

    Sphere _spehre;

    // 【修正】DxLib_Initのエラーは -1 が返ってきます
    if (DxLib_Init() == -1) { return -1; }
    SetWaitVSyncFlag(TRUE);

    // 【修正】裏画面設定はループの前に1回だけ行う
    SetDrawScreen(DX_SCREEN_BACK);
    while (ProcessMessage() == 0 && ClearDrawScreen() == 0) {
        DrawString(0, 20, "Gキーでゲーム画面、Mキーでメニュー画面,Tキーでクリア画面", GetColor(255, 255, 255));

        _spehre.Draw();


        ScreenFlip();
    }

    DxLib_End();
    return 0;
}
