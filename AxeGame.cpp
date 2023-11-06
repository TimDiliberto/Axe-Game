/*

*/
#include "raylib.h"

int main()
{
    // Initialize window dimensions WIDTH and HEIGHT
    int width{1600};
    int height{900};
    InitWindow(width, height, "Axe Game");

    // Initialize circle data
    int centerX = 800;
    int centerY = 450;
    float radius = 50.0;

    // Ideal frames per second
    SetTargetFPS(60);

    // WindowShouldClose() will return false until you hit 'ESC' or 'X' button
    while (!WindowShouldClose())
    {
        // Setup window data
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw centered circle and initialize movement SPEED
        DrawCircle(centerX, centerY, radius, BLUE);
        float speed = 10.0;

        // Move circle smoothly with WASD and add barrier
        if (IsKeyDown(KEY_W) && centerY > 0 + radius)
            { centerY = centerY - speed;}
        if (IsKeyDown(KEY_A) && centerX > 0 + radius)
            { centerX = centerX - speed;}
        if (IsKeyDown(KEY_S) && centerY < height - radius)
            { centerY = centerY + speed;}
        if (IsKeyDown(KEY_D) && centerX < width - radius)
            { centerX = centerX + speed;}

        // Deconstruct window data
        EndDrawing();
    }

    return 0;
}