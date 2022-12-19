//
// raia-engine.c
//

#include "raia-engine.h"

#include "platforms.h"

#ifdef __MACOS__
#include "gamepad.h"

void callback(int type, int page, int usage, int value) {
    // 2 9 1 0 左ボタン離す
    // 2 9 1 1 左
    //     2 1 下
    //     3 1 右
    //     4 1 上
    //     5 1 L1
    //     6 1 R1
    //     7 1 L2
    //     8 1 R2
    //     9 1 左の小さいボタン
    //     10 1 右の小さいボタン（メニュー）
    //     11 1 左スティック押し込み
    //     12 1 右スティック押し込み
    //     13 1 PSボタン
    //     14 1 中央の大きいボタン
    //     15 1 ミュートボタン
    // 1 1 57 8 左カーソル離す
    // 1 1 57 0 上
    //        1 右上
    //        2 右
    //        3 右下
    //        4 下
    //        5 左下
    //        6 左
    //        7 左上
    // 1 1 49 左スティック
    // 1 1 50 右スティック
    // 1 1 48 傾き・加速度？
    // 1 1 53 傾き・加速度？
    // 1 1 65280 ?
    if (type == 1 && page != 65280 && usage!=48 && usage!=53)
        printf("type=%d, page=%d, usage=%d, value=%d\n", type, page, usage, value);
}
#endif

#ifdef __WINDOWS__
#pragma comment(lib, "winmm.lib")
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#endif

int main(int argc, char* argv[]) {

#ifdef __WINDOWS__
    JOYINFOEX JoyInfoEx;
    JoyInfoEx.dwSize = sizeof(JOYINFOEX);
    JoyInfoEx.dwFlags = JOY_RETURNALL;

    for (unsigned int i = 0; i < joyGetNumDevs(); i++) {//サポートされているジョイスティックの数を返す
        if (JOYERR_NOERROR == joyGetPosEx(i, &JoyInfoEx))
            printf("JoyStick No.%d OK\n", i);
    }
    Sleep(1000);
    //DWORD dwSize;                /* size of structure */
    //DWORD dwFlags;               /* flags to indicate what to return */
    //DWORD dwXpos;                /* x position */
    //DWORD dwYpos;                /* y position */
    //DWORD dwZpos;                /* z position */
    //DWORD dwRpos;                /* rudder/4th axis position */
    //DWORD dwUpos;                /* 5th axis position */
    //DWORD dwVpos;                /* 6th axis position */
    //DWORD dwButtons;             /* button states */
    //DWORD dwButtonNumber;        /* current button number pressed */
    //DWORD dwPOV;                 /* point of view state */
    //DWORD dwReserved1;           /* reserved for communication between winmm & driver */
    //DWORD dwReserved2;           /* reserved for future expansion */
    while (1) {
        if (JOYERR_NOERROR == joyGetPosEx(0, &JoyInfoEx)) { //0番のジョイスティックの情報を見る
            printf("dwSize = 0x%x, ", JoyInfoEx.dwSize);
            printf("dwFlags = 0x%x, ", JoyInfoEx.dwFlags);
            printf("dwXpos = 0x%x, ", JoyInfoEx.dwXpos);
            printf("dwYpos = 0x%x, ", JoyInfoEx.dwYpos);
            printf("dwXpos = 0x%x, ", JoyInfoEx.dwZpos);
            printf("dwRpos = 0x%x, ", JoyInfoEx.dwRpos);
            printf("dwUpos = 0x%x, ", JoyInfoEx.dwUpos);
            printf("dwVpos = 0x%x, ", JoyInfoEx.dwVpos);
            printf("dwButtons = 0x%x, ", JoyInfoEx.dwButtons);
            printf("dwButtonNumber = 0x%x, ", JoyInfoEx.dwButtonNumber);
            printf("dwPOV = 0x%x, ", JoyInfoEx.dwPOV);
            printf("dwReserved1 = 0x%x, ", JoyInfoEx.dwReserved1);
            printf("dwReserved2 = 0x%x, ", JoyInfoEx.dwReserved2);
            printf("\n");
        }
        else {
            printf("error\n");
        }
        Sleep(100);
}
#endif
#ifdef __MACOS__
    /* initialize gamepad */
    void* ctx = gamepad_init(1, 1, 0);
    if (!ctx) {
        puts("init failed");
        return -1;
    }

    /* set callback */
    gamepad_set_callback(ctx, callback);
#endif
    
    init_raia_header(); // ヘッダー情報を初期化
    raia_header_t header = get_raia_header(); // ヘッダーを取得
    init_pixel_data(header.window_width, header.window_height, header.samples_per_pixel); // ピクセルデータを初期化
    //openal_start(); // OpenALを開始
    glfw_start(); // GLFWを開始
    init_raia_shader(get_pixel_data(), header.window_width, header.window_height);
    glfw_redraw(); // 画面を再描画しておく
    init_duk_ctx();
    duktape_start(); // Duktapeを開始
    glfwTerminate(); // GLFWを終了
    free_pixel_data(); // ピクセルデータを解放する
    exit(EXIT_SUCCESS);
}
