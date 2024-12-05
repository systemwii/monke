// setup basic terminal. commentated example:
// https://github.com/devkitPro/gamecube-examples/blob/master/devices/dvd/readsector/source/dvd.c
#include "console.h"
GXRModeObj* _vMode;
void* _fb;

// video management

void videoInit() {
    VIDEO_Init();
    _vMode = VIDEO_GetPreferredMode(NULL);
    VIDEO_Configure(_vMode);
    _fb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(_vMode));
}

void videoClear(u32 color) {
    VIDEO_ClearFrameBuffer(_vMode, _fb, color);
    VIDEO_SetNextFramebuffer(_fb);
}

void videoShow(bool show) {
    VIDEO_SetBlack(!show);
    VIDEO_Flush();
    VIDEO_WaitVSync();
    VIDEO_WaitVSync();
}

// gamepad read

int padScanOnNextFrame() {
    VIDEO_WaitVSync();
    return PAD_ScanPads();	// not guaranteed to work w/o VIDEO_WaitVSync() first
}

// console management

void consoleInit() {
    videoInit();
    PAD_Init();
    CON_Init(_fb, 0, 64, _vMode->fbWidth, _vMode->xfbHeight, _vMode->fbWidth * 2);
    videoClear(COLOR_BLACK);
    videoShow(true);
}

void consoleClear() {
    printf(CON_CLEAR);
}
