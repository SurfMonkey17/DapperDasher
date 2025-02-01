#include "raylib.h"

int main()
{
    const int windowWidth{1000};
    const int windowHeight{600};
    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    // is player in air?
    bool isInAir{};

    // jump velocity
    const int jumpVal{-22};

    int velocity{0};

    // acceleration due to gravity (pixels/frame)/frame

    const int gravity{1};

    Texture2D scarfy = LoadTexture("dapper-dasher-master-textures/textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width / 6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth / 2 - scarfyRec.width / 2;
    scarfyPos.y = windowHeight - scarfyRec.height;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // game logic here
        // perform ground check
        if (scarfyPos.y >= (windowHeight - scarfyRec.height))
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
        scarfyPos.y += velocity;

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

        EndDrawing();
    }

    CloseWindow();
}