#ifndef MOVEUP_H
#define MOVEUP_H

#include "command.h"
#include "paddle.h"

class MoveUp : public Command {
public:
    MoveUp(Paddle* paddle);
    void execute() override;

private:
    Paddle* paddle;
};


#endif // MOVEUP_H