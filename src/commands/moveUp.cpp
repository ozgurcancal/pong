

#include "moveUp.h"

MoveUp::MoveUp(Paddle* p) : paddle(p) {};

void MoveUp::execute() 
{
    paddle->moveUp();
}