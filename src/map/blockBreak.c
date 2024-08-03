#include "blockBreak.h"

void updateBlockBreak()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
    {
        Vector2 mousePos = GetMousePosition();
        int mouseX = (int)(mousePos.x / 20) * 20;
        int mouseY = (int)(mousePos.y / 20) * 20;

        for (int i = 0; i < blockCount; i++)
        {
            if (blocks[i].posX == mouseX && blocks[i].posY == mouseY)
            {
                // Shift all blocks after the found block to the left
                for (int j = i; j < blockCount - 1; j++)
                {
                    blocks[j] = blocks[j + 1];
                }
                blockCount--;
                break;  // Exit the loop after removing the block
            }
       }
    }
}
