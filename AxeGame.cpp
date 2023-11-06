/*

*/
#include "raylib.h"

int main()
{
    // Initialize WIDTH and HEIGHT variables
    int width = 1600;
    int height = 900;

    // Initialize Popup window with specified dimensions and title
    InitWindow(width, height, "Axe Game");

    // WindowShouldClose will return false until you hit 'ESC' or 'X' button
    while (!WindowShouldClose())
    {
        // Setup and deconstruct background color
        BeginDrawing();
        ClearBackground(BLACK);
        // Draw centered circle
        DrawCircle(800, 450, 50, BLUE);
        EndDrawing();
    }

    return 0;
}