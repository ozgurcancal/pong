#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "commands/command.h"
#include "commands/moveUp.h"
#include "commands/moveDown.h"
#include "gameObjects/paddle.h"

#include <memory>

enum class CommandType : int {
    MOVEUP = 1,
    MOVEDOWN = 2,

};


class CommandHandler {
public:
    //CommandHandler(Command* MoveUp1, Command* MoveDown1, Command* MoveUp2, Command* MoveDown2);
   // CommandHandler ch;

    std::unique_ptr<Command> createNew(CommandType group, Paddle* paddle);
 
    void onPressW();
    void onPressS();
    void onPressUp();
    void onPressDown();

private:
    Command* buttonW;
    Command* buttonS;
    Command* buttonUp;
    Command* buttonDown;
};



#endif // COMMANDHANDLER_H