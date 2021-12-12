#include <string>
#include "raylib.h"
#include "InternalErrorHandling.hpp"
void ThrowInternalError (const std::string& error) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);
    SetTraceLogLevel(LOG_NONE);

    InitWindow(800, 450, "Internal Error");

    SetExitKey(0);
    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText(error.c_str(), GetScreenWidth() / 2 - MeasureText(error.c_str(), 20) / 2, GetScreenHeight() / 2.3 , 20, RED);
            EndDrawing();
    }
    CloseWindow();


}

