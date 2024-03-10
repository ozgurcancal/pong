

#include "setDifficulty.h"

SetDifficulty::SetDifficulty(int inputDifficulty, Ball *ball, Paddle *paddle1, Paddle *paddle2)
    : m_inputDifficulty(inputDifficulty), m_ball(ball), m_paddle1(paddle1), m_paddle2(paddle2)
{
}

void SetDifficulty::execute()
{
    m_ball->setDifficulty(m_inputDifficulty);
    m_paddle1->setDifficulty(m_inputDifficulty);
    m_paddle2->setDifficulty(m_inputDifficulty);
}
