

#include "screenManager.h"

#include <mutex>

ScreenManager::ScreenManager(sf::RenderWindow &window)
{
    m_screens["MenuScreen"] = std::make_unique<MenuScreen>();
    m_screens["GameScreen"] = std::make_unique<GameScreen>();

    m_currentScreen = "MenuScreen";

    // createi constructora tasi menuScreen ve gameScreen icindeki
    m_screens[m_currentScreen]->createScreen(window);
    m_screens[m_currentScreen]->draw(window);
    // m_Screens["GameOverScreen"] = std::make_unique<GameOverScreen>();
}

void ScreenManager::switchScreen(const std::string &screenName, sf::RenderWindow &window)
{
    m_currentScreen = screenName;

    m_screens[screenName]->createScreen(window);
    m_screens[screenName]->updateScreen(window);
    m_screens[screenName]->draw(window);
}
