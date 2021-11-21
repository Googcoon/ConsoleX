#ifndef __ANSI_COLOR_INCLUDED__
#define __ANSI_COLOR_INCLUDED__

#define ANSI_RESET       "0"
#define ANSI_BOLD        "1"
#define ANSI_BLACK      "30"
#define ANSI_RED        "31"
#define ANSI_GREEN      "32"
#define ANSI_YELLOW     "33"
#define ANSI_BLUE       "34"
#define ANSI_MAGENTA    "35"
#define ANSI_CYAN       "36"
#define ANSI_WHITE      "37"
#define ANSI_ON_BLACK   "40"
#define ANSI_ON_RED     "41"
#define ANSI_ON_GREEN   "42"
#define ANSI_ON_YELLOW  "43"
#define ANSI_ON_BLUE    "44"
#define ANSI_ON_MAGENTA "45"
#define ANSI_ON_CYAN    "46"
#define ANSI_ON_WHITE   "47"

#define ANSI_ESC(x)          "\x1b[" x "m"
#define ANSI1(x)             ANSI_ESC(ANSI_ ## x)
#define ANSI2(x, y)          ANSI_ESC(ANSI_ ## x ";" ANSI_ ## y)
#define ANSI3(x, y, z)       ANSI_ESC(ANSI_ ## x ";" ANSI_ ## y ";" ANSI_ ## z)
#define ANSI4(x, y, z, t)    ANSI_ESC(ANSI_ ## x ";" ANSI_ ## y ";" ANSI_ ## z ";" ANSI_ ## t)
#define ANSI_SELECT_VERSION(_1, _2, _3, _4, VERSION,...) VERSION
#define ANSI(...)            ANSI_SELECT_VERSION(__VA_ARGS__, ANSI4, ANSI3, ANSI2, ANSI1)(__VA_ARGS__)

/**
 * printf("%sERROR%s", ANSI(RED, BOLD), ANSI(RESET));
 * printf("%sHLIGHTED%s", ANSI(BLACK, ON_YELLOW), ANSI(RESET));
 * ...
 */

#endif