
#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "screen.h"
#include <map>
#include <string>

#include "gameScreen.h"
#include "menuScreen.h"

class ScreenManager
{

public:
    ScreenManager(sf::RenderWindow &window);
    void switchScreen(const std::string &screenName, sf::RenderWindow &window);

private:
    std::map<std::string, std::unique_ptr<Screen>> m_screens;
    std::string m_currentScreen;
};

#endif // SCREENMANAGER_H