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

    // acceleration due to gravity (pixels/frame)/frame

    const int gravity{1};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // game logic here
        // perform ground check
        if (posY >= (windowHeight - height))
        {
            // rectangle is on the ground
            velocity = 0;
        }
        else
        {
            // rectangle is in the air
            velocity += gravity;
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            velocity -= 10;
        }

        // update position
        posY += velocity;

        DrawRectangle(windowWidth / 2, posY, width, height, BLUE);

        EndDrawing();
    }

    CloseWindow();
}