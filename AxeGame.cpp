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
    float gravity{9.81};

    // Initialize circle data
    int circleX{800};
    int circleY{800};
    int circleRadius{50};
    float circleSpeed{10.0};
    // circle edges
    int l_circleX{circleX - circleRadius};
    int r_circleX{circleX + circleRadius};
    int u_circleY{circleY - circleRadius};
    int b_circleY{circleY + circleRadius};

    // Initialize axe data
    int axeX{300};
    int axeY{0};
    int axeLength{50};
    float axeMass{1.0};
    // axe edges
    int l_axeX{axeX};
    int r_axeX{axeX + axeLength};
    int u_axeY{axeY};
    int b_axeY{axeY + axeLength};

    // Initialize game variables
    bool collisionWithAxe {
        b_axeY >= u_circleY &&
        u_axeY <= b_circleY &&
        l_axeX <= r_circleX &&
        r_axeX >= l_circleX };
    int textX{605};
    int textY{419};
    int textSize{69};

    // Ideal frames per second
    SetTargetFPS(60);

    // WindowShouldClose() will return false until you hit 'ESC' or 'X' button
    while (!WindowShouldClose())
    {
        // Setup window data
        BeginDrawing();
        ClearBackground(BLACK);

        if (collisionWithAxe)
            { DrawText("Game Over!", textX, textY, textSize, RED); }
        else 
        {
            // update edges
            l_circleX = circleX - circleRadius;
            r_circleX = circleX + circleRadius;
            u_circleY = circleY - circleRadius;
            b_circleY = circleY + circleRadius;
            
            l_axeX = axeX;
            r_axeX = axeX + axeLength;
            u_axeY = axeY;
            b_axeY = axeY + axeLength;

            // update collisionWithAxe
            collisionWithAxe =
                b_axeY >= u_circleY &&
                u_axeY <= b_circleY &&
                l_axeX <= r_circleX &&
                r_axeX >= l_circleX;
            // Draw shapes
            DrawCircle(circleX, circleY, circleRadius, BLUE);
            DrawRectangle(axeX, axeY, axeLength, axeLength, RED);
            //DrawRectangle(axeX+200, axeY, axeLength, axeLength, BROWN);

            // Move the axe with window collision
            axeY += axeMass * gravity;
            if (axeY >= (winHeight-axeLength) || axeY <= 0) { axeMass = -axeMass; }

            // Move circle smoothly with WASD and add window collision
            if (IsKeyDown(KEY_W) && circleY > 0 + circleRadius)
                { circleY -= circleSpeed;}
            if (IsKeyDown(KEY_A) && circleX > 0 + circleRadius)
                { circleX -= circleSpeed;}
            if (IsKeyDown(KEY_S) && circleY < winHeight - circleRadius)
                { circleY += circleSpeed;}
            if (IsKeyDown(KEY_D) && circleX < winWidth - circleRadius)
                { circleX += circleSpeed;}
        }

        // Deconstruct window data
        EndDrawing();
    }

    return 0;
}