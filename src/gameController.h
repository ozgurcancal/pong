
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <SFML/Graphics.hpp>

#include "commands/commandHandler.h"
#include "commands/moveUp.h"
#include "commands/moveDown.h"
#include "gameObjects/gameObjectFactory.h"

class GameController {

public:
    GameController();
    void run();

private:
    sf::RenderWindow m_window;
    GameObjectFactory m_gameObjectFactory;
    CommandHandler m_commandHandler;
    std::unique_ptr<Paddle> m_paddle1, m_paddle2;
    std::unique_ptr<Ball> m_ball;

    void handleCollision(sf::Sprite& sprite1, sf::Sprite& sprite2);
    void setup();
    void setWindowPosition();
    //Paddle& paddle1, Paddle& paddle2
};

#endif // GAMECONTROLLER_H