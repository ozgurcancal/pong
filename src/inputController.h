

#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include "commands/commandHandler.h"
#include "gameObjects/gameObjectFactory.h"
#include "screens/screenManager.h"

class InputController
{
public:
    InputController(sf::RenderWindow &window);

    void handleInput(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
    void menu(sf::RenderWindow &window);

private:
    CommandHandler m_commandHandler;
    std::unique_ptr<ScreenManager> m_screenManager;
};

#endif // INPUTCONTROLLER_H