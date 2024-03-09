

#include "setSpeed.h"

SetSpeed::SetSpeed(int inputSpeed, Ball *ball, Paddle *paddle1, Paddle *paddle2) : m_inputSpeed(inputSpeed), m_ball(ball), m_paddle1(paddle1), m_paddle2(paddle2) {}

void SetSpeed::execute()
{
    m_ball->setSpeed(m_inputSpeed);
    m_paddle1->setSpeed(m_inputSpeed);
    m_paddle2->setSpeed(m_inputSpeed);
}