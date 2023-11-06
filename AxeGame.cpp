/*

*/
#include "raylib.h"

int main()
{
    // Initialize WIDTH and HEIGHT variables
    int width = 800;
    int height = 450;

    // Initialize Popup window with specified dimensions and title
    InitWindow(width, height, "Axe Game");

    // WindowShouldClose will return false until you hit 'ESC' or 'X' button
    while (!WindowShouldClose())
    {
        // Setup and deconstruct background color
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    return 0;
}