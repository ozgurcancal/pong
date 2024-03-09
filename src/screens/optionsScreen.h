

#ifndef OPTIONS_H
#define OPTIONS_H

#include "screen.h"

class OptionsScreen : public Screen
{

public:
    OptionsScreen(sf::RenderWindow &window);

    // void handleOnput(sf::RenderWindow &window, std::function<void(std::any)> callBack) override;
    void handleInput(sf::RenderWindow &window, std::string &currentScreen) override;
    void draw(sf::RenderWindow &window) override;

private:
    void createScreen(sf::RenderWindow &window) override;
    // Fix: Add a data type and a variable name to the declaration
    sf::Event m_event;
    std::vector<sf::Text> m_menuItems;
    sf::Font m_font;
};

#endif // OPTIONS_H
