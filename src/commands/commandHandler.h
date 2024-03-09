#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "command.h"
#include "moveUp.h"
#include "moveDown.h"
#include "moveBall.h"

#include "component.h"
#include "paddle.h"
#include "ball.h"

#include <memory>

enum class CommandType : int
{
    MOVE = 1,
    MOVEUP = 2,
    MOVEDOWN = 3,
    INCREASESPEED = 4,
    DECREASESPEED = 5,
};

class CommandHandler
{
public:
    std::unique_ptr<Command> createNew(CommandType group, Paddle *paddle);
    std::unique_ptr<Command> createNew(CommandType group, Ball *ball);
};

//  std::unique_ptr<Command> createNew(CommandType group, Component* ball);

#endif // COMMANDHANDLER_H