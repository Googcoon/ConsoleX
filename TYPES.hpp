//COLORS
#include <string>
#include <iostream>
#include <vector>

using namespace std;

#ifndef TYPES_H

// Color Functions
bool Values(const string&);


namespace COLORS {
#define CONSOLE_BLACK "0"
#define CONSOLE_BLUE "1"
#define CONSOLE_GREEN "2"
#define CONSOLE_AQUA "3"
#define CONSOLE_RED "4"
#define CONSOLE_PURPLE "5"
#define CONSOLE_YELLOW "6"
#define CONSOLE_WHITE "7"
#define CONSOLE_GRAY "8"
#define CONSOLE_LIGHTBLUE "9"
#define CONSOLE_LIGHTGREEN "A"
#define CONSOLE_LIGHTAQUA "B"
#define CONSOLE_LIGHTRED "C"
#define CONSOLE_LIGHTPURPLE "D"
#define CONSOLE_LIGHTYELLOW "E"
#define CONSOLE_BRIGHTWHITE "F"
    }

namespace WindowTypes {
    typedef enum CurrentWindow {
        LOAD_Window,
        MAIN_Window,
        GAME_Window,
        SETTINGS_Window,
        NONE_Window
    } CurrentWindow;
}

#endif