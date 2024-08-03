#ifndef BLOCKCREATE_H
#define BLOCKCREATE_H

#include "raylib.h"
#include <stdio.h>

#define MAX_BLOCKS 1000

enum BlockType
{
    STONE
};

struct block
{
    int posX;
    int posY;
};

extern struct block blocks[MAX_BLOCKS];
extern int blockCount;

// New declarations for drag-and-place functionality
extern bool isDragging;
extern Vector2 ghostBlockPos;

void updateDragAndPlace();
void drawBlocks();

#endif
