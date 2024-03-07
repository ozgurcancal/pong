

#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "screen.h"

class MenuScreen : public Screen
{

public:
    MenuScreen() = default;
    void createScreen(sf::RenderWindow &window) override;
    void updateScreen(sf::RenderWindow &window) override;
    void draw(sf::RenderWindow &window) override;

private:
    // Fix: Add a data type and a variable name to the declaration
    sf::Event m_event;
    std::vector<sf::Text> m_menuItems;
    sf::Font m_font;
};

#endif // MENUSCREEN_H