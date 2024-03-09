

#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
#include <iostream>
#include <any>

class Screen
{
public:
    // Constructor
    Screen()
    {
        loadFont("sprites/GreatVibes.otf"); // Specify the default font path
    }
    virtual void refreshScreen(sf::RenderWindow &window) = 0;

    // virtual void handleOnput(sf::RenderWindow &window, std::function<void(std::any)> callBack) = 0;
    //  virtual void handleInput(sf::RenderWindow &window, std::string &currentScreen) = 0;
    virtual void handleInput(sf::RenderWindow &window, std::function<void(const std::string &)> switchScreenCallback) = 0;

    virtual void draw(sf::RenderWindow &window) = 0;
    virtual ~Screen() = default;

    float m_speed = 1.0f;

protected:
    sf::Font m_font;
    void loadFont(const std::string &fontPath)
    {
        if (!m_font.loadFromFile(fontPath))
        {
            std::cerr << "Error loading font" << std::endl;
        }
    }
};

#endif // SCREEN_H

// std::function<ReturnType(ArgType)> func;

// SingleArgFunctionWrapper(std::function<ReturnType(ArgType)> f) : func(f) {}
