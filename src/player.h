#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

struct player
{
    int x;
    int y;
    int vx;
    int vy;
};
int playerMove(int *vy, int *vx);
int playerUpdate(int *vy, int *vx, int *x, int *y);

#endif