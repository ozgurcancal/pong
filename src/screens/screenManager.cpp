

#include "screenManager.h"

ScreenManager::ScreenManager(sf::RenderWindow &window)
{
    m_commandHandler = std::make_shared<CommandHandler>();
    m_paddle1 = m_gameObjectFactory.createPaddle(PaddleType::BLUE);
    m_paddle2 = m_gameObjectFactory.createPaddle(PaddleType::RED);
    m_ball = m_gameObjectFactory.createBall();

    m_paddle1->setPosition(window, PaddlePosition::LEFT);
    m_paddle2->setPosition(window, PaddlePosition::RIGHT);
    m_ball->setPosition(window);

    m_screens["MenuScreen"] = std::make_unique<MenuScreen>(window);
    m_screens["OptionsScreen"] = std::make_unique<OptionsScreen>(window, m_paddle1, m_paddle2, m_ball, m_commandHandler);
    m_screens["SinglePlayerScreen"] = std::make_unique<SinglePlayerScreen>(window, m_paddle1, m_paddle2, m_ball, m_commandHandler);
    m_screens["MultiPlayerScreen"] = std::make_unique<MultiPlayerScreen>(window, m_paddle1, m_paddle2, m_ball, m_commandHandler);
    m_screens["GameOverScreen"] = std::make_unique<GameOverScreen>(window);

    m_currentScreen = "MenuScreen";
    m_screens[m_currentScreen]->draw(window);
}

ScreenManager::~ScreenManager() = default;

void ScreenManager::switchScreen(const std::string &screenName)
{
    m_currentScreen = screenName;
}

void ScreenManager::handleInput(sf::RenderWindow &window)
{
    auto callback = [this](const std::string &screenName)
    { this->switchScreen(screenName); };

    m_screens[m_currentScreen]->handleInput(window, callback);
}

void ScreenManager::draw(sf::RenderWindow &window)
{
    m_screens[m_currentScreen]->draw(window);
}
