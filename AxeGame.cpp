/*

*/
#include "raylib.h"

int main()
{
    // Initialize window dimensions WIDTH and HEIGHT
    int winWidth{1600};
    int winHeight{900};
    InitWindow(winWidth, winHeight, "Axe Game");

    // Initialize physics variables
    float gravity = 9.81;

    // Initialize circle data
    int circleX = 400;
    int circleY = 400;
    float radius = 50.0;
    float speed = 10.0;

    // Initialize axe data
    int axeX = 300;
    int axeY = 0;
    int axeWidth = 50;
    int axeHeight = 50;
    float axeMass = 1.0;

    // Ideal frames per second
    SetTargetFPS(60);

    // WindowShouldClose() will return false until you hit 'ESC' or 'X' button
    while (!WindowShouldClose())
    {
        // Setup window data
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw shapes
        DrawCircle(circleX, circleY, radius, BLUE);
        DrawRectangle(axeX, axeY, axeWidth, axeHeight, RED);
        //DrawRectangle(axeX+200, axeY, axeWidth, axeHeight, BROWN);

        // Move the axe
        axeY += axeMass * gravity;
        if (axeY >= (900-axeHeight) || axeY <= 0) { axeMass = -axeMass; }

        // Move circle smoothly with WASD and add barrier
        if (IsKeyDown(KEY_W) && circleY > 0 + radius)
            { circleY -= speed;}
        if (IsKeyDown(KEY_A) && circleX > 0 + radius)
            { circleX -= speed;}
        if (IsKeyDown(KEY_S) && circleY < winHeight - radius)
            { circleY += speed;}
        if (IsKeyDown(KEY_D) && circleX < winWidth - radius)
            { circleX += speed;}

        // Deconstruct window data
        EndDrawing();
    }

    return 0;
}