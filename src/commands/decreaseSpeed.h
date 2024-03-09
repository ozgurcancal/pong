

#ifndef DECREASESPEED_H
#define DECREASESPEED_H

#include "command.h"
#include "ball.h"
#include "paddle.h"

class DecreaseSpeed : public Command
{
public:
    DecreaseSpeed(Ball *ball, Paddle *paddle);
    void execute() override;

private:
    Ball *m_ball;
    Paddle *m_paddle;
};

#endif // DECREASESPEED_H