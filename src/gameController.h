
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

    void handleCollision(sf::Sprite& ps1, sf::Sprite& ps2, sf::Sprite& pb);
    void setup();
    void setWindowPosition();
};

#endif // GAMECONTROLLER_H