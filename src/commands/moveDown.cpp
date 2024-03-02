

#include "moveDown.h"


#include <iostream> // std::cout icin eklendi

MoveDown::MoveDown(Paddle* p) : paddle(p) {};

void MoveDown::execute() 
{
    paddle->moveDown(); 
}