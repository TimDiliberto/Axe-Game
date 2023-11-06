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

    while (true)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    return 0;
}