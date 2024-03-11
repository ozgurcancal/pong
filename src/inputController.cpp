
#include "inputController.h"
#include "gameObjectFactory.h"

InputController::InputController(sf::RenderWindow &window)
{
    m_screenManager = std::make_unique<ScreenManager>(window);
}

void InputController::handleInput(sf::RenderWindow &window)
{
    m_screenManager->handleInput(window);
}

void InputController::draw(sf::RenderWindow &window)
{
    m_screenManager->draw(window);
}
