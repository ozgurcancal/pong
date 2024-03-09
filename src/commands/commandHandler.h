#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "command.h"
#include "moveUp.h"
#include "moveDown.h"
#include "moveBall.h"
#include "setSpeed.h"

#include "component.h"
#include "paddle.h"
#include "ball.h"

#include <memory>

enum class CommandType : int
{
    MOVE = 1,
    MOVEUP = 2,
    MOVEDOWN = 3,
    SETSPEED = 4,
};

class CommandHandler
{
public:
    std::unique_ptr<Command> createNew(CommandType group, Paddle *paddle);
    std::unique_ptr<Command> createNew(CommandType group, Ball *ball);
    std::unique_ptr<Command> createNew(CommandType group, float inSpeed, Ball *ball, Paddle *paddle1, Paddle *paddle2);
};

//  std::unique_ptr<Command> createNew(CommandType group, Component* ball);

#endif // COMMANDHANDLER_H