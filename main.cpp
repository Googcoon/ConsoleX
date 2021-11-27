#include <cstdio>
#include <cstdlib>
#include "raylib.h"
#include "extras/raygui.h"
#include "InternalErrorHandling.hpp"
#include "Functions.hpp"
#include <iostream>
#include <filesystem>



using namespace std::filesystem;
using namespace ConsoleFunctions;

vector<string> GetDir(const string& dir) {
    vector<string> files;
    int count = 0;
    char** paths = GetDirectoryFiles(dir.c_str(), &count);
    for (int i = 0; i < count; i++)
    {
        files.emplace_back(paths[i]);
    }
    ClearDirectoryFiles();
    return files;
 }

int main() {
    // Declare variables
    const string projFolder = (string) getenv("USERPROFILE") + "\\ConsoleX Projects";
    int currentWin = WindowTypes::LOAD_Window;

    // Pre Init
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);
    SetTraceLogLevel(LOG_NONE);

    // Init
    InitWindow(0, 0, "ConsoleX - The Best Console Game Engine");

    // Post Init
    SetExitKey(0);
    MaximizeWindow();

    // GUI Post Init
    float offset = 0;

    // Variables Post Init
    vector<string> projFolderContents = GetDir(projFolder);

    // Main Window Loop
    while (!WindowShouldClose()) {
        // Necessary code for window handling
        if (IsWindowMaximized() && IsWindowResized())
            MaximizeWindow();

        // Non-window Independent Code
        // Mouse Input Shit
        offset += GetMouseWheelMove() * 10;
        if (offset < 0)
            offset = 0;
        if (offset > 800)
            offset = 800;


        switch (currentWin) {
            case WindowTypes::NONE_Window: {
                SetWindowTitle("ConsoleX - The Best Console Game Engine");
                break;
            }
            case WindowTypes::LOAD_Window: {
                SetWindowTitle("ConsoleX - The Best Console Game Engine | Load Project");

                // If project directory container doesn't exist create one and if any errors occur it throws it to the error handler
                if (!DirectoryExists(projFolder.c_str())) {
                    bool dirError = create_directory(projFolder.c_str());
                    if (!dirError) ThrowInternalError("Could not create project directory \"" + projFolder + "\"");
                }

                // TODO make the ui scrollable on the right side of the screen and shows the directories in the projects dir
                // GUI
                BeginDrawing();

                ClearBackground(RAYWHITE);

                Rectangle clipRect = {1000, 0, GetMonitorWidth(GetCurrentMonitor()) * 20.0f, 1000000};
                DrawRectangleRec(clipRect, DARKGRAY);

                BeginScissorMode(clipRect.x, clipRect.y, clipRect.width, clipRect.height);

                for (int i = 0; i < 20000; i += 20) {
                    DrawRectangle(clipRect.x + 2, clipRect.y - offset + i, 300 + (i % 30) * 20, 100,
                                  i % 40 == 0 ? RED : GREEN);
                    DrawText(("" + to_string(i)).c_str(), clipRect.x + 2, clipRect.y - offset + i, 20, LIGHTGRAY);
                }

                EndScissorMode();
                EndDrawing();
                break;
            }
            case WindowTypes::MAIN_Window: {
                SetWindowTitle("ConsoleX - The Best Console Game Engine | Editor Window");
                break;
            }
            case WindowTypes::SETTINGS_Window: {
                SetWindowTitle("ConsoleX - The Best Console Game Engine | Settings Window");
                break;
            }
        }
    }
    CloseWindow();

    return 0;
}
