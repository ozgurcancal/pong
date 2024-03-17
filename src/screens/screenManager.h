
#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "screen.h"
#include <map>
#include <string>

#include "gameScreen.h"
#include "menuScreen.h"
#include "optionsScreen.h"
#include "gameObjectFactory.h"
#include "gameOverScreen.h"
#include "singlePlayerScreen.h"
#include "multiPlayerScreen.h"

class ScreenManager
{

public:
    ScreenManager(sf::RenderWindow &window);

    void handleInput(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);

private:
    void switchScreen(const std::string &screenName);
    std::map<std::string, std::unique_ptr<Screen>> m_screens;
    std::string m_currentScreen;
    GameObjectFactory m_gameObjectFactory;
    std::shared_ptr<Paddle> m_paddle1, m_paddle2;
    std::shared_ptr<Ball> m_ball;
    std::shared_ptr<CommandHandler> m_commandHandler;
};

#endif // SCREENMANAGER_H