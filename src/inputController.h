

#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include "commands/commandHandler.h"
#include "gameObjects/gameObjectFactory.h"
#include "screens/screenManager.h"

class InputController
{
public:
    InputController(sf::RenderWindow &window);
    ~InputController();

    void handleInput(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);

private:
    std::unique_ptr<ScreenManager> m_screenManager;
};

#endif // INPUTCONTROLLER_H