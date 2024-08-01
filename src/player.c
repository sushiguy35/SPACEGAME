#include "player.h"

int playerMove(int *vy, int *vx)
{
    if (IsKeyDown(KEY_W))  vy++;
    if (IsKeyDown(KEY_S))  vy--;
    if (IsKeyDown(KEY_A))  vx--;
    if (IsKeyDown(KEY_D))  vx++;

    return 0;
}

int playerUpdate(int *vy, int *vx, int *x, int *y)
{
    *x += *vx;
    *y += *vy;
    return 0;
}
