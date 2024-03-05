
#include "commandHandler.h"

#include <iostream> // std::cout icin eklendi

// CommandHandler::CommandHandler(Command* MoveUp1, Command* MoveDown1, Command* MoveUp2, Command* MoveDown2) : 
// buttonW(MoveUp1), buttonS(MoveDown1), buttonUp(MoveUp2), buttonDown(MoveDown2) {};

std::unique_ptr<Command> CommandHandler::createNew(CommandType command, Paddle* paddle) 
{
    if(paddle == nullptr) 
    {
        throw std::invalid_argument("Paddle is null");

    }
    
    switch(command) 
    {
        case CommandType::MOVEUP:
            return std::unique_ptr<Command>(new MoveUp(paddle));

        case CommandType::MOVEDOWN:
            return std::unique_ptr<Command>(new MoveDown(paddle));
    }

    return nullptr;
}

// void CommandHandler::onPressW() 
// {
//     buttonW->execute();
// }

// void CommandHandler::onPressS() 
// {
//     buttonS->execute();
// }

// void CommandHandler::onPressUp() 
// {
//     buttonUp->execute();
// }

// void CommandHandler::onPressDown() 
// {
//     buttonDown->execute();
// }