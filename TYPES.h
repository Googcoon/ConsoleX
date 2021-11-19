//COLORS
#include <string>
#include <iostream>
#include <vector>

using namespace std;

#ifndef TYPES_H
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




    extern bool Values(const string &i) {
        vector<string> iz{CONSOLE_BLACK, CONSOLE_BLUE, CONSOLE_GREEN, CONSOLE_AQUA, CONSOLE_RED, CONSOLE_PURPLE,
                          CONSOLE_YELLOW, CONSOLE_WHITE, CONSOLE_GRAY, CONSOLE_LIGHTBLUE, CONSOLE_LIGHTGREEN,
                          CONSOLE_LIGHTAQUA, CONSOLE_LIGHTRED, CONSOLE_LIGHTPURPLE, CONSOLE_LIGHTYELLOW,
                          CONSOLE_BRIGHTWHITE};

        return find(iz.begin(), iz.end(), i) != iz.end();

    }

#endif