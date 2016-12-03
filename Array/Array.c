#include "raylib.h"
#define MAX_ENEMIES 50

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
    Rectangle enemies[MAX_ENEMIES];
    
    for (int i = 0; i < MAX_ENEMIES; i++) //Array for instantiate differents enemies in differents positions.
    {
        enemies[i].x = GetRandomValue(screenWidth, screenWidth*2);
        enemies[i].y = GetRandomValue(0, screenHeight);
        enemies[i].width = 10;
        enemies[i].height = 10;
    }
    
    Rectangle player = {10, screenHeight/2, 20, 20};
    int counter = 0;
    bool gameOver = false;
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if(!gameOver)
        {
            for(int i = 0; i < MAX_ENEMIES; i++)
            {
                enemies[i].x -= 4;
                
                if(enemies[i].x < 0) enemies [i].x = GetRandomValue(screenWidth, screenHeight*2);
                
                if(CheckCollisionRecs(player, enemies[i])) gameOver = true;
                
            }
            //PLAYER
            if (IsKeyDown(KEY_UP)) player.y -= 6;
            else if (IsKeyDown(KEY_DOWN)) player.y += 6;
            
            if (player.y < 0) player.y = 0;
            else if ((player.y + player.height) > screenHeight) player.y = screenHeight - player.height;
            //
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            for(int i = 0; i < MAX_ENEMIES; i++)
            {
                DrawRectangleRec(enemies[i], RED);
            }
            DrawRectangleRec(player, BLACK);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}