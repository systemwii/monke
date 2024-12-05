# console

**Basic terminal.**

Offers functions for setting up video output, waiting for inputs, and managing the console, as well as macros for output formatting. Print text to the console using `printf` as usual.

As well as the below example, check out the [template](https://github.com/systemwii/template) repository for an demo app you can fork and compile right away, which measures button mashing, and is built only with monke/console on top of libogc.

## Example
```c
#include <unistd.h>     // offers sleep(), usleep()     
#include "console.h"    // implicitly includes <stdio.h>, <gccore.h>

char ukiki[6] = "ukiki ";
u32 bgcols[20] = {  // see https://github.com/devkitPro/libogc/blob/master/gc/ogc/color.h
    COLOR_BLACK, COLOR_MAROON, COLOR_GREEN, COLOR_OLIVE, COLOR_NAVY,
    COLOR_PURPLE, COLOR_TEAL, COLOR_GRAY, COLOR_SILVER, COLOR_RED,
    COLOR_LIME, COLOR_YELLOW, COLOR_BLUE, COLOR_FUCHSIA, COLOR_AQUA,
    COLOR_WHITE, COLOR_MONEYGREEN, COLOR_SKYBLUE, COLOR_CREAM, COLOR_MEDGRAY,
};

int main() {
    consoleInit();
    printf(CON_BGRED(" eternal ") " " CON_BGMAGENTA(" monke ") " " CON_BGYELLOW(CON_BLACK(" disorder ")) "\n");
    // idiom to detect button hold (if controller 0 holds A)
    if (padScanOnNextFrame() && PAD_ButtonsHeld(0) & PAD_BUTTON_A) {
        printf("a button holder\n");
    }
    printf(CON_RED("wait ") CON_YELLOW("wait ") CON_GREEN("wait\n"));
    printf(CON_BLUE("wait ") CON_MAGENTA("wait ") CON_CYAN("wait\n"));
    sleep(2);

    consoleClear();
    printf("press %s or " CON_BLUE("%s") "\n", CON_CYAN("A"), "B");
    int ctr = 0;
    // idiom to wait for button press
    while (padScanOnNextFrame()) {
        if (PAD_ButtonsDown(0) & PAD_BUTTON_A) { // if controller 0 pressed A
            printf("%c", ukiki[ctr++ % (sizeof(ukiki)/sizeof(ukiki[0]))]);
        } else if (PAD_ButtonsDown(0) & PAD_BUTTON_B) {
            printf(CON_MAGENTA("\nnokiki :c"));     sleep(1);
            videoShow(false);   usleep(500000);     videoShow(true);    usleep(500000);
            videoShow(false);   usleep(500000);     videoShow(true);
            return 0;
        } else if (PAD_ButtonsDown(0) & PAD_TRIGGER_Z) {
            videoClear(bgcols[ctr % (sizeof(bgcols)/sizeof(bgcols[0]))]);
            // clearing video (not console) doesn't reset cursor position
        }
    }
    printf("\ncontroller disconnected ._.\n");
    return 0;
}
```
