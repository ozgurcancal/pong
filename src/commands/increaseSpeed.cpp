

#include "increaseSpeed.h"

IncreaseSpeed::IncreaseSpeed(Ball *ball, Paddle *paddle1, Paddle *paddle2) : m_ball(ball), m_paddle1(paddle1), m_paddle2(paddle2) {}

void IncreaseSpeed::execute()
{
    m_ball->increaseSpeed();
    m_paddle1->increaseSpeed();
    m_paddle2->increaseSpeed();
}