

#ifndef INCREASESPEED_H
#define INCREASESPEED_H

#include "command.h"
#include "ball.h"
#include "paddle.h"

class IncreaseSpeed : public Command
{
public:
    IncreaseSpeed(Ball *ball, Paddle *paddle);
    void execute() override;

private:
    Ball *m_ball;
    Paddle *m_paddle;
};

#endif // INCREASESPEED_H
