#include <cstdio>
#include <cstdlib>
#include "raylib.h"
#include "extras/raygui.h"
#include "InternalErrorHandling.hpp"
#include "Functions.hpp"
#include <iostream>
#include <filesystem>
#include "pugixml.hpp"
using namespace std;
using namespace std::filesystem;
using namespace ConsoleFunctions;
using namespace pugi;

// Declare variables
xml_document doc;
xml_parse_result result;
xml_node projectRoot = doc.child("Project");
const string projFolder = (string) getenv("USERPROFILE") + "\\ConsoleX Projects";
int currentWin = WindowTypes::LOAD_Window;
string loadedProject;

vector<string> GetDir(const string& dir) {
    vector<string> files;
    int count = 0;
    char** paths = GetDirectoryFiles(dir.c_str(), &count);
    for (int i = 0; i < count; i++)
    {
        files.emplace_back(paths[i]);
    }
    ClearDirectoryFiles();
    // remove the first 2 elements of files vector
    files.erase(files.begin());
    files.erase(files.begin());
    return files;
 }

void OpenProject(string dir) {
    currentWin = WindowTypes::MAIN_Window;
    loadedProject = "";
    result = doc.load_file((dir + "project.xml").c_str(),parse_default | parse_declaration);
}

    bool RectangleClickDetection(Rectangle rect) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), rect))
            return true;
        return false;
    }
int main() {
    cout << projectRoot.child("ProjectName").child_value()<< endl;
    // Pre Init
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);
    SetTraceLogLevel(LOG_NONE);

    // Init
    InitWindow(0, 0, "ConsoleX - The Best Console Game Engine");
    SetWindowIcon(LoadImage("icon.png"));

    // Post Init
    SetExitKey(0);
    MaximizeWindow();
    int ScreenWidth = GetMonitorWidth(GetCurrentMonitor());
    int ScreenHeight = GetMonitorHeight(GetCurrentMonitor());

    // GUI Post Init
    float offset = 0;

    // Variables Post Init
   vector<string> projFolderContents =  GetDir(projFolder);

   // This loop removes all the files that are not directories in the project folder array
    for (auto str : projFolderContents) {
        if (str.find('.') != string::npos)
            projFolderContents.erase(find(projFolderContents.begin(), projFolderContents.end(), str));

    }

    int projects = projFolderContents.size();
    printf(("The number of projects are: " + to_string(projects)).c_str());

    try {
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
                // Basic window
                case WindowTypes::NONE_Window: {
                    SetWindowTitle("ConsoleX - The Best Console Game Engine");
                    break;
                }
                // Load Projects Window
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

                    // Essentially the actual scroll box for the projects display and drawing it on the screen
                    Rectangle clipRect = {ScreenHeight * .8f,  ScreenWidth / 6.0f, ScreenWidth * 20.0f,ScreenHeight * 20.0f};
                    DrawRectangleRec(clipRect, RAYWHITE);

                    BeginScissorMode(clipRect.x, clipRect.y, clipRect.width, clipRect.height);
                    int i = 0;
                    for (const auto& project : projFolderContents) {
                        Rectangle currentProj = {clipRect.x + 2, clipRect.y - offset + i, 1000, 100};
                        // Projects display content box
                        DrawRectangleRec(currentProj,WHITE);
                        // Projects display outlines
                        DrawRectangleLines(clipRect.x + 2, clipRect.y - offset + i, 1000, 100,GRAY);
                        // Draw Project Name
                        DrawText(project.c_str(), clipRect.x + 2, clipRect.y - offset + i,20,BLACK);
                        if(RectangleClickDetection(currentProj))
                            OpenProject(projFolder + "\\" + project);

                        // Increment Position variable
                        i += 100;
                    }


                    EndScissorMode();
                    EndDrawing();
                    break;
                }
                // Game Engine Window
                case WindowTypes::MAIN_Window: {
                    SetWindowTitle(("ConsoleX - The Best Console Game Engine | "  + loadedProject).c_str());
                    break;
                }
                case WindowTypes::SETTINGS_Window: {
                    SetWindowTitle("ConsoleX - The Best Console Game Engine | Settings Window");
                    break;
                }
            }
        }
    } catch (const std::exception& e) {
        ThrowInternalError(e.what());
    }
    CloseWindow();
    return 0;
}
