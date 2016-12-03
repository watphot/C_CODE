#include "raylib.h"

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Exercice 01 - Bouncing ball");
    
    // Ball variables definitions
    Vector2 ballPosition = { screenWidth/2, screenHeight/2};
    Vector2 ballSpeed = {6, 4};
    float ballRadius = 20;
    
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        
        // Ball logic
            ballPosition.x += ballSpeed.x;
            ballPosition.y += ballSpeed.y;
            
            if (((ballPosition.x + ballRadius) > screenWidth) || ((ballPosition.x - ballRadius < 0))) ballSpeed.x *= -1;
            if (((ballPosition.y + ballRadius) > screenHeight) || ((ballPosition.y - ballRadius < 0))) ballSpeed.y *= -1;
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawCircleV(ballPosition, ballRadius, RED);             
            DrawText("Exercice 01 - Bouncing ball", 10, 10, 5, GRAY);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}