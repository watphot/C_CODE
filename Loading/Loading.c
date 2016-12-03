#include "raylib.h"

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
    int currentScreen = 0; 
    SetTargetFPS (60);
    
    //Fading variables
    bool fading = false; //Check for do or don't loading
    int nextScreen = 0; //Next Screen
    int framesCounter = 0; //Counter
    float alpha = 0.0f; //Degree of transparency, range 0 to 1f
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (!fading)
        {
        
            switch (currentScreen)
            {
                case 0:
                {
                    if (IsKeyPressed(KEY_ENTER)) nextScreen = 1, fading = true;
                } break;
                case 1:
                {
                    if (IsKeyPressed(KEY_ENTER)) nextScreen = 0, fading = true;
                } break;
                default:
                break;
            }
        }
        else 
        {
            framesCounter++;
            if (framesCounter < 120) alpha += 0.05f;
            else if (framesCounter == 120) currentScreen = nextScreen; //If alpha arrive at 1, change screen
            else if (framesCounter < 240) alpha -= 0.05f; //When counter arrive at 240 (2 seconds more), alpha goes to 0 again
            else fading = false, framesCounter = 0, alpha = 0.0f;  //Variable reset //Fading = False !!!
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
                switch (currentScreen)
                {
                    case 0:
                    {
                        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
                    } break;
                    case 1:
                    {
                        DrawText("Congrats! You created your first window2!", 190, 200, 20, LIGHTGRAY);
                    } break;
                    default: break;
                }
            DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, alpha));  //Square of the whole screen
            if (alpha >= 1.0f) DrawText ("Loading", screenWidth - 160, screenHeight - 50, 30, RAYWHITE); //When arrive at square we can see the loading
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}