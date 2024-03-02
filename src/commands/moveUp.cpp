

#include "moveUp.h"

#include <iostream> // std::cout icin eklendi

MoveUp::MoveUp(Paddle* p) : paddle(p) {};

void MoveUp::execute() 
{
    paddle->moveUp();
}