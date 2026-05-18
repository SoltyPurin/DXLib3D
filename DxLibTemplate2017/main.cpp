#include <DxLib.h>
#include "Spere.h"
#include "Vector2.h"
// -------------------- Main --------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    SetOutApplicationLogValidFlag(FALSE);

    // 【修正】FALSEは全画面です。非全画面（ウィンドウ）なら TRUE にします
    ChangeWindowMode(TRUE);

    SetGraphMode(1920, 1080, 32);
    SetBackgroundColor(0, 0, 0, 1);

    int _currentMousePosX, _currentMousePosY;
    int _xDifference, _yDifference;

    VECTOR _cameraPos = VGet(0.0f, 0.0f, 0.0f);

    float _sensitivity = 0.005f;
    float _yaw=0, _pitch=0;
    float _flontX,_flontY,_flontZ;
    Sphere _spehre;

    // 【修正】DxLib_Initのエラーは -1 が返ってきます
    if (DxLib_Init() == -1) { return -1; }
    SetWaitVSyncFlag(TRUE);
    SetMouseDispFlag(FALSE);

    // 【修正】裏画面設定はループの前に1回だけ行う
    SetDrawScreen(DX_SCREEN_BACK);
    while (ProcessMessage() == 0 && ClearDrawScreen() == 0) {
        DrawString(0, 20, "Gキーでゲーム画面、Mキーでメニュー画面,Tキーでクリア画面", GetColor(255, 255, 255));

        GetMousePoint(&_currentMousePosX, &_currentMousePosY);
        _xDifference = _currentMousePosX - 960;
        _yDifference = _currentMousePosY - 540;
        _yaw += _xDifference * _sensitivity;
        _pitch -= _yDifference * _sensitivity;
        _flontX = cos(_pitch) * sin(_yaw);
        _flontY = sin(_pitch);
        _flontZ = cos(_pitch) * cos(_yaw);
        float lookX = _cameraPos.x + _flontX;
        float lookY = _cameraPos.y + _flontY *-1;
        float lookZ = _cameraPos.z + _flontZ;
        SetCameraPositionAndTarget_UpVecY(_cameraPos, VGet(lookX,lookY,lookZ));
        _spehre.Draw();
        //SetCameraPositionAndTarget_UpVecY(_cameraPos, VGet(_currentMousePosX, _currentMousePosY, 0));

        SetMousePoint(960, 540);
        ScreenFlip();
        ClearDrawScreen();
    }

    DxLib_End();
    return 0;
}
