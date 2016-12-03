#include "raylib.h"

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 600;
    int screenHeight = 200;

    InitWindow(screenWidth, screenHeight, "03_pause_and_reset");
    
    Vector2 ballPosition = {screenWidth/3, screenHeight/2};
    Vector2 ballSpeed = {6, 4};
    float ballRadius = 10;
    
    Rectangle rect = {450, 0, 200, 200};
    int ballX, ballY;      //Velocidad que nos servira para poder volverle a dar la velocidad original
    
    bool pause = false;            
    
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        
        // COLLISIONS        
            ballPosition.x += ballSpeed.x;
            ballPosition.y += ballSpeed.y;
 
            if ((ballPosition.x - ballRadius) < 0) ballSpeed.x *= -1;            
            if ((ballPosition.y + ballRadius) > screenHeight) ballSpeed.y *= -1;
            else if ((ballPosition.y - ballRadius) < 0) ballSpeed.y *= -1;
            if(CheckCollisionCircleRec(ballPosition, ballRadius, rect)) ballSpeed.x *= -1;
        // Pause
            if(IsKeyPressed('P'))
            {
                pause = !pause;
                    if(pause == true)
                    {
                        ballX = ballSpeed.x;
                        ballY = ballSpeed.y; 
                        ballSpeed.x = 0;
                        ballSpeed.y = 0;
                    }
                    else ballSpeed.x = ballX, ballSpeed.y = ballY;
            }
            // RESET
            
            if(IsKeyPressed('R')) ballPosition.x = screenWidth/3, ballPosition.y = screenHeight/2;
            
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(LIGHTGRAY);

            DrawRectangleRec(rect, RAYWHITE);
            DrawText("Exercise 03 - pause and reset", 10, 10, 5, DARKGRAY);
            DrawText("[P] PAUSE", 470, 20, 20, BLACK);
            DrawText("[R] RESET", 470, 50, 20, BLACK);
            DrawText("[ESC] EXIT", 470, 80, 20, BLACK);
            
            DrawCircleV(ballPosition, ballRadius, MAROON);
            
            if(pause == true) DrawText("GAME PAUSED", 140, 90, 20, BLACK);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}