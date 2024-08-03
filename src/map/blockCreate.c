#include "blockCreate.h"
#include <stdlib.h>
#include <stdio.h>

struct block blocks[MAX_BLOCKS];
int blockCount = 0;

// New variables for drag-and-place
bool isDragging = false;
Vector2 ghostBlockPos = {0, 0};

void updateDragAndPlace()
{
    Vector2 mousePos = GetMousePosition();
    
    // Start dragging
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        isDragging = true;
    }
    
    // Update ghost block position while dragging
    if (isDragging)
    {
        ghostBlockPos.x = (int)(mousePos.x / 20) * 20;
        ghostBlockPos.y = (int)(mousePos.y / 20) * 20;
    }
    
    // Place block when mouse is released
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && isDragging)
    {
        if (blockCount < MAX_BLOCKS)
        {
            blocks[blockCount].posX = ghostBlockPos.x;
            blocks[blockCount].posY = ghostBlockPos.y;
            blockCount++;
        }
        isDragging = false;
    }
}

void drawBlocks()
{
    Color stone = {128, 128, 128, 255};  // Gray color
    for (int i = 0; i < blockCount; i++)
    {
        DrawRectangle(blocks[i].posX, blocks[i].posY, 20, 20, stone);
    }
    
    // Draw ghost block while dragging
    if (isDragging)
    {
        Color ghostColor = {128, 128, 128, 128};  // Semi-transparent gray
        DrawRectangle(ghostBlockPos.x, ghostBlockPos.y, 20, 20, ghostColor);
    }
}
