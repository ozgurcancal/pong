
#ifndef PADLEFACTORY_H
#define PADLEFACTORY_H

#include "paddle.h"
#include "ball.h"

#include <memory>

// enum class GameMode {
//     SinglePlayer,
//     Multiplayer
// };

class GameObjectFactory {
public:
    std::unique_ptr<Paddle> createPaddle(PaddleType type);
    std::unique_ptr<Ball> createBall();

private:
    sf::Texture m_paddleTexture1;
    sf::Texture m_paddleTexture2;
    sf::Texture m_ballTexture;
};

#endif // PADLEFACTORY_H