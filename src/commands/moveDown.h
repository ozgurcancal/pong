#ifndef MOVEDOWN_H
#define MOVEDOWN_H


#include "command.h"
#include "paddle.h"


class MoveDown : public Command{
public:
    MoveDown(Paddle* paddle);
    void execute() override;

private:
    Paddle* paddle;
};


#endif // MOVEDOWN_H