#include "player.h"

#define FRICTION 0.9  // Friction coefficient, adjust as needed
#define MAXSPEED 4    // Max speed which the player can move

int playerMove(int *vy, int *vx)
{
    if (IsKeyDown(KEY_W))  (*vy)--;
    if (IsKeyDown(KEY_S))  (*vy)++;
    if (IsKeyDown(KEY_A))  (*vx)--;
    if (IsKeyDown(KEY_D))  (*vx)++;

    // Apply friction when no keys are pressed
    if (!IsKeyDown(KEY_W) && !IsKeyDown(KEY_S)) *vy *= FRICTION;
    if (!IsKeyDown(KEY_A) && !IsKeyDown(KEY_D)) *vx *= FRICTION;

    if (IsKeyDown(KEY_W) && IsKeyDown(KEY_S)) *vy *= 0;
    if (IsKeyDown(KEY_A) && IsKeyDown(KEY_D)) *vx *= 0;

    return 0;
}

int playerUpdate(int *vy, int *vx, int *x, int *y)
{
    if (*vx > MAXSPEED) *vx = MAXSPEED;         // Limit the speed on positive X axis
    if (*vx < -MAXSPEED) *vx = -MAXSPEED;       
    if (*vy > MAXSPEED) *vy = MAXSPEED;
    if (*vy < -MAXSPEED) *vy = -MAXSPEED;

    *x += *vx;
    *y += *vy;
    return 0;
}
