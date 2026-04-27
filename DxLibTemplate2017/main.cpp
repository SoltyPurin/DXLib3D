#include <DxLib.h>
// -------------------- Main --------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    SetOutApplicationLogValidFlag(FALSE);
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1) return -1;
    SetDrawScreen(DX_SCREEN_BACK);
    ScreenFlip();
    DxLib_End();
    return 0;
}
