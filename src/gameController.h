
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <SFML/Graphics.hpp>

#include "commandHandler.h"
#include "commands/moveUp.h"
#include "commands/moveDown.h"
#include "commands/paddleFactory.h"

class GameController {

public:
    GameController();
    void run();

private:
    sf::RenderWindow m_window;
    PaddleFactory m_paddleFactory;
    CommandHandler m_commandHandler;
    std::unique_ptr<Paddle> m_paddle1, m_paddle2;

    void handleCollision(sf::Sprite& sprite1, sf::Sprite& sprite2);
    void setup();
    //Paddle& paddle1, Paddle& paddle2
};

#endif // GAMECONTROLLER_H