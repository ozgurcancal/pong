

#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>

class Screen
{
public:
    virtual void createScreen(sf::RenderWindow &window) = 0;
    virtual void updateScreen(sf::RenderWindow &window) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual ~Screen() = default;
};

#endif // SCREEN_H