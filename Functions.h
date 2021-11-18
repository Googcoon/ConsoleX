#include <process.h>
#include <string>
#include <utility>
#include "TYPES.h"

using namespace std;
using namespace COLORS;

#ifndef FUNCTIONS_H
//colors

namespace ConsoleFunctions {
    string background = CONSOLE_BLACK;
    string text = CONSOLE_WHITE;

    extern void SetConsoleTextColor(const string& color) {
        if(color == background || !Values(color)) return;
            //check if console color param is valid otherwise throw err
            text = color;
            const string cmd = "Color " + background + text;
            system(cmd.c_str());

    }

    extern void SetConsoleBackground(const string& color) {
        if (color == background || !Values(color)) return;
        //check if console color param is valid otherwise throw err
        background = color;
        const string cmd = "Color " + background + " " + text;
        system(cmd.c_str());
    }
}
#endif

