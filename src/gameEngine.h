
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <SFML/Graphics.hpp>

#include "commands/commandHandler.h"
#include "commands/moveUp.h"
#include "commands/moveDown.h"
#include "gameObjects/gameObjectFactory.h"

#include "screenController.h"

class GameEngine {

public:
    GameEngine();
    void run();
   // void menu();

private:
    sf::RenderWindow m_window;
    GameObjectFactory m_gameObjectFactory;
    CommandHandler m_commandHandler;
    std::unique_ptr<ScreenController> m_screenController;
    std::unique_ptr<Paddle> m_paddle1, m_paddle2;
    std::unique_ptr<Ball> m_ball;

    //void handleCollision(sf::Sprite& ps1, sf::Sprite& ps2, sf::Sprite& pb);
    void setup();
    void setWindowPosition();
};

#endif // GAMECONTROLLER_H