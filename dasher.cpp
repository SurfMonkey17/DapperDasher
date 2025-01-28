#include "raylib.h"

int main()
{
    const int windowWidth{1000};
    const int windowHeight{600};
    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // game logic here

        EndDrawing();
    }

    CloseWindow();
}