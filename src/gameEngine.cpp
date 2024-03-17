
#include "gameEngine.h"
#include "screenManager.h"

GameEngine::GameEngine() : m_window(sf::VideoMode(800, 600), "Pong Game")
{
    m_inputController = std::make_unique<InputController>(m_window);
}

// the three main stages of the game loop
// while (IsRunning) {
//     ProcessInput(); // if any
//     UpdateGame();
//     Draw();
// }
void GameEngine::run()
{
    setup();

    while (m_window.isOpen())
    {
        m_inputController->handleInput(m_window);
        m_inputController->draw(m_window);
    }
}

void GameEngine::setup()
{
    setWindowPosition();
}

void GameEngine::setWindowPosition()
{
    // Get the desktop mode to access the screen resolution
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    // Calculate the window position to center it
    unsigned int posX = (desktop.width / 2) - (m_window.getSize().x / 2);
    unsigned int posY = (desktop.height / 2) - (m_window.getSize().y / 2);

    // Set the window position
    m_window.setPosition(sf::Vector2i(posX, posY));
}
