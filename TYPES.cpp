#include "TYPES.hpp"
bool Values(const string &i) {
    vector<string> iz{CONSOLE_BLACK, CONSOLE_BLUE, CONSOLE_GREEN, CONSOLE_AQUA, CONSOLE_RED, CONSOLE_PURPLE,
                      CONSOLE_YELLOW, CONSOLE_WHITE, CONSOLE_GRAY, CONSOLE_LIGHTBLUE, CONSOLE_LIGHTGREEN,
                      CONSOLE_LIGHTAQUA, CONSOLE_LIGHTRED, CONSOLE_LIGHTPURPLE, CONSOLE_LIGHTYELLOW,
                      CONSOLE_BRIGHTWHITE};

    return find(iz.begin(), iz.end(), i) != iz.end();

}
