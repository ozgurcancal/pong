
#include "paddleFactory.h"

std::unique_ptr<Paddle> PaddleFactory::createPaddle(PaddleType type)
{
    if(type == PaddleType::Blue){
        return std::make_unique<Paddle>(m_paddleTexture1, type);
    }
    else if(type == PaddleType::Red){
        return std::make_unique<Paddle>(m_paddleTexture2, type);
    }
    else{
        throw std::invalid_argument("Invalid paddle type");
    }
    
}