

#include "increaseSpeed.h"

IncreaseSpeed::IncreaseSpeed(Ball *ball, Paddle *paddle) : m_ball(ball), m_paddle(paddle) {}

void IncreaseSpeed::execute()
{
    m_ball->increaseSpeed();
    m_paddle->increaseSpeed();
}