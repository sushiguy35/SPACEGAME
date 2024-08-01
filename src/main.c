#include "raylib.h"
#include "player.h"

int main(void)
{
    struct player P;
    
    InitWindow(800, 450, "GEAM");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        playerMove(&P.vy, &P.vx);
        playerUpdate(&P.vy, &P.vx, &P.x, &P.y);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(P.x, P.y, 25, 50, RED);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}