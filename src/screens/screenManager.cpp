

#include "screenManager.h"

#include <mutex>

ScreenManager::ScreenManager(sf::RenderWindow &window)
{
    std::cout << "in createScreen\n";
    m_paddle1 = m_gameObjectFactory.createPaddle(PaddleType::Blue);
    m_paddle2 = m_gameObjectFactory.createPaddle(PaddleType::Red);
    m_ball = m_gameObjectFactory.createBall();

    m_paddle1->setPosition(window, PaddlePosition::Left);
    m_paddle2->setPosition(window, PaddlePosition::Right);

    m_ball->setPosition(window);
    m_commandHandler = std::make_shared<CommandHandler>();

    m_screens["MenuScreen"] = std::make_unique<MenuScreen>(window);
    m_screens["OptionsScreen"] = std::make_unique<OptionsScreen>(window, m_paddle1, m_paddle2, m_ball, m_commandHandler);
    m_screens["GameScreen"] = std::make_unique<GameScreen>(window, m_paddle1, m_paddle2, m_ball, m_commandHandler);

    m_currentScreen = "MenuScreen";
    // to do game objesini her seferinde yeniden initialize etmen lazim

    m_screens[m_currentScreen]->draw(window);
    // m_Screens["GameOverScreen"] = std::make_unique<GameOverScreen>();
}

// make use or remove
void ScreenManager::switchScreen(const std::string &screenName)
{
    m_currentScreen = screenName;
    //   m_ball->reset();
}

void ScreenManager::handleInput(sf::RenderWindow &window)
{
    // buraya callback koyabilirsin
    auto callback = [this](const std::string &screenName)
    { this->switchScreen(screenName); };
    m_screens[m_currentScreen]->handleInput(window, callback);
}

void ScreenManager::draw(sf::RenderWindow &window)
{
    m_screens[m_currentScreen]->draw(window);
}
