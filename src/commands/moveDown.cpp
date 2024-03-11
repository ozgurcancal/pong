

#include "moveDown.h"

MoveDown::MoveDown(Paddle *p) : paddle(p){};

void MoveDown::execute()
{
    paddle->moveDown();
}