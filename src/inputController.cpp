
#include "inputController.h"
#include "gameObjectFactory.h"

InputController::InputController(sf::RenderWindow &window)
{
    std::cout << "in screencontroller\n";
    m_screenManager = std::make_unique<ScreenManager>(window);
}

void InputController::handleInput(sf::RenderWindow &window)
{
    m_screenManager->handleInput(window);
}

void InputController::draw(sf::RenderWindow &window)
{
    std::cout << "in draw\n";
    m_screenManager->draw(window);
}
