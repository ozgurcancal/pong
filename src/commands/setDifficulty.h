

#ifndef SETDIFFICULTY_H
#define SETDIFFICULTY_H

#include "command.h"
#include "ball.h"
#include "paddle.h"

class SetDifficulty : public Command
{
public:
    SetDifficulty(int inputDifficulty, Ball *ball, Paddle *paddle1, Paddle *paddle2);
    void execute() override;

private:
    Ball *m_ball;
    Paddle *m_paddle1, *m_paddle2;
    int m_inputDifficulty;
};

#endif // SETDIFFICULTY_H