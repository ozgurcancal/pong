
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <SFML/Graphics.hpp>

#include "commands/commandHandler.h"
#include "commands/moveUp.h"
#include "commands/moveDown.h"
#include "gameObjects/gameObjectFactory.h"

#include "inputController.h"

class GameEngine
{
public:
    GameEngine();
    ~GameEngine();
    void run();

private:
    sf::RenderWindow m_window;
    std::unique_ptr<InputController> m_inputController;

    void setup();
    void setWindowPosition();
};

#endif // GAMECONTROLLER_H