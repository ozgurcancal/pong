
#include "gameObjectFactory.h"

std::shared_ptr<Paddle> GameObjectFactory::createPaddle(PaddleType type)
{
    if (type == PaddleType::BLUE)
    {
        return std::make_shared<Paddle>(m_paddleTexture1, type);
    }
    else if (type == PaddleType::RED)
    {
        return std::make_shared<Paddle>(m_paddleTexture2, type);
    }
    else
    {
        throw std::invalid_argument("Invalid paddle type");
    }
}

std::shared_ptr<Ball> GameObjectFactory::createBall()
{
    return std::make_shared<Ball>(m_ballTexture);
}