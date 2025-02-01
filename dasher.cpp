#include "raylib.h"

int main()
{
    const int windowWidth{1000};
    const int windowHeight{600};
    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    // rectangle dimensions
    const int width{50};
    const int height{80};

    // is player in air?
    bool isInAir{};

    // jump velocity
    const int jumpVal{-22};

    int posY{windowHeight - height}; // set on ground
    int velocity{0};

    // acceleration due to gravity (pixels/frame)/frame

    const int gravity{1};

    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    Vector2 scarfyPos;

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
            isInAir = false;
        }
        else
        {
            // rectangle is in the air
            velocity += gravity;
            isInAir = true;
        }

        // jump check
        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVal;
        }

        // update position
        posY += velocity;

        DrawRectangle(windowWidth / 2, posY, width, height, BLUE);

        EndDrawing();
    }

    CloseWindow();
}