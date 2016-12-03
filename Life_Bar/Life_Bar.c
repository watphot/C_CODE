#include "raylib.h" // ctrl f para sustituir cosikas

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 600;
    int screenHeight = 220;

    InitWindow(screenWidth, screenHeight, "Exercise 04 - Life bar");
    
    Rectangle rojo = {60, 60, 490, 95};
    Rectangle negro = {55, 55, 500, 105};
    Rectangle amarillo = {60, 60, 310, 95};
    
    int desdibujado = -1;
    int pantalla = 0; //0 = title screen,  1 = you are wining, 2 = you are loosing, 3 = you win, 4 = you lose
    
    SetTargetFPS (60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if(IsKeyPressed(KEY_SPACE)) amarillo.width += 9, amarillo.width += desdibujado;
        if((amarillo.width < 370) && (amarillo.width > 150)) pantalla = 0, amarillo.width += desdibujado;
        if(amarillo.width >= 370) pantalla = 1, amarillo.width += desdibujado;
        if((amarillo.width <= 150) && (amarillo.width > 0)) pantalla = 2, amarillo.width += desdibujado;
        if(amarillo.width <= 0) pantalla = 4, amarillo.width += desdibujado;
        if(amarillo.width >= 490) pantalla = 3, amarillo.width = 490, desdibujado = 0;
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
        DrawText("Exercise 04 - Life bar", 10, 10, 8, GRAY); 
        DrawRectangleRec(negro, BLACK);
        DrawRectangleRec(rojo, RED);
        DrawRectangleRec(amarillo, GOLD);

        if (pantalla == 0) DrawText("QUICKLY! PUSH SPACE!!!", 180, 185, 20, LIGHTGRAY), DrawText("Go! Go! Go!", 250, 20, 20, BLACK);  
        else if (pantalla == 1) DrawText("QUICKLY! PUSH SPACE!!!", 180, 185, 20, LIGHTGRAY), DrawText("Almost there!", 250, 20, 20, BLACK);
        else if (pantalla == 2) DrawText("QUICKLY! PUSH SPACE!!!", 180, 185, 20, LIGHTGRAY), DrawText("Ouch!", 275, 20, 20, BLACK);
        else if (pantalla == 4) DrawText("YOU LOSE...", 250, 100, 20, BLACK);
        else if (pantalla == 3) DrawRectangleRec(amarillo, LIME), DrawText("YOU WIN!", 270, 100, 20, BLACK);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}