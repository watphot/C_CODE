#include "raylib.h"

typedef enum {AzulC, Azul, VerdeC, Verde} GameScreen;

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 200;
    int screenHeight = 500;

    InitWindow(screenWidth, screenHeight, "Exercise 02 - Moving bar");
    
    GameScreen currentScreen = AzulC;
    
    // Player 1
    Vector2 playerSize = {20, 60};
    Vector2 playerPosition = {screenWidth/2 - 10, screenHeight/2 - 30};
    Vector2 playerSpeed = {0, 5};
    
    //Player 2
    int sX = playerSize.x;
    int sY = playerSize.y;
    int pX = playerPosition.x;
    int pY = playerPosition.y;
    int spY = playerSpeed.y;
    
    SetTargetFPS (60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        switch (currentScreen)
        {
            case AzulC:
            {                
                playerPosition.y +=  playerSpeed.y;                
                if ((playerPosition.y + playerSize.y) >= 400) playerSpeed.y *= -1, currentScreen = VerdeC;
                else if ((playerPosition.y + playerSize.y) <= 160) playerSpeed.y *= -1, currentScreen = VerdeC; 
                
                if (IsKeyPressed(32)) sY = playerSize.y, pY = playerPosition.y, spY = playerSpeed.y, currentScreen = Azul;                
            } break;
            case Azul:
            {
                pY +=  spY;                
                if ((pY + sY) <= 160) spY *= -1, currentScreen = Verde;
                else if ((pY + sY) >= 400) spY *= -1, currentScreen = Verde;
                
                if (IsKeyPressed(32)) playerSize.y = sY, playerPosition.y = pY, playerSpeed.y = spY, currentScreen = AzulC;                
            } break;
            case VerdeC:
            {                
                playerPosition.y +=  playerSpeed.y;                
                if ((playerPosition.y + playerSize.y) >= 400) playerSpeed.y *= -1, currentScreen = AzulC;
                else if ((playerPosition.y + playerSize.y) <= 160) playerSpeed.y *= -1, currentScreen = AzulC;
                
                if (IsKeyPressed(32)) sY = playerSize.y, pY = playerPosition.y, spY = playerSpeed.y, currentScreen = Verde;
            } break;
            case Verde:
            {
                pY +=  spY;                
                if ((pY + sY) >= 400) spY *= -1, currentScreen = Azul;
                else if ((pY + sY) <= 160) spY *= -1, currentScreen = Azul;
                
                if (IsKeyPressed(32)) playerSize.y = sY, playerPosition.y = pY, playerSpeed.y = spY, currentScreen = VerdeC;
            } break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
        if (currentScreen == AzulC)
        {
            ClearBackground (WHITE);
            
            DrawRectangle(0, 0, 200, 100, BLUE);

            DrawText("Exercise 02 - Moving bar", 10, 10, 10, WHITE);
            
            DrawRectangle(0, 400, 200, 100, GREEN);
            
            DrawText("PRESS SPACE", 65, 420, 10, WHITE);
            
            DrawRectangleV(playerPosition, playerSize, BLUE);
            
        }
        
        else if (currentScreen == Azul)
        {
            ClearBackground (WHITE);
            
            DrawRectangle(0, 0, 200, 100, BLUE);

            DrawText("Exercise 02 - Moving bar", 10, 10, 10, WHITE);
            
            DrawRectangle(0, 400, 200, 100, GREEN);
            
            DrawText("PRESS SPACE", 65, 420, 10, WHITE);
            
            DrawRectangleLines (pX, pY, sX, sY, BLUE);
            
        }
        
        else if (currentScreen == VerdeC)
        {
            ClearBackground (WHITE);
            
            DrawRectangle(0, 0, 200, 100, BLUE);

            DrawText("Exercise 02 - Moving bar", 10, 10, 10, WHITE);
            
            DrawRectangle(0, 400, 200, 100, GREEN);
            
            DrawText("PRESS SPACE", 65, 420, 10, WHITE);
            
            DrawRectangleV(playerPosition, playerSize, GREEN);
        }
        
        else if (currentScreen == Verde)
        {
            ClearBackground (WHITE);
            
            DrawRectangle(0, 0, 200, 100, BLUE);

            DrawText("Exercise 02 - Moving bar", 10, 10, 10, WHITE);
            
            DrawRectangle(0, 400, 200, 100, GREEN);
            
            DrawText("PRESS SPACE", 65, 420, 10, WHITE);
            
            DrawRectangleLines (pX, pY, sX, sY, GREEN);
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}