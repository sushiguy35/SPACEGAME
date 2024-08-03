#include "raylib.h"
#include "player.h"
#include "map/blockBreak.h"
#include "map/blockCreate.h"

int main(void)
{
    struct player P;
    
    InitWindow(800, 450, "GEAM");
    SetTargetFPS(60);
    SetExitKey(KEY_F12);    // Set a custom key to exit program (default is ESC)

    while (!WindowShouldClose())
    {
        playerMove(&P.vy, &P.vx);
        playerUpdate(&P.vy, &P.vx, &P.x, &P.y);
        updateDragAndPlace();  // Replace createBlock() with updateDragAndPlace()
        updateBlockBreak();    // Add block breaking functionality

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(P.x, P.y, 25, 50, RED);
            drawBlocks();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
