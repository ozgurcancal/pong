


#include "moveBall.h"


MoveBall::MoveBall(Ball* p) : m_ball(p) {};

void MoveBall::execute() 
{
    m_ball->move();
}