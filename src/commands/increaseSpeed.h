

#ifndef INCREASESPEED_H
#define INCREASESPEED_H

#include "command.h"
#include "ball.h"
#include "paddle.h"
#include "component.h"

#include <memory>

class IncreaseSpeed : public Command
{
public:
    IncreaseSpeed(Ball *ball, Paddle *paddle1, Paddle *paddle2);
    void execute() override;

private:
    Ball *m_ball;
    Paddle *m_paddle1, *m_paddle2;
};

#endif // INCREASESPEED_H
