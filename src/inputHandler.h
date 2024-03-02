#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "commands/command.h"

class InputHandler {
public:
    InputHandler(Command* MoveUp, Command* MoveDown);
    
    void onPressW();
    void onPressS();

private:
    Command* buttonW;
    Command* buttonS;
};



#endif // INPUTHANDLER_H