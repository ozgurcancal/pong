#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "command.h"
#include "moveUp.h"
#include "moveDown.h"
#include "paddle.h"

#include <memory>

enum class CommandType : int {
    MOVEUP = 1,
    MOVEDOWN = 2,
};


class CommandHandler {
public:
    std::unique_ptr<Command> createNew(CommandType group, Paddle* paddle);
};



#endif // COMMANDHANDLER_H