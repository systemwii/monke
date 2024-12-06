#pragma once
#pragma GCC visibility push(hidden)

#include <stdio.h>
#include <gccore.h>

void videoInit(void);           // on program startup (configure registers, video mode, frame buffer)
void videoClear(u32 color);     // clear screen and set background colour (text remains black bkgd, like teletext)
void videoShow(bool show);      // toggle showing video vs black screen (hides transitions)
int padScanOnNextFrame(void);   // scan GameCube pads on next frame (returns bitfield of connected pads)
void consoleInit();             // initialises video, console (black background) and gamepads
void consoleClear(void);        // clears console (alternative to printf(CON_CLEAR))

// console colours :O
// these macros work well with black background but
// you can use the codes manually or your own macros in other circumstances
// e.g. videoClear(COLOR_RED); printf("\x1b[31;1m");

// text colours
#define CON_BLACK(str)		"\x1b[30m" str "\x1b[37;1m"
#define CON_RED(str)		"\x1b[31;1m" str "\x1b[37;1m"
#define CON_GREEN(str)		"\x1b[32;1m" str "\x1b[37;1m"
#define CON_YELLOW(str)		"\x1b[33;1m" str "\x1b[37;1m"
#define CON_BLUE(str)		"\x1b[34;1m" str "\x1b[37;1m"
#define CON_MAGENTA(str)	"\x1b[35;1m" str "\x1b[37;1m"
#define CON_CYAN(str)		"\x1b[36;1m" str "\x1b[37;1m"
// background colours
#define CON_BGRED(str)		"\x1b[41;1m" str "\x1b[40m"
#define CON_BGGREEN(str)	"\x1b[42;1m" str "\x1b[40m"
#define CON_BGYELLOW(str)	"\x1b[43;1m" str "\x1b[40m"
#define CON_BGBLUE(str)		"\x1b[44;1m" str "\x1b[40m"
#define CON_BGMAGENTA(str)	"\x1b[45;1m" str "\x1b[40m"
#define CON_BGCYAN(str)		"\x1b[46;1m" str "\x1b[40m"
#define CON_BGWHITE(str)	"\x1b[47;1m" str "\x1b[40m"

#define CON_CLEAR			"\x1b[2J" // signal text to clear console

#pragma GCC visibility pop
