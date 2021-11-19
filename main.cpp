#include <cstdio>
#include <stdlib.h>
#include "raylib.h"
#include "extras/raygui.h"
#include "Functions.h"
#include <iostream>
#include <filesystem>



namespace fs = std::filesystem;
using namespace ConsoleFunctions;

vector<string> getDir(const string& dir) {
    vector<string> files;
    for (auto & p : fs::directory_iterator(dir)) {
        files.push_back(p.path().string());
    }
    return files;
}



int main() {
    const string projFolder = (string) getenv("USERPROFILE") + "ConsoleX Projects";

    // Pre Init
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(0);
    SetTraceLogLevel(LOG_NONE);

    // Init
    InitWindow(0, 0, "ConsoleX - The Best Console Game Engine");

    // Post Init
    SetExitKey(0);
    MaximizeWindow();

    // GUI Post Init
    float offset = 0;


    while (!WindowShouldClose())
    {
        // Necessary code for window handling
        if(IsWindowMaximized() && IsWindowResized())
            MaximizeWindow();
        SetWindowTitle("ConsoleX - The Best Console Game Engine | Load Project");

        // Mouse Input Settings Shit
        offset += GetMouseWheelMove() * 5;
        if (offset < 0)
            offset = 0;
        if (offset > 800)
            offset = 800;

        // GUI
        BeginDrawing();

        ClearBackground(RAYWHITE);

        Rectangle clipRect = { 20,20,300,200 };
        DrawRectangleRec(clipRect, DARKGRAY);

        BeginScissorMode(clipRect.x, clipRect.y, clipRect.width, clipRect.height);

        for (int i = 0; i < 1200; i += 20)
        {

            DrawRectangle(clipRect.x + 2, clipRect.y - offset + i, 300 + (i % 30) * 2, 100, i % 40 == 0 ? RED : GREEN);
            DrawText(string("HELLO BOZO " + to_string(i)).c_str(), clipRect.x + 2, clipRect.y - offset + i, 20, LIGHTGRAY);
        }

        EndScissorMode();

        EndDrawing();

    }

    CloseWindow();

    return 0;
}
