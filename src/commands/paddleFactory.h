
#ifndef PADLEFACTORY_H
#define PADLEFACTORY_H

#include "paddle.h"
#include <memory>
// enum class GameMode {
//     SinglePlayer,
//     Multiplayer
// };

class PaddleFactory {
public:




    std::unique_ptr<Paddle> createPaddle(PaddleType type);

private:
    sf::Texture m_paddleTexture1;
    sf::Texture m_paddleTexture2;
};

#endif // PADLEFACTORY_H