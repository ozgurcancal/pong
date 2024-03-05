
#ifndef MOVEBALL_H
#define MOVEBALL_H

#include "command.h"
#include "ball.h"


class MoveBall : public Command{
public:
    MoveBall(Ball* ball);
    void execute() override;

private:
    Ball* m_ball;
};

#endif // MOVEBALL_H