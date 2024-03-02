
#include "inputHandler.h"

#include <iostream> // std::cout icin eklendi

InputHandler::InputHandler(Command* MoveUp, Command* MoveDown) : buttonW(MoveUp), buttonS(MoveDown) {};

void InputHandler::onPressW() 
{
    buttonW->execute();
}

void InputHandler::onPressS() 
{
    buttonS->execute();
}