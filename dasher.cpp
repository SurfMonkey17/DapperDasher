#include "raylib.h"

int main()
{
    const int windowWidth{1000};
    const int windowHeight{600};
    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    // rectangle dimensions
    const int width{50};
    const int height{80};

    int posY{windowHeight - height}; // set on ground
    int velocity{0};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // game logic here
        if (IsKeyPressed(KEY_SPACE))
        {
            velocity -= 10;
        }

        posY += velocity;

        DrawRectangle(windowWidth / 2, posY, width, height, BLUE);

        EndDrawing();
    }

    CloseWindow();
}